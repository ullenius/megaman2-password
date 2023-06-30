CC = c99
CFLAGS = -Wall -Werror -pedantic

options.o: password.h options.c
	${CC} ${CFLAGS} -c options.c
	
port.o: password.h port.c
	${CC} ${CFLAGS}  -c port.c
	
mm2pwd: options.o port.o
	${CC} ${CFLAGS} options.o port.o  -o mm2pwd

test_password.o: password.h test_passwords.c
	${CC} ${CFLAGS} -c test_passwords.c

unittest: test_passwords.o port.o
	${CC} ${CFLAGS} test_passwords.o port.o -o unittest
	./unittest

clean:
	rm -rf *.o unittest mm2pwd
