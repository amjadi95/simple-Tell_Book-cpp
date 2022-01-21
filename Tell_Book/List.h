#pragma once
#include "Person.h"

template <typename T> class List
{
protected:
	T* list[50];
	int current;
	int size;

public:
	List();

	bool Insert(T);
	virtual T* Delete(int);
	virtual List<T>* Search(T);
	virtual T* Update(T, string);
	virtual void Display(void (*)(List<T>*));
	int Count();
	List<T>* getList();
	int Size();
	T* getItem(int);

};

template <typename T> List<T>::List<T>()
{
	for (int i = 0; i < size; i++)
	{
		list[i] = NULL;
	}
	current = 0;
	size = 50;
}

template <typename T> bool   List<T>::Insert(T p)
{
	try
	{
		if (current < size)
		{
			list[current++] = new T(p);
		}
	}
	catch (const exception& e)
	{
		return false;
	}
	return true;

}

template <typename T> void List<T>::Display(void (*func)(List<T>*))
{
	if (func != NULL)
		func(getList());

}

template <typename T> T* List<T>::Update(T p, string number)
{
	return NULL;

}

template <typename T>T* List<T>::Delete(int index) {

	T* deleted = NULL;
	if (index >= 0 && index < Count())
	{
		try {
			deleted = list[index];
			list[index] = NULL;
			for (int i = index;i < Count();i++)
			{
				if (list[i + 1] != NULL && i + 1 < Count())
				{
					T* x = list[i + 1];
					list[i] = x;
				}
				else {
					list[i] = NULL;
					current--;
					break;
				}
			}
		}
		catch (const exception& e)
		{
			return NULL;
		}
		
	}
	return deleted;
}
template <typename T>List<T>* List<T>::Search(T p)
{
	return NULL;
}

template <typename T>int List<T>::Count()
{
	if (current == 0)
		return 0;
	else
		return current;

}

template <typename T>List<T>* List<T>::getList()
{
	if (Count() > 0)
	{
		List<T>* l = new List<T>();
		for (int i = 0; i < Count();i++)
		{

			l->Insert(*list[i]);

		}
		return l;
	}
	else
		return NULL;

}

template <typename T>T* List<T>::getItem(int index)
{
	if (index < size)
	{
		if (list[index] != NULL)
		{
			T p = *list[index];
			return new T(p);
		}
	}
	return NULL;
}

template <typename T>int List<T>::Size()
{
	return size;
}