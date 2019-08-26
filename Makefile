LIB = libft/libft.a
PNME = push_swap
CNME = checker
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -g
CSRC = checker.c \
		src/read_input.c \
		src/validator.c \
		src/rot_operations_01.c \
		src/rot_operations_02.c \
		src/rot_operations_03.c \
		src/list_operations.c \
		src/sub_validator.c \
		src/sub_list_operations.c \
		$(LIB)
PSRC = push_swap.c \
		src/do_sort.c \
		src/do_sort_sub.c \
		src/validator.c \
		src/sub_validator.c \
		src/rot_operations_01.c \
		src/rot_operations_02.c \
		src/rot_operations_03.c \
		src/read_input.c \
		src/list_operations.c \
		src/sub_list_operations.c \
		$(LIB)

all: $(CNME) $(PNME)

$(CNME):
	gcc $(FLGS) $(CSRC) -o $(CNME)

$(PNME):
	gcc $(FLGS) $(PSRC) -o $(PNME)

db:
	gcc $(DBFLG) $(CSRC) -o $(CNME)
	gcc $(DBFLG) $(PSRC) -o $(PNME)

clean:
	rm -fr $(CNME) $(PNME) $(CNME).dSYM $(PNME).dSYM

re: clean all

redb: clean db
