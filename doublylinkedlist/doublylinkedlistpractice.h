class node{

private:
   
    	int data;
    	node *next;
    	node *prev;

public:
   	 node()
	{
	}
    	node(int data)
	{
    		this->data = data;
    		this->next = NULL;
    		this->prev =NULL;
    	}
    	void insertAtBegin(node*&tail,node* &head,int d);
    	void insertAtLast(node* &tail,node* &head,int d);
    	void insertInBetween(node* &tail,node* &head,int position,int d);
    	void deleteFromBegin(node* &head);
    	void deleteFromEnd(node* &head,node* &tail);
    	void deleteFromInBetween(node*&tail,node* &head,int position);
    	void update(node* &head,int d);
    	void traverse(node*&head);
	void reverseTraverse(node*&tail);
};
