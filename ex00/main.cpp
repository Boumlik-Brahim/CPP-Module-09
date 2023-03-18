/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:41:47 by bbrahim           #+#    #+#             */
/*   Updated: 2023/03/18 18:47:14 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <vector>
#include <map>

void checkDate()
{}
void checkValue()
{}
int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    std::string line;
    std::vector<std::string> tokens;
    std::map<std::string, float> myMap;
    
    size_t pos = 0;
    std::string token;
    std::string delimiter;

    std::ifstream file("data.csv");
    if (!file.is_open())
    {
        std::cout << "Failed to open file." << std::endl;
        return (EXIT_FAILURE);
    }
    
    delimiter = ",";
    while(std::getline(file, line))
    {
        while((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            tokens.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        tokens.push_back(line);
    }

    for (size_t i = 0; i < tokens.size(); i++) 
    {
        std::cout << tokens[i] << std::endl;
    }

    file.close();
    return 0;
}
