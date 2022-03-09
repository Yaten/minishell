NAME = ./bin/minishell
DIRNAME = ./bin
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
APP = ./apps
LIB_PATH = ./libft
LIBFT = libft.a
OBJDIR = ./objects
SRCDIR_PARSE = ./sources/parse
SRCDIR_RUNTIME = ./sources/run_time
INCLUDE = ./includes
REMOVE = rm -rf

SRC_PARSE +=
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

SRC_RUNTIME +=
OBJRUNTIME = $(SRC_RUNTIME:.c=.o)
OBJECTS_RUNTIME = $(addprefix $(OBJDIR)/, $(OBJRUNTIME))

all: $(NAME)

$(NAME): $(OBJECTS_PARSE) $(OBJECTS_RUNTIME)
	$(MAKE) -C $(LIB_PATH)
	@mkdir -p ./bin/
	$(CC) $(APP)/main.c -o $(NAME) $(OBJECTS_PARSE) $(OBJECTS_RUNTIME) $(LIB_PATH)/$(LIBFT)

$(OBJDIR)/%.o: $(SRCDIR_PARSE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_RUNTIME)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(MAKE) fclean -C $(LIB_PATH)

fclean: clean
	$(REMOVE) $(OBJDIR)
	$(REMOVE) $(DIRNAME)

re: fclean all

.PHONY: bonus clean fclean re
