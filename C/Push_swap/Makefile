NAME = push_swap
CHECKER = checker
CC = gcc
CLFAGS = -Wall -Wextra -Werror
RM = rm -f
LEAK = -fsanitize=address 
PATH1 = $(CURDIR)/control/
PATH2 = $(CURDIR)/solve/
PATH3 = $(CURDIR)/utils/
PATH4 = $(CURDIR)/instructions/
PATH5 = $(CURDIR)/solve_utils/
PATH6 = $(CURDIR)/check/
DEP = $(CURDIR)/swap.h
FILES = main.c \
		$(PATH1)control.c \
		$(PATH1)split.c \
		$(PATH1)arrcheck.c \
		$(PATH4)instructions.c \
		$(PATH4)instructions2.c \
		$(PATH2)solve_2-5.c \
		$(PATH2)solve_5-500.c \
		$(PATH5)back_to_normal.c \
		$(PATH5)count_howmany.c \
		$(PATH5)count_utils.c \
		$(PATH5)count.c \
		$(PATH5)counter_howmany.c \
		$(PATH5)counter_utils.c \
		$(PATH5)counter.c \
		$(PATH3)utils.c \
		$(PATH3)arr_utils.c \
		$(PATH3)lis_utils.c \
		$(PATH3)lis.c \

FILES_C = $(PATH1)control.c \
		$(PATH1)split.c \
		$(PATH1)arrcheck.c \
		$(PATH4)instructions.c \
		$(PATH4)instructions2.c \
		$(PATH2)solve_2-5.c \
		$(PATH2)solve_5-500.c \
		$(PATH5)back_to_normal.c \
		$(PATH5)count_howmany.c \
		$(PATH5)count_utils.c \
		$(PATH5)count.c \
		$(PATH5)counter_howmany.c \
		$(PATH5)counter_utils.c \
		$(PATH5)counter.c \
		$(PATH3)utils.c \
		$(PATH3)arr_utils.c \
		$(PATH3)lis_utils.c \
		$(PATH3)lis.c \
		$(PATH6)checker_utils.c \
		$(PATH6)checker.c

OBJS =  $(FILES:.c=.o)

OBJS_C =  $(FILES_C:.c=.o)

push_swap: $(OBJS)
	$(CC) -o $(NAME) $^

all: push_swap bonus

deb: $(FILES)
	$(CC) $(CFLAGS) $^ -o $(NAME) -g

leak: $(FILES)
	$(CC) $(LEAK) $^ -o $(NAME)

bonus: $(OBJS_C)
	$(CC) -o $(CHECKER) $^

clean:
	$(RM) $(OBJS) $(OBJS_C)

fclean:
	$(RM) $(OBJS) $(OBJS_C) $(NAME) $(CHECKER)

re: clean all

.PHONY: all clean fclean re deb
