# Vladyslav Libov, vladyslav.libov@desy.de

FLAGS=`root-config --glibs --cflags` -g

FLAGS_OBJ=`root-config --cflags` -Wall -g

OBJ := tmp
SRC := src
INC := inc
LIB := lib

vpath %.o   $(OBJ)
vpath %.cxx $(SRC)
vpath %.C   $(SRC)
vpath %.h   $(INC)

all: libTXMLParser.so

TXMLParser.o: TXMLParser.cxx TXMLParser.h
	gcc -o $(OBJ)/$@ -c $< -I inc/ $(FLAGS_OBJ) -fPIC

libTXMLParser.so: TXMLParser.o
	gcc -shared -o $(LIB)/libTXMLParser.so tmp/TXMLParser.o

.PHONY: clean
clean:
	-rm -rf $(OBJ)/*.o
	-rm -rf $(LIB)/*so
