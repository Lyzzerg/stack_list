// Queue.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "../../../include/TQueue.h"
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;


int main()
{
	int tmp;
	double chance, *mass;  
	setlocale(LC_CTYPE, "Russian");
	char c;
	do
	{
		cout << "����� �������:" << endl;
		do
		{
			cin >> tmp;
			if (tmp <= 0)	
				cout << "������������ ����" << endl;
		} while (tmp <= 0);
		TQueue <int> queue(tmp);
		mass = new double[tmp];
		for (int i = 0; i < tmp; i++)
			mass[i] = rand() % 100 / 100.0;
		cout << endl << "����������� ����������� ����� ������ (� ���������)" << endl;
		do
		{
			cin >> chance;
			if ((chance < 0) || (chance>100))
				cout << "������������ ����" << endl;
		} while ((chance < 0) || (chance>100));
		chance /= 100.0;
		cout << endl << "��������� �������:" << endl;
		int j = 0;
		for (int i = 0; i < tmp; i++)
		{
			if (mass[i] >= chance)
				continue;
			int tmp = (rand() % 100) + 1;  //�������� ������
			queue.Push(tmp);
			j++;
			cout << "� ������� ��������� " << i << "-� ������ � ������� " << tmp << " - ����������� " << mass[i] << endl;
			while ((queue.Top() < queue.Bot()) && (!queue.IsEmpty()))  //���� �������� ������ ������ � ������� ������ ���������, �� ������ ��������� �����������
				cout << "��������� ������ � ������� " << queue.Pop() << endl;
		}
		while (!queue.IsEmpty())
			cout << "��������� ������ � ������� " << queue.Pop() << endl;
		if (!j)
			cout << "� ������� �� ��������� �� ����� ������" << endl;
		else cout << "����� ��������� " << j << " �����" << endl;
		cout << endl << "������� '1', ���� ������ ��� ��� ������ �����������, ��� ����� ������ ������ ��� ���������� ������:" << endl;
		cin >> c;
		cout << endl;
	} while (c == '1');
    return 0;
}

