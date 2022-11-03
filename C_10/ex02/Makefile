NAME = ft_tail

SRC = ft_tail.c

OFILE = ft_tail.o

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