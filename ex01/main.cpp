/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:43:13 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/22 18:51:05 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
# include <stack>

int is_token_operator(char token)
{
	if (token == '+' || token == '-' || token == '/' || token == '*')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int is_token_operand(char token)
{
	if (token >= '0' && token <= '9')
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	std::stack<float>		my_stak;
	std::string				mathematical_expression;
	std::string::iterator	it;
	float					res;
	int 					a;
	int 					b;
	int 					val;
	float 					fval;

	mathematical_expression = argv[1];
	for (it = mathematical_expression.begin(); it != mathematical_expression.end(); it++)
	{
		if (!is_token_operator(*it))
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
				res = b / a;
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
			break ;
		}
	}
	if (!my_stak.empty())
		std::cout << my_stak.top() << std::endl;
	return 0;
}
