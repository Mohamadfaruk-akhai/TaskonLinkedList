#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int data){
    this->data = data;
    this->next = NULL; 
    }
};
void insertAtBegin(node* &head,int d){
    node*temp=new node(d);
    temp->next=head;
    head=temp;
    
}
void insertAtLast(node* &tail,int d){
    node*temp=new node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertInBetween(node* &tail,node* &head,int position,int d){
    node*temp=head;
    int count=1;
    if(position==1){
        insertAtBegin(head,d);
        return;
    }
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtLast(tail,d);
        return;
    }
    node* newnode = new node(d);
    newnode->next=temp->next;
    temp->next=newnode;
    
}
void deleteFromBegin(node* &head){
    node*temp=head;
    head=head->next;
    delete temp;
    
}
void deleteFromEnd(node* &head,node* &tail){
    node *current=head;
    node*previous=NULL;
    while(current->next!=NULL){
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}
void deleteFromInBetween(node* &head,int position)
{
    node *current=head;
    node*previous=NULL;
    int count=1;
    while(count<position){
        previous=current;
        current=current->next;
        count++;
    }  
    previous->next = current->next;
    delete current;
    
}
void update(node* &head,int d){
    node* temp=head;
    int val=1;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==d)
        {
            temp->data+=val;
            val++;
            flag=1;
        }
        temp=temp->next;
    }
    if(flag==0){
        cout<<"No element found in linkedlist"<<endl;
    }
    else{
        cout<<"element updated succesfully"<<endl;
    }
}
void traverse(node*&head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    node* node1= new node(10);
    node*head=node1;
    node*tail=node1;
    int ch,element,position;
    do{
        cout<<"1.insert node at the begining of linkedlist\n2.insert node at the end of linkedlist\n3.insert node in between from linkedlist\n4.Delete node from the begining of the linkedlist\n5.Delete node from the end of the linkedlist\n6.Delete node in between from linkedlist\n7.update node in linkedlist\n8.traverse the linkedlist\n9.Exit"<<endl;
        cin>>ch;
        switch (ch){
            case 1 : cout<<"Enter the element you want to insert"<<endl;
                     cin>>element;
                     insertAtBegin(head,element);
                     cout<<"node succesfully inserted at begining"<<endl<<endl;
                     break;
            case 2 : cout<<"Enter the element you want to insert"<<endl;
                     cin>>element;
                     insertAtLast(tail,element);
                     cout<<"node succesfully inserted at Last"<<endl<<endl;
                     break;
            case 3 : cout<<"Enter the element you want to insert"<<endl;
                     cin>>element;
                     cout<<"Enter the position where you want to insert element"<<endl;
                     cin>>position;
                    insertInBetween(tail,head,position,element);
                    cout<<"node succesfully inserted at specified position"<<endl<<endl;
                     break;
            case 4 : 
                     deleteFromBegin(head);
                     cout<<"node succesfully deleted from begining"<<endl<<endl;
                     break;
            case 5 : deleteFromEnd(head,tail);
                     cout<<"node succesfully deleted from end"<<endl<<endl;
                     break;
            case 6 : cout<<"Enter the position which node you want to delete"<<endl;
                     cin>>position;
                     deleteFromInBetween(head,position);
                     cout<<"node succesfully deleted from specified position"<<endl<<endl;
                     break;
            case 7 : cout<<"Enter the element you want to update in Linkedlist"<<endl;
                     cin>>element;
                     update(head,element);
                     cout<<endl;
                     break;
            case 8 : cout<<"element In singly linkedlist are: ";
                     traverse(head);
                     cout<<endl<<endl;
                     break;         
            case 9 :
                     break;
            default : cout<<"you Entered wrong choice please enter valid choice"<<endl;
                     
        }
        
    }while(ch!=9);
    return 0;
}
