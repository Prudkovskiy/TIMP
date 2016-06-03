#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;


class Base {
public:
	virtual void show() = 0;
	void setData(int v) {
		value = v;
	}
protected:
	int value;
};

class A : public Base {
public:
	void show() { cout << "class A: " << value << endl; }
};

class B : public Base {
public:
	void show() { cout << "class B: " << value << endl; }
};

class C : public Base {
public:
	void show() { cout << "class C: " << value << endl; }
};

map <int, Base*> mbase;

int main()
{
	int N;
	int data;
	cin >> N;
	string command;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		if (command == "showall") {
			for (int j = 0; j < mbase.size(); j++)
				mbase[j]->show();
		}
		if (command == "create")
		{
			cin >> command;
			if (command == "A") {
				cin >> data;
				mbase[k] = new A;
				mbase[k]->setData(data);
				k++;
			}
			if (command == "B") {
				cin >> data;
				mbase[k] = new B;
				mbase[k]->setData(data);
				k++;
			}
			if (command == "C") {
				cin >> data;
				mbase[k] = new C;
				mbase[k]->setData(data);
				k++;
			}
		}
	}
	//system("pause");
	return 0;
}