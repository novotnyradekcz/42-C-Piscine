NAME = rush-02

FLAGS = -Wall -Wextra -Werror

SOURCES = main.c decompose.c conversion.c

OFILES = main.o decompose.o conversion.o

all:	$(NAME)

$(NAME):	precomp
	cc -o $(NAME) $(OFILES)

precomp:
	cc -c $(SOURCES)
clean:
	rm $(OFILES)

fclean:	clean
	rm $(NAME)

re:	fclean all
