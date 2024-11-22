NAME := libftprintf.a
COMPILER := cc
FLAGS := -Wextra -Werror -Wall -c
REMOVE := rm -f

src := printf.c print_unsigned.c print_int.c print_hex.c print_characters.c print_address.c map_array_of_struct.c\

src_libft := libft/ft_atoi.c libft/ft_bzero.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_memchr.c\
	     libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memset.c libft/ft_putchar_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_split.c\
	     libft/ft_strchr.c libft/ft_strdup.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_strmapi.c libft/ft_strncmp.c\
	     libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strtrim.c libft/ft_substr.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_puts.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_reverse.c

src_libft_bonus :=  libft/ft_lstadd_back_bonus.c libft/ft_lstadd_front_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstiter_bonus.c\
		    libft/ft_lstlast_bonus.c libft/ft_lstmap_bonus.c libft/ft_lstnew_bonus.c libft/ft_lstsize_bonus.c 

src_bonus := bonus_parsing.c bonus_print.c bonus_functions.c bonus_parser_functions.c\
	     bonus_percision.c bonus_print_count_len.c bonus_print_functions.c

obj = $(src:%.c=%.o) 
obj_libft = $(src_libft:%.c=%.o)
obj_libft_bonus = $(src_libft_bonus:%.c=%.o)
obj_bonus = $(src_bonus:%.c=%.o)

all: $(NAME)

$(NAME): $(obj) $(obj_bonus) $(obj_libft)
	ar rsc $(NAME) $(obj) $(obj_bonus) $(obj_libft)

bonus: $(obj) $(obj_bonus) $(obj_libft)
	ar rsc $(NAME) $(obj) $(obj_bonus) $(obj_libft)

%.o: %.c
	$(COMPILER) $(FLAGS) $< -o $@

clean:
	$(REMOVE) $(obj) $(obj_bonus)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all
