/*
    Array source code 
*/

#include "arrays.h"

#define PRINT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

void* create_array_int(size_t length)
{
    void *array = malloc(sizeof(int) * length);
    if(array == NULL)
    {
        PRINT("Memmory Allocation failed");
        return NULL;
    }
    return array;
}

int array_get_int(int *arr, size_t length, int element)
{
    while(length)
    {
        if(arr[--length] == element)
            return length;
    }
    return -1;
}

void merge_sort(int *arr, int beg, int end)
{
    if(beg>=end)
        return;
    int mid = beg + (end - beg)/2;
    merge_sort(arr, beg, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, beg, end, mid);

}

int binary_search_int(int *arr, int len, int element)
{
    int beg = 0, end = len - 1;

    while(beg <= end)
    {
        int mid =  beg + (end - beg)/2; 
        if(arr[mid] == element)
            return mid;
        else if(arr[mid] > element)
            end = mid - 1;
        else
            beg = mid + 1;
    }
    return -1;
}

void print_array_int(int *arr, size_t len)
{
    int i = 0;
    while(i < len)
    {
        PRINT("%d ", arr[i++]);
    }
    PRINT("\n");
}
