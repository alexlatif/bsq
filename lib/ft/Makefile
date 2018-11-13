NAME	 = libft.a

RM	 = rm -f

IDIR	= include/

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

# CHAR_IS_DIR	= my_char_is/
# CHAR_IS_FILES	= my_char_isalpha.c		\
# 		  my_char_islower.c		\
# 		  my_char_isnum.c		\
# 		  my_char_isprintable.c		\
# 		  my_char_isupper.c
# CHAR_IS		= $(addprefix $(CHAR_IS_DIR), $(CHAR_IS_FILES))

# ENV_DIR		= env/
# ENV_FILES	= my_envcpy.c			\
# 		  my_getenv.c			\
# 		  my_printenv.c			\
# 		  my_setenv.c			\
# 		  my_unsetenv.c
# ENV		= $(addprefix $(ENV_DIR), $(ENV_FILES))

# PRINTF_DIR	= my_printf/
# PRINTF_FILES	= compare_char.c	\
# 		  find_flag.c		\
# 		  flag_char.c		\
# 		  flag_int.c		\
# 		  flag_ptr.c		\
# 		  flag_str.c		\
# 		  flag_uint.c		\
# 		  init.c		\
# 		  my_printf.c		\
# 		  my_putchar.c		\
# 		  my_putnbr_base.c	\
# 		  my_put_nbr.c		\
# 		  my_putstr.c		\
# 		  my_showstr.c
# PRINTF		= $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))

# STR_IS_DIR	= my_str_is/
# STR_IS_FILES	= my_str_isalpha.c		\
# 		  my_str_islower.c		\
# 		  my_str_isnum.c		\
# 		  my_str_isprintable.c		\
# 		  my_str_isupper.c
# STR_IS		= $(addprefix $(STR_IS_DIR), $(STR_IS_FILES))

SRCS_DIR	= src/
SRCS_FILES	= ft_exit.c			\
		ft_atoi.c				\
		ft_puts.c				\
		ft_strlen.c				\
		#   $(CHAR_IS)
		#   $(ENV)
		#   $(PRINTF)	
		#   $(STR_IS)
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