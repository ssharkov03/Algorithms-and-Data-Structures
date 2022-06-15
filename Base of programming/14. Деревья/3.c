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

void pref(tree* t){
    if (t == NULL){
        return;
    }
    printf("%d ", t->value);
    pref(t->left);
    pref(t->right);

}

void post(tree *t){
    if (t == NULL){
        return;
    }
    post(t->left);
    post(t->right);
    printf("%d ", t->value);
}

int num_leaves(tree* t){

    if (t == NULL){
        return 0;
    }

    if (t->left == NULL && t->right == NULL){
        return 1;
    }


    return num_leaves(t->left) + num_leaves(t->right);
}




int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    tree* t=NULL;
    int elem;
    while(scanf("%d", &elem) == 1){
        t = add(t, elem);
    }
    printf("%d", num_leaves(t));

    return 0;
}
