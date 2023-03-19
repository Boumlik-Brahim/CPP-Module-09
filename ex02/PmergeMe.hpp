/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:32:08 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:32:31 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>

class PmergeMe
{
	private:

	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &copy);

		// Operators
		PmergeMe & operator=(const PmergeMe &assign);

		// Destructor
		~PmergeMe();		
};

#endif