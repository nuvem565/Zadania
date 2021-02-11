#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


typedef struct
{
    uint8_t id;
    uint8_t message;
    uint8_t ctrl;
} obj;

obj storage[1000];


int main(int argc, char *argv[])
{
    printf("\n");
    // file pointer for input.txt, which takes first argument passed to main or simply input text file
    FILE* input = fopen( (argc == 2 ? argv[1] : "input.txt") , "r");
    //char array for every 8 bits of the input data
    char ch[8];

    // prepare temporal object for storing it and use in the loop
    obj temp = {0,0,0};
    // a loop reads from the file, then every 8 bits assigns them to the
    // fields of the temporal object. i = [0,7], number of bytes: bytesCount = [0, +]
    int i = 0, bytesCount = 0;
    while( (ch[i] = getc(input)) != EOF )
    {
        // saves each char 48 as 0, and 49 as 1 and skips all other characters
        if(ch[i] == '1' || ch[i] == '0')
        {
            ch[i] -= '0';
        }
        else
        {
            i++;
            continue;
        }
        if(i == 7)
        {
            // bit shifting - for manual placing proper bits in each field
            temp.id = (uint8_t)(
                ch[0] << 3\
                | ch[1] << 2\
                | ch[2] << 1\
                | ch[3]);
            temp.message = (uint8_t)(
                ch[4] << 2\
                | ch[5] << 1\
                | ch[6]);
            temp.ctrl = (uint8_t)ch[7];

            storage[bytesCount] = temp;
            /* debug only
            if( temp.message == 0 || temp.ctrl != (temp.id % 2) )
                printf( "Incorrect! %i, %i, %i \n", temp.id, temp.message, temp.ctrl);
            else
                printf( "Correct data: %i, %i, %i\n", temp.id, temp.message, temp.ctrl);
            */
            i = 0;
            bytesCount++;
        }
        i++;
    }
