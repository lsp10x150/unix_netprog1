client: ./tcpcli01.o ../../../common/libunp.a ../../../common/config.h 
	gcc ./tcpcli01.o -o tcp-client.out -lunp -I../../../common -L../../../common
tcpcli01.o: ../tcpcli01.c ../../../common/libunp.a ../../../common/config.h
	gcc ../tcpcli01.c -c -o ./tcpcli01.o -Wall -Wpedantic -I../../../common -L../../../common
str_cli.o: ../str_cli.c ../../../common/libunp.a ../../../common/config.h
	gcc ../str_cli.c -c -o ./str_cli.o -Wall -Wpedantic -I../../../common -L../../../common
clean: tcp-server.out tcp-server.out
	rm tcp-client.out
	rm *.o
all: client server
