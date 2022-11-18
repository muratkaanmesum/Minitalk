PRINTF_DIR = ft_printf/
printfArchive = $(PRINTF_DIR)libftprintf.a

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME= minitalk


SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): printf client server


printf:
	make -C $(PRINTF_DIR)


client: client.o
	$(CC) $(CFLAGS) -o $@ $< $(printfArchive)
server: server.o
	$(CC) $(CFLAGS) -o $@ $< $(printfArchive)

clean:
	make clean -C $(PRINTF_DIR)
	$(RM) $(OBJS)
fclean: clean
	$(RM)  $(NAME)
	make fclean -C $(PRINTF_DIR)
	$(RM) server client $(OBJS)
re: fclean all
