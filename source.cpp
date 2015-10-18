#include <iostream>
#include <string>
#include "Stacks.h"
using namespace std;

const int PUSH_CHOICE = 1, POP_CHOICE = 2, DISPLAY_CHOICE = 3, QUIT_CHOICE = 4;

void menu(int &);
void getStackSize(int &);
void pushItem(Stacks<string>&);
void popItem(Stacks<string>&);
void displayItem(Stacks<string>&);

int main()
{
	//int stackSize;
	int choice;

	//getStackSize(stackSize);
	Stacks<string> stack;

	do
	{
		menu(choice);

		if (choice != QUIT_CHOICE)
		{
			switch (choice)
			{
			case PUSH_CHOICE:
				pushItem(stack);
				break;
			case POP_CHOICE:
				popItem(stack);
				break;
			case DISPLAY_CHOICE:
				displayItem(stack);
			
			}
		}
	} while (choice != QUIT_CHOICE);

	system("pause");
	return 0;
}
void menu(int &choice)
{
	cout << "\nWhat do you want to do?\n"
		<< PUSH_CHOICE
		<< " - push an item on to the stack.\n"
		<< POP_CHOICE
		<< " - pop an item off the stack.\n"
		<< DISPLAY_CHOICE
		<< " - display the items in the stack.\n"
		<< QUIT_CHOICE
		<< " - quit the program.\n"
		<< "Enter your choice: \n";
	cin >> choice;

	while (choice < PUSH_CHOICE || choice > QUIT_CHOICE)
	{
		cout << "Enter a valid choice.\n";
		cin >> choice;
	}
}
void pushItem(Stacks<string> &stack)
{
	string item;

	cin.ignore();
	cout << "\nEnter an item: ";
	getline(cin, item);
	stack.push(item);
}
void popItem(Stacks<string> &stack)
{
	string item = "";

	stack.pop(item);
	if (item != "")
		cout << item << " was popped.\n";
}
void displayItem(Stacks<string> &stack)
{
	stack.displayList();
}
