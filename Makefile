CC=gcc
CFLAGS += -Wall -Wextra -std=c11 -pedantic -g -I include -s -I -I../install_dir/include -L../install_dir/lib
LDFLAGS += -lm -lSDL2 -Linstall_dir/lib
BFILE = bin/
OFILE = obj/
SFILE  = src/
IFILE = include/
DFILE = dist/
LFILE = levels/
OBJ = main.o grid.o player.o sdl2.o event.o
ILIB = install_dir/include
LLIB = install_dir/lib

vpath %.h ${IFILE}
vpath %.c ${SFILE}
vpath %.o ${OFILE}
vpath %.txt ${LFILE}



main: $(OBJ)
	@mkdir -p ${BFILE}
	$(CC) -o ${BFILE}$@ ${OFILE}main.o ${OFILE}grid.o ${OFILE}player.o ${OFILE}sdl2.o $(OFILE)event.o ${LDFLAGS}

%.o: %.c 
	@mkdir -p ${OFILE}
	$(CC) $(CFLAGS) -I${IFILE} -I${ILIB} -L${LLIB} -o  ${OFILE}/$@ -c $<


LD_LIBRARY_PATH =../install_dir/lib

clean:
	rm -rf  ${DFILE} ${BFILE} ${OFILE}

install_sdl2:
	cd SDL2 && ./configure --prefix=$(PWD)/../install_dir
	cd SDL2 &&  make install -j6

docs:
	doxygen Doxyfile

archive:
	@mkdir -p dist
	tar -cvJf dist/ZARE_Alireza.tar.gz src/*.c include/*.h levels/*.txt README.md Makefile SDL2/
