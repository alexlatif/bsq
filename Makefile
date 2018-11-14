NAME	= bsq

IDIR	= include/
IDIR_MY	= lib/ft/include/

LIB	= libft.a
LNAME	= ft
LDIR	= lib/ft

CC	= gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -ansi #-fsanitize=address
# CFLAGS	+= -Werror

SRCS_DIR		= src/
SRCS_FILES		= get_board_matrix.c	\
				check_board_matrix.c	\
				solver.c				\
				main.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)

RM	= rm -f


all: $(LIB) $(NAME)

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  -L $(LDIR) -l $(LNAME)

clean:
	$(RM) $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re