CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./
CFILES = $(addsuffix .c, ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_strlen ft_memset ft_bzero \
ft_memcpy ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp\
ft_memchr ft_memcmp ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin ft_strtrim ft_split\
ft_itoa ft_strmapi ft_striteri ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone ft_lstclear ft_lstiter ft_lstmap\
printf/ft_printf printf/write_cspx printf/write_diu\
gnl/get_next_line_bonus gnl/get_next_line_utils_bonus\
ft_nbstr ft_arrjoin ft_free_arr ft_abs)
OBJS_DIR = ./objs
OBJ = $(CFILES:%.c=$(OBJS_DIR)/%.o)
HEADER = -I. -I ./printf -I ./gnl
AR = ar
ARFLAGS = -rc
RM = rm -rf

NAME = libft.a

all: dirobj $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^ 

$(OBJS_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^ $(HEADER)

dirobj: 
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/printf
	@mkdir -p $(OBJS_DIR)/gnl

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJS_DIR)/printf
	@$(RM) $(OBJS_DIR)/gnl
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re