NAME = pipex
CFLAGS = -c

LIBFT = lib/libft
LIB = $(LIBFT)/libft.a
SOURCES = pipex.c pipex_utils.c

OBJECTS = ${SOURCES:.c=.o}
HEADERS = -I inc

ARGS = "infile" "notexisting" "wc" "outfile.txt"
CMD = < infile notexisting | wc > outfile.txt

all: $(LIB) $(NAME)

$(LIB):
	make -C $(LIBFT)

$(NAME): $(OBJECTS) $(LIB)
	@cc -o $@ $^

run: $(NAME)
	@./$^ $(ARGS)

valgrind: $(NAME)
	@valgrind --leak-check=full ./$^ $(ARGS)

command:
	$(CMD)

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

