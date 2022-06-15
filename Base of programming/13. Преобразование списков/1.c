#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;	         //информационное поле, данные
    struct node *next; // указатель на следующий элемент списка
};




void free_list(struct node *head)
{
    struct node *tmp;

    while(head != NULL){
        tmp = head;
        head = head -> next;
        free(tmp);
    }
}


void print(struct node *head){
    for (struct node *p = head; p != 0; p = p->next){
        printf("%d ", p->data);
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    struct node *head=NULL; // - указатель на голову списка
    struct node  *cur, *prev, *temp;


    int elem;
    scanf("%d", &elem);
    cur = (struct node*) malloc( sizeof( struct node ));
    cur->data = elem;
    cur->next = NULL;
    head = cur;
    prev = cur;

    while(scanf("%d", &elem) == 1){

        cur = (struct node*) malloc( sizeof( struct node ) );
        prev->next = cur;
        cur-> data = elem;
        prev = cur;
        cur -> next = NULL;
    }
    cur = head;
    prev = head;
    cur = cur -> next;
    while (cur != NULL){
        if (cur -> data == prev-> data){
            temp = cur->next;
            prev->next = temp;
            free(cur);
            cur = temp;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }

    print(head);
    free_list(head);
    return 0;
}


