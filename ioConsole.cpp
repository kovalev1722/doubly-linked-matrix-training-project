//#include <iostream>
#include <string>
#include "List.h"

using namespace std;

void add(List &list)
{
	while (1)
	{
		cout << "Where do you want to add an element? (Tail, Head): ";
		string choice;
		cin >> choice;
		if (choice == "Tail" || choice == "tail")
		{
			list.addToTail();
			return;
		}
		if (choice == "Head", choice == "head")
		{
			list.addToHead();
			return;
		}
		else
			continue;
	}
}

void insert(List &list)
{
	if (!list.getAmount())
	{
		cout << "The list of matrix is empty." << endl;
		return;
	}
	cout << "Enter the number of element to change it: ";
	int position;
	cin >> position;

	if (position < 0 || position > list.getAmount())
	{
		cout << "There is no such number." << endl;
		return;
	}
	list.insert(position);
}

void remove(List &list)
{
	while (1)
	{
		if (!list.getAmount())
		{
			cout << "The list of matrix is empty." << endl;
			return;
		}
		cout << "Which element do you want to remove? (Tail, Head, Key): ";
		string choice;
		cin >> choice;
		if (choice == "Tail" || choice == "tail")
		{
			list.removeTail();
			return;
		}
		if (choice == "Head", choice == "head")
		{
			list.removeHead();
			return;
		}
		if (choice == "Key" || choice == "key")
		{
			if (!list.getAmount())
			{
				cout << "The list of matrix is empty." << endl;
				return;
			}
			cout << "Enter the number of element to remove it: ";
			int choice;
			cin >> choice;

			if (choice < 0 || choice > list.getAmount())
			{
				cout << "There is no such number." << endl;
				return;
			}
			list.removeElement(choice);
			return;
		}
		else
			continue;
	}
}

void print(List &list)
{
	cout << list;
}

void search(List &list)
{
	cout << "Enter the number of element, which you are searching: ";
	int position;
	cin >> position;

	if (position < 0 || position > list.getAmount())
	{
		cout << "There is no such number." << endl;
		return;
	}
	cout << "\n******************************************\n" << endl;
	cout << "It is your element: \n" << endl;
	list.printElement(list.searchElement(position));
}

void search(List &list, const int &position)
{
	if (position < 0 || position > list.getAmount())
	{
		cout << "There is no such number." << endl;
		return;
	}
	cout << "\n******************************************\n" << endl;
	cout << "It is your element: \n" << endl;
	list.printElement(list.searchElement(position));
}

void filter(List &list, List &filtList)
{
	while (1)
	{
		cout << "How do you want filter the list? (<, >)" << endl;
		cout << "Enter '<'/'>': ";
		string choice;
		cin >> choice;
		if (choice != "<" && choice != ">")
			continue;

		cout << "Enter your trace: ";
		float trace;
		cin >> trace;

		if (choice == ">")
		{
			list.listForFilterMore(filtList, trace);
			cout << filtList;
			return;
		}
		list.listForFilterLess(filtList, trace);
		cout << filtList;
		return;
	}
}

void saveFile(List &list)
{
	list.save();
}

void readFile(List &list)
{
	list.load();
}

void startProgram()
{
	cout << "To begin, enter the command." << endl;
	cout << "If you don't know the command, enter 'Help'." << endl;
	cout << "If you want to exit, enter 'Exit'." << endl;
}

void help()
{
	cout << "\n///////////////////////////////////////////////////////////\n" << endl;
	cout << "\t Command: \t Command discription:\n" << endl;
	cout << "\t Help \t\t List of commands" << endl;
	cout << "\t Add \t\t Add matrix" << endl;
	cout << "\t Insert \t Insert matrix" << endl;
	cout << "\t Search \t Search the element of list" << endl;
	cout << "\t Filter \t To filter matrix list" << endl;
	cout << "\t Save \t\t Save to file" << endl;
	cout << "\t Read \t\t Reads file" << endl;
	cout << "\t Print \t\t To print matrix list" << endl;
	cout << "\t Remove \t Remove matrix" << endl;
	cout << "\t Exit \t\t Program exit" << endl;
	cout << "\n///////////////////////////////////////////////////////////\n" << endl;
	return;
}

void readCommand(List &list, List &filtList)
{
	cout << "Enter the command: ";
	string command;
	getline(cin, command);
	if (command == "Add" || command == "add")
	{
		add(list);
		return;
	}
	if (command == "Print" || command == "print")
	{
		print(list);
		return;
	}
	if (command == "Search" || command == "search")
	{
		search(list);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Filter" || command == "filter")
	{
		filter(list, filtList);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Save" || command == "save")
	{
		saveFile(list);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Read" || command == "read")
	{
		readFile(list);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Remove" || command == "remove")
	{
		remove(list);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Insert" || command == "insert")
	{
		insert(list);
		cin.clear(),
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return;
	}
	if (command == "Help" || command == "help")
	{
		help();
		return;
	}
	if (command == "Exit" || command == "exit")
	{
		exit(1);
	}
	else
	{
		cout << "There is no such command. Enter the command again. ";
	}
}