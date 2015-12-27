#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxStackSize 100000
template <class ValType>
class TStack
{
protected:
	ValType *data;
	int top_index;
	int stack_size;

public:
	TStack(int _size = MaxStackSize);
	TStack(const TStack & _stack);
	~TStack();
	bool IsFull();
	bool IsEmpty();
	void push(const ValType &_elem);
	ValType top();
	ValType pop();
	void stack_add_memory(const int &_byte);
	void stclear();
};

template <class ValType>
TStack<ValType>::TStack(int _size = MaxStackSize)
{
	stack_size = _size;
	top_index = -1;
	data = new ValType[stack_size];
}

template<class ValType>
TStack<ValType>::TStack(const TStack & _stack)
{
	stack_size = _stack.stack_size;
	data = new ValType[stack_size];
	top_index = _stack.top_index;
	for (int i = 0; i < top_index + 1; i++)
		data[i] = _stack.data[i];
}

template <class ValType>
TStack<ValType>::~TStack()
{
	delete[] data;
	data = NULL;
}
template<class ValType>
bool TStack<ValType>::IsFull()
{
	return top_index == stack_size - 1;
}

template<class ValType>
bool TStack<ValType>::IsEmpty()
{
	return top_index == -1;
}

template<class ValType>
void TStack<ValType>::push(const ValType & _elem)
{
	if (top_index == stack_size - 1)
		throw "Stack is Full";
	data[++top_index] = _elem;
}

template<class ValType>
inline ValType TStack<ValType>::top()
{
	if (top_index == -1)
		throw "Stack is Empty";
	return data[top_index];
}

template<class ValType>
ValType TStack<ValType>::pop()
{
	if (top_index == -1)
		throw "Stack is Emtpy";
	return data[top_index--];
}

template<class ValType>
void TStack<ValType>::stack_add_memory(const int & _byte)
{
	if (top_index == -1)
	{
		delete[] data;
		stack_size += _byte;
		data = new ValType[stack_size];
	}
	else
	{
		TStack <ValType> tmp(*this);
		delete[] data;
		stack_size += _byte;
		data = new ValType[stack_size];
		for (int i = 0; i < tmp.top_index + 1; i++)
			data[i] = tmp.data[i];
		top_index = tmp.top_index;
	}
}

template<class ValType>
void TStack<ValType>::stclear()
{
	top_index = -1;
}

