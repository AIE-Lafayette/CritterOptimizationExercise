#pragma once

template<typename T>
struct Node
{
	Node<T>() {}
	Node<T>(T newData) { data = newData; }
	T data;
	Node* previous = nullptr;
	Node* next = nullptr;
};