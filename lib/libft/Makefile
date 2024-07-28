CFLAGS = -Wall -Wextra -Werror -c

SOURCES = src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c src/ft_strlen.c \
src/ft_toupper.c src/ft_tolower.c src/ft_putchar_fd.c src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c \
src/ft_putcaphex_fd.c src/ft_puthex_fd.c src/ft_putmemory_fd.c src/ft_putunbr_fd.c src/ft_strmapi.c src/ft_striteri.c \
src/ft_strnstr.c src/ft_strtrim.c src/ft_strdup.c src/ft_memset.c src/ft_bzero.c src/ft_strjoin.c src/ft_strncmp.c \
src/ft_atoi.c src/ft_split.c src/ft_strchr.c src/ft_strrchr.c src/ft_substr.c src/ft_memchr.c src/ft_strlcpy.c \
src/ft_itoa.c src/ft_memcpy.c src/ft_memmove.c src/ft_memcmp.c src/ft_strlcat.c src/ft_findchar.c \
src/ft_lstlast.c src/ft_lstadd_back.c src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstdelone.c \
src/ft_lstclear.c src/ft_lstiter.c src/ft_lstmap.c src/ft_calloc.c src/get_next_line.c src/ft_printf.c

OBJECTS = ${SOURCES:.c=.o}

INCLUDES = -I inc/

NAME = libft.a


all: ${NAME}

.c.o:
	@cc $(CFLAGS) $(INCLUDES) $< -o ${<:.c=.o}

${NAME}: ${OBJECTS}
	@ar rcs $@ $^

clean:
	@rm -f ${OBJECTS}

fclean: clean
	@rm -f ${NAME}

re: fclean all
