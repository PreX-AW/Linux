.PHONY:all
all:server client1 client2
server:server.cc common.hpp
	g++ -o $@ $^ -std=c++11
client1:client1.cc common.hpp
	g++ -o $@ $^ -std=c++11
client2:client2.cc common.hpp
	g++ -o $@ $^ -std=c++11
.PHONY:clean
clean:
	rm -rf server client1 client2
