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

void reverse(struct node **head){
    struct node *prev=NULL,*curr=*head,*next;

    while(curr!=NULL){
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    *head=prev;
}

void reverserecur(struct node **head){
  struct node *first,*rest;
  if(*head==NULL)
  return;

  first=*head;
  rest=first->next;

  if(rest==NULL)
  return;

  reverserecur(&rest);

  first->next->next=first;
  first->next=NULL;

   *head=rest;
   //cout<<(*(*head)).data<<endl;
   //cout<<rest->data<<endl;
  //cout<<first->data<<endl;
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
  //reverse(&head);
  reverserecur(&head);
  display(head);

 return 0;
}
