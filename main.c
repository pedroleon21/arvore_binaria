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

void push_node(node *main_root, int num)
{
    printf("%d ", num);
    node *aux, *nxt;
    //if (main_root == NULL) problemas

    nxt = aux = main_root;
    while (nxt != NULL && num != aux->var)
    {
        aux = nxt;
        if (num > aux->var)
        {
            printf("r");
            nxt = aux->r;
        }
        if (num < aux->var)
        {
            printf("l");
            nxt = aux->l;
        }
    }
    if (num > aux->var)
    {
        printf("alocando a direita");
        aux->r = alloca_node(num);
    }
    if (num < aux->var)
    {
        printf("alocando a esquerda");
        aux->l = alloca_node(num);
    }printf(" %d\n",aux->var);
}
node *alloca_node(int num)
{
    node *n = (node *)calloc(1, sizeof(node));
    n->var = num;
    return n;
}
void em_ordem(node *main_root, int f)
{
    if (main_root->l != NULL)
    {
        em_ordem(main_root->l, f + 1);
    }
    printf("var: %d, profundidade: %d\n", main_root->var, f);
    if (main_root->r != NULL)
    {
        em_ordem(main_root->r, f + 1);
    }
    free(main_root);
}