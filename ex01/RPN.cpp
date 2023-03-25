/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:40 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/25 18:11:48 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{}

RPN::RPN(std::string expression): mathematical_expression(expression)
{}

RPN::RPN(const RPN &copy): my_stak(copy.my_stak), mathematical_expression(copy.mathematical_expression)
{}

// Operators
RPN & RPN::operator=(const RPN &assign)
{
	if(this != &assign)
	{
		this->my_stak = assign.my_stak;
		this->mathematical_expression = assign.mathematical_expression;
	}
	return *this;
}

int RPN::is_token_operator(char token)
{
	if (token == '+' || token == '-' || token == '/' || token == '*')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int RPN::is_token_operand(char token)
{
	if (token >= '0' && token <= '9')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

void RPN::rpn()
{
	std::string::iterator	it;
	int 					a = 0;
	int 					b = 0;
	int 					val = 0;
	float					res = 0;
	float 					fval = 0;

	for (it = mathematical_expression.begin(); it != mathematical_expression.end(); it++)
	{
		if (!is_token_operator(*it) && my_stak.size() >= 2)
		{
			a = my_stak.top();
			my_stak.pop();
			b = my_stak.top();
			my_stak.pop();
			if (*it == '+')
				res = b + a;
			else if (*it == '-')
				res = b - a;
			else if (*it == '*')
				res = b * a;
			else if (*it == '/')
			{
				if(a == 0)
				{
					std::cout << "Error" << std::endl;
					return ;
				}
				res = b / a;
			}
			my_stak.push(res);
		}
		else if (!is_token_operand(*it))
		{
			val = *it - '0';
			fval = (float)val;
			my_stak.push(fval);
		}
		else if (*it != ' ')
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	if (my_stak.size() != 1	)
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << my_stak.top() << std::endl;
}

// Destructor
RPN::~RPN()
{}