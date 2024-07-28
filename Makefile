NAME = pipex
CFLAGS = -c

LIBFT = lib/libft
LIB = $(LIBFT)/libft.a
SOURCES = pipex.c pipex_utils.c

OBJECTS = ${SOURCES:.c=.o}
HEADERS = -I inc

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBFT)

$(NAME): $(OBJECTS) $(LIB)
	@cc -o $@ $^ $(LIB)

run: $(NAME)
	@./$^ "infile.txt" "grep Now" "wc -w" "outfile.txt"

valgrind: $(NAME)
	@valgrind --leak-check=full ./$^ "infile.txt" "wc" "notexisting" "outfile.txt"

norm:
	norminette $(SOURCES) inc/pipex.h

%.o: %.c
	@cc $(CFLAGS) -o $@ $< $(HEADERS)

clean:
	@rm -rf $(OBJECTS)
	@make fclean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)

re: fclean all run

