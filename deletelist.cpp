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


void deletelist(struct node **head){
  struct node *temp=NULL,*curr=*head;

  while(curr!=NULL){
    temp=curr;
    curr=curr->next;
    free(temp);
  }
   if(curr==NULL)
   cout<<"All deleted"<<endl;

   *head=NULL;
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

  deletelist(&head);
  display(head);
 return 0;
}
