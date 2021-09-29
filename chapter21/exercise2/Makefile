udp_cli.out: udpcli06.c dg_cli.o
	gcc udpcli06.c dg_cli.o -I../../common -L../../common -lunp -o udp_cli.out
dg_cli.o:	dgclimcast6.c
	gcc dgclimcast6.c -c -I../../common -L../../common -lunp -o dg_cli.o

