#include <stdio.h>
#include <stdlib.h>

struct list {
    int data;	         //информационное поле, данные
    struct list *next; // указатель на следующий элемент списка
};


void print(struct list *head){
    for (struct list *p = head; p != 0; p = p->next){
        printf("%d ", p->data);
    }
}

void free_list(struct list *head)
{
    struct list *tmp;

    while(head != NULL){
        tmp = head;
        head = head -> next;
        free(tmp);
    }
}


int mean(struct list *head){
    int cnt = 0;
    int sum = 0;
    for (struct list *p = head; p != 0; p = p->next){
        cnt += 1;
        sum += p -> data;
    }
    return sum/cnt;
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    struct list *head=NULL; // - указатель на голову списка
    struct list  *p, *t;


    int elem;

    scanf("%d", &elem);
    p = (struct list*) malloc( sizeof( struct list ));
    p->data = elem;
    p->next = NULL;
    head = p;

    while(scanf("%d", &elem) == 1){
        p = (struct list*) malloc( sizeof( struct list ) );
        p->data = elem;
        p->next = NULL;
        t = head;
        while (t->next != NULL)
            t = t->next;
        t->next = p;
    }
    int m;
    m = mean(head);
    printf("%d\n", m);
    free_list(head);
    return 0;
}