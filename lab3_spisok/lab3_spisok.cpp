// lab3_spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct elem {
	int a;
	elem *next = NULL;
};

class list {
	elem *first;
public:
	list() {
		first = new elem;
	}
	~list() {
		while (first)
		{
			elem *p = first->next;
			delete first;
			first = p;
		}
	}
	void Add(int x, int ind);
	void Delete(int ind);
	void Show(int ind);
};

void list::Add(int x, int index)
{
	elem *temp = new elem;
	temp->a = x;
	if (index==0) {
		temp->next = first;
		first = temp;
	}
	else
	{
		elem *dop = first;
		if (index > 1) 
			for (int i = 0; i < index-1; i++) {
				if (dop->next != NULL)
					dop = dop->next;
				else {
					elem *empty = new elem;
					dop->next = empty;
					dop = dop->next;
				}
			}
		elem *el = dop->next;
		dop->next = temp;
		temp->next = el;
	}
	
}

void list::Show(int ind)
{
	elem *temp = first;
	if (ind != 0) {
		for (int i = 0; i < ind; i++)
		{
			temp = temp->next;
		}
	}
	cout << temp->a << endl;
}

void list::Delete(int ind) {
	if (ind == 0) first = first->next;
	else {
		elem *temp = first;
		if (ind > 1) {
			for (int i = 0; i < ind - 1; i++)
			{
				temp = temp->next;
			}
		}
		elem *node = temp->next;
		temp->next = node->next;
		delete node;
	}
}

void main()
{
	int N, ind, dat;
	list lst;
	char command[4];

	cout << "N = ";
	cin >> N;
	cout << "add get dell" << endl;
	for (int i = 1; i <= N; i++) {
		scanf("%s", &command);
		switch (command[0]) {
		case 'a':
			scanf("%d %d", &ind, &dat);
			lst.Add(dat, ind);
			break;
		case 'g':
			scanf("%d", &ind);
			lst.Show(ind);
			break;
		case 'd':
			scanf("%d", &ind);
			lst.Delete(ind);
			break;
		default:
			break;
		}
	}

	system("pause");
}