// Stack_Task.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "../../../include/Parser.h"
#include <iostream>
#define MaxLen 201
using namespace std;

int main()
{
	char tmpch[MaxLen];
	double rez;
	while (1)
	{
		cin >> tmpch;
		if (tmpch[0] == '\0')
			break;
		TParser tmp(tmpch);
		tmp.infixtopostfix();
		tmp.printinfix();
		tmp.printpostfix();
		rez=tmp.calcPost();
		cout << "result: " <<rez<< endl;
	}
	return 0;
}

