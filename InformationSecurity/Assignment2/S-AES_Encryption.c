#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Binary to Decimal Number
long long BTD(long long binary)
{
    long long num, m = 0, i = 0;
    while (binary > 0)
    {
        num = binary % 10;
        binary = binary / 10;
        m = m + (num << i);
        i++;
    }
    return m;
}
//Decimal to Binary Number
long long DTB(long long decimal)
{
    if (decimal == 0 || decimal == 1)
    {
        return decimal;
    }
    else
    {
        return decimal % 2 + 10 * DTB(decimal / 2);
    }
}
//RotNib Function
long long RotNib(long long rotNibInput)
{
    long long temp = rotNibInput / 10000;
    rotNibInput = (rotNibInput % 10000) * 10000;
    rotNibInput += temp;
    return rotNibInput;
}
//S-Box
long long S_BOX(long long input)
{
    int SBOX[16] = {9, 4, 10, 11, 13, 1, 8, 5, 6, 2, 0, 3, 12, 14, 15, 7};
    input = BTD(input);
    input = DTB(SBOX[input]);
    return input;
}
//SubNib Function
long long SubNib(long long subNibInput)
{
    long long left = subNibInput / 10000;
    long long right = subNibInput % 10000;
    left = S_BOX(left);
    right = S_BOX(right);
    subNibInput = left * 10000 + right;
    return subNibInput;
}
int main()
{
    // Key Generation
    long long plaintext, binaryKey;
    printf("Enter plaintext: ");
    scanf("%lld", &plaintext);
    printf("Enter binary key: ");
    scanf("%lld", &binaryKey);
    long long w0, w1;
    w0 = binaryKey / 100000000;
    w1 = binaryKey % 100000000;
    long long w2 = BTD(w0) ^ BTD(10000000) ^ BTD(SubNib(RotNib(w1)));
    w2 = DTB(w2);
    long long w3 = BTD(w2) ^ BTD(w1);
    w3 = DTB(w3);

    long long w4 = BTD(w2) ^ BTD(110000) ^ BTD(SubNib(RotNib(w3)));
    w4 = DTB(w4);
    long long w5 = BTD(w4) ^ BTD(w3);
    w5 = DTB(w5);
    long long key0 = w0 * 100000000 + w1;
    long long key1 = w2 * 100000000 + w3;
    long long key2 = w4 * 100000000 + w5;
    // Encryption
    //Add Round0 Key
    long long result = BTD(plaintext) ^ BTD(key0);
    result = DTB(result);

//Round1
    long long resultLeft = result /100000000;
    long long resultRight = result % 100000000;
    resultLeft = SubNib(resultLeft);
    resultRight = SubNib(resultRight);
    result = resultLeft * 100000000 + resultRight;
    long long result0, result1, result2, result3;
    result0 = result / 1000000000000;
    result = result % 1000000000000;
    result1 = result / 100000000;
    result = result % 100000000;
    result2 = result / 10000;
    result = result % 10000;
    result3 = result;
    int M[2][2] = {{1, 2}, {3, 4}};
    int S[2][2] = {{result0, result2}, {result3, result1}};
    int SP[2][2] = {{0, 0}, {0, 0}};
    int b0 = S[0][0] / 1000;
    S[0][0] = S[0][0] % 1000;
    int b1 = S[0][0] / 100;
    S[0][0] = S[0][0] % 100;
    int b2 = S[0][0] / 10;
    S[0][0] = S[0][0] % 10;
    int b3 = S[0][0];
    int b4 = S[1][0] / 1000;
    S[1][0] = S[1][0] % 1000;
    int b5 = S[1][0] / 100;
    S[1][0] = S[1][0] % 100;
    int b6 = S[1][0] / 10;
    S[1][0] = S[1][0] % 10;
    int b7 = S[1][0];
    int c0 = S[0][1] / 1000;
    S[0][1] = S[0][1] % 1000;
    int c1 = S[0][1] / 100;
    S[0][1] = S[0][1] % 100;
    int c2 = S[0][1] / 10;
    S[0][1] = S[0][1] % 10;
    int c3 = S[0][1];
    int c4 = S[1][1] / 1000;
    S[1][1] = S[1][1] % 1000;
    int c5 = S[1][1] / 100;
    S[1][1] = S[1][1] % 100;
    int c6 = S[1][1] / 10;
    S[1][1] = S[1][1] % 10;
    int c7 = S[1][1];
    SP[0][0] = (b0 ^ b6) * 1000 + (b1 ^ b4 ^ b7) * 100 + (b2 ^ b4 ^ b5) * 10 + b3 ^ b5;
    SP[0][1] = (c0 ^ c6) * 1000 + (c1 ^ c4 ^ c7) * 100 + (c2 ^ c4 ^ c5) * 10 + c3 ^ c5;
    SP[1][0] = (b2 ^ b4) * 1000 + (b0 ^ b3 ^ b5) * 100 + (b0 ^ b1 ^ b6) * 10 + b1 ^ b7;
    SP[1][1] = (c2 ^ c4) * 1000 + (c0 ^ c3 ^ c5) * 100 + (c0 ^ c1 ^ c6) * 10 + c1 ^ c7;
    result = (long long)SP[0][0] * 1000000000000 + (long long)SP[1][0] * 100000000 + (long
    long)SP[0][1] * 10000 + (long long)SP[1][1];
    result = BTD(result) ^ BTD(key1);
    result = DTB(result);

    //Final Round
    resultLeft = result / 100000000;
    result = result % 100000000;
    resultRight = result;
    resultLeft = SubNib(resultLeft);
    resultRight = SubNib(resultRight);
    result = resultLeft * 100000000 + resultRight;
    result0 = result/1000000000000;
    result = result%1000000000000;
    result1 = result/100000000;
    result = result%100000000;
    result2 = result/10000;
    result = result%10000;
    result3 = result;
    result = result0*1000000000000 + result3*100000000 + result2*10000 + result1;
    result = BTD(result) ^ BTD(key2);
    result = DTB(result);
    printf("CipherText: %lld\n", result);
    return 0;
}
