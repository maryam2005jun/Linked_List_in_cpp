#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node(int val)
		{
			data=val;
			next=NULL;
		}
};
class list{
	
		node* head;
		node* tail;
		public:
		list()
		{
			head=NULL;
			tail=NULL;
		}
			void push_front(int val)
{
	node* newnode=new node(val);
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
		return ;
	}
	else {
		newnode->next=head;
		head=newnode;
	}
}
void push_back(int val){

node* newnode =new node(val);
	if(head==NULL)
	{
		head=newnode;
		tail=newnode;
		return;
	}
	else
{
	tail->next=newnode;
	tail=newnode;
	
}
}
void pop_front()
{
	if(head==NULL)
	{
		cout<<"list is empty "<<endl;
		return;
	}
	node* temp=head;
	head=head->next;
	delete temp;
}
void pop_back()
{
	if(head==NULL)
	{
		cout<<"list is empty "<<endl;
		return;
	}
	else
	{
		node* temp =head;
		while(temp->next!=tail)
		{
			temp=temp->next;
		}
	delete tail;
	tail=temp;
	tail->next=NULL;
	}
}
void print ()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void insert(int val,int  pos)
{
	node* newnode=new node(val);
	if (pos<0)
	{
		cout<<"linked out of bound"<<endl;
	 }

	 	if(pos==0){
		 
	 	push_front(val);

	  } 
	  node* temp=head;
	  for(int i=0;i<pos-1;i++)
	  {
	  	if(temp==0)
	  	{
	  		cout<<"out of bound";
	  		
		  }
		  temp=temp->next;
		  if(temp==tail)
		  {
		  	push_back(val);
		  	
		  }
		  newnode->next=temp->next;
		  temp->next=newnode;
		  
	  }
	  
}
int search(int key)
{
	node* temp=head;
	int pos=0;
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			return pos;
		}
		temp=temp->next;
		pos++;
	}
	return -1;
}

};

int main()
{
list l;
l.push_back(1);
l.push_back(2);
l.push_back(3);
l.push_front(0);
l.print();
l.pop_front();
l.print();
l.pop_back();
l.print();
l.insert(3,2);
l.print();
cout<<"element 2 found at position :"<<l.search(2)<<endl;
cout<<"element 3 found at position :"<<l.search(3)<<endl;
return 0;
}
