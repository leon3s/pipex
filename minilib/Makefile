### GenMake V1 By leone ###

NAME	=	mini.a

CFLAGS	+=  -Wall -Wextra -Werror -I include

SRCS	=		srcs/ft_strlen.c\
	srcs/ft_bzero.c\
	srcs/ft_myfree.c\
	srcs/ft_strsplit.c\
	srcs/ft_error.c

SRC	= $(addprefix $(SRCPATH), $(SRCS))

OBJ	= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	 rm -f $(OBJ)

fclean : clean 
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
