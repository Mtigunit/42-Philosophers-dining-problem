# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 14:57:01 by mtigunit          #+#    #+#              #
#    Updated: 2023/03/25 14:16:12 by mtigunit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJDIR		= 	objects
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
NAME		=	philo
SRCS		=	\
				ft_check_arg.c\
				ft_philosopher_eat.c\
				ft_philosopher_sleep.c\
				init_vars.c\
				print_state.c\
				start_simutalion.c\
				timestamp_in_ms.c\
				usage.c\
				delay_ms.c\
				ft_philosopher_dead.c\
				ft_philosopher_one.c\
				ft_philosopher_think.c\
				routine.c\
				stil_alive.c\
				unlock_all.c\
				ft_atoi.c\
				ft_isdigit.c\
				main.c

OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)

all: 			$(NAME)

$(OBJDIR)/%.o:	%.c philosophers.h | $(OBJDIR)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(OBJS) -o $(NAME)

$(OBJDIR):
				@mkdir -p $(OBJDIR)

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all
