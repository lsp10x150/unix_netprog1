client: ../udpcli01.c ./dg_cli.o ../../../common/libunp.a ../../../common/config.h
	gcc ../udpcli01.c dg_cli.o -I../../../common -L../../../common -lunp -o ./udp_client.out
server: ../udpserv01.c ./dg_echo.o ../../../common/libunp.a ../../../common/config.h
	gcc ../udpserv01.c dg_echo.o -I../../../common -L../../../common -lunp -o ./udp_server.out
dg_cli.o: ../dg_cli.c
	gcc ../dg_cli.c -c -o dg_cli.o -lunp -L../../../common -I../../../common
dg_echo.o: ../dg_echo.c
	gcc -c ../dg_echo.c -o dg_echo.o -lunp -L../../../common -I../../../common
clean: 
	rm *.out
	rm *.o
all: client server
