// Stack_Task.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "../../../include/TStack.h"
#include "../../../include/Parser.h"
#include "../../../include/TQueue.h"
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
		cout << "infix: " << tmp.infix << endl;
		cout << "postfix: " << tmp.postfix << endl;
		rez=tmp.calcPost();
		cout << "result: " <<rez<< endl;
	}
	return 0;
}

