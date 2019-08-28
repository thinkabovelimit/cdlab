#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
void insert(struct node *head,int data){
    struct node *t=(struct node *)malloc(sizeof(struct node));
    t=head;
    if(t->next==NULL){
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->data=data;
        head->next=p;
        p->next=NULL;
    }
    else{
        while(t->next!=NULL){
            t=t->next;
        }
        struct node *m=(struct node *)malloc(sizeof(struct node));
        m->data=data;
        t->next=m;
        m->next=NULL;


    }
    t=head;
    while(t->next!=NULL){

        printf("%d\t",t->data);
        t=t->next;
    }
    printf("%d\t",t->data);

}
void count(struct node * head){
    int count=0;
    struct node *m=(struct node *)malloc(sizeof(struct node));
    m=head;
   if(m->next!=NULL){
    m=m->next;
    while(m->next!=NULL){
        count=count+1;
        m=m->next;
    }
   }
    printf("%d",count+1);
    }



int main(){

    struct node * head,p;
    int n,k,data,val=0;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    while(1){

    printf("\n1-insert \n 2-print count");
    scanf("%d",&n);
    if(n==1){
        printf("\nEnter the data");
        scanf("%d",&data);
        insert(head,data);
    }
    else if(n==2){
        count(head);
    }
    else if(n==0){
        exit(0);
    }
    }

}