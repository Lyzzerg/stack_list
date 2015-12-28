// Queue.cpp: определяет точку входа для консольного приложения.
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
		cout << "Число заданий:" << endl;
		do
		{
			cin >> tmp;
			if (tmp <= 0)	
				cout << "Некорректный ввод" << endl;
		} while (tmp <= 0);
		TQueue <int> queue(tmp);
		mass = new double[tmp];
		for (int i = 0; i < tmp; i++)
			mass[i] = rand() % 100 / 100.0;
		cout << endl << "Вероятность поступления новой задачи (в процентах)" << endl;
		do
		{
			cin >> chance;
			if ((chance < 0) || (chance>100))
				cout << "Некорректный ввод" << endl;
		} while ((chance < 0) || (chance>100));
		chance /= 100.0;
		cout << endl << "Состояние очереди:" << endl;
		int j = 0;
		for (int i = 0; i < tmp; i++)
		{
			if (mass[i] >= chance)
				continue;
			int tmp = (rand() % 100) + 1;  //значение задачи
			queue.Push(tmp);
			j++;
			cout << "В очередь поступила " << i << "-я задача с номером " << tmp << " - вероятность " << mass[i] << endl;
			while ((queue.Top() < queue.Bot()) && (!queue.IsEmpty()))  //если значение первой задачи в очереди меньше последней, то задача считается выполненной
				cout << "Выполнена задача с номером " << queue.Pop() << endl;
		}
		while (!queue.IsEmpty())
			cout << "Выполнена задача с номером " << queue.Pop() << endl;
		if (!j)
			cout << "В очередь не поступило ни одной задачи" << endl;
		else cout << "Всего выполнено " << j << " задач" << endl;
		cout << endl << "Введите '1', если хотите ещё раз ввести вероятность, или любой другой символ для завершения работы:" << endl;
		cin >> c;
		cout << endl;
	} while (c == '1');
    return 0;
}

