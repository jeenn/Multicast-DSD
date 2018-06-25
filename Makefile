emisor: emisor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o
	g++ -std=c++11 emisor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o -o ./emisor
receptor: receptor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o
	g++ -std=c++11 receptor.o PaqueteDatagrama.o SocketMulticast.o SocketDatagrama.o -o ./receptor
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ -std=c++11 -Wall -c PaqueteDatagrama.cpp
SocketMulticast.o: SocketMulticast.cpp
	g++ -std=c++11 -Wall -c SocketMulticast.cpp
SocketDatagrama.o: SocketDatagrama.cpp
	g++ -std=c++11 -Wall -c SocketDatagrama.cpp
emisor.o: emisor.cpp
	g++ -std=c++11 -Wall -c emisor.cpp
receptor.o: receptor.cpp
	g++ -std=c++11 -Wall -c receptor.cpp
clean:
	rm *.o *.out ./emisor ./receptor