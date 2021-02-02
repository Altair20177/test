#pragma once
#include "Ring.cpp"

template <class T>
class Interface
{
	T obj;
public:
	static void menu();
	static void functions(Ring<T>& ring);
};