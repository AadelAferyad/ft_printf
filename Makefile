NAME := libftprintf.a
COMPILER := cc
FLAGS := -Wextra -Werror -Wall -c
REMOVE := rm -f

src := printf.c print_int.c print_hex.c print_func.c map_table.c
obj = $(src:%.c=%.o) 

all: $(NAME)

$(NAME): $(obj)
	ar rcs $(NAME) $(obj)

%.o: %.c
	$(COMPILER) $(FLAGS) $< -o $@

clean:
	$(REMOVE) $(obj)
fclean:
	$(REMOVE) $(obj) $(NAME)

re: fclean all
