deluser:delserver.o delmain.o
				gcc -o deluser delmain.o delserver.o
delserver.o:delserver.c delserver.h
				gcc -c delserver.c delserver.h
delmain.o:delserver.h delmain.c
				gcc -c delserver.h delmain.c
