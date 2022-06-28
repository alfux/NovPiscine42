PATH_SRCS = ./srcs/
OPTION = -o
SRCS = $(PATH_SRCS)ft_init_t_map.c $(PATH_SRCS)ft_check_map.c $(PATH_SRCS)ft_resolve.c  $(PATH_SRCS)main.c

NAME		= bsq

all: $(NAME)

$(NAME):
			gcc -Wall -Wextra -Werror $(SRCS) $(OPTION) $(NAME)

fclean:		clean
			rm -f ${NAME} srcs/temp

re:			fclean all

.PHONY:		all clean fclean re
