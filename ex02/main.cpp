/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:45:01 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/26 14:42:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char const *argv[])
{
	std::vector<int>	v1;
	std::deque<int>		v2;
	PmergeMe			obj;
	int					val;

	clock_t start_vector = clock();
	for (int i = 1; i < argc; i++)
	{
		val = atoi(argv[i]);
		if (!obj.is_digit(argv[i]) || val < 0)
		{
			std::cout << "Error" << std::endl;
			return (EXIT_FAILURE);
		}
		v1.push_back(val);
	}
	if (!obj.checkSort(v1) || !obj.checkdup(v1))
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	obj.printVector(v1, 'b');
	obj.sortVector(v1, 0, v1.size());
	clock_t end_vector = clock();
	double elapsed_time_vector = double(end_vector - start_vector) / CLOCKS_PER_SEC * 1000000;
	obj.printVector(v1, 'a');

	clock_t start_deque = clock();
	for (int i = 1; i < argc; i++)
		v2.push_back(atoi(argv[i]));
	obj.sortDeque(v2, 0, v2.size());
	clock_t end_deque = clock();
	double elapsed_time_deque = double(end_deque - start_deque) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of	" << v1.size() << " elements with std::vector<int> v1 : " << elapsed_time_vector << " us"<< std::endl;
	std::cout << "Time to process a range of	" << v2.size() << " elements with std::deque<int> v2 : " << elapsed_time_deque << " us"<< std::endl;

	return (0);
}
