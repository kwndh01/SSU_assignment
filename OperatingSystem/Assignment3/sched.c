#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <time.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/mman.h>
#include <fcntl.h>

struct sched_attr {
    int size;
    int sched_policy;
    unsigned long long sched_runtime;
    unsigned long long sched_deadline;
    unsigned long long sched_period;
    int sched_flags;
    int sched_nice;
    int sched_priority;
};

static int sched_setattr(pid_t pid, const struct sched_attr *attr, unsigned int flags) {
    return syscall(SYS_sched_setattr, pid, attr, flags);
}

int main() {
    printf("\033[H\033[J");
    struct timeval mytime;
    double startTime[21], endTime[21];
    double startTimeMil[21], endTimeMil[21];
    double *averages;
    long pidList[21];
    int sp = 0;
    int resulty;
    struct sched_attr attr;
    int cycle = 21;
    int niceValue[21];
    int timeSlice = 10000;
    srand((unsigned)time(NULL));

    printf("Input the Scheduling Policy to apply:\n");
    printf("1. CFS_Default\n");
    printf("2. CFS_NICE\n");
    printf("3. RT_FIFO\n");
    printf("4. RT_RR\n");

    while (sp != 1 && sp != 2 && sp != 3 && sp != 4) {
        scanf("%d", &sp);
    }
    if (sp == 4) {
        printf("Input Time Slice to apply: \n");
        printf("1. 10ms\n");
        printf("2. 100ms\n");
        printf("3. 1000ms\n");
        while (timeSlice != 1 && timeSlice != 2 && timeSlice != 3) {
            scanf("%d", &timeSlice);
        }
    }
    pid_t pidMaster = getpid();

    // averages for calculate average of Elapsed Time
    averages = (double *)mmap(NULL, cycle * sizeof(double), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (averages == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    for (int at = 1; at <= cycle; at++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
        	//startTime Calc
            gettimeofday(&mytime, NULL);
            startTime[at - 1] = (mytime.tv_sec + 9 * 60 * 60) % (60 * 60 * 24);
            startTimeMil[at - 1] = mytime.tv_usec;
            pidList[at - 1] = pidMaster + getpid();
            memset(&attr, 0, sizeof(attr));
            attr.size = sizeof(struct sched_attr);

            if (sp == 1) {
                attr.sched_policy = SCHED_OTHER;
                attr.sched_nice = 0;
            } else if (sp == 2) {
                attr.sched_policy = SCHED_OTHER;
            } else if (sp == 3) {
                attr.sched_policy = SCHED_FIFO;
                attr.sched_priority = 95;
            } else if (sp == 4) {
                attr.sched_policy = SCHED_RR;
                attr.sched_priority = 95;
                if (timeSlice == 1) {
                    attr.sched_period = 10;
                } else if (timeSlice == 2) {
                    attr.sched_period = 100;
                } else {
                    attr.sched_period = 1000;
                }
            }
            if (sp == 2) {
                if (at / 8 == 0) {
                    attr.sched_nice = -20;
                    niceValue[at - 1] = -20;
                } else if (at / 8 == 1) {
                    attr.sched_nice = 0;
                    niceValue[at - 1] = 0;
                } else if (at / 8 == 2) {
                    attr.sched_nice = 19;
                    niceValue[at - 1] = 19;
                }
            }

            resulty = sched_setattr(getpid(), &attr, 0);

            int B[100][100];
            int A[100][100];

            for (int k = 0; k < 100; k++) {
                for (int j = 0; j < 100; j++) {
                    A[j][k] = rand();
                    B[j][k] = rand();
                }
            }

            int count = 0;
            int result[100][100] = {0};
            
            while (count < 100) {
                for (int k = 0; k < 100; k++) {
                    for (int i = 0; i < 100; i++) {
                        for (int j = 0; j < 100; j++) {
                            result[k][j] += A[k][j] * B[i][j];
                        }
                    }
                }
                count++;
            }
            //endTime Calc
            gettimeofday(&mytime, NULL);
            endTime[at - 1] = (mytime.tv_sec + 9 * 60 * 60) % (60 * 60 * 24);
            endTimeMil[at - 1] = mytime.tv_usec;
            
            //print Information
            int check = at - 1;
            long temp1 = startTime[check] / (60 * 60);
            long temp2 = startTime[check] / 60 - temp1 * 60;
            long temp3 = startTime[check] - temp2 * 60 - temp1 * 60 * 60;
            printf("PID: %ld | ", pidList[check]);
            if (sp == 2) {
                printf("NICE: %d | ", niceValue[check]);
            }
            printf("Start time: %ld:%ld:%ld.%.lf | ", temp1, temp2, temp3, startTimeMil[check]);
            long temp4 = endTime[check] / (60 * 60);
            long temp5 = endTime[check] / 60 - temp1 * 60;
            long temp6 = endTime[check] - temp2 * 60 - temp1 * 60 * 60;
            printf("End time: %ld:%ld:%ld.%.lf | ", temp4, temp5, temp6, endTimeMil[check]);
            long temp7 = temp4 - temp1;
            long temp8 = temp5 - temp2;
            long temp9 = temp6 - temp3;
            double revised = endTimeMil[check] - startTimeMil[check];
            if (revised < 0) {
                revised = 1000000 + revised;
                temp9 -= 1;
            }
            printf("Elapsed time: %ld:%ld:%ld.%.lf | \n", temp7, temp8, temp9, revised);

            //Send Process Elapsed time to parent Process
            double temp10 = (endTime[check] - startTime[check]) / (60 * 60);
            double temp100 = (endTime[check] - startTime[check]) / 60 - temp10 * 60;
			double temp1000 = (endTime[check] - startTime[check]) - temp100 * 60 - temp10 * 60 * 60;
            double tempMil = endTimeMil[check] - startTimeMil[check];
            double elapsed = (temp10 * 60 * 60 + temp100 * 60 + temp1000) * 1000000 + tempMil;
            averages[check] = elapsed;

            exit(0);
        }
    }

    // Wait for every process to terminate
    for (int i = 0; i < 21; i++) {
        wait(NULL);
    }

    // Calculate Average of process Elapsed time
    double totalAverage = 0;
    for (int i = 0; i < cycle; i++) {
        totalAverage += averages[i];
    }
    
    totalAverage /= cycle;
    double tvSec = totalAverage / 1000000;
    double tvUsec = totalAverage - tvSec * 1000000;
    double hour = tvSec / (60 * 60);
    double min = tvSec / 60 - hour * 60;
    double sec = tvSec - hour * 60 * 60 - min * 60;
   //print SchedPolicy & Average Time & timeQuantum
    char spChar[20];
	if (sp == 1) {
    		strcpy(spChar, "CFS_DEFAULT");
	} else if (sp == 2) {
    		strcpy(spChar, "CFS_NICE");
	} else if (sp == 3) {
    		strcpy(spChar, "RT_FIFO");
	} else {
    		strcpy(spChar, "RT_RR");
	}

	

    printf("Scheduling Policy: %s | ", spChar);
    if(sp == 4){
	    if(timeSlice == 1){
		    timeSlice = 10;
	    } else if(timeSlice == 2){
		    timeSlice = 100;
	    } else {
		    timeSlice = 1000;
	    }
	    printf("Time Quantum: %d ms | ", timeSlice);
    }
    printf("Average Elapsed Time::%lf\n", tvSec);
 
    munmap(averages, cycle * sizeof(double));

    return 0;
}


