/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:46:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/10/11 13:46:16 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout <<"lalala\n";
	myArr = new T();
	n = 0;
}

template <typename T>
Array<T>::Array(unsigned int &n)
{
	this->n = n;
	myArr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		myArr[i] = 0;//check type T if its something else
}

template <typename T>
Array<T>::Array(const Array &arr)
{
	*this = arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &arr)
{
	unsigned int len;
	
	if (myArr)
		delete []myArr;
	len = arr.size();
	myArr = new T[len];
	for (unsigned int i = 0; i < len; i++)
		myArr[i] = arr.myArr[i];
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete []myArr;
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (n);
}

template <typename T>
T &Array<T>::operator[](unsigned long n)
{
	if (n < 0 || n >= size())
		throw (std::out_of_range("index out of range"));
	return (myArr[n]);
}