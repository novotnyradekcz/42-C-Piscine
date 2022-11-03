NAME = ft_display_file

SRC = ft_display_file.c

OFILE = ft_display_file.o

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