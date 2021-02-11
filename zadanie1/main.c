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

