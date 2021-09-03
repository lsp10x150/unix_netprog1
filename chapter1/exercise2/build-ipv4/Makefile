client: ../daytimetcpcli.c ../../../common/libunp.a ../../../common/config.h
	gcc ../daytimetcpcli.c -I../../../common -L../../../common -lunp -o ./time_client.out
server: ../daytimetcpsrv.c ../../../common/libunp.a ../../../common/config.h
	gcc ../daytimetcpsrv.c -I../../../common -L../../../common -lunp -o ./time_server.out
clean: time_client.out time_server.out
	rm time_client.out
	rm time_server.out
all: client server
