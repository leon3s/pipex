NAME	=	pipex

SRCS	=	src/main.c src/tests.c src/cleans.c src/creat_src.c\
			src/pipex_errors.c

SRC		=   $(addprefix $(SRCPATH), $(SRCS))

OBJ		=   $(SRC:.c=.o)

TEST		=	./src/main.o

CFLAGS	+=  -Wall -Wextra -Werror -I ./include -I minilib/include

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilib
	@gcc $(CFLAGS) -o $(NAME) $(SRC) minilib/mini.a
	@echo "\033[1;32m[ $(NAME) Created ]\033[1;32m"

clean :
	make clean -C minilib
	@if test -f $(TEST) ;then \
	rm -f $(OBJ) && echo "\033[1;32m[ OBJCLEAN : DONE ]\033[1;32m"; \
	else echo "\033[1;31m[ OBJCLEAN : file not exist ]\033[1;31m"; \
	fi

fclean : clean
	make fclean -C minilib
	@if test -e $(NAME) ;then \
	rm -f $(NAME) && echo "\033[1;32m[ BINCLEAN : DONE ]\033[1;32m"; \
	else echo "\033[1;31m[ BINCLEAN : file not exist ]\033[1;31m"; \
	fi

re: fclean all

.PHONY: all clean fclean re
