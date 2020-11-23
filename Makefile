options.o: password.h options.c
	cc -c options.c
	
port.o: password.h port.c
	cc -c port.c
	
mm2pwd: options.o port.o
	cc options.o port.o  -o mm2pwd

test_password.o: password.h test_passwords.c
	cc -c test_passwords.c

unittest: test_passwords.o port.o
	cc test_passwords.o port.o -o unittest
	./unittest
