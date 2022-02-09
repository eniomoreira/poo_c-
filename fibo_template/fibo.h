#ifndef FIBO_H
#define FIBO_H
// FIBO.h (header file)
#include <iostream>
class error
{
	const char *message;
public:
	error() :message("-- Posicao invalida -- ") {}
	const char *what() const { return message; }
};
#endif

template <class T>
T fibonacci(const T& nesimo)
{
	if (nesimo <= 0)
		throw error();
	if (nesimo == 1 || nesimo==2)
		return 1;
	//else
	return fibonacci(nesimo - 1) + fibonacci(nesimo - 2);
};