// lab3_spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct elem {
	int info;
	elem *next = NULL;
};

class stack {
	elem *first;
public:
	stack() {
		first = new elem;
	}
	~stack() {
		while (first)
		{
			elem *p = first->next;
			delete first;
			first = p;
		}
	}
	void Add(int x);
	void Delete();
	void Show();
};

/**
\func add function of stack - add obj in stack
*/

void stack::Add(int x)
{
	elem *temp = new elem;
	temp->info = x;
	temp->next = first;
	first = temp;
}

/**
\func show function of stack - get first obj in stack
*/

void stack::Show()
{
	cout << first->info << endl;
}

/**
\func del function of stack - del last obj added in stack
*/

void stack::Delete() 
{
	elem *dop = first;
	first = first->next;
	delete dop;
}

/**
\func void main()
*/

int main()
{
	int N, dat;
	stack stack;
	char command[4];

	cin >> N;
	for (int i = 1; i <= N; i++) {

		scanf("%s", &command);
		switch (command[0]) {
		case 'a':
			scanf("%d", &dat);
			stack.Add(dat);
			break;
		case 'g':
			stack.Show();
			break;
		case 'd':
			stack.Delete();
			break;
		default:
			break;
		}
	}

	//system("pause");
	return 0;
}