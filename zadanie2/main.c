#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void decimalToBinary(uint32_t decimal, char * outBuff);
int binaryToDecimal(char * binary);


int main()
{
    int number = 0;
    char decision;
    char charBuff[33], outBuff[33];


    do
    {
        printf("Choose whether you want to convert to binary or to decimal.\
\nPress b, d or e for exit:\n");
        decision = getc(stdin);


