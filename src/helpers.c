
#include "helpers.h"

#define PRINT(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

void merge(int *arr, int beg, int end, int mid)
{
    int l_size = mid - beg + 1;
    int r_size = end - mid;
    int l_arr[l_size];
    int r_arr[r_size];

    for(int i = 0; i < l_size; i++)
        l_arr[i] = arr[beg + i];
    
    for(int i = 0; i < r_size; i++)
        r_arr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = beg;

    while(i < l_size && j < r_size)
    {
        if(l_arr[i] < r_arr[j])
        {
            arr[k++] = l_arr[i++];
        } else {
            arr[k++] = r_arr[j++];
        }
    }

    while(i < l_size)
    {
        arr[k++] = l_arr[i++];
    }

    while(j < r_size)
    {
        arr[k++] = r_arr[j++];
    }    

}
