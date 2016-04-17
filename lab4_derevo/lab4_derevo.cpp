#include "stdafx.h"
#include <iostream>
using namespace std;

int N;
int* mas;

void back(int root) {
	for (int i = 0; i < N; i++)
		if (mas[i] == root)
			back(i);

	cout << root << " ";
}

void direct(int root) {
	cout << root << " ";

	for (int i = 0; i < N; i++)
		if (mas[i] == root)
			direct(i);
}

void symmetric(int root) {
	int id = 0;
	while ((mas[id] != root) && (id < N))
		id++;
	if (id < N)
		symmetric(id);

	cout << root << " ";

	if (id < N)
		for (int i = id + 1; i < N; i++)
			if (mas[i] == root)
				symmetric(i);
}


int main() {

	cin >> N;
	mas = new int[N];
	for (int i = 0; i < N; i++)
		cin >> mas[i];

	int root = 0;
	while (mas[root] != -1)
		root++;

	direct(root);
	cout << endl;
	back(root);
	cout << endl;
	symmetric(root);
	cout << endl;

	delete[] mas;

	system("pause");
	return 0;
}