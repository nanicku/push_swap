NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.
CC		= gcc
NORMIN	= norminette
SRC		= srcs/ft_atoi.c \
		srcs/ft_isalpha.c \
		srcs/ft_isdigit.c \
		srcs/ft_itoa.c \
		srcs/ft_memcpy.c \
		srcs/ft_putchar.c \
		srcs/ft_putstr.c \
		srcs/ft_split.c \
		srcs/ft_strchr.c \
		srcs/ft_strdup.c \
		srcs/ft_strlen.c \
		srcs/ft_strncmp.c \
		srcs/ft_strcmp.c \
		srcs/get_next_line.c \
		srcs/ft_strcpy.c \
		srcs/ft_strjoin.c \

OBJ		= $(SRC:%.c=%.o)

.PHONY: all clean fclean re norm

all: $(NAME)

.o: .c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $?
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
