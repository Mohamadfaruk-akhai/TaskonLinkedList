#include <iostream>
using namespace std;
#include "doublylinkedlistpractice.h"
void node::insertAtBegin(node*&tail,node* &head,int d)
{
    	if(NULL == head)
	{
        	node*temp=new node(d);
        	head=temp;
        	tail=temp;
    	}
    	else
	{
    		node*temp=new node(d);
    		temp->next=head;
    		head->prev=temp;
    		head=temp;
    	}
    
}
void node::insertAtLast(node* &tail,node* &head,int d)
{
     	if(NULL == tail)
	{
	        node*temp=new node(d);
	        head=temp;
	        tail=temp;
    	}
    	else
	{
	    	node*temp=new node(d);
	    	tail->next=temp;
    		temp->prev=tail;
    		tail=temp;
    	}
}
void node::insertInBetween(node* &tail,node* &head,int position,int d)
{
    	node*temp=head;
    	int count=1;
    	if(1==position)
	{
        	insertAtBegin(tail,head,d);
        	return;
    	}
    	while(count<position-1)
	{
        	temp=temp->next;
        	count++;
    	}
    	if(NULL==temp->next)
	{
        	insertAtLast(tail,head,d);
        	return;
    	}
    	node* newnode = new node(d);
    	newnode->next=temp->next;
    	temp->next->prev=newnode;
    	newnode->prev=temp;
    	temp->next=newnode;
    
}
void node::deleteFromBegin(node* &head)
{
    	node*temp=head;
    	temp->next->prev=NULL;
    	head=head->next;
    	delete temp;
    
}
void node::deleteFromEnd(node* &head,node* &tail)
{
    	node *current=head;
    	node*previous=NULL;
    	while(NULL!=current->next)
	{
        	previous=current;
	        current=current->next;
    	}
    	tail=previous;
    	previous->next=NULL;
    	current->prev=NULL;
    	delete current;
}
void node::deleteFromInBetween(node*&tail,node* &head,int position)
{
    if(1==position){
        deleteFromBegin(head);
    }
    else{
    node *current=head;
    node*previous=NULL;
    int count=1;
    while(count<position){
        previous=current;
        current=current->next;
        count++;
    } 
    if(NULL==current->next)
    	tail=previous;
    current->prev=NULL;
    previous->next = current->next;
    delete current;
    }
}
void node::update(node* &head,int d)
{
    	node* temp=head;
    	int val=1;
    	int flag=0;
    	while(NULL!=temp)
	{
        	if(temp->data==d)
        	{
            		temp->data+=val;
            		val++;
            		flag=1;
        	}
        	temp=temp->next;
    	}
    	if(0==flag)
	{
        	cout<<"No element found in linkedlist"<<endl;
    	}
    	else
	{
        	cout<<"element updated succesfully"<<endl;
    	}
}
void node::traverse(node*&head)
{
    	node*temp=head;
    	if(NULL==head)
	{
	        cout<<"linkedlist are empty"<<endl;
    	}
    	else
	{
    		cout<<"element In singly linkedlist are: ";
    		while(NULL!=temp)
		{
        		cout<<temp->data<<" ";
        		temp=temp->next;
    		}
    	}
}
void node::reverseTraverse(node*&tail)
{
    	node*temp=tail;
    	if(NULL==tail)
	{
        	cout<<"linkedlist are empty"<<endl;
    	}
    	else
	{
    		cout<<"element In singly linkedlist are: ";
    		while(NULL!=temp)
		{
		        cout<<temp->data<<" ";
		        temp=temp->prev;
		}
    	}
}
int main()
{
    	node ll;
    	//node* node1= new node(10);
    	node*head=NULL;
    	node*tail=NULL;
    	int ch,element,position;
    	do
	{
		cout<<"1.insert node at the begining of linkedlist\n2.insert node at the end of linkedlist\n3.insert node in between from linkedlist\n4.Delete node from the begining of the linkedlist\n5.Delete node from the end of the linkedlist\n6.Delete node in between from linkedlist\n7.update node in linkedlist\n8.traverse the linkedlist\n9.traverse the linkedlist in reverse order\n10.Exit"<<endl;
        	cin>>ch;
        	switch (ch)
		{
            		case 1 :cout<<"Enter the element you want to insert"<<endl;
                     		cin>>element;
                     		ll.insertAtBegin(tail,head,element);
                     		cout<<"node succesfully inserted at begining"<<endl<<endl;
                     		break;
            		case 2 :cout<<"Enter the element you want to insert"<<endl;
                     		cin>>element;
                     		ll.insertAtLast(tail,head,element);
                     		cout<<"node succesfully inserted at Last"<<endl<<endl;
                     		break;
            		case 3 :cout<<"Enter the element you want to insert"<<endl;
                     		cin>>element;
                     		cout<<"Enter the position where you want to insert element"<<endl;
                     		cin>>position;
                    		ll.insertInBetween(tail,head,position,element);
                    		cout<<"node succesfully inserted at specified position"<<endl<<endl;
                     		break;
            		case 4 :ll.deleteFromBegin(head);	
                     		cout<<"node succesfully deleted from begining"<<endl<<endl;
                     		break;
            		case 5 :ll.deleteFromEnd(head,tail);
                    		cout<<"node succesfully deleted from end"<<endl<<endl;
                    		break;
            		case 6 :cout<<"Enter the position which node you want to delete"<<endl;
                     		cin>>position;
                     		ll.deleteFromInBetween(tail,head,position);
                     		cout<<"node succesfully deleted from specified position"<<endl<<endl;
                     		break;
            		case 7 :cout<<"Enter the element you want to update in Linkedlist"<<endl;
                    		cin>>element;
                    		ll.update(head,element);
                    		cout<<endl;
                     		break;
            		case 8 :ll.traverse(head);
                     		cout<<endl<<endl;
                     		break;  
	    		case 9 :ll.reverseTraverse(tail);
                     		cout<<endl<<endl;
                    	 	break;        
            		case 10 :break;		
            		default :cout<<"you Entered wrong choice please enter valid choice"<<endl;         
        	}   
    }while(ch!=10);
    return 0;
}

