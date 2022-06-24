#include "bst.h"
#include <stdlib.h>

 t_btree* bstree_create_node(int item) {
    t_btree* root = malloc(sizeof(t_btree));
    root->item = item;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int)) {
    if (cmpf(item, root->item) == root->item) {
        if (root->left == NULL) {
            root->left = bstree_create_node(item);
            return;
        } else {
            bstree_insert(root->left, item, cmpf);
        }
    }
    if (cmpf(item, root->item) == item) {
        if (root->right == NULL) {
            root->right = bstree_create_node(item);
            return;
        } else {
            bstree_insert(root->right, item, cmpf);
        }
    }
}
void bstree_apply_infix(t_btree *root, void (*applyf) (int)) {
    if (root->left)
        bstree_apply_infix(root->left, applyf);
    if (root)
        applyf(root->item);
    if (root->right)
        bstree_apply_infix(root->right, applyf);
}
void bstree_apply_prefix(t_btree *root, void (*applyf) (int)) {
    if (root)
        applyf(root->item);
    if (root->left)
        bstree_apply_prefix(root->left, applyf);
    if (root->right)
        bstree_apply_prefix(root->right, applyf);
}
void bstree_apply_postfix(t_btree *root, void (*applyf) (int)) {
    if(root->right)
        bstree_apply_postfix(root->right, applyf);
    if (root)
        applyf(root->item);
    if (root->left)
        bstree_apply_postfix(root->left, applyf);
}
