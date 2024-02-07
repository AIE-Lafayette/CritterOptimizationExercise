#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
public:
	Iterator();
	Iterator(Node<T>* node);
	T& operator *();
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
}

template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
}

template<typename T>
inline T& Iterator<T>::operator*()
{
}

template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
}

template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
}

template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
}

template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
}
