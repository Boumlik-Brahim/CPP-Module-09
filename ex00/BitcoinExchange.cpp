/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:57:14 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/22 15:53:54 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(std::string file_name): data("data.csv"), input(file_name), val(0), date("")
{
	if (!data.is_open() || !input.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): val(copy.val), date(copy.date), myMap(copy.myMap)
{}

// Operators
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if(this != &assign)
	{
		this->val = assign.val;
		this->date = assign.date;
		this->myMap = assign.myMap;
	}
	return *this;
}

int BitcoinExchange::is_digit(std::string str)
{
	for( size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int BitcoinExchange::is_digit_point(std::string str)
{
	for( size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != '-')
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

std::string BitcoinExchange::strtrim(std::string str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return "";
	str.erase(0, first);
	size_t last = str.find_last_not_of(" \t\n\r");
	str.erase(last + 1);
	return (str);
}

int BitcoinExchange::check_date(std::string token_date)
{
	std::string tmp_year;
	std::string tmp_month;
	std::string tmp_day;

	if (this->date.size() == 10)
	{
		if (this->date.at(4) != '-' || this->date.at(7) != '-')
		{
			std::cout << "Error: bad input => " << token_date << std::endl;
			return (EXIT_FAILURE);
		}
		tmp_year = this->date.substr(0, 4);
		tmp_month = this->date.substr(5, 2);
		tmp_day = this->date.substr(8, 2);
		if (!is_digit(tmp_year) || !is_digit(tmp_month) || !is_digit(tmp_day))
		{
			std::cout << "Error: bad input => " << token_date << std::endl;
			return (EXIT_FAILURE);
		}
		int year = std::atoi(tmp_year.c_str());
		int month = std::atoi(tmp_month.c_str());
		int day = std::atoi(tmp_day.c_str());
		if (month < 1 || month > 12 || year < 2009 || year >= 2023)
		{
			std::cout << "Error: bad input => " << token_date << std::endl;
			return (EXIT_FAILURE);
		}
		if (month == 2)
		{
			if (day <= 0 || day > 28)
			{
				std::cout << "Error: bazd input => " << token_date << std::endl;
				return (EXIT_FAILURE);
			}
		}
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (day <= 0 || day > 30)
			{
				std::cout << "Error: bad input => " << token_date << std::endl;
				return (EXIT_FAILURE);
			}
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 0 || day > 31)
			{
				std::cout << "Error: bad input => " << token_date << std::endl;
				return (EXIT_FAILURE);
			}
		}				
	}
	else
	{
		std::cout << "Error: bad input => " << token_date << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int BitcoinExchange::check_value(std::string value)
{
	if (value.empty() || value.at(0) == '.' || value.at(value.size() - 1) == '.')
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return (EXIT_FAILURE);
	}
	if (!is_digit_point(value))
	{
		std::cout << "Error: bad input => " << value << std::endl;
		return (EXIT_FAILURE);
	}
	this->val = std::atof(value.c_str());
	if (this->val < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (EXIT_FAILURE);
	}
	if (this->val > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void BitcoinExchange::read_data()
{
	size_t 		pos;
	std::string	token_date;
	std::string	token_value;
	
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
}

void BitcoinExchange::read_input()
{
	std::string													token_date;
	std::string													token_value;
	std::string													value;
	size_t														pos;
	int															count;

	val = 0;
	pos = 0;
	count = 0;
	while (std::getline(input, token_value))
	{
		if ((pos = token_value.find("|")) == std::string::npos && !token_value.empty())
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
			if (check_date(token_date))
				break ;
			/*check value*/
			if (check_value(value))
				break ;
			std::cout << date << " => " << val << " = " << myMap.lower_bound(date)->second * val << std::endl;			
		}
		count++;
	}
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	this->data.close();
	this->input.close();
}