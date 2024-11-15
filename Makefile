CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf

# Platform-specific settings
UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
    INCLUDES = -I/usr/include -I$(LIBFTHEADERS) -I$(MINILIBXDIR) -O3
    LIBS = -L/usr/lib -lX11 -lXext -lz -lm -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx_Linux
else
    INCLUDES = -I$(HEADERSDIR) -I$(LIBFTHEADERS) -I$(MINILIBXDIR) -O3
    LIBS = -framework OpenGL -framework AppKit -L$(LIBFTDIR) -lft -L$(MINILIBXDIR) -lmlx
endif

# directories
MINILIBXDIR = minilibx-linux
MINILIBX = $(MINILIBXDIR)/libmlx.a
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
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)

all: $(NAME)

$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(INCLUDES) -o $(NAME)

re:
	fclean all

clean:
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MINILIBXDIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MINILIBXDIR) fclean

.PHONY: all clean fclean re
