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

int findloop(struct node *head){
    if(head == NULL)
    return 0;

    struct node *temp=head->next;

    while(temp!=NULL && temp!=head)
    temp=temp->next;

    if(temp==NULL)
    return 0;
    else
    return 1;

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
  head->next->next=head;//next->next->next=head;
  //display(head);

  if(findloop(head))
  cout<<"loop found"<<endl;
  else
  cout<<"no loop"<<endl;

 return 0;
}
