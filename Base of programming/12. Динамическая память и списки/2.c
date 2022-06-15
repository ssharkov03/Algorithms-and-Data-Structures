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


int count(struct list *head){
    int cnt = 0;
    for (struct list *p = head; p != 0; p = p->next){
        if (p->data % 7 == 0 && p->data < 0){
            cnt += 1;
        }
    }
    return cnt;
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    struct list *head=NULL; // - указатель на голову списка
    struct list  *p;


    int elem;

    while(scanf("%d", &elem) == 1){
        p = (struct list*) malloc(sizeof(struct list));
        p->data = elem;
        p->next = head;
        head = p;
    }

    int cnt;
    cnt = count(p);
    printf("%d\n", cnt);
    free_list(p);
    //print(head);

    return 0;
}