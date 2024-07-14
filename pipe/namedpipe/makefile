.PHONY:all
all:server client
server:server.cc component.hpp
	g++ -o $@ $^ -std=c++11
client:client.cc component.hpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -rf server client

