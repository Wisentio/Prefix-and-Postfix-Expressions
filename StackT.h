#pragma once
#include <iostream>
#include <string>

template <typename T>
struct Nod
{
	T data;
	Nod* next;
};

template <typename T>
class StackT
{
	Nod<T>* cap;

public:
	StackT()
	{
		cap = 0;
	}
	void push(T data);
	void pop();
	T top();
	bool isEmpty();
	friend std::ostream& operator<<(std::ostream& stream, T nod);
	~StackT();
};


template <typename T>
void StackT<T>::push(T dat)
{
	Nod<T>* p;
	p = new Nod<T>;
	p->data = dat;
	p->next = cap;
	cap = p;
}

template <typename T>
void StackT<T>::pop()
{
	if (!isEmpty())
	{
		cap = cap->next;
	}
}

template <typename T>
T StackT<T>::top()
{
	if (!isEmpty())
	{
		return cap->data;
	}
	else
	{
		std::cout << "Stiva e vida";
		return NULL;
	}
}

template <typename T>
bool StackT<T>::isEmpty()
{
	if (cap == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
StackT<T>::~StackT()
{
	while (cap != 0)
	{
		Nod<T>* aux = cap;
		cap = cap->next;
		delete aux;
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, Nod<T> nod)
{
	stream << nod->data;
	return stream;
}

