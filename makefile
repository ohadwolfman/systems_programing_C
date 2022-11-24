CC = gcc
CFLAGS = -Wall -g
.PHONY: loops recursives recursived loopd all clean

BASIC =  basicClassification
ACL = advancedClassificationLoop
ACR = advancedClassificationRecursion


all: loops recursives loopd recursived mains maindloop maindrec



basicClassification.o: $(BASIC).c $(BASIC).h
	$(CC) $(CFLAGS) -c $<

advancedClassificationLoop.o: $(ACL).c $(ACL).h
	$(CC) $(CFLAGS) -c $<

advancedClassificationRecursion.o: $(ACR).c $(ACR).h
	$(CC) $(CFLAGS) -c $<

main.o: main.c $(BASIC).h $(ACL).h $(ACR).h
	$(CC) $(CFLAGS) -c $<




loops: $(BASIC).o $(ACL).o
	ar -rc libclassloops.a $^

recursives: $(BASIC).o $(ACR).o
	ar -rc libclassrec.a $^
	
recursived: $(BASIC).o $(ACR).o
	$(CC) $(CFLAGS) -fPIC -shared -o libclassrec.so $^
	
loopd: $(BASIC).o $(ACL).o
	$(CC) $(CFLAGS) -fPIC -shared -o libclassloops.so $^
	
mains: main.o libclassrec.a
	$(CC) $(CFLAGS) main.o -L. -lclassrec -o mains -lm
	
maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) main.c -L. -lclassloops -o maindloop -lm
	
maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) main.c -L. -lclassrec -o maindrec -lm
	
clean:
	rm -f *.o *.so *.a mains maindloop maindrec
