#include <bits/stdc++.h>
using  namespace std;

struct node{
  int data;
  struct node *next;
};

void push(struct node** head, int new_data)
{
    struct node* newnode =
        (struct node*) malloc(sizeof(struct node));

    newnode->data  = new_data;
    newnode->next = NULL;

    if(*head==NULL){
      *head=newnode;
    }
    else{
     newnode->next=*head;
     *head=newnode;
    }
}

void display(struct node *head){
   struct node *temp=head;
   while(temp!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
   }
   cout<<endl;
}

void mergelist(struct node **head,struct node **head1,struct node **head2){
      struct node *temp;

   if(*head1==NULL || *head2==NULL)
   return;

   if((*head1)->data <= (*head2)->data){
   *head=*head1;
   temp=*head1;
   *head1=(*head1)->next;
  }

   else{
   *head=*head2;
   temp=*head2;
   *head2=(*head2)->next;
  }



   while(*head1 && *head2){
     if((*head1)->data <= (*head2)->data){
       temp->next=*head1;
       temp=temp->next;
       *head1=(*head1)->next;
     }
     else{
        temp->next=*head2;
       temp=temp->next;
       *head2=(*head2)->next;
       }
   }

  if(*head1==NULL){
     temp->next=*head2;
     return;
  }
  else if(*head2==NULL){
    temp->next=*head1;
    return;
  }
}

int main(){
   struct node *head1=NULL,*head2=NULL,*head=NULL;
  push(&head1,19);
  push(&head1,8);
  push(&head1,1);
  push(&head2,45);
  push(&head2,25);
  push(&head2,12);
  push(&head2,8);
  push(&head2,2);


  display(head1);
  display(head2);

  mergelist(&head,&head1,&head2);
  display(head);

return 0;
}
