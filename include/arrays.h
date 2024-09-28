#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "helpers.h"

void* create_array_int(size_t length);

int array_get_int(int *arr, size_t length, int element);

void merge_sort(int *arr, int beg, int end);

void print_array_int(int *arr, size_t len);

int binary_search_int(int *arr, int len, int element);

#endif