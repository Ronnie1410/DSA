#include "arrays.h"
#include <time.h> 

#define PRINT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)


uint8_t reverse_bits(uint8_t x)
{
    x = ((x&0xF0) >> 4) | ((x&0x0F) << 4);
    x = ((x&0xCC)>>2) | ((x&0x33)<<2);
    x = ((x&0xAA)>>1) | ((x&0x55)<<1);

    return x;
}

uint8_t round_to_greatest_same_pattern(uint8_t x)
{
    uint8_t f1 = x & (~x + 1);
    uint8_t f0_1 = (x+1) & (~(x+1) + 1);
    PRINT("here %x and %x\n", f1, f0_1);

    return  (x | (1<<(f0_1-1))) & ~(1<<(f1-1)); 
}



int main()
{
    int *a = create_array_int(10U);

    for(int i = 0; i < 10; ++i)
    {
        *(a+i) = rand() % 10; 
    }
    print_array_int(a, 10U);
    merge_sort(a, 0, 9);
    print_array_int(a, 10U);
    PRINT("key %d found at %d\n", 2, binary_search_int(a, 10, 2));
    free(a);

    int x = -7;

    unsigned int y = 0xFFFFFFFF;

    //y = y + 1;
    PRINT("%u\n", y);

    short c = 0x00FF;
    PRINT("%x and %x\n", (int)c, c);

    PRINT("%x\n", x);
    y = y<<31;
    PRINT("%x and %u\n", y, y);

    PRINT("%x\n", reverse_bits(0xAA));
    PRINT("%x\n", round_to_greatest_same_pattern(0x02));
    return 0;
}