/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:34 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:20:04 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>

class BitcoinExchange
{
	private:

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