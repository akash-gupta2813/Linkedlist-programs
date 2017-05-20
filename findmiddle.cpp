
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

int findmiddle(struct node *head){
   struct node *prev=head,*curr=head;

    if(head==NULL)
    return 0;

   while(curr!=NULL && curr->next!=NULL){
     prev=prev->next;
     curr=curr->next->next;
   }
   return prev->data;
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
   cout<<findmiddle(head)<<endl;;

 return 0;
}
