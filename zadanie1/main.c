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

