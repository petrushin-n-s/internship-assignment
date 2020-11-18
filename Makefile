TARGET = hellobye

PREFIX = /usr/local/bin

.PHONY: all clean install uninstall staticlib sharedlib

all: $(TARGET)
	
clean:
			rm -rf $(TARGET) *.o *.a *.so
			
staticlib: main.o libhellobye.a
			gcc -o $(TARGET) main.o -L. -lhellobye
 
sharedlib: main.o libhellobye.so
			gcc -o $(TARGET) main.o -L. -lhellobye -Wl,-rpath,.

main.o: main.c
			gcc -c -o main.o main.c
			
hello.o: hello.c
			gcc -c -o hello.o hello.c
			
bye.o: bye.c
			gcc -c -o bye.o bye.c
			
libhellobye.a: hello.o bye.o
			ar rc libhellobye.a hello.o bye.o
        
libhellobye.so: hello.o bye.o
			gcc -shared -o libhellobye.so hello.o bye.o
	
$(TARGET): main.o hello.o bye.o
			gcc -o $(TARGET) main.o hello.o bye.o

install:
			install $(TARGET) $(PREFIX)
			
uninstall:
			rm -rf $(PREFIX)/$(TARGET)
