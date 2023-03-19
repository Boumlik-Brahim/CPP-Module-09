/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:40 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:24:51 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	std::cout << "\e[0;33mDefault Constructor called of RPN\e[0m" << std::endl;
}

RPN::RPN(const RPN &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of RPN\e[0m" << std::endl;
}

// Operators
RPN & RPN::operator=(const RPN &assign)
{
	(void) assign;
	return *this;
}

// Destructor
RPN::~RPN()
{
	std::cout << "\e[0;31mDestructor called of RPN\e[0m" << std::endl;
}