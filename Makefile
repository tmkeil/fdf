CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

# Platform-specific settings
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -I$(LIBFTHEADERS) -I$(MINILIBXLINUXDIR) -I$(HEADERSDIR)
	LIBS = -L/usr/lib -L/usr/lib/x86_64-linux-gnu -L$(LIBFTDIR) -lft -L$(MINILIBXLINUXDIR) -lmlx_Linux -L/usr/lib/x86_64-linux-gnu -lXext -lX11 -lm -lbsd
	MINILIBX = $(MINILIBXLINUXDIR)/libmlx_Linux.a
else
    INCLUDES = -I/usr/local/include -I$(LIBFTHEADERS) -I$(MINILIBXDIR) -I$(HEADERSDIR)
    LIBS = -L/usr/local/lib/ -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
	MINILIBX = $(MINILIBXDIR)/libmlx.a
endif

# directories
MINILIBXDIR = mlx
# MINILIBX = $(MINILIBXDIR)/libmlx.a
MINILIBXLINUXDIR = linux
# MINILIBXLINUX = $(MINILIBXLINUXDIR)/libmlx.a

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
LIBFTHEADERS = $(LIBFTDIR)/headers
HEADERSDIR = headers
SRCSDIR = srcs
OBJSDIR = objs

SRCS = main.c utils.c utils2.c clear.c init.c parse.c numbers.c wireframe.c transformations.c rotation_matrices.c \
		scrollzoom_bonus.c handlemouse_bonus.c translate_bonus.c

SRCS_BONUS = handle_input.c scrollzoom_bonus.c translate_bonus.c 

SRCSS = $(addprefix $(SRCSDIR)/, $(SRCS))
SRCSS_BONUS = $(addprefix $(SRCSDIR)/, $(SRCS_BONUS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJSDIR)/, $(SRCS_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@echo "\n\n\n\n\ncreate\n\n\n\n\n\n\n\n"
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

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean
	$(MAKE) -C $(MINILIBXLINUXDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
