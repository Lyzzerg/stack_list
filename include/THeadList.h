#pragma once
#include "../include/TLink.h"
template <class ListType>
class THeadList
{
//protected:
public:
	TLink<ListType> *pHead, *pFirst, *pStop, *pCurrent, *pPrevious;	
	int listlen;																							 // длина списка
	int currentpos;																							// номер текущей позиции
public:
	void insFirst(const ListType _value);																  // вставить в начало (Current не меняется)
	void insCurrent(const ListType _value);																 // вставить текущий
	void insLast (const ListType _value);																// вставить последний
	bool IsFull (){return (TLink<ListType>*tmp=new TLink<ListType>)==NULL;}							   // полна ли очередь?
	bool IsEnd () {return pCurrent==pStop;}															  // конец очереди? pCurrent=pStop pPrevious=последнему элементу
	void Reset() { pPrevious = NULL; pCurrent = pFirst; currentpos = 1; }							 // установить текущий на начало
	void GoNext()
	{
		if (pCurrent != pStop)
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->NextLink;
			currentpos++;
		}
		else
			throw "конец списка";
	}		    // перейти на следующий элемент списка
	void delFirst();																			   // удалить первый
	void delCurrent();																			  // удалить текущий
	void setCurrent(int _curr);																	 // установить _curr'ый элемент текущим
	int getCurrentPos() {return currentpos;}													// получить номер текущего элемента
	ListType GetCurrentValue() { return pCurrent->value; }
	THeadList()
	{
		pHead = new TLink<ListType>;
		pFirst = pCurrent = pPrevious = NULL;
		pStop = pHead;
		pHead->NextLink = pStop;
		listlen = 0;
		currentpos = 0;
	};
	~THeadList()
	{
		while (listlen!=0)
		{
			delFirst();
		}
		delete pHead;
	};
};

template<class ListType>
void THeadList<ListType>::insFirst(const ListType _value)
{
	TLink<ListType> *tmp = new TLink<ListType>;
	tmp->value = _value;
	tmp->NextLink = pHead->NextLink;
	pHead->NextLink = tmp;
	pFirst = tmp;
	listlen++;
	if (currentpos != 0)
	{
		currentpos++;
	}
}

template<class ListType>
void THeadList<ListType>::insCurrent(const ListType _value)
{
	if (pCurrent==pFirst)
	{
		insFirst(_value);
		pPrevious = pFirst;
	}
	else
	{
		TLink<ListType> *tmp = new TLink<ListType>;
		tmp->value = _value;
		pPrevious->NextLink = tmp;
		tmp->NextLink = pCurrent;
		pPrevious = tmp;
		listlen++;
		currentpos++;
	}
}

template<class ListType>
void THeadList<ListType>::insLast(const ListType _value)
{
	if (listlen == 0)
	{
		insFirst(_value);
	}
	else
	{
		TLink<ListType> *tmp = new TLink<ListType>;
		tmp->value = _value;
		for (Reset(); pCurrent->NextLink!=pStop; GoNext());
		pCurrent->NextLink = tmp;
		tmp->NextLink = pStop;
		listlen++;
	}
}

template<class ListType>
void THeadList<ListType>::delFirst()
{
	TLink<ListType> *tmp;
	if (listlen != 0)
	{
		if (pCurrent == pFirst)
			if (pCurrent->NextLink != pStop)
				pCurrent = pCurrent->NextLink;
			else
				pCurrent = NULL;
		else
			if (pCurrent == pFirst->NextLink)
			{
				pPrevious = NULL;
				currentpos--;
			}
		tmp = pFirst;
		pHead->NextLink = pFirst->NextLink;
		if (pFirst->NextLink != pStop)
			pFirst = pFirst->NextLink;
		else
			pFirst = NULL;
		delete tmp;
		listlen--;
	}
}

template<class ListType>
void THeadList<ListType>::delCurrent()
{
	if (listlen != 0)
		if (pCurrent == pFirst)
		{
			delFirst();
		}
		else
		{
			TLink<ListType> *tmp;
			tmp = pCurrent;
			if (pCurrent->NextLink != pStop)
			{
				pCurrent = pCurrent->NextLink;
				pPrevious->NextLink = pCurrent;
			}
			else
				if (pCurrent == pFirst->NextLink)
				{
					pPrevious = NULL;
					pCurrent = pFirst;
					pFirst->NextLink = pStop;
					currentpos--;
				}
				else
				{
					for (Reset(); pCurrent->NextLink->NextLink != pStop; GoNext());
					currentpos--;
				}
			delete tmp;
			listlen--;
		}
}

template<class ListType>
void THeadList<ListType>::setCurrent(int _curr)
{
	if (_curr > 0 && _curr <= listlen)
		for (Reset(); currentpos < _curr; GoNext());
	else
		throw _curr;
}
