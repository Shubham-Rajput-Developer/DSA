/*
A Dictionary stores keywords & its meanings. 
Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order.
Also find how many maximum comparisons may require for finding any keyword. 
Use Binary Search Tree for implementation.
*/

#include<iostream>
#include<string.h>
using  namespace std;

struct Node{
	char k[20];
	char m[20];
	Node* left;
	Node* right;
};

class Dict{
	public:
		Node* root;
		void Create();
		void insert(Node *root,Node *temp);
		void Display(Node *root);
		int Search(Node*,char[]);
		int Update(Node*,char[]);
		
};

void Dict::Create()
{
	int ch;
	do{
		Node* temp = new Node();
		cout<<"\nEnter key : ";
		cin>>temp->k;
		cout<<"\nEnter Meaning : ";
		cin>>temp->m;
		temp->left=NULL;
		temp->right=NULL;
		
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			insert(root,temp);
		}
		cout<<"\nDo you want to continue(yes=1/No=0) : ";
		cin>>ch;
	}while(ch==1);
}
void Dict::insert(Node *root,Node *temp)
{
	if(strcmp(temp->k,root->k)<0)
	{
		if(root->left==NULL)
		{
			root->left=temp;
		}
		else
		{
			insert(root->left,temp);
		}
	}
	else
	{
		if(root->right==NULL)
		{
			root->right=temp;
		}
		else
		{
			insert(root->right,temp);
		}			
	}
}
void Dict::Display(Node *root)
{
	if(root!=NULL)
	{
		Display(root->left);
		cout<<"\nKey Word : "<<root->k;
		cout<<"\tMeanning is "<<root->m;
		Display(root->right);
	}
}
int Dict::Search(Node *root,char k[20])
{
	int c=0;
	while(root!=NULL)
	{
		c++;
		if(strcmp(k,root->k)==0)
		{
			cout<<"\nNo. of Comparision require : "<<c;
			return 1;
		}
		if(strcmp(k,root->k)<0)
		{
			root = root->left;
		}
		if(strcmp(k,root->k)>0)
		{
			root = root->right;
		}
	}
	return -1;
}
int Dict::Update(Node *root,char k[20])
{
	while(root!=NULL)
	{
	if(strcmp(k,root->k)==0)
	{
		cout<<"\nEnter Meaning of key "<<root->k<<" : ";
		cin>>root->m;
		return 1;
	}
	if(strcmp(k,root->k)<0)
	{
		root = root->left;
	}
	if(strcmp(k,root->k)>0)
	{
		root = root->right;
	}
	}
	return -1;
}
int main()
{
	Dict d;
	d.root = NULL;
	int ch;
	do{
	cout<<"\nEnter your Choice : \n1.Create \n2.Display \n3.Search \n4.Update \n5.Delete \n--->";
	cin>>ch;
	switch(ch)
	{
		case 1:
			d.Create();
			break;
		case 2:
			if(d.root==NULL)
			{
				cout<<"\nDictionary is Empty!!!!";
			}
			else
			{
				d.Display(d.root);
			}
			break;
		case 3:
			if(d.root==NULL)
			{
				cout<<"\nDictionary is Empty!!!";
			}
			else
			{
				char k[20];
				cout<<"\nEnter key do you want to Search : ";
				cin>>k;
				if(d.Search(d.root,k)==1)
				{
					cout<<"\nKeyword Found ";
				}
				else
				{
					cout<<"\nKeyword Not Found";
				}
			}
			break;
		case 4:
			if(d.root==NULL)
			{
				cout<<"\nDictionary is Empty!!!";
			}
			else
			{
				char k[20];
				cout<<"\nEnter key do you want to update : ";
				cin>>k;
				if(d.Update(d.root,k)==1)
				{
					cout<<"\nUpdate Successfully!!";
				}
				else
				{
					cout<<"\nUpdate Unsuccefull!!!!";
				}
			}
			break;
	}
	}while(ch<5);
	return 0;
}