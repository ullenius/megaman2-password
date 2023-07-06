.POSIX:
CC = c99
CFLAGS = -Wall -Wextra -Werror -pedantic

options.o: password.h options.c
	${CC} $(LDFLAGS) ${CFLAGS} -c options.c $(LDLIBS)
	
port.o: password.h port.c
	${CC} $(LDFLAGS) ${CFLAGS} -c port.c $(LDLIBS)
	
mm2pwd: options.o port.o
	${CC} $(LDFLAGS) ${CFLAGS} options.o port.o -o mm2pwd $(LDLIBS)

test_password.o: password.h test_passwords.c
	${CC} $(LDFLAGS) ${CFLAGS} -c test_passwords.c $(LDLIBS)

test: test_passwords.o port.o
	${CC} $(LDFLAGS) ${CFLAGS} test_passwords.o port.o -o unittest $(LDLIBS)
	./unittest

clean:
	rm -rf *.o unittest mm2pwd
