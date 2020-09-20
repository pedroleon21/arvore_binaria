#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include "tree.h"

void push_node(node *root, int num);
node *alloca_node(int num);
void in_order(node *main_root, int f);

int main()
{
    node *main_root = alloca_node(0);
    for (int i = 0; i < 100; i++)
    {
        push_node(main_root, i);
        //printf("balanced tree %s\n", (balanced_tree(main_root) ? "true" : "false"));
    }
    free_tree(main_root);
    return 0;
}
