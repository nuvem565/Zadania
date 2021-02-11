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


        if(decision == 'b')
        {
            printf("Input decimal number:\n");
            scanf("%i", &number);
            decimalToBinary(number, outBuff);
            printf("\nThe integer in binary format:\n%s\n\n", outBuff);
        }
        else if(decision == 'd')
        {
            printf("Input binary number:\n");
            scanf("%s", charBuff);
            printf("\nThe integer in decimal format:\n%i\n\n", binaryToDecimal(charBuff));
        }
        else if(decision == 'e')
        {
            exit(0);
        }

    // clears buffer in case of more than one char inputed resulting in redundant loop iterations
    fflush(stdin);
    } while(1);

    return 0;
}


void decimalToBinary(uint32_t decimal, char * outBuff)
{
    if(decimal == 0)
    {
        outBuff[0] = '0'; outBuff[1] = '\0';
        return ;
    }
    else if(decimal < 0)
        decimal = -decimal;
    // can be easy achieved using itoa function but more general code is following:
    char binBuff[33];
    int i, j;
