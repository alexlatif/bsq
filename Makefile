NAME	= bsq

IDIR	= include/
IDIR_MY	= lib/ft/include/

LIB	= libft.a
LNAME	= ft
LDIR	= lib/ft

CC	= gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra -ansi
# CFLAGS	+= -Werror

SRCS_DIR		= src/
SRCS_FILES		= get_board_matrix.c	\
				check_board_matrix.c	\
				solver.c				\
				main.c
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)


all: $(LIB) $(NAME); @echo "successful make"

$(LIB):
	make -C $(LDIR)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS)  -L $(LDIR) -l $(LNAME)

clean:
	@/bin/rm -f $(OBJS)
	make -C $(LDIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re