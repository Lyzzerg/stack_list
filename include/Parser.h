#pragma once
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include "../include/TStack.h"
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#define MaxLen 201
#define NumLen 100
using namespace std;
class TParser
{
public:
	char infix[MaxLen];
	char postfix[MaxLen];
	TStack<double> st_d;
	TStack<char> st_c;
	int NumbersLen[NumLen];
public:
	TParser(char *_str);
	~TParser();
	int Priority(char _ch);
	bool IsOperation(char _ch);
	bool IsNumber(char _ch);
	bool IsFuction(char _ch);
	void infixtopostfix();
	double calcPost();
	void Function(char* _ch, int _k, double &_rez);
};

TParser::TParser(char *_str) :st_d(100), st_c(100)
{
	if (_str == NULL)
		infix[0] = '\0';
	else
		strcpy_s(infix, _str);
}
TParser :: ~TParser() {}

int TParser::Priority(char _ch)
{
	int n;
	switch (_ch)
	{
	case '(':
	case ')': n = 0; break;
	case '+':
	case '-': n = 1; break;
	case '*':
	case '/': n = 2; break;
	case '^': n = 3; break;
	default:
		n = -1; break;
	}
	return n;
}

bool TParser::IsOperation(char _ch)
{

	return (_ch == '+' || _ch == '-' || _ch == '*' || _ch == '/' || _ch == '(' || _ch == ')' || _ch == '^');
}

bool TParser::IsNumber(char _ch)
{
	return (_ch == '.' || _ch == ',' || _ch == '0' || _ch == '1' || _ch == '2' || _ch == '3' || _ch == '4' || _ch == '5' || _ch == '6' || _ch == '7' || _ch == '8' || _ch == '9' || _ch=='e'|| _ch=='p');
}

bool TParser::IsFuction(char _ch)
{
	return (_ch=='s' || _ch == 'l' || _ch == 'c' || _ch == 't' || _ch == 'a');
}

void TParser::Function(char* _ch, int _k, double &_rez)
{
	switch (_ch[_k])
	{
	case 's': 
		if (_ch[_k + 3] == 'h')
		{
			_rez = sinh(_rez);
		}
		else
		{
			_rez = sin(_rez);
		}
		break;
	case 'l':
		if (_ch[_k + 3] == '1')
		{
			_rez = log10(_rez);
		}
		else
		{
			_rez = log(_rez);
		}
		break;
	case 'c': 
		if (_ch[_k + 3] == 'h')
		{
			_rez = cosh(_rez);
		}
		else
		{
			_rez = cos(_rez);
		}
		break;
	/*case 'a':
		if (_ch[_k + 1] == 'c')
		{
			if (_ch[_k + 4] == 'h')
			{
				_rez = acosh(_rez);
			}
			else
			{
				_rez = acos(_rez);
			}
		}
		if (_ch[_k + 1] == 's')
		{
			if (_ch[_k + 4] == 'h')
			{
				_rez = asinh(_rez);
			}
			else
			{
				_rez = asin(_rez);
			}
		}
		if (_ch[_k + 1] == 't')
		{
			if (_ch[_k + 4] == 'h')
			{
				_rez = atanh(_rez);
			}
			else
			{
				_rez = atan(_rez);
			}
		}
		break;*/
	case 't':
		if (_ch[_k + 3] == 'h')
		{
			_rez = tanh(_rez);
		}
		else
		{
			_rez = tan(_rez);
		}
		break;
	}
}

void TParser::infixtopostfix()
{
	st_c.stclear(); st_d.stclear(); // очистка стеков

	int i = 0, j = 0, k = 0;
	//	сначала необходимо проверить первый знак на . либо -
	//	затем считываем пока не '\0'
	while (infix[i] != '\0')
	{
		//if (IsFunction(infix[i]))
		if (IsOperation(infix[i])) //если встречена операция
		{
			if (infix[i] == '(')
			{
				if ( i == 0 || IsOperation(infix [i-1]) )
				{
					st_c.push(infix[i]);
					i++;
				}
				else
				{
					st_c.push('*');
					st_c.push(infix[i]);
					i++;
				}
			}
			else
			{
				if (infix[i] == ')')
				{
					while (st_c.top() != '(')
					{
						postfix[j] = st_c.pop();
						j++;
					}
					int tmp=st_c.pop();
					i++;
				}
				else
				{
					if (infix[i] == '-' && (i == 0 || infix[i - 1] == '(')) //особый случай с минусом
					{
					
							postfix[j++] = '0'; //записываем ноль в постфиксную строку (для получения выражения 0-x= при встреченном -x=)
							NumbersLen[k] = 1;
							k++;
							i++;
							while (IsNumber(infix[i]))
							{
								NumbersLen[k] += 1;
								postfix[j++] = infix[i++];
							}
							k++;
							postfix[j++] = '-';
					}
					else
					{
						if (st_c.IsEmpty() || Priority(infix[i]) > Priority(st_c.top())) //если стек пуст или если приоритет текущей операции больше чем приоритет предыдущей
						{
							st_c.push(infix[i]); //кладём операцию в стек
							i++;
						}
						else  //если приоритет текущей операции меньше чем приоритет предыдущей
							if (Priority(infix[i]) < Priority(st_c.top()))
							{
								while (!st_c.IsEmpty() && Priority(infix[i]) <= Priority(st_c.top())) // пока не встречена операция с наименьшим приоритетом
								{
									postfix[j] = st_c.pop(); // выталкиваем все операции
									j++;
								}
								st_c.push(infix[i]);// оставляем знак на верхушке стека
								i++;
							}
							else
							{
								st_c.push(infix[i]);
								i++;
							}
					}
				}
			}
		}
		else
		{
			if (IsNumber(infix[i]))
			{
				while (IsNumber(infix[i]))
				{
					NumbersLen[k] += 1;
					postfix[j] = infix[i];
					j++;
					i++;
				}
				k++;
			}
		}
		if (IsFuction(infix[i]))
		{
			int m=0, n=i, l=0;
			char *len=new char [195];
			while (infix[i] != '(')
				i++;
			i++;
			while (infix[i] != '\0')
			{
				len[m] = infix[i];
				m++;
				i++;
			}
			i++;
			len[m] = '\0';
			TParser tmp(len);
			tmp.infixtopostfix();
			double reztmp = tmp.calcPost();
			Function(infix, n, reztmp);
			char len2[30];
			sprintf(len2, "%f", reztmp);
			if (len2[0] == '-')
				{
					postfix[j] = '0';
					j++;
					NumbersLen[k] += 1;
					k++;
					l++;
					while (len2[l]!='\0')
					{
						NumbersLen[k] += 1;
						postfix[j] = len2[l];
						j++;
						l++;
					}
					k++;
					postfix[j] = '-';
					j++;
				}
				else
				{
					NumbersLen[k] += 1;
					postfix[j] = len2[l];
					j++;
					l++;
				}
		k++;
	}
}
	//выталкиваем оставшиеся операции из стека
	while (!st_c.IsEmpty()) // пока стек не пуст
	{
		postfix[j] = st_c.pop(); // выталкиваем все операции до тех пор пока стек не опустеет
		j++;
	}

}

double TParser::calcPost()
{
	int i = 0, k=0;
	st_c.stclear(); st_d.stclear(); //очистка стеков
	while (postfix[i] != '\0')
	{
		
		if (IsNumber(postfix[i]))
		{
			if (postfix[i] == 'e')
			{
				st_d.push(M_E);
				i++;
			}
			else
				if (postfix[i] == 'p')
				{
					st_d.push(M_PI);
					i++;
				}
				else
				{
					double tmp;
					char *len = new char[NumbersLen[k]];
					for (int j = 0; j < NumbersLen[k]; j++)
						len[j] = postfix[i + j];
					tmp = atof(len);
					st_d.push(tmp);
					i += NumbersLen[k];
					k++;
					delete[]len;
				}
		}
		else
		{
			double reg1, reg2;
			reg1 = st_d.pop();
			reg2 = st_d.pop();
			switch (postfix[i])
			{	
			case '+': st_d.push(reg1 + reg2); break;
			case '-': st_d.push(reg2 - reg1); break;
			case '*': st_d.push(reg1 * reg2); break;
			case '/': st_d.push(reg2 / reg1); break;
			case '^': st_d.push(exp(reg1*log(reg2))); break;
			}
			i++;
		}
	}
	return st_d.pop();
}


