# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrahim <bbrahim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/15 08:41:54 by bbrahim           #+#    #+#              #
#    Updated: 2023/03/18 15:03:12 by bbrahim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CXX = c++

FLAGS =  -Wall -Wextra -Werror -std=c++98

HEADER = BitcoinExchange.hpp

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp $(HEADER)
	$(CXX) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re