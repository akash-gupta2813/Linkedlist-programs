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


struct node * findnode(struct node *head,int pos){
     struct node *curr=head,*prev=head;

     while(curr!=NULL && pos>0){
     curr=curr->next;
     pos--;
     }
     if(curr==NULL)
     return NULL;

     while(curr!=NULL){
         curr=curr->next;
         prev=prev->next;
     }
     return prev;
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

  //swap(&head,2,4);
  int pos;
  cin>>pos;
    struct node *temp=findnode(head,pos);
    if(temp==NULL)
    cout<<"OUT of range"<<endl;
    else
  cout<<temp->data<<endl;

 return 0;
}
