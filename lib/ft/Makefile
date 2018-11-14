NAME	 = libft.a

RM	 = rm -f

IDIR	= include/

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SRCS_DIR	= src/
SRCS_FILES	= ft_exit.c			\
		ft_atoi.c				\
		ft_puts.c				\
		ft_string.c				\
		ft_realloc.c			\

SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	 = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re