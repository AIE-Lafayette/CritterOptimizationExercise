#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);
	T operator *();
	Iterator<T> operator ++ ();
	Iterator<T> operator -- ();
	const bool operator == (const Iterator<T>& iter);
	const bool operator != (const Iterator<T>& iter);

private:
	Node<T>* current;

};

template<typename T>
inline Iterator<T>::Iterator()
{
	current = nullptr;
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	current = node;
}

template<typename T>
inline T Iterator<T>::operator*()
{
	return current->data;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	return current = current->next;
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	return current = current->previous;
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	return current == iter.current;
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	return current != iter.current;
}
