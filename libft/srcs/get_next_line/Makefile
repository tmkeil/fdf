CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = getnextlinelibft.a
SRCS = get_next_line.c get_next_line_utils.c
BSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

# all: comp
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $@ $<

bonus: $(BOBJS) $(OBJS)
	ar -rcs $(NAME) $(BOBJS) $(OBJS)
comp:
	cc *.c
	./a.out

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(OBJS) $(BOBJS)

re: fclean all

.PHONY: clean fclean all re

.SILENT: