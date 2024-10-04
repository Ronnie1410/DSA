#include "arrays.h"

#define PRINT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

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
    return 0;
}