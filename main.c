#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"

void push_node(node *root, int num);
node *alloca_node(int num);
void em_ordem(node *main_root, int f);

int main()
{
    node *main_root = alloca_node((int)random() % 100);

    for (int i = 0; i < 10; i++)
    {
        push_node(main_root, (int)random() % 100);
    }
    em_ordem(main_root, 0);
    return 0;
}
