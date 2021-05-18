#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include "node.h"
#include "utils/utils.h"


int main(int argc, char *argv[])
{
    node *root = NULL;
    int n = 0, *vet = NULL;
    printf("INT_MAX %d node: %ld , argc: %d\n", INT_MAX, sizeof(node), argc);
    if (argc == 1)
    {
        printf("Digite o tamanho a arvore: ");
        scanf("%d", &n);
    }
    else
        n = atoi(argv[1]);

    vet = cria_bagunca_vetor(n);
    for (int i = 0; i < n; i++)
        root = push_node(root, vet[i]);

    free(vet);
    pula();
    em_ordem(root);
    pula();
    pre_ordem(root);
    pula();
    pos_ordem(root);
    printf("\n size: %d", size_tree(root));
    free_tree(root);
    return 0;
}