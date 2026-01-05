#include <iostream>
using namespace std;
class node{
	public:
		int data;
		node* next;
		node* prev;
		node(int val)
		{
			data=val;
			next=NULL;
			prev=NULL;
			
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
	void push_front(int val){
	node *newnode=new node(val);
	
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else{
			newnode->next=head;
			head->prev=newnode;
			head=newnode;
		}
	}
	void push_back(int val){
	node *newnode=new node(val);
	
		if(head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else{
			tail->next=newnode;
			newnode->prev=tail;
			tail=newnode;
			
		}
	}
	void pop_front()
	{
	
		if(head==NULL)
		{
			cout<<"list is empty :"<<endl;
		}
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
			tail=NULL;
			return;
		}
		else{
			node* temp=head;
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
	}
	void pop_back()
	{
		if(head==NULL)
		{
			cout<<"list is empty :"<<endl;
			
		}
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
			tail=NULL;
			return;
		}
		else
		{
			node* temp=tail;
			tail=tail->prev;
			tail->next=NULL;
			delete temp;

		}
	}
	
	void print()
	{
		node* temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
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
return 0;
}

