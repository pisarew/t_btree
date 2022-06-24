#include "bst.h"
#include <stdio.h>

void bst_create_test(int item);
void bst_insert_test(int* arr, int n);
void bst_traverse_test(int* arr, int n);

int who_max(int a, int b) {
    int result;
    if (a > b)
        result = a;
    else
        result = b;
    return result;
}
void print_list(int item) {
    printf("%d ", item);
}

int main() {
    bst_create_test(42);
    printf("\n");
    bst_create_test(21);
    printf("\n");
    int test1[] = {4, 2, 1, 8, 6, 7, 0, 3, 5, 9};
    int test2[] = {1, 3, 6, 2, 4};
    bst_insert_test(test1, 5);
    bst_insert_test(test2, 10);
    bst_traverse_test(test1, 10);
    printf("\n");
    bst_traverse_test(test2, 5);
    return 0;
}
void bst_create_test(int item) {
    t_btree* test = bstree_create_node(item);
    printf("item: %d\tleft: %p\tright: %p", test->item, test->left, test->right);
}
void bst_insert_test(int* arr, int n) {
    t_btree* test = bstree_create_node(arr[0]);
    printf("insert %d in ", arr[0]);
    bstree_apply_prefix(test, print_list);
    printf("\n");
    for (int i = 1; i < n; i++) {
        bstree_insert(test, arr[i], who_max);
        printf("insert %d in ", arr[i]);
        bstree_apply_prefix(test, print_list);
        printf("\n");
    }
}
void bst_traverse_test(int* arr, int n) {
    t_btree* root = bstree_create_node(arr[0]);
    for (int i = 1; i < n; i++) {
        bstree_insert(root, arr[i], who_max);
    }
    printf("infix: ");
    bstree_apply_infix(root, print_list);
    printf("\nprefix: ");
    bstree_apply_prefix(root, print_list);
    printf("\npostfix: ");
    bstree_apply_postfix(root, print_list);
}
