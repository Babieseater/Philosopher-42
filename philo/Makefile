# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 12:54:03 by smayrand          #+#    #+#              #
#    Updated: 2022/12/13 13:03:02 by smayrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = '\033[32m'
NONE = '\033[0m'

NAME = philo

CC = gcc -g 
CFLAGS = -Wall -Werror -Wextra -pthread
AR = ar -rcs

RM = rm -f

SRCS = philo.c\
srcs/timer.c\
srcs/utils.c\
srcs/error.c\
srcs/init_philo_mutex.c\
srcs/actions.c\
srcs/cycles.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)
#	@afplay ./srcs/sounds/th.wav
	@echo " ==============="
	@echo $(GREEN) "FULLY	COMPILED" $(NONE)
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
#	@afplay ./srcs/sounds/cry.wav
	@$(RM) $(NAME)
	@echo $(GREEN) "FULLY	CLEANED" $(NONE)

rick:
	@curl -s -L http://bit.ly/10hA8iC | bash
	
re: fclean all