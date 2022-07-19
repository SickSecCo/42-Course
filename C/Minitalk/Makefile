NAME = server
NAME1 = client
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
LIBRARIES = printf/libftprintf.a

SOURCE_CLIENT =	client.c

SOURCE_SERVER =	server.c

OBJS_CLIENT = $(SOURCE_CLIENT:.c=.o)

OBJS_SERVER = $(SOURCE_SERVER:.c=.o)

all: lib server client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(LIBRARIES)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $^ -o $(NAME1) $(LIBRARIES)

lib:
	make -C ./printf

deb:
	$(CC) $(CFLAGS) $(SOURCE_SERVER) -o $(NAME) -g $(LIBRARIES)
	$(CC) $(CFLAGS) $(SOURCE_CLIENT) -o $(NAME1) -g $(LIBRARIES)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make clean -C ./printf

fclean: clean
	$(RM) $(NAME) $(NAME1)
	make fclean -C ./printf

re: fclean all

.PHONY: all clean fclean re server client deb lib