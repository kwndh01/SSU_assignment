#include <stdio.h>
#include <string.h>
// to calculate greatest common divisor
int gcd(int a, int b) {
    while (b != 0) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}
int main() {
    char ciphertext[1000000];
    scanf("%s", ciphertext);
    int cipherlength = strlen(ciphertext);
    int distanceValue[100];
    6
    int distanceCount = 0;
    //to find repeated strings
    for (int i = 0; i < cipherlength - 4; i++) {
        int searchLocation = i;
        char block[5];
        for (int j = 0; j < 5; j++) {
            block[j] = ciphertext[searchLocation + j];
        }
        char candidate[6];
        strcpy(candidate, block);
        int priority = 1;
        for (int k = i + 5; k < cipherlength - 4; k += 5) {
            int compareLocation = k;
            for (int j = 0; j < 5; j++) {
                if (ciphertext[compareLocation + j] != block[j]) {
                    break;
                }
                if (j == 4) {
                    priority++;
                    if (priority == 9) {
                        for (int l = 0; l < 8; l++) {
                            distanceValue[distanceCount++] = k - i;
                        }
                    }
                }
            }
        }
        if (priority >= 4) {
            printf("repeated string '%s' repeated %d times.\n", candidate, priority);
        }
    }
    int prevGCD = distanceValue[0];
//calculate gcd of the entire distanceValue array
    for (int i = 1; i < distanceCount; i++) {
        prevGCD = gcd(prevGCD, distanceValue[i]);
    }
    printf("Greatest Common Divisor: %d\n", prevGCD);
//split blocks in to groups
    char group[30][10000];
    int groupCount = 0;
    for (int i = 0; i < cipherlength; i += 5) {
        char block[5];
        for (int l = 0; l < 5; l++) {
            block[l] = ciphertext[l + i];
        }
        for (int l = 0; l < 5; l++) {
            group[l][groupCount + l] = block[l];
        }
        groupCount++;
    }
    for (int i = 0; i < prevGCD; i++) {
        printf("Group%d: \n", i);
        for (int j = 0; j < groupCount; j++) {
            printf("%c", group[i][j]);
        }
        printf("\n");
    }
//Identify the most frequently used letter and assume it has been shifted from
    the letter 'e' in the alphabet.
    7
    printf("Encrypt Key: ");
    char keys[30];
    for (int i = 0; i < prevGCD; i++) {
        int repeatedTime[26] = {0};
        for (int j = 0; j < groupCount; j++) {
            char temp = group[i][j];
            if (temp >= 'a' && temp <= 'z') {
                repeatedTime[temp - 'a']++;
            }
        }
        int maxIndex = 0;
        int maxCount = 0;
        for (int j = 0; j < 26; j++) {
            if (repeatedTime[j] > maxCount) {
                maxCount = repeatedTime[j];
                maxIndex = j;
            }
        }
        int key = (maxIndex - ('e' - 'a') + 26) % 26;
        keys[i] = key;
        printf("%c", 'a' + key);
    }
    printf("\n");
//shift backward to decrypt ciphertext
    for (int i = 0; i < cipherlength; i += 5) {
        char block[5];
        for (int l = 0; l < 5; l++) {
            block[l] = ciphertext[l + i];
            if (block[l] - keys[l] < 'a') {
                ciphertext[l] = block[l] - keys[l] + 26;
            } else {
                ciphertext[l] = block[l] - keys[l];
            }
            printf("%c", ciphertext[l]);
        }
    }
    return 0;
