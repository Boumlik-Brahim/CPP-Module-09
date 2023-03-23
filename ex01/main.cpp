/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:43:13 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/23 10:28:03 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return (EXIT_FAILURE);
	}
	RPN eval(argv[1]);
	eval.rpn();
	return (0);
}
