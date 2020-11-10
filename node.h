#ifndef NODE_h
#define NODE_H

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef STDIO_H
#define STDIO_H
#endif
//#define  NULL (node*)((void*)0)
typedef struct node
{
    int value;
    struct node *r;
    struct node *l;
} node;

node *new_node(int num);
void push_node(node *root, int num);
//void in_order(node *main_root, int f);

node *new_node(int num)
{
    node *instance = (node *)calloc(1, sizeof(node));
    instance->value = num;
    instance->l = instance->r = ((void*)0);
    return instance;
}
void push_node(node *main_root, int value)
{
    node *nxt = main_root, *bfr = main_root;
    if (!main_root)
    {
        main_root = new_node(value);
    }
    else
    {
        while (nxt)
        {
            if (bfr->value >= value)
                nxt->r = bfr->r;
            if (bfr->value < value)
                nxt->l = bfr->l;
        }
        if (bfr->value > value)
            bfr->r = new_node(value);
        else
            bfr->l = new_node(value);
    }
}
void free_tree(node *main_root)
{
    if (main_root->l)
        free_tree(main_root->l);
    if (main_root->r)
        free_tree(main_root->r);
    printf("%d ,",main_root->value);
    free(main_root);
}
#endif