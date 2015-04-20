populate:populate.c

generate:
	gcc populate.c -I/usr/include/mysql -lmysqlclient -o populate

retrieve:
	gcc fetch.c -I/usr/include/mysql -lmysqlclient -o fetch

all:
	gcc fetch.c -I/usr/include/mysql -lmysqlclient -o fetch
	gcc populate.c -I/usr/include/mysql -lmysqlclient -o populate
