// TIIMP Laba2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char  s[255];
	char str[255];
	char* result;

	cout << "File name? "; cin >> s;
	ifstream fin(s);
	while (!fin.eof()) {
		fin.getline(s, 255);	//��������� �� ����� ������ � s	
		if ((strstr(s, "\\func")) != NULL) { //�������� �� ������� � s "\func"
			result = strstr(s, "\\func"); //result ��������� �� �� ����� � s, ��� ����� \func
			result += 6;//result ������ ��������� �� 6 ���� ������ (������������ "\func ")
			if (strstr(result, "*/") != NULL) //���������, ������������� �� ������ ������  �� "*/"
			{
				strcpy(str, result); //�������� result  � str 
				str[strlen(result) - 2] = '\0';// "��������" */
				cout << str << endl;
			}
			else
				cout << result << endl;
		}
	}
	//system("pause");

	return 0;
}

