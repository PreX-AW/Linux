.PHONY:all
all:
	server client
server:server.cc component.hpp
	g++ -o $@ $^ -std=c11
client:client.cc component.hpp
	g++ -o $@ $^ -std=c11
.PHONY:clean
	rm -rf server client

