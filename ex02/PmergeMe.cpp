/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:32:01 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/26 15:19:14 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	(void) copy;
}

// Operators
PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	(void) assign;
	return *this;
}

/*------------------------------Utils-----------------------------------*/

void PmergeMe::printVector(std::vector<int> &v, char c)
{
	if(c == 'b')
		std::cout << "Before:	";
	else if (c == 'a')
		std::cout << "After:	";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::is_digit(std::string str)
{
	for( size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int PmergeMe::checkSort(std::vector<int> &v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v.at(i) < v.at(j))
				break ;
			else 
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int PmergeMe::checkdup(std::vector<int> &v)
{
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		for (size_t j = i + 1; j < v.size(); j++)
		{
			if (v.at(i) == v.at(j))
				return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}

/*------------------------------Utils-----------------------------------*/

/*------------------------------Vector----------------------------------*/

void PmergeMe::mergeSortVector(std::vector<int> &v, int start, int half, int size)
{
	int i, j, k;
	int n1 = half - start + 1;
	int n2 = size - half;
	std::vector<int> tmpvec1(n1);
	std::vector<int> tmpvec2(n2);

	for (int i = 0; i < n1; i++)
		tmpvec1.at(i) = v.at(start + i);
	for (int j = 0; j < n2; j++)
		tmpvec2.at(j) = v.at(half + 1 + j);
	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2)
	{
		if (tmpvec1.at(i) <= tmpvec2.at(j))
		{
			v.at(k) = tmpvec1.at(i);
			i++;
		}
		else
		{
			v.at(k) = tmpvec2.at(j);
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		v.at(k) = tmpvec1.at(i);
		i++;
		k++;
	}

	while (j < n2)
	{
		v.at(k) = tmpvec2.at(j);
		j++;
		k++;
	}
}

void PmergeMe::insertionSortVector(std::vector<int> &v, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		int key = v.at(i);
		int j = i - 1;
		while (j >= 0 && v.at(j) > key)
		{
			v.at(j + 1) = v.at(j);
			j--;
		}
		v.at(j + 1) = key;
	}
}

void PmergeMe::sortVector(std::vector<int> &v, int start, int size)
{
	if (size - start > 10)
	{
		int half = (start + size) / 2;
		sortVector(v, start, half);
		sortVector(v, half + 1, size);
		mergeSortVector(v, start, half, size - 1);
	}
	else
		insertionSortVector(v, size);
}

/*------------------------------Vector----------------------------------*/

/*------------------------------Deque-----------------------------------*/

void PmergeMe::mergeSortDeque(std::deque<int> &v, int start, int half, int size)
{
	int i, j, k;
	int n1 = half - start + 1;
	int n2 = size - half;
	std::deque<int> tmpdeque1(n1);
	std::deque<int> tmpdeque2(n2);

	for (int i = 0; i < n1; i++)
		tmpdeque1.at(i) = v.at(start + i);
	for (int j = 0; j < n2; j++)
		tmpdeque2.at(j) = v.at(half + 1 + j);

	i = 0;
	j = 0;
	k = start;
	while (i < n1 && j < n2)
	{
		if (tmpdeque1.at(i) <= tmpdeque2.at(j))
		{
			v.at(k) = tmpdeque1.at(i);
			i++;
		}
		else
		{
			v.at(k) = tmpdeque2.at(j);
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		v.at(k) = tmpdeque1.at(i);
		i++;
		k++;
	}
	while (j < n2)
	{
		v.at(k) = tmpdeque2.at(j);
		j++;
		k++;
	}
}

void PmergeMe::insertionSortDeque(std::deque<int> &v, size_t size)
{
	for (size_t i = 1; i < size; i++)
	{
		int key = v.at(i);
		int j = i - 1;
		while (j >= 0 && v.at(j) > key)
		{
			v.at(j + 1) = v.at(j);
			j--;
		}
		v.at(j + 1) = key;
	}
}

void PmergeMe::sortDeque(std::deque<int> &v, int start, int size)
{
	if (size - start > 10)
	{
		int half = (start + size) / 2;
		sortDeque(v, start, half);
		sortDeque(v, half + 1, size);
		mergeSortDeque(v, start, half, size - 1);
	}
	else
		insertionSortDeque(v, size);
}

/*------------------------------Deque-----------------------------------*/

// Destructor
PmergeMe::~PmergeMe()
{}