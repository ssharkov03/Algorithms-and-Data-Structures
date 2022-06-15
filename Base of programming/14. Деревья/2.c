#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
} tree;

tree* add(tree* t, int n){
    if (t == NULL) {
        t = (tree *)malloc(sizeof(tree));
        t->value = n;
        t->left = NULL;
        t->right = NULL;
        return t;
    }

    if (n < t->value){
        t->left = add(t->left, n);
    }
    else{
        if (n > t->value){
            t->right = add(t->right, n);
        }
    }
    return t;
}


int height(tree* t){
    if (t == NULL){
        return 0;
    }
    int left_height = height(t->left) + (t->left != NULL);
    int right_height = height (t->right) + (t->right != NULL);
    if (right_height >= left_height)
        return right_height;
    else{
        return left_height;
    }
}

void post(tree *t){
    if (t == NULL){
        return;
    }
    post(t->left);
    post(t->right);
    printf("%d ", t->value);
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tree* t=NULL;
    int elem;
    while(scanf("%d", &elem) == 1){
        t = add(t, elem);
    }
    printf("%d", height(t));

    return 0;
}
