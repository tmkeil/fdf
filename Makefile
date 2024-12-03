CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -I$(MINILIBXLINUXDIR) -I$(HEADERSDIR)
	LIBS = -L/usr/lib -L/usr/lib/x86_64-linux-gnu -L$(LIBFTDIR) -lft -L$(MINILIBXLINUXDIR) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lbsd
	MINILIBX = $(MINILIBXLINUXDIR)/libmlx_Linux.a
else
    INCLUDES = -I/usr/local/include -I$(MINILIBXDIR) -I$(HEADERSDIR)
    LIBS = -L/usr/local/lib/ -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
	MINILIBX = $(MINILIBXDIR)/libmlx.a
endif

MINILIBXDIR = mlx
MINILIBXLINUXDIR = linux

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
HEADERSDIR = headers
SRCSDIR = srcs
OBJSDIR = objs

SRCS = main.c utils.c utils2.c clear.c clear_images.c init.c parse.c numbers.c wireframe.c transformations.c rotation_matrices.c positioning.c window_resize.c

SRCS_BONUS = main_bonus.c handle_input_bonus.c transformations_bonus.c utils_bonus.c window_resize_bonus.c transformations.c rotation_matrices.c \
				wireframe.c utils.c utils2.c clear.c clear_images.c init.c parse.c numbers.c positioning.c

SRCS_PATHS = $(addprefix $(SRCSDIR)/, $(SRCS))
SRCS_PATHS_BONUS = $(addprefix $(SRCSDIR)/, $(SRCS_BONUS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJSDIR)/, $(SRCS_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

bonus: $(LIBFT) $(MINILIBX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(INCLUDES) -o $(NAME)

ifeq ($(UNAME), Linux)
    $(MINILIBX):
	$(MAKE) -C $(MINILIBXLINUXDIR)
else
    $(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
endif

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
