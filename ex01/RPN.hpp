/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:30 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/25 17:48:54 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	private:
		std::stack<float>		my_stak;
		std::string				mathematical_expression;

	public:
		// Constructors
		RPN();
		RPN(std::string	expression);
		RPN(const RPN &copy);

		// Operators
		RPN & operator=(const RPN &assign);

		int		is_token_operand(char token);
		int		is_token_operator(char token);
		void	rpn();

		// Destructor
		~RPN();		
};

#endif