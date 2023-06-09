# Main Variables
NAME   = pipex
GCC    = cc
CFLAGS = -Wall -Wextra -Werror
RM     = rm -rf
OUTPUT = ./$(NAME)
LIBS   = -I ./includes/

# Compiled directories
SRC = src
OBJ = obj
SUBDIRS = main utils gnl

# Folder directions
SRC_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(SRC)/, $(dir)))
OBJ_DIR = $(foreach dir, $(SUBDIRS), $(addprefix $(OBJ)/, $(dir)))

# File directions
SRCS = $(foreach dir, $(SRC_DIR), $(wildcard $(dir)/*.c))
OBJS = $(subst $(SRC), $(OBJ), $(SRCS:.c=.o))

# Libft
LIBFT = ./libft/

# Colors
RESET  = \033[0m
RED    = \033[31m
GREEN  = \033[32m
YELLOW = \033[33m
BLUE   = \033[34m

all: $(NAME)

bonus: all

#$(NAME): $(OBJS) Makefile
#	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
#	@make -C $(LIBFT) all
#	@$(GCC) $(LIBS) -L$(LIBFT) -lft $(OBJS) -o $(NAME)
#	@$(GCC) $(CFLAGS) $(LIBS) -L$(LIBFT) -lft $(OBJS) -o $(NAME)
#	@make DONE_MSG

$(NAME): $(OBJS)
	@echo "${GREEN}-> Compiling LIBFT...${RESET}"
	@make -C $(LIBFT) all
	@$(GCC) -o $(NAME)  $(OBJS) $(LIBS) -L$(LIBFT) -lft
	@make DONE_MSG

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ) $(OBJ_DIR)
	@echo "${YELLOW}Compiling $^${RESET}"
	@$(GCC) $(LIBS) -c $< -o $@
	@$(GCC)  $(LIBS) -c $< -o $@

clean: DELETE_OBJ_MSG
	@make -C $(LIBFT) clean
	@$(RM) $(OBJ)
fclean: clean DELETE_PROGRAM_MSG
	@make -C $(LIBFT) fclean
	@$(RM) $(NAME)
re: fclean all

# Helper messages
DONE_MSG:
	@echo "${GREEN}! DONE !${RESET}"
DELETE_OBJ_MSG:
	@echo "${RED}Object files deleting...${RESET}"
DELETE_PROGRAM_MSG:
	@echo "${RED}! ATTENTION !\nProgram is deleting...${RESET}"