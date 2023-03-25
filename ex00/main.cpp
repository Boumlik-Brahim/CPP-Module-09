/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:47 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/25 15:33:52 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	/*open files*/
	BitcoinExchange exchange(argv[1]);
	/*read data*/
	exchange.read_data();
	/*read input*/
	exchange.read_input();
	return (0);
}