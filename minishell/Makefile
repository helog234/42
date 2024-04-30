# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgandar <hgandar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/01 13:46:07 by hgandar           #+#    #+#              #
#    Updated: 2024/04/27 13:04:39 by hgandar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = ./
OBJS_DIR = ./objs
HISTORY = ./.history.log

# Détecter le répertoire d'installation de Readline
READLINE_42 = /Users/$(USER)/.brew/opt/readline
READLINE_PERSO = /opt/homebrew/opt/readline

# Tester l'environnement et définir les flags de Readline en conséquence
ifeq ($(shell test -d $(READLINE_42) && echo exists),exists)
    READLINE_INC += -I$(READLINE_42)/include
    READLINE_LIB += -L$(READLINE_42)/lib
else
    READLINE_INC += -I$(READLINE_PERSO)/include
    READLINE_LIB += -L$(READLINE_PERSO)/lib
endif
READLINE_FLAGS += -lreadline

INC = -I. -I ./libft

CFILES = $(addsuffix .c, main env tools_env_lst tools_env_lst2 tools_env history \
signal_handeling set_prompt parsing tokens_lst parse_line ctr_input_utils \
check_data get_char_str token run_line check_dollar handle_dollar check_data_2 is_token_type \
init_type add_type utils_type path syntax check_input set_redir global_utils \
errors free_tokens free_data_types print_utils check_heredoc execution tools_exec tools_exec2 \
tools_exec3 tools_exec4 exec_exp_unset exec_cd_pwd exec_env_echo child_process tools_child_proc \
tools_child_proc2)

OFILES = $(CFILES:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OFILES) | libftk 
	$(CC) $(CFLAGS) $(READLINE_FLAGS) $(READLINE_LIB) -L $(LIBFT_DIR) -lft -o $@ $^

libftk:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o: %.c | obdir
	$(CC) $(CFLAGS) $(INC) $(READLINE_INC) -c $< -o $@

obdir:
	mkdir -p $(OBJS_DIR)

copyexe:
	mkdir -p $(HOME)/msh/bin
	cp $(NAME) $(HOME)/msh/bin
	export PATH=$$HOME/msh/bin:$$PATH; minishell

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(HOME)/msh
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(HISTORY)

run:
	./minishell

re: fclean all

.PHONY: all clean fclean re libft obdir run copyexe
