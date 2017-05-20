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

void append(struct node **head,int data){
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
   newnode->next=NULL;

   if(*head==NULL){
    *head=newnode;
    end=newnode;
    return;
   }

   end->next=newnode;
   end=end->next;
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

void deletenode(struct node **head,int data){
  struct node *temp=*head;

  if(*head==NULL)
   return;

  if(temp->data==data){
     struct node *acg=temp;
     temp=temp->next;
     *head=temp;
     free(acg);
     return;
   }
   while(temp->next!=NULL && temp->next->data!=data)
   temp=temp->next;

   if(temp==NULL)
    return;
   else{
   struct node *acd=temp->next;
   temp->next=temp->next->next;
     free(acd);
   }
   //return;
}

void length(struct node **head){
    int lngth=0;
    struct node *temp=*head;
   while(temp!=NULL){
     lngth++;
     temp=temp->next;
   }
   cout<<lngth<<endl;
}

int searchnode(struct node **head,int d){
   struct node *temp=*head;

   while(temp!=NULL && temp->data!=d){
     temp=temp->next;
   }
   if(temp==NULL)
   return false;
   else
   return true;
}

int main(){
  struct node *head=NULL;
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
   int d;
   cin>>d;
   append(&head,d);
  }

 display(head);

 length(&head);
// deletenode(&head,1);
 //display(head);
if(searchnode(&head,6))
cout<<"yes"<<endl;
else
cout<<"no"<<endl;

 return 0;
}
