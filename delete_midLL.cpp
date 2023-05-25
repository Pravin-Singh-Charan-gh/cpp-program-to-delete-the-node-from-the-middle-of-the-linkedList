#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
};
void append(node**head,int data){
    node*newn=new node();
    newn->data=data;
    newn->next=NULL;
    
    if(*head==NULL){
    *head=newn;
    return ;
    }
    node*temp=*head;
    
    while(temp->next!=NULL)
    temp=temp->next;

    temp->next=newn;
}
void printLL(node**head){
    node*temp=*head;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<"\n";
}
void delete_mid(node**head,int pos){
    if(*head==NULL)return;
    node*temp=*head;
    
    if(pos==0){
        *head=(*head)->next;
        delete temp;
        return;
    }
    
    for(int i=0;i<pos-1 && temp!=NULL;i++)
    temp=temp->next;
    
    if(temp==NULL || temp->next==NULL){
        cout<<"Node are less than position.\n";
        return;
    }
    
    node*next_node=temp->next->next;
    delete temp->next;
    temp->next=next_node;
}
int main(){
    node*head=NULL;
    for(int i=1;i<=10;i++)
    append(&head,i*2);
    printLL(&head);
    delete_mid(&head,0);
    delete_mid(&head,8);
    printLL(&head);
    return 0;
}
