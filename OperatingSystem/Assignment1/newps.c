#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *proc;
    struct dirent *location;

    proc = opendir("/proc");
    if (proc == NULL) {
        perror("opendir");
        return 1;
    }

    long clk_tck = sysconf(_SC_CLK_TCK);
    printf("    PID TTY          TIME CMD\n");

    int self_tty_nr;
    {
        int pid = getpid();
        char path[10000];
        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        FILE *file_stat = fopen(path, "r");
        if (file_stat == NULL) {
            perror("fopen");
            return 1;
        }
        fscanf(file_stat, "%*d %*s %*c %*d %*d %*d %d", &self_tty_nr);
        fclose(file_stat);
    }

    int tty_nr_values[1024] = {0};
    int tty_nr_count = 0;

    DIR *proc2;
    struct dirent *location2;

    proc2 = opendir("/proc");
    if (proc2 == NULL) {
        perror("opendir");
        return 1;
    }

    while ((location2 = readdir(proc2)) != NULL) {
        char path[10000];
        int pid, tty_nr;

        if (sscanf(location2->d_name, "%d", &pid) != 1) {
            continue;
        }

        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        FILE *file_stat = fopen(path, "r");

        if (file_stat == NULL) {
            perror("fopen");
            return 1;
        }

        fscanf(file_stat, "%*d %*s %*c %*d %*d %*d %d", &tty_nr);

        fclose(file_stat);

        int found = 0;
        for (int i = 0; i < tty_nr_count; i++) {
            if (tty_nr_values[i] == tty_nr) {
                found = 1;
                break;
            }
        }

        if (!found && tty_nr_count < sizeof(tty_nr_values)/sizeof(tty_nr_values[0])) {
            tty_nr_values[tty_nr_count++] = tty_nr;
        }
    }
    closedir(proc2);

    while ((location = readdir(proc)) != NULL) {
        char path[10000];
        char cmdline[1000];
        int pid,  tty_nr;
        unsigned long usermode_time, kernelmode_time;

        if (sscanf(location->d_name, "%d", &pid) != 1) {
            continue;
        }
        snprintf(path, sizeof(path), "/proc/%d/cmdline", pid);
        FILE *file_cmdline = fopen(path, "r");

        snprintf(path, sizeof(path), "/proc/%d/stat", pid);
        FILE *file_stat = fopen(path, "r");

        if (file_cmdline == NULL || file_stat == NULL) {
            perror("fopen");
            return 1;
        }


        fgets(cmdline, sizeof(cmdline), file_cmdline);
        fscanf(file_stat, "%*d %*s %*c %*d %*d %*d %d %*d %*u %*u %*u %*u %*u %lu %lu",&tty_nr, &usermode_time, &kernelmode_time);

        if (tty_nr != self_tty_nr) {
            continue;
        }

        double seconds = (double)(usermode_time + kernelmode_time) / clk_tck;
        char *cmdline_skip = cmdline;
        if (cmdline[0] == '.' && cmdline[1] == '/') {
            cmdline_skip += 2;
        }
        printf("%7d pts/%-5d%02ld:%02ld:%02ld %s\n", pid, tty_nr_count-3, (long)(seconds / 3600), (long)(seconds / 60) % 60, (long)seconds % 60, cmdline_skip);

        fclose(file_cmdline);
        fclose(file_stat);
    }
    closedir(proc);
    return 0;
}