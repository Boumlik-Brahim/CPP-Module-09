/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:14 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:22:19 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{
	std::cout << "\e[0;33mDefault Constructor called of BitcoinExchange\e[0m" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of BitcoinExchange\e[0m" << std::endl;
	(void) copy;
}

// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;
	return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;
}