/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:24:30 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/19 18:25:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>

class RPN
{
	private:

	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);

		// Operators
		RPN & operator=(const RPN &assign);

		// Destructor
		~RPN();		
};

#endif