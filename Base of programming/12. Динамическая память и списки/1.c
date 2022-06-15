#include <stdio.h>
#include <stdlib.h>

//  wrong answer!


struct node {
    int data;	         //информационное поле, данные
    struct node *next; // указатель на следующий элемент списка
};


struct node* remove_reps(struct node *head){
    struct node *p = head;
    while (p->next != 0){
        if (p->next->data == p->data){
            struct node *tmp = p->next;
            p ->next = tmp->next;
            free(tmp);
            continue;
        }

        p = p -> next;
    }
    return head;
}

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
    struct node  *p, *t;


    int elem;

    scanf("%d", &elem);
    p = (struct node*) malloc( sizeof( struct node ));
    p->data = elem;
    p->next = NULL;
    head = p;

    while(scanf("%d", &elem) == 1){
        p = (struct node*) malloc( sizeof( struct node ) );
        p->data = elem;
        p->next = NULL;
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }

    print(remove_reps(head));
    free_list(head);
    return 0;
}