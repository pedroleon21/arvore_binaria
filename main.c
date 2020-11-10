#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include "node.h"



int main()
{
    node *main_root = NULL;
    for (int i = 0; i < 100; i++)
    {
        push_node(main_root, i);
        //printf("balanced tree %s\n", (balanced_tree(main_root) ? "true" : "false"));
    }
    free_tree(main_root);
    return 0;
}
