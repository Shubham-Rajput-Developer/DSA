/*
Read the marks obtained by students of second year in an online examination of
particular subject. Find out maximum and minimum marks obtained in that subject.
Use heap data structure. Analyze the algorithm
*/
#include<iostream>
using namespace std;

//Min Heap
void Mininsert(int Heap[],int i)
{
	int parent = (i-1)/2;
	int curr = i;
	while(parent>=0 && Heap[parent]>Heap[curr])
	{
		swap(Heap[parent],Heap[curr]);
		curr = parent;
		parent = (curr-1)/2;
	}
	
}

//Max Heap
void Maxinsert(int Heap[],int i)
{
	int parent = (i-1)/2;
	int curr = i;
	while(parent>=0 && Heap[parent]<Heap[curr])
	{
		swap(Heap[parent],Heap[curr]);
		curr = parent;
		parent = (curr-1)/2;
	}
}
int main()
{
	int n;
	cout<<"\nEnter total No. of Student who score marks in Physics : ";
	cin>>n;
	int Heap[n];
	//Accept Student data
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter Marks of Student "<<(i+1)<<" : ";
		cin>>Heap[i];
	}
	
	//Min Heap
	for(int i=1;i<n;i++)
	{
		Mininsert(Heap,i);
	}
	cout<<"\nMinimum Marks obtained in Physics is : "<<Heap[0];
	
	//Max Heap
	for(int i=1;i<n;i++)
	{
		Maxinsert(Heap,i);
	}
	cout<<"\nMinimum Marks obtained in Physics is : "<<Heap[0];
}