#ifndef STACKS_H
#define STACKS_H
#include <iostream>
using namespace std;

template <class T>
class Stacks
{
private:
	struct StackNode
	{
		T value;
		StackNode *next;
	};
	
	StackNode *top;
public:
	Stacks()
	{ top = nullptr; }
	~Stacks();

	void push(T);
	void pop(T &);
	void displayList() const;
	bool isEmpty();
};
template <class T>
Stacks<T>::~Stacks()
{
	StackNode *nodePtr;
	StackNode *nextNode;
	nodePtr = top;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
template <class T>
void Stacks<T>::push(T item)
{
	StackNode *newNode = nullptr;

	newNode = new StackNode;
	newNode->value = item;

	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = top;
		top = newNode;
	}
}
template <class T>
void Stacks<T>::pop(T &item)
{
	StackNode *temp = nullptr;

	if (isEmpty())
	{
		cout << "Stack is empty.\n";
	}
	else
	{
		item = top->value;
		temp = top->next;
		delete top;
		top = temp;
	}
}
template <class T>
bool Stacks<T>::isEmpty()
{
	bool status;

	if (!top)
		status = true;
	else
		status = false;

	return status;
}
template <class T>
void Stacks<T>::displayList() const
{
	StackNode *nodePtr;

	nodePtr = top;

	while (nodePtr)
	{
		cout << nodePtr->value << endl;

		nodePtr = nodePtr->next;
	}
}
#endif
