#ifndef bst_h
#define bst_h

#include <stdio.h>

typedef struct t_btree {
    int item;
    struct t_btree* left;
    struct t_btree* right;
}t_btree;

t_btree *bstree_create_node(int item);
void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int));
void bstree_apply_infix(t_btree *root, void (*applyf) (int));
void bstree_apply_prefix(t_btree *root, void (*applyf) (int));
void bstree_apply_postfix(t_btree *root, void (*applyf) (int));

#endif /* bst_h */
