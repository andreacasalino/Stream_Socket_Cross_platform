mkdir bin
g++ -o ./bin/Server ./src/Server.cpp ../../src/Stream_Socket.cpp
g++ -o ./bin/Client ./src/Client.cpp ../../src/Stream_Socket.cpp
g++ -o ./bin/Repeater ./src/Repeater.cpp ../../src/Stream_Socket.cpp
