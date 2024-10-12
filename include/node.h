#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct {
    int val;
    node *next;
}node;

node *create_node(int val)
{
    node *new_node = (node *)malloc(sizeof(node));

    if(new_node !=NULL)
    {
        
    }

    return new_node;
}

#endif