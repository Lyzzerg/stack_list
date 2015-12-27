#pragma once
#include "../include/THeadList.h"
#include <iostream>
using namespace std;
struct TMonom
{
	double coeff;
	double power;
};

class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom& operator= (TPolinom &_polinom);
	TPolinom operator+ (TPolinom &_polinom);
	TPolinom operator* (const double _val);
	TPolinom operator* (TPolinom &_polinom);
	TPolinom operator- (TPolinom &_polinom);
	void similar();
	friend ostream& operator<<(ostream &out, TPolinom &_polinom)
	{
		if (_polinom.listlen != 0)
		{
			int X, Y, Z;
			double coefficient;
			for (_polinom.Reset(); !_polinom.IsEnd(); _polinom.GoNext())
			{
				coefficient = _polinom.pCurrent->value.coeff;
				X = static_cast<int>(_polinom.pCurrent->value.power) / 100;
				Y = static_cast<int>(_polinom.pCurrent->value.power) % 100 / 10;
				Z = static_cast<int>(_polinom.pCurrent->value.power) % 10;
				if (X > 1)
				{
					if (Y > 1)
					{
						if (Z > 1)
						{
							cout << coefficient << "x^" << X << "y^" << Y << "z^" << Z << " ";  // x>1 y>1 z>1
						}
						else
						{
							if (Z == 0)
							{
								cout << coefficient << "x^" << X << "y^" << Y << " "; // x>1 y>1 z=0
							}
							else
							{
								cout << coefficient << "x^" << X << "y^" << Y << "z" << " "; // x>1 y>1 z=1
							}
						}
					}
					else
					{
						if (Y == 0)
						{
							if (Z > 1)
							{
								cout << coefficient << "x^" << X << "z^" << Z << " "; // x>1 y=0 z>1
							}
							else
							{
								if (Z == 0)
								{
									cout << coefficient << "x^" << X << " "; // x>1 y=0 z=0
								}
								else
								{
									cout << coefficient << "x^" << X << "z" << " "; // x>1 y=0 z=1
								}
							}
						}
						else
						{
							if (Z > 1)
							{
								cout << coefficient << "x^" << X << "y" << "z^" << Z << " "; // x>1 y=1 z>1
							}
							else
							{
								if (Z == 0)
								{
									cout << coefficient << "x^" << X << "y" << " "; // x>1 y=1 z=0
								}
								else
								{
									cout << coefficient << "x^" << X << "y" << "z" << " "; // x>1 y=1 z=1
								}
							}
						}
					}
				}
				else
					if (X == 0)
					{
						if (Y > 1)
						{
							if (Z > 1)
							{
								cout << coefficient << "y^" << Y << "z^" << Z << " ";  // x=0 y>1 z>1
							}
							else
							{
								if (Z == 0)
								{
									cout << coefficient << "y^" << Y << " "; // x=0 y>1 z=0
								}
								else
								{
									cout << coefficient << "y^" << Y << "z" << " "; // x=0 y>1 z=1
								}
							}
						}
						else
						{
							if (Y == 0)
							{
								if (Z > 1)
								{
									cout << coefficient << "z^" << Z << " "; // x=0 y=0 z>1
								}
								else
								{
									if (Z == 0)
										cout << coefficient;	// x=0 y=0 z=0
									else
										cout << coefficient << "z" << " "; // x=0 y=0 z=1
								}
							}
							else
							{
								if (Z > 1)
								{
									cout << coefficient << "y" << "z^" << Z << " "; // x=0 y=1 z>1
								}
								else
								{
									if (Z == 0)
									{
										cout << coefficient << "y" << " "; // x=0 y=1 z=0
									}
									else
									{
										cout << coefficient << "y" << "z" << " "; // x=0 y=1 z=1
									}
								}
							}
						}
					}
					else
					{
						if (Y > 1)
						{
							if (Z > 1)
							{
								cout << coefficient << "x" << "y^" << Y << "z^" << Z << " ";  // x=1 y>1 z>1
							}
							else
							{
								if (Z == 0)
								{
									cout << coefficient << "x" << "y^" << Y << " "; // x=1 y>1 z=0
								}
								else
								{
									cout << coefficient << "x" << "y^" << Y << "z" << " "; // x=1 y>1 z=1
								}
							}
						}
						else
						{
							if (Y == 0)
							{
								if (Z > 1)
								{
									cout << coefficient << "x" << "z^" << Z << " "; // x=1 y=0 z>1
								}
								else
								{
									if (Z == 0)
									{
										cout << coefficient << "x" << " "; // x=1 y=0 z=0
									}
									else
									{
										cout << coefficient << "x" << "z" << " "; // x=1 y=0 z=1
									}
								}
							}
							else
							{
								if (Z > 1)
								{
									cout << coefficient << "x" << "y" << "z^" << Z << " "; // x=1 y=1 z>1
								}
								else
								{
									if (Z == 0)
									{
										cout << coefficient << "x" << "y" << " "; // x=1 y=1 z=0
									}
									else
									{
										cout << coefficient << "x" << "y" << "z" << " "; // x=1 y=1 z=1
									}
								}
							}
						}
					}
			}
		}
		else
		{
			cout << 0;
		}
		return out;
	}
	TPolinom();
	TPolinom(TPolinom &_polinom);
	~TPolinom() {};
};

TPolinom & TPolinom::operator=(TPolinom & _polinom)
{
	while (listlen != 0)
		delFirst();
	if (_polinom.listlen != 0)
	{
		for (_polinom.Reset(); !_polinom.IsEnd(); _polinom.GoNext()) // добавить моном
		{
			insLast(_polinom.pCurrent->value);
		}
		similar();
	}
	return *this;
}

TPolinom TPolinom::operator+(TPolinom & _polinom)
{
	int i=1, j = 1;
	TPolinom tmp;
	tmp = *this;
	tmp.Reset();
	_polinom.Reset();
	while (!_polinom.IsEnd())
	{
		if(tmp.pCurrent->value.power > _polinom.pCurrent->value.power)
		{
			tmp.GoNext();
		}
		else
			if(tmp.pCurrent->value.power < _polinom.pCurrent->value.power)
			{
				tmp.insCurrent(_polinom.pCurrent->value);
				_polinom.GoNext();
			}
			else // if(tmp.pCurrent->value.power == _polinom.pCurrent->value.power)
			{
				tmp.pCurrent->value.coeff+=_polinom.pCurrent->value.coeff;
				if (tmp.pCurrent->value.coeff==0)
					tmp.delCurrent();
				_polinom.GoNext();
			}
	}
	tmp.similar();
	return tmp;
}

TPolinom TPolinom::operator*(const double _val)
{
	for (Reset(); !IsEnd(); GoNext())
		pCurrent->value.coeff *= _val;
	return *this;
}

TPolinom TPolinom::operator* (TPolinom &_polinom)
{
	TPolinom tmp; TMonom temp;
	for (Reset(); !IsEnd(); GoNext())
		for (_polinom.Reset(); !_polinom.IsEnd(); _polinom.GoNext())
		{
			temp.coeff = pCurrent->value.coeff*_polinom.pCurrent->value.coeff;
			temp.power = pCurrent->value.power + _polinom.pCurrent->value.power;
			tmp.insLast(temp);
		}
	tmp.similar();
	return tmp;
}

TPolinom TPolinom::operator-(TPolinom &_polinom)
{
	TPolinom tmp;
	return tmp=*this+_polinom*(-1);
}

void TPolinom::similar()
{
	if (listlen > 1)
	{
		TLink<TMonom> *tmp;
		Reset();
		while (pCurrent->NextLink != pStop)
		{
			tmp = pCurrent->NextLink;
			while (tmp != pStop)
				if (pCurrent->value.power == tmp->value.power)
				{
					tmp->value.coeff += pCurrent->value.coeff;
					delCurrent();
					tmp = tmp->NextLink;
				}
				else
					tmp = tmp->NextLink;
			if (tmp == pStop)
				break;
			else
				GoNext();
		}
	}
}

TPolinom::TPolinom()
{
	pHead->value.coeff = 0;
	pHead->value.power = -1;
}

TPolinom::TPolinom(TPolinom &_polinom)
{
	pHead->value.coeff = 0;
	pHead->value.power = -1;
	if (_polinom.listlen != 0)
	{
		for (_polinom.Reset(); !_polinom.IsEnd(); _polinom.GoNext())
			insLast(_polinom.pCurrent->value);
	}	
}