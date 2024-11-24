CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

# Platform-specific settings
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/local/include -I$(LIBFTHEADERS) -I$(MINILIBXDIR)
    LIBS = -L/usr/local/lib/ -lX11 -lXext -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
else
    INCLUDES = -I/usr/local/include -I$(HEADERSDIR) -I$(LIBFTHEADERS) -I$(MINILIBXDIR)
    LIBS = -L/usr/local/lib/ -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
endif

# directories
MINILIBXDIR = mlx
MINILIBX = $(MINILIBXDIR)/libmlx.a
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTHEADERS = $(LIBFTDIR)/headers
HEADERSDIR = headers
SRCSDIR = srcs
OBJSDIR = objs

SRCS = main.c utils.c utils2.c clear.c init.c parse.c numbers.c wireframe.c transformations.c rotation_matrices.c mouseevents.c
SRCSS = $(addprefix $(SRCSDIR)/, $(SRCS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	@echo "Trying to create"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)

$(OBJSDIR):
	@echo "abc"
	mkdir -p $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	@echo "Compiling $< -> $@"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) fclean

.PHONY: all clean fclean re $(LIBFT) $(MINILIBX)
