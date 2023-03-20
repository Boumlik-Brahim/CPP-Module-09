/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:47 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/20 18:02:47 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>
#include <ctime>

std::string strtrim(std::string str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	str.erase(0, first);
	size_t last = str.find_last_not_of(" \t\n\r");
	str.erase(last + 1);
	return (str);
}

int main(int argc, char const *argv[])
{
	float														val;
	int															count;
	size_t														pos;
	std::string													token_date;
	std::string													date;
	std::string													token_value;
	std::string													value;
	std::string													delimiter;
	std::map<std::string, float, std::greater<std::string> >	myMap;
	(void)argc;
	(void)argv;

	std::ifstream file("input.csv");
	if (!file.is_open())
	{
		std::cout << "Failed to open file." << std::endl;
		return (EXIT_FAILURE);
	}
	val = 0;
	pos = 0;
	count = 0;
	delimiter = "|";
	while (std::getline(file, token_value))
	{
		if ((pos = token_value.find(delimiter)) == std::string::npos)
			std::cout << "invalid line" << std::endl;
		while ((pos = token_value.find(delimiter)) != std::string::npos)
		{
			/*split line*/
			token_date = token_value.substr(0, pos);
			date = strtrim(token_date);
			token_value.erase(0, pos + delimiter.length());
			value = strtrim(token_value);

			/*check header*/
			if (count == 0 && date == "date" && value == "value")
				break;
			if (count == 0 && (date != "date" || value != "value"))
			{
				std::cout << "invalid header" << token_date << " " << token_value << std::endl;
				break ;
			}

			/*check date*/
			std::string tmp_year;
			std::string tmp_month;
			std::string tmp_day;
			if (date.at(4) != '-' || date.at(7) != '-' || date.size() < 10 || date.size() > 10)
				std::cout << "invalid date" << token_date << std::endl;
			tmp_year = date.substr(0, 4);
			tmp_month = date.substr(5, 2);
			tmp_day = date.substr(8, 2);
			try
			{
				/* code */
				int year = stoi(tmp_year);
				int month = stoi(tmp_month);
				int day = stoi(tmp_day);
				if (month < 1 || month > 12 || year < 2009 || year >= 2023)
				{
					std::cout << "invalid date" << std::endl;
				}
				if (month == 2)
				{
					if (day <= 0 || day > 28)
						std::cout << "invalid date" << std::endl;
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11)
				{
					if (day <= 0 || day > 30)
						std::cout << "invalid date" << std::endl;
				}
				else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if (day <= 0 || day > 31)
						std::cout << "invalid date" << std::endl;
				}
			}
			catch(const std::invalid_argument & e)
			{
				std::cerr << "invalid date" << std::endl;
			}

			/*check value*/
			if (!value.empty() && value.at(0) == '.')
				std::cout << "invalid value" << value << std::endl;
			std::cout << "value    " << value << std::endl;
			try
			{
				val = std::stof(value);
				std::cout << "val    " << val << std::endl;
				
				if (val < 0 || val > 1000)
					std::cout << "invalid value" << val << std::endl;
			}
			catch(const std::invalid_argument & e)
			{
				std::cerr << "invalid value" << std::endl;
			}

			/*insert into map*/
			// myMap.insert(std::make_pair(token_date, value));
		}
		count++;
	}

	// for (std::map<std::string, float>::iterator it = myMap.begin(); it != myMap.end(); it++)
	// {
	// 	std::cout << "key ==>     " << it->first << "       value ==>       " << it->second << std::endl;
	// }

	file.close();
	return 0;
}
