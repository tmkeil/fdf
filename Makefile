CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

INCLUDES = -I$(HEADERSDIR) -I$(LIBFTHEADERS) -I$(MINILIBXDIR)
# (MAC) LIBS = -lmlx -framework OpenGL -framework AppKit -lm -lft -L$(LIBFTDIR) -L$(MINILIBXDIR)
LIBS = -lmlx -lX11 -lGL -lm -lft -L$(LIBFTDIR) -L$(MINILIBXDIR)

# directories
MINILIBX = minilibx-linux/libmlx.a
MINILIBXDIR = minilibx-linux
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTHEADERS = $(LIBFTDIR)/headers
HEADERSDIR = headers
SRCSDIR = srcs
OBJSDIR = objs

SRCS = test.c
SRCSS = $(addprefix $(SRCSDIR)/, $(SRCS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJSDIR)
    mkdir -p $@

$(LIBFT):
    $(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
    $(MAKE) -C $(MINILIBXDIR)

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS) $(OBJSDIR)
    $(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJS) -o $(NAME)

re:
    fclean all

clean:
    rm -rf $(OBJSDIR)
    $(MAKE) -C $(LIBFTDIR) clean
    $(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
    rm -rf $(NAME)
    rm -rf $(MINILIBX)
    rm -rf $(LIBFT)

.PHONY: all clean fclean re

.SILENT:
