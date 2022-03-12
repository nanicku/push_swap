ifeq ($(MAKECMDGOALS),bonus)
	NAME = checker
else
	NAME = push_swap
endif
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
SRCS		= src/ft_addnum.c \
		src/ft_bigsort.c \
		src/ft_bigsort2.c \
		src/ft_count.c \
		src/ft_exit_clean.c \
		src/ft_findmax_min.c \
		src/ft_sort_45.c \
		src/push_swap.c \
		src/operations.c \
		src/push.c \
		src/revrotate.c \
		src/rotate.c \
		src/smallsorters.c \
		src/swap.c \
		src/validation.c \
		src/validation2.c \

SRCS_BONUS	= src/checker.c \
		src/ft_bigsort.c \
		src/ft_bigsort2.c \
		src/ft_count.c \
		src/ft_exit_clean.c \
		src/ft_findmax_min.c \
		src/ft_sort_45.c \
		src/operations.c \
		src/push.c \
		src/revrotate.c \
		src/rotate.c \
		src/smallsorters.c \
		src/swap.c \
		src/validation.c \
		src/validation2.c \
		src/ft_addnum.c


INCLUDE		= push_swap.h 

LIBFT_A		= libft/libft.a

.PHONY: all clean fclean re bonus libft

.o: .c $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@

all: libft $(NAME)

${NAME}: $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)

bonus: libft $(NAME)


libft:
	make -C libft

clean:
	rm -f src/*.o
	rm -f get_next_line/*.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	rm -f push_swap
	rm -rf a.out*
	rm -rf */a.out*
	rm -rf *.gch
	rm -rf */*.gch
	rm -f libft/libft.a

re: fclean all