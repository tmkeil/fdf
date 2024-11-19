# Compiler and Flags
CC = cc
# Library name
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(HEADERSDIR) -I$(GNL_HEADERSDIR)

# MANDATORY files
MANDATORY_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c

GNL_SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 
# BONUS files
BONUS_SRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCSDIR = srcs
HEADERSDIR = headers
GNLDIR = srcs/get_next_line
GNL_HEADERSDIR = srcs/get_next_line
OBJSDIR = objs

SRCSM = $(addprefix $(SRCSDIR)/, $(MANDATORY_SRCS)) \
SRCSGNL = $(addprefix $(GNLDIR)/, $(GNL_SRCS))
SRCSB = $(addprefix $(SRCSDIR)/, $(BONUS_SRCS))

OBJSM = $(addprefix $(OBJSDIR)/, $(notdir $(MANDATORY_SRCS:.c=.o)))
OBJSGNL = $(addprefix $(OBJSDIR)/, $(notdir $(GNL_SRCS:.c=.o)))
OBJSB = $(addprefix $(OBJSDIR)/, $(BONUS_SRCS:.c=.o))

# Default
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJSM) $(OBJSGNL)
		ar -rcs $@ $^

# Rule to compile .c files to .o files
$(OBJSDIR)/%.o: $(SRCSDIR)/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJSDIR)/%.o: $(GNLDIR)/%.c | $(OBJSDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the bonus library
bonus: $(OBJSB) $(OBJSM) $(OBJSGNL)
		ar -rcs $(NAME) $(OBJSB) $(OBJSM) $(OBJSGNL)

$(OBJSDIR):
	mkdir -p $(OBJSDIR)

# Rule to clean up object files
clean:
		rm -rf $(OBJSDIR)

# Rule to clean up object files and the library
fclean: clean
		rm -rf $(NAME)

# Rule to fclean and redo all
re: fclean all

# Phony targets to avoid conflicts with files of the same name
.PHONY: all clean fclean re bonus
