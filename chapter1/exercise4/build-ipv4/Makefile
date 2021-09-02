client: ../daytimetcpcli.c ../libunp.a ../config.h
	gcc ../daytimetcpcli.c -I.. -L.. -lunp -o ./time_client.out
server: ../daytimetcpsrv.c ../libunp.a ../config.h
	gcc ../daytimetcpsrv.c -I.. -L.. -lunp -o ./time_server.out
clean: time_client.out time_server.out
	rm time_client.out
	rm time_server.out
all: client server
