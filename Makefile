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

SRCS = main.c utils.c utils2.c clear.c init.c parse.c numbers.c wireframe.c transformations.c rotation_matrices.c scrollzoom.c
SRCSS = $(addprefix $(SRCSDIR)/, $(SRCS))
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@echo "\n\n\n\n\ncreate\n\n\n\n\n\n\n\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

ifeq ($(UNAME), Linux)
    $(MINILIBX):  # Only for Linux
	@echo "Compiling MinilibX for Linux..."
	$(MAKE) -C $(MINILIBXLINUXDIR)  # Navigate into the linux folder and run make there
else
    $(MINILIBX):
	@echo "Compiling MinilibX for macOS..."
	$(MAKE) -C $(MINILIBXDIR)  # For macOS, change the directory accordingly
endif

$(LIBFT):
	@echo "\n\n\n\n\ncrea12222te\n\n\n\n\n\n\n\n"
	$(MAKE) -C $(LIBFTDIR)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean
	$(MAKE) -C $(MINILIBXLINUXDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

.PHONY: all clean fclean re $(LIBFT) $(MINILIBX) $(MINILIBXLINUX)
