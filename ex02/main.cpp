/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:45:01 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/24 15:46:41 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>

/*------------------------------Deque-----------------------------------*/

void mergeDeque(std::deque<int> &v, int start, int half, int size)
{
	int n1 = half - start + 1;
	int n2 = size - half;

	std::deque<int> L(n1);
	std::deque<int> M(n2);
	
	for (int i = 0; i < n1; i++)
	{
		L.at(i) = v.at(start + i);
	}
	for (int j = 0; j < n2; j++)
	{
		M.at(j) = v.at(half + 1 + j);
	}

	int i, j, k;
	i = 0;
	j = 0;
	k = start;

	while (i < n1 && j < n2)
	{
		if (L.at(i) <= M.at(j))
		{
			v.at(k) = L.at(i);
			i++;
		}
		else
		{
			v.at(k) = M.at(j);
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		v.at(k) = L.at(i);
		i++;
		k++;
	}

	while (j < n2)
	{
		v.at(k) = M.at(j);
		j++;
		k++;
	}
}

void mergesortDeque(std::deque<int> &v, int start, int size)
{
	if (start < size)
	{
		int half = start + (size - start) / 2;

		mergesortDeque(v, start, half);
		mergesortDeque(v, half + 1, size);

		mergeDeque(v, start, half, size);
	}
}

void insertionsortDeque(std::deque<int> &v, size_t size)
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

void sortDeque(std::deque<int> &v, int start, int size)
{
	if (size - start > 10)
	{
		int half = (start + size) / 2;
		sortDeque(v, start, half);
		sortDeque(v, half + 1, size);	
		mergesortDeque(v, start, size - 1);
	}
	else
		insertionsortDeque(v, size);
}

/*------------------------------Deque-----------------------------------*/

/*------------------------------Vector----------------------------------*/
 
void mergeVector(std::vector<int> &v, int start, int half, int size)
{
	int n1 = half - start + 1;
	int n2 = size - half; 

	std::vector<int> L(n1);
	std::vector<int> M(n2);
	
	for (int i = 0; i < n1; i++)
	{
		L.at(i) = v.at(start + i);
	}
	for (int j = 0; j < n2; j++)
	{
		M.at(j) = v.at(half + 1 + j);
	}

	int i, j, k;
	i = 0;
	j = 0;
	k = start;

	while (i < n1 && j < n2)
	{
		if (L.at(i) <= M.at(j))
		{
			v.at(k) = L.at(i);
			i++;
		}
		else
		{
			v.at(k) = M.at(j);
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		v.at(k) = L.at(i);
		i++;
		k++;
	}

	while (j < n2)
	{
		v.at(k) = M.at(j);
		j++;
		k++;
	}
}

void mergesortVector(std::vector<int> &v, int start, int size)
{
	if (start < size)
	{
		int half = start + (size - start) / 2;

		mergesortVector(v, start, half);
		mergesortVector(v, half + 1, size);

		mergeVector(v, start, half, size);
	}
}


void insertionsortVector(std::vector<int> &v, size_t size)
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

void sortVector(std::vector<int> &v, int start, int size)
{
	if (size - start > 10)
	{
		int half = (start + size) / 2;
		sortVector(v, start, half);
		sortVector(v, half + 1, size);	
		mergesortVector(v, start, size - 1);
	}
	else
		insertionsortVector(v, size);
}

/*------------------------------Vector----------------------------------*/

int main(int argc, char const *argv[])
{
	std::vector<int> v1;

	clock_t start_vector = clock();
	for (int i = 1; i < argc; i++)
	{
		v1.push_back(atoi(argv[i]));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	sortVector(v1, 0, v1.size());
	clock_t end_vector = clock();

	double elapsed_time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After: ";
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << v1.size() << " elements with std::vector<int> v1 : " << std::fixed << std::setprecision(5) << elapsed_time_vector << " us"<< std::endl;


	// std::deque<int> v2;
	// clock_t start_deque = clock();
	// for (int i = 1; i < argc; i++)
	// {
	// 	v2.push_back(atoi(argv[i]));
	// }

	// std::cout << "Before: ";
	// for (size_t i = 0; i < v2.size(); i++)
	// {
	// 	std::cout << v2[i] << " ";
	// }
	// std::cout << std::endl;

	// sortDeque(v2, 0, v2.size());
	// clock_t end_deque = clock();

	// double elapsed_time_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;

	// std::cout << std::endl;
	// std::cout << "After: ";
	// for (size_t i = 0; i < v2.size(); i++)
	// {
	// 	std::cout << v2[i] << " ";
	// }
	// std::cout << std::endl;

	// std::cout << "Time to process a range of " << v2.size() << " elements with std::deque<int> v2 : " << std::fixed << std::setprecision(5) << elapsed_time_deque << " us"<< std::endl;

	return (0);
}
