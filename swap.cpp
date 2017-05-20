#include <bits/stdc++.h>
using namespace std;

struct node{
  int data;
  struct node *next;
};
struct node *end;

void begin(struct node **head,int data){
   struct node *newnode=(struct node *)malloc(sizeof(struct node));
   newnode->data=data;
   newnode->next=NULL;

  if(*head==NULL){
    *head=newnode;
    return;
  }

  newnode->next=*head;
  *head=newnode;

  return;
}

void display(struct node *head){
   struct node *temp=head;

   while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
   }
   cout<<endl;
}

void swap(struct node **head,int x,int y){
    if(x==y)
    return;

    struct node *prevx=NULL,*currx=*head,*prevy=NULL,*curry=*head;

    while(currx && currx->data!=x){
        prevx=currx;
        currx=currx->next;
    }

    while(curry && curry->data!=y){
        prevy=curry;
        curry=curry->next;
    }

    if(currx==NULL || curry==NULL)
    return;

    if(prevx!=NULL)
    prevx->next=curry;
    else
    *head=curry;

    if(prevy!=NULL)
    prevy->next=currx;
    else
    *head=currx;

    struct node *temp=curry->next;
    curry->next=currx->next;
    currx->next=temp;

}

int main(){
  struct node *head=NULL;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
   int d;
   cin>>d;
   begin(&head,d);
  }

  display(head);

  swap(&head,8,20);

  display(head);

 return 0;
}
