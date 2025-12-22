# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/01 14:00:27 by Serge             #+#    #+#              #
#    Updated: 2025/12/20 19:59:23 by Serge            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42

SOURCES = \
	get_next_line.c \
	get_next_line_utils.c \
	main.c

OBJECTS = $(SOURCES:.c=.o)

TARGET = prog

all : $(NAME)

$(NAME) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) $(NAME) -o $(TARGET)

clean : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME) $(TARGET)

re : fclean all

test : clear $(TARGET) #fclean

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
	./$(TARGET)

clear :
	clear
