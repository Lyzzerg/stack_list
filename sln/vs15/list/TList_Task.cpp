#include "../../include/TPolinom.h"
#include <iostream>
using namespace std;
TPolinom CreatePolinom(double **mass, int _size)
{
	TPolinom tmppol;
	TMonom tmpmon;
	for (int i = _size - 1; i >= 0; i--)
	{
		tmpmon.coeff = mass[0][i];
		tmpmon.power = mass[1][i];
		tmppol.insFirst(tmpmon);
	}
	return tmppol;
}

void qsort(double **mass, int left, int right)
{
	int l = left;
	int r = right;
	double foo1 = 0, foo2 = 0;
	double mid = mass[1][(l + r) / 2];

	while (l <= r)
	{
		while ((mass[1][l] > mid) && (l <= right))
		{
			l++;
		}
		while ((mass[1][r] < mid) && (r >= left))
		{
			r--;
		}

		if (l <= r)
		{
			foo1 = mass[1][l];
			foo2 = mass[0][l];
			mass[1][l] = mass[1][r];
			mass[0][l] = mass[0][r];
			mass[1][r] = foo1;
			mass[0][r] = foo2;
			l++;
			r--;
		}
	}

	if (r > left)
	{
		qsort(mass, left, r);
	}
	if (l < right)
	{
		qsort(mass, l, right);
	}
}

TPolinom createPolinom(double mass[][2], int _size)
{
	TPolinom tmppol; // { {1,100} {2,40} .....}
	TMonom tmpmon;
	for (int i = _size - 1; i >= 0; i--)
	{
		tmpmon.coeff = mass[i][0];
		tmpmon.power = mass[i][1];
		tmppol.insFirst(tmpmon);
	}
	return tmppol;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	TPolinom P, Q, Z;
	int stop=0,numberofmonoms, monompower, whattodo;
	double **massive3 = new double*[2];
	/*double massive1[][2] = { {4,333}, {1,222}, {1,111} };
	double massive2[][2] = { {3,333}, {2,222}, {2,000} };
	P=createPolinom(massive1, 3);
	Q = createPolinom(massive2, 3);
	P.similar();
	Q.similar();
	//cout << "P: " << P << endl;
	//cout << "Q: " << Q << endl << endl;
	//cout << "Z: " << Z << endl;
	*/
	cout << "введите количество мономов:" << endl;
	cin >> numberofmonoms;
	massive3[0] = new double[numberofmonoms];
	massive3[1] = new double[numberofmonoms];
	for (int i = 0; i < numberofmonoms; i++)
	{
		cout << "Введите коэффициент при " << i+1 << " мономе" << endl;
		cin >> massive3[0][i];
		cout<<endl<<"Введите степени при " << i+1 << " мономе" << endl;
		cout << "X^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] = monompower * 100;
		cout << "Y^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] += monompower * 10;
		cout << "Z^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] += monompower;
	}
	///
	qsort(massive3, 0, numberofmonoms - 1);
	P = CreatePolinom(massive3, numberofmonoms);
	///
	cout << "введите количество мономов:" << endl;
	cin >> numberofmonoms;
	massive3[0] = new double[numberofmonoms];
	massive3[1] = new double[numberofmonoms];
	for (int i = 0; i < numberofmonoms; i++)
	{
		cout << "Введите коэффициент при " << i + 1 << " мономе" << endl;
		cin >> massive3[0][i];
		cout << endl << "Введите степени при " << i + 1 << " мономе" << endl;
		cout << "X^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] = monompower * 100;
		cout << "Y^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] += monompower * 10;
		cout << "Z^ ";	do { cin >> monompower; } while (!(monompower > 0 && monompower < 9));	massive3[1][i] += monompower;
	}
	qsort(massive3, 0, numberofmonoms - 1);
	Q = CreatePolinom(massive3, numberofmonoms);
	system("cls");
	cout << "P: " << P << endl;
	cout << "Q: " << Q << endl << endl;
	do
	{
		cout << "Выберите действие:" << endl;
		cout << "1 - сложить" << endl << "2 - вычесть" << endl << "3 - умножить" << endl << "4-ввести другие полиномы" << endl;
		cin >> whattodo;
		cout << endl;
		switch (whattodo)
		{
		case 1:
			Z = P + Q;
			cout << "P+Q= " << Z << endl<<endl;
			break;
		case 2:
			Z = P - Q;
			cout << "P-Q= " << Z << endl << endl;
			break;
		case 3:
			Z = P*Q;
			cout << "(ATTENTION!)" << endl << "Произведение может быть подсчитано не верно, если хотя бы одна из сумм степеней > 9" << endl << endl;
			cout << "P*Q= " << Z << endl << endl;
			break;
		case 4:
			break;
		default:
			cout << "выбрана неверная операция" << endl << endl;
			break;
		}
	} while (whattodo!=4);
	return 0;
}