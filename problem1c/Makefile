#
#  Makefile for Goldification
#


LIBDIR =  -Wl,-rpath,-lm  -ltiff

CFLAGS = -g3 -Wno-deprecated

CC = g++

.SUFFIXES: .o .cpp

.cpp.o: 
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $*.o $<


ALL.O =  HDRtest.o figio.o 

HDRtest: $(ALL.O)
	$(CC) $(CFLAGS) -o $@ $(ALL.O) $(INCLUDE) $(LIBDIR) $(LIBS)

clean:
	rm -f $(ALL.O) HDRtest
