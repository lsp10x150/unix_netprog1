server: ./tcpserv01.o ./str_echo.o ../../../common/libunp.a ../../../common/config.h
	gcc ./tcpserv01.o ./str_echo.o -o ./tcp-server.out -lunp -I../../../common -L../../../common
client: ./tcpcli01.o ../../../common/libunp.a ../../../common/config.h ./str_cli.o
	gcc ./tcpcli01.o ./str_cli.o -o tcp-client.out -lunp -I../../../common -L../../../common
tcpcli01.o: ../tcpcli01.c ../../../common/libunp.a ../../../common/config.h 
	gcc ../tcpcli01.c -c -o ./tcpcli01.o -Wall -Wpedantic -lunp -I../../../common -L../../../common
tcpserv01.o: ../tcpserv01.c ../../../common/libunp.a ../../../common/config.h 
	gcc ../tcpserv01.c -c -o ./tcpserv01.o -Wall -Wpedantic -lunp -I../../../common -L../../../common
str_echo.o: ../str_echo.c ../../../common/libunp.a ../../../common/config.h 
	gcc ../str_echo.c -c -o ./str_echo.o -Wall -Wpedantic -lunp -I../../../common -L../../../common
str_cli.o: ../str_cli.c ../../../common/libunp.a ../../../common/config.h 
	gcc ../str_cli.c -c -o ./str_cli.o -Wall -Wpedantic -lunp -I../../../common -L../../../common
clean: tcp-server.out tcp-server.out
	rm *.out
	rm *.o
all: client server
