IDIR =../Acertou-Miseravi-master/include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../Acertou-Miseravi-master/src
LDIR =../Acertou-Miseravi-master

LIBS=-lm

_DEPS = project_headers.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o functions.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

acertoMizeravi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

