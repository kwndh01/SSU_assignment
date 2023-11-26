#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE3(print_reverse2, long, inputValueFirstLong, long, inputValueLastLong, int, operators) {
long outputValueLong;
if (operators == 1) {
outputValueLong = inputValueFirstLong + inputValueLastLong;
} else {
outputValueLong = inputValueFirstLong - inputValueLastLong;
}
return outputValueLong;
}
