#ifndef TREE_H
#define TREE_H

#ifndef STDBOOL_H
#define STDBOOL_H
#endif

typedef struct node
{
    int pathqtd;
    void * contend;
    node ** paths;
}node;

#endif