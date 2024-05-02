#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Dictionary
{
    public:
    int key;
    Dictionary *left;
    Dictionary *right;
    Dictionary(int ndata)
    {
        key = ndata;
        left=NULL;
        right = NULL;
    }
};
class Copies
{
    public:
    Dictionary *rootNode;
    Copies()
    {
        rootNode = NULL;
    }
    void insertKeys(Dictionary*& rootNode,int data);
    Dictionary* deletekeys(Dictionary* rootNode,int data);
    void updateKeys(Dictionary* rootNode,int data);
    void displayAscendingOrder(Dictionary* rootNode);
    void displayDescendingOrder(Dictionary* rootNode);
};
void Copies::insertKeys(Dictionary*& rootNode,int data)
{
    if(rootNode == NULL)
    {
        rootNode = new Dictionary(data);
        return;
    }
    if(data<=rootNode->key)
    {
        insertKeys(rootNode->left,data);
    }
    else{
        insertKeys(rootNode->right,data);
    }
}
void Copies::displayAscendingOrder(Dictionary* rootNode)
{
    if(rootNode == NULL)
    {
        return;
    }
    displayAscendingOrder(rootNode->left);
    cout<<"Data is"<<rootNode->key<<endl;
    displayAscendingOrder(rootNode->right);
}
void Copies::displayDescendingOrder(Dictionary* rootNode)
{
    if(rootNode == NULL)
    {
        return;
    }
    displayDescendingOrder(rootNode->right);//visit the right node 1st
    cout<<"The data is "<<rootNode->key<<endl;//print data when coming back 
    displayDescendingOrder(rootNode->left);//visit the left node then
}
Dictionary* Copies::deletekeys(Dictionary* rootNode, int data)
{
    if(rootNode ==  NULL)
    {
        return NULL;
    }
    if(rootNode->key == data)
    {
    
    }
}
int main()
{
    Copies copy1;
    copy1.insertKeys(copy1.rootNode,50);
    copy1.insertKeys(copy1.rootNode,45);
    copy1.insertKeys(copy1.rootNode,62);
    copy1.insertKeys(copy1.rootNode,30);
    copy1.insertKeys(copy1.rootNode,54);
    copy1.displayAscendingOrder(copy1.rootNode);
    copy1.displayDescendingOrder(copy1.rootNode);
    return 0;
}