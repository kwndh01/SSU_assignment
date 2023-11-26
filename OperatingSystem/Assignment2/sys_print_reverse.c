#include <linux/kernel.h>
#include <linux/syscalls.h>

//custom strlen function
int custom_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// string upside down
void custom_reverse(char *str) {
    int length = custom_strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

//custom atoi function
long custom_atoi(const char *str) {
    long result = 0;
    int sign = 1;

    while (*str == ' ') {
        str++;
    }

    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

SYSCALL_DEFINE1(print_reverse, long, inputValue) {
char inputValueString[10000];
sprintf(inputValueString, "%ld", inputValue);

custom_reverse(inputValueString);

long outputValue = custom_atoi(inputValueString);
return outputValue;
}