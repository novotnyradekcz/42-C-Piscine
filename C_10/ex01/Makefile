NAME = ft_cat

SRC = ft_cat.c

OFILE = ft_cat.o

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OFILE)
	cc $(FLAGS) -o $(NAME) $(OFILE)

$(OFILE):	$(SRC)
	cc -c $(FLAGS) $(SRC)

clean:
	rm -f $(OFILE)

fclean: clean
	rm -f $(NAME)

re: fclean all