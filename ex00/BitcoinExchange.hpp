/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:34 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/21 18:19:16 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <cstdlib>

class BitcoinExchange
{
	private:
		// float														val;
		// std::string													date;
		// std::map<std::string, float, std::greater<std::string> >	myMap;

	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		// Destructor
		~BitcoinExchange();		
};

#endif