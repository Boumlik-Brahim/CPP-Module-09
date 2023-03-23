/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:45:01 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/23 17:52:41 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <vector>

void insertionsort(std::vector<int> &v, size_t size)
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

int main(int argc, char const *argv[])
{
	std::vector<int> v1;

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

	insertionsort(v1, v1.size());

	std::cout << "After: ";
	for (size_t i = 0; i < v1.size(); i++)
	{
		std::cout << v1[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
