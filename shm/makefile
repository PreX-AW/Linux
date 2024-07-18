all:server client
server:server.cc common.hpp
	g++ -o $@ $^ -std=c++11
client:client.cc common.hpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -rf server client
