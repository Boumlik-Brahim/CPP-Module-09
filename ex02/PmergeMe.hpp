/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:32:08 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/24 21:57:24 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <iomanip>

class PmergeMe
{
	private:

	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &copy);

		// Operators
		PmergeMe & operator=(const PmergeMe &assign);

		void printVector(std::vector<int> &v, char c);
		int is_digit(std::string str);
		int checkSort(std::vector<int> &v);
		int checkdup(std::vector<int> &v);
		
		void mergeVector(std::vector<int> &v, int start, int half, int size);
		void mergesortVector(std::vector<int> &v, int start, int size);
		void insertionsortVector(std::vector<int> &v, size_t size);
		void sortVector(std::vector<int> &v, int start, int size);

		void mergeDeque(std::deque<int> &v, int start, int half, int size);
		void mergesortDeque(std::deque<int> &v, int start, int size);
		void insertionsortDeque(std::deque<int> &v, size_t size);
		void sortDeque(std::deque<int> &v, int start, int size);

		// Destructor
		~PmergeMe();		
};

#endif