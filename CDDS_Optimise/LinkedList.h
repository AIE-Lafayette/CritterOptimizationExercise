#pragma once
#include "Iterator.h"
#include <iostream>

template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T>& other);
	~LinkedList();

	void initialize();
	void destroy();

	Iterator<T> begin() const;
	Iterator<T> end() const;

	bool contains(const T object) const;
	bool isEmpty() const;

	void pushFront(const T& value);
	void pushBack(const T& value);

	T popFront();
	T popBack();

	bool insert(const T& value, int index);
	bool remove(const T& value);

	bool getData(Iterator<T>& iter, int index);
	int getLength() const;
	void operator =(const LinkedList<T>& otherList); 
private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount;
};

template<typename T>
inline LinkedList<T>::LinkedList()
{
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
}

template<typename T>
inline void LinkedList<T>::initialize()
{
}

template<typename T>
inline void LinkedList<T>::destroy()
{
}

template<typename T>
inline Iterator<T> LinkedList<T>::begin() const
{
}

template<typename T>
inline Iterator<T> LinkedList<T>::end() const
{
}

template<typename T>
inline bool LinkedList<T>::contains(const T object) const
{
}

template<typename T>
inline bool LinkedList<T>::isEmpty() const
{
}

template<typename T>
inline void LinkedList<T>::pushFront(const T& value)
{
}

template<typename T>
inline void LinkedList<T>::pushBack(const T& value)
{
}

template<typename T>
inline T LinkedList<T>::popFront()
{
}

template<typename T>
inline T LinkedList<T>::popBack()
{
}

template<typename T>
inline bool LinkedList<T>::insert(const T& value, int index)
{
}

template<typename T>
inline bool LinkedList<T>::remove(const T& value)
{
}

template<typename T>
inline bool LinkedList<T>::getData(Iterator<T>& iter, int index)
{
}

template<typename T>
inline int LinkedList<T>::getLength() const
{
}

template<typename T>
inline void LinkedList<T>::operator =(const LinkedList<T>& other)
{
}