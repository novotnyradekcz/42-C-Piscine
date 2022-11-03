NAME = bsq

CFILES = main.c \
	main_pt2.c \
	matrix.c

OFILES = main.o \
	main_pt2.o \
	matrix.o

FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OFILES)
	cc $(FLAGS) -o $(NAME) $(OFILES)

$(OFILES):	$(CFILES)
	cc -c $(FLAGS) $(CFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all