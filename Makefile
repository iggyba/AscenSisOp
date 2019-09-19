CC = gcc
IDIR = .
CFLAGS = -I$(IDIR) -std=gnu99
LIBS = -lpthread
OBJ = estruc.o elevFun.o perFun.o cola.o schedFun.o
DEPS = estruc.h

%.o: %.c $(DEPS)
	$(CC) -Wall -c -o $@ $< $(CFLAGS)


estruc: $(OBJ) 
	$(CC) -Wall -o $@ $^ $(CFLAGS) $(LIBS)

# clean out the dross
clean:
	rm -f estruc  *~ *.o 
