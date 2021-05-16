#ifndef NODE_H
#define NODE_H

#ifndef STDLIB_H
#define STDLIB_H
#endif

#ifndef STDIO_H
#define STDIO_H
#endif

/*
*   Standard structure to binary tree
*   int values, node * r, node * l;
*/
typedef struct node
{
    int value;
    struct node *r, *l;
} node;

/*
*   is_balanced function 
*   return false or true 
*
*/

// bool is_balanced(node *root)
// {
//     int higth_r = calculate_high(root->r, 1);
//     int higth_l = calculate_high(root->l, 0);
//     if (higth_l > higth_r)
//     {
//         int diference = higth_l - higth_r;
//         if (diference < 2)
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }
//     }
// }

/*
*   balance_tree recives a node root
*   balance the tree: void
*   must return new node root not doing
*
*/
// void balance_tree(node *root)
// {
//     if (root->l)
//         balance_tree(root->l);
//     if (root->r)
//         balance_tree(root->r);
//     //if(!is_balanced(root))
//     //balace
// }

/*
*   Node function recives int
*   return new instance of node
*   allocate initializate new *node
*/
node *Node(int num)
{
    node *instance = (node *)malloc(sizeof(node));
    instance->value = num;
    instance->l = instance->r = NULL;
    return instance;
}

/*
*   push_node function recives node *root, int value
*   void
*   create node in position
*/
node *push_node(node *main_root, int value)
{
    node *nxt = main_root, *bfr = main_root;
    if (!value)
        return main_root;
    else if (!main_root)
        return Node(value);
    else
    {
        bool find = true;
        while (find)
        {
            find = false;
            if (nxt->value < value && nxt->r)
            {
                nxt = nxt->r;
                find = true;
            }
            else if (nxt->value > value && nxt->l)
            {
                nxt = nxt->l;
                find = true;
            }
        }
        if (nxt->value < value)
            nxt->r = Node(value);
        else if (nxt->value > value)
            nxt->l = Node(value);
    }
    return main_root;
}

/*
*   free_tree function
*   node * main_root
*   free all tree
*/
void free_tree(node *main_root)
{
    if (main_root->l)
        free_tree(main_root->l);
    if (main_root->r)
        free_tree(main_root->r);
    free(main_root);
}

/*
*   busca function
*   node * main_root, int value;
*   return node * equal value or if not found NULL
*
*/
node *busca(node *main_root, int value)
{
    node *nxt = main_root;
    bool find = true;
    if (!nxt)
        return NULL;
    while (find)
    {
        find = false;
        if (nxt->value == value)
            return nxt;
        if (nxt->r && nxt->value < value)
        {
            nxt = nxt->r;
            find = true;
        }
        else if (nxt->r && nxt->value > value)
        {
            nxt = nxt->l;
            find = true;
        }
        else
        {
            return NULL;
        }
    }
}

/*
*   em_ordem function
*   node * root
*   void
*   print value
*/
void em_ordem(node *root)
{
    if (root->l)
        em_ordem(root->l);
    printf("%d ", root->value);
    if (root->r)
        em_ordem(root->r);
}

/*
*   pre_ordem
*   node * root
*   void
*   print value
*/
void pre_ordem(node *root)
{
    if (root)
    {
        printf("%d ", root->value);
        pre_ordem(root->l);
        pre_ordem(root->r);
    }
}

void pos_ordem(node *root)
{
    if (root)
    {
        pos_ordem(root->l);
        pos_ordem(root->r);
        printf("%d ", root->value);
    }
}

int size_tree(node *root)
{
    if (root)
    {
        return 1 + size_tree(root->l) + size_tree(root->r);
    }
    return 0;
}

#endif