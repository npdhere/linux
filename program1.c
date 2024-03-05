#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head, *temp, *newnode;

void create(){
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("note: enter the elements in sorted way\n");
    for(i=0;i<n;i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
}

void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp= temp->next;
    }
    printf("NULL");
}

void remove_duplicate(){
    struct node* temp1;
    temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            temp1=temp->next->next;
            free(temp->next);
            temp->next=temp1;
        }
        else{
            temp=temp->next;
        }
    }
}
int main(){
    create();
    printf("the created linked list: ");
    display();
    remove_duplicate();
    printf("\nlinked list after removing duplicates: ");
    display();
    
}
