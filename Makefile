CC = c99
CFLAGS = -Wall -Werror -pedantic

options.o: password.h options.c
	${CC} -c options.c
	
port.o: password.h port.c
	${CC} -c port.c
	
mm2pwd: options.o port.o
	${CC} options.o port.o  -o mm2pwd

test_password.o: password.h test_passwords.c
	${CC} -c test_passwords.c

unittest: test_passwords.o port.o
	${CC} test_passwords.o port.o -o unittest
	./unittest
