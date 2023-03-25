/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:34 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/25 17:06:31 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include <map>

class BitcoinExchange
{
	private:
		std::ifstream												data;
		std::ifstream												input;
		float														val;
		std::string													date;
		std::map<std::string, float, std::greater<std::string> >	myMap;

	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(std::string file_name);
		BitcoinExchange(const BitcoinExchange &copy);

		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);

		int			is_digit(std::string str);
		int			is_digit_point(std::string str);
		std::string	strtrim(std::string str);
		int			check_date();
		int			check_value(std::string value);
		void		read_data();
		void		read_input();

		// Destructor
		~BitcoinExchange();		
};

#endif