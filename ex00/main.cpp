/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:47 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:19:33 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
#include <ctime>

void checkDate()
{
}
void checkValue()
{
}
int main(int argc, char const *argv[])
{
	float															value;
	size_t															pos;
	std::string														token;
	std::string														delimiter;
	std::string														exchange_rate;
	std::map<std::string, float, std::greater<std::string> >	myMap;
	(void)argc;
	(void)argv;

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cout << "Failed to open file." << std::endl;
		return (EXIT_FAILURE);
	}
	pos = 0;
	delimiter = ",";
	while (std::getline(file, exchange_rate))
	{
		while ((pos = exchange_rate.find(delimiter)) != std::string::npos)
		{
			token = exchange_rate.substr(0, pos);
			if (token == "date")
				break;
			std::tm date = {};
			std::istringstream ss(token);
			ss >> std::get_time(&date, "%Y-%m-%d-%h");
			int year = date.tm_year + 1900;
			int month = date.tm_mon + 1;
			int day = date.tm_mday;
			if (ss.fail() || month < 1 || month > 12 || year < 2009 || year >= 2023)
			{
				std::cout << "invalid date" << token << std::endl;
			}
			if (month == 2)
			{
				if (day > 28)
					std::cout << "invalid date" << token << std::endl;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11)
			{
				if (day > 30)
					std::cout << "invalid date" << token << std::endl;
			}
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day > 31)
					std::cout << "invalid date" << token << std::endl;
			}
			exchange_rate.erase(0, pos + delimiter.length());
			try
			{
				value = std::stof(exchange_rate);
				if (value < 0)
					std::cout << "invalid value" << value << std::endl;
			}
			catch(const std::invalid_argument & e)
			{
				std::cerr << "invalid value" << std::endl;
			}
			
			myMap.insert(std::make_pair(token, value));
		}
	}

	// for (std::map<std::string, float>::iterator it = myMap.begin(); it != myMap.end(); it++)
	// {
	// 	std::cout << "key ==>     " << it->first << "       value ==>       " << it->second << std::endl;
	// }

	file.close();
	return 0;
}
