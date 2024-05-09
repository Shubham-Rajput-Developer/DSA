/*
Beginning with an empty binary search tree,
Construct binary search tree by inserting the values in the order given.
After constructing a binary tree - 
i. Insert new node 
ii. Find number of nodes in longest path 
iii. Minimum data value found in the tree 
iv. Change a tree so that the roles of the left and right pointers are swapped at every node 
v. Search a valu
*/
#include<iostream>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};
BSTNode* GetNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
BSTNode* Insert(BSTNode* root,int data)
{
	if(root==NULL)
	{
		root = GetNode(data);
	}
	else if(data < root->data)
	{
		root->left = Insert(root->left,data);
	}
	else
	{
		root->right = Insert(root->right,data);
	}
	return root;
}
void Inorder(BSTNode* root)
{
	if(root==NULL)
	{
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
bool Search(BSTNode* root,int data)
{
	if(root==NULL)
	{
		return false;
	}
	else if(data == root->data)
	{
		return true;
	}
	else if(data<root->data)
	{
		return Search(root->left,data);
	}
	else
	{
		return Search(root->right,data);
	}
}
int maxDepth(BSTNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);
	return 1+max(lh,rh);
}
int minValue(BSTNode* root)
{
	if(root==NULL)
	{
		return 0;
	}
	if(root->left == NULL)
	{
		return root->data;
	}
	return minValue(root->left);
}
void SwapTree(BSTNode* root)
{
	struct BSTNode* temp;
	if(root==NULL)
	{
		return;
	}
	SwapTree(root->left);
	SwapTree(root->right);
	
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	
}
int main()
{
	BSTNode* root = NULL;
	root = Insert(root,5);
	root = Insert(root,3);
	root = Insert(root,6);
	root = Insert(root,7);
	root = Insert(root,1);
	cout<<"Data in Tree is : ";
	Inorder(root);
	cout<<"\nMinimum value is : "<<minValue(root);
	cout<<"\nMaximum Depth is : "<<maxDepth(root);
	int X = Search(root,12);
	if(X)
	{
		cout<<"\nSearch Sucessfully... Element Found!!!";
	}
	else
	{
		cout<<"\nElement Not Found!!!";
	}
	SwapTree(root);
	cout<<"\nSwap Tree data is : ";
	Inorder(root);
}





