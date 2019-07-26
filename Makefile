LIB = libft/libft.a
PNME = push_swap
CNME = checker
FLGS = -Wall -Werror -Wextra
DBFLG = -Wall -Werror -Wextra -g
CSRC = checker.c \
		read_input.c \
		validator.c \
		rot_operations_01.c \
		rot_operations_02.c \
		rot_operations_03.c \
		list_operations.c \
		list_counter.c \
		sub_validator.c \
		$(LIB)
PSRC = push_swap.c \
		do_sort.c \
		validator.c \
		sub_validator.c \
		rot_operations_01.c \
		rot_operations_02.c \
		rot_operations_03.c \
		list_operations.c \
		list_counter.c \
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
