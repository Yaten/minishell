NAME = ./bin/minishell
DIRNAME = ./bin
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
APP = ./apps
PRINTF_PATH = ./ft_printf
PRINTF = libftprintf.a
OBJDIR = ./objects
SRCDIR_PARSE = ./sources/parse
SRCDIR_RUNTIME = ./sources/run_time
SRCDIR_LINKEDLIST = ./sources/doubly_linked_list
INCLUDE = ./includes
REMOVE = rm -rf

SRC_LINKEDLIST += ft_list_add_first.c ft_list_create.c ft_list_destroy.c
SRC_LINKEDLIST += ft_list_is_empty.c ft_node_create.c ft_list_print.c
SRC_LINKEDLIST += ft_list_add_last.c
OBJLINKEDLIST = $(SRC_LINKEDLIST:.c=.o)
OBJECTS_LINKEDLIST = $(addprefix $(OBJDIR)/, $(OBJLINKEDLIST))

SRC_PARSE += ft_expand.c
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

SRC_RUNTIME += ft_event_loop.c ft_prompt_concat.c ft_set_new_line.c
OBJRUNTIME = $(SRC_RUNTIME:.c=.o)
OBJECTS_RUNTIME = $(addprefix $(OBJDIR)/, $(OBJRUNTIME))

all: $(NAME)

$(NAME): $(OBJECTS_LINKEDLIST) $(OBJECTS_PARSE) $(OBJECTS_RUNTIME)
	$(MAKE) -C $(PRINTF_PATH)
	@mkdir -p ./bin/
	$(CC) $(APP)/main.c -o $(NAME) $(OBJECTS_LINKEDLIST) $(OBJECTS_PARSE) $(OBJECTS_RUNTIME) $(PRINTF_PATH)/$(PRINTF) -lreadline

$(OBJDIR)/%.o: $(SRCDIR_LINKEDLIST)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_PARSE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_RUNTIME)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(MAKE) fclean -C $(PRINTF_PATH)

fclean: clean
	$(REMOVE) $(OBJDIR)
	$(REMOVE) $(DIRNAME)

re: fclean all

.PHONY: bonus clean fclean re

