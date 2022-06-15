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
    struct node  *cur, *temp, *prev;

    int number;
    scanf("%d", &number);
    int elem;

    while(scanf("%d", &elem) == 1){
        cur = (struct node*) malloc(sizeof(struct node));
        cur->data = elem;
        cur->next = head;
        head = cur;
    }
    int flag = 0;
    cur = head;
    prev = head;
    cur = cur -> next;

    while (cur != NULL){
        if (cur -> data == number && flag == 0){
            prev ->data = cur->data;
            prev ->next = cur ->next;
            free(cur);
            cur = prev -> next;
            continue;
        }
        flag = 1;
        if (cur->next != NULL && cur->next->data == number){
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