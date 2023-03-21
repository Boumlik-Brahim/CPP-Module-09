/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:47 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/21 18:21:53 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int is_digit(std::string str)
{
	for( size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int is_digit_point(std::string str)
{
	for( size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

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
	std::map<std::string, float, std::greater<std::string> >	myMap;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	
	/*open data*/
	std::ifstream data("data.csv");
	if (!data.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	/*read data*/
	pos = 0;
	while (std::getline(data, token_value))
	{
		while ((pos = token_value.find(",")) != std::string::npos)
		{
			/*split line*/
			token_date = token_value.substr(0, pos);
			token_value.erase(0, pos + 1);

			/*check header*/
			if (date == "date")
				break;

			/*insert into map*/
			val = std::atof(token_value.c_str());
			myMap.insert(std::make_pair(token_date, val));
		}
	}

	/*open input*/
	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (EXIT_FAILURE);
	}
	/*read input*/
	val = 0;
	pos = 0;
	count = 0;
	while (std::getline(input, token_value))
	{
		if ((pos = token_value.find("|")) == std::string::npos)
			std::cout << "Error: bad input => " << token_value << std::endl;
		while ((pos = token_value.find("|")) != std::string::npos)
		{
			/*split line*/
			token_date = token_value.substr(0, pos);
			date = strtrim(token_date);
			token_value.erase(0, pos + 1);
			value = strtrim(token_value);

			/*check header*/
			if (count == 0 && date == "date" && value == "value")
				break ;
			if (count == 0 && (date != "date" || value != "value"))
			{
				std::cout << "Error: invalid header" << std::endl;
				break ;
			}

			/*check date*/
			std::string tmp_year;
			std::string tmp_month;
			std::string tmp_day;
			if (date.size() == 10)
			{
				if (date.at(4) != '-' || date.at(7) != '-')
				{
					std::cout << "Error: bad input => " << token_date << std::endl;
					break ; 
				}
				tmp_year = date.substr(0, 4);
				tmp_month = date.substr(5, 2);
				tmp_day = date.substr(8, 2);
				if (!is_digit(tmp_year) || !is_digit(tmp_month) || !is_digit(tmp_day))
				{
					std::cout << "Error: bad input => " << token_date << std::endl;
					break ;
				}
				int year = std::atoi(tmp_year.c_str());
				int month = std::atoi(tmp_month.c_str());
				int day = std::atoi(tmp_day.c_str());
				if (month < 1 || month > 12 || year < 2009 || year >= 2023)
				{
					std::cout << "dkhel lhna" << std::endl;
					std::cout << "Error: bad input => " << token_date << std::endl;
					break ;
				}
				if (month == 2)
				{
					if (day <= 0 || day > 28)
					{
						std::cout << "Error: bazd input => " << token_date << std::endl;
						break ;
					}
				}
				else if (month == 4 || month == 6 || month == 9 || month == 11)
				{
					if (day <= 0 || day > 30)
					{
						std::cout << "Error: bad input => " << token_date << std::endl;
						break ;
					}
				}
				else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					if (day <= 0 || day > 31)
					{
						std::cout << "Error: bad input => " << token_date << std::endl;
						break ;
					}
				}				
			}
			else
			{
				std::cout << "Error: bad input => " << token_date << std::endl;
				break ;
			}

			/*check value*/
			if (value.empty() || value.at(0) == '.' || value.at(value.size() - 1) == '.')
			{
				std::cout << "Error: bad input => " << value << std::endl;
				break ;
			}
			if (!is_digit_point(value))
			{
				std::cout << "Error: bad input => " << value << std::endl;
				break ;
			}
			val = std::atof(value.c_str());
			if (val < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				break ;
			}
			if (val > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				break ;
			}
			std::cout << date << " => " << val << " = " << myMap.lower_bound(date)->second * val << std::endl;
		}
		count++;
	}

	// for (std::map<std::string, float>::iterator it = myMap.begin(); it != myMap.end(); it++)
	// {
	// 	std::cout << "key ==>     " << it->first << "       value ==>       " << it->second << std::endl;
	// }

	data.close();
	input.close();
	return 0;
}
