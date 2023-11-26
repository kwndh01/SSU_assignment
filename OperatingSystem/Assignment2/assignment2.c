#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <ctype.h>

int main(){
    int shutDown = 1;

    while (shutDown){
        int program = 1;
        char inputValue[10000];
        int operators;

        printf("Input: ");

        if (fgets(inputValue, sizeof(inputValue)-1, stdin) == NULL){
            break;
        }

        if (inputValue[0] == '\n'){
            shutDown = 0;
            break;
        }

        inputValue[strlen(inputValue) - 1] = '\0';
        int length = strlen(inputValue);

        for (int i = 0; i < length; i++){
            if (inputValue[i] == '+'){
                program = 2;
                operators = 0;
            }
            else if (inputValue[i] == '-'){
                program = 2;
                operators = 1;
            }
            else if (!isdigit(inputValue[i])){
                program = 0;
                break;
            }
        }

        if (program == 1){
            long inputValueLong = atoi(inputValue);
            long outputValue = syscall(450, inputValueLong);
            printf("Output: %ld\n", outputValue);
        }
        else if (program == 2){
            char inputFirst[1000];
            char inputLast[1000];
            int i;
            int firstLength = 0;


            for (i = 0; i < length; i++) {
                if (isdigit(inputValue[i])) {
                    inputFirst[i] = inputValue[i];
                    firstLength++;
                }
                else {
                    break;
                }
            }
            inputFirst[firstLength] = '\0';


            for (int j = i + 1; j < length; j++) {
                if (isdigit(inputValue[j])) {
                    inputLast[j - i - 1] = inputValue[j];
                }
                else {
                    break;
                }
            }
            inputLast[length - i - 1] = '\0';

            long inputFirstLong = atoi(inputFirst);
            long inputLastLong = atoi(inputLast);
            int change =0;
            if(inputFirstLong <inputLastLong){
                long temp;
                temp = inputFirstLong;
                inputFirstLong = inputLastLong;
                inputLastLong = temp;
                change=1;
            }

            long outputValueLong = syscall(451, inputFirstLong, inputLastLong, operators);
            if (operators==0 && change ==1){
                outputValueLong =0- outputValueLong;
            }
            printf("Output: %ld\n", outputValueLong);
        }
        else{
            printf("Wrong Input!\n");
        }
    }
    return 0;
}
