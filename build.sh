#g++ src/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
g++ -c src/main.cpp -I SFML-2.6.2/include
#g++ src/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
#export LD_LIBRARY_PATH=/SFML-2.3.2/lib && ./main Test.bin
#export LD_LIBRARY_PATH=<sfml-install-path>/lib && ./sfml-app

#g++ src/main.cpp -I SFML-2.5.1-macos-clang/include -o main -L SFML-2.5.1-macos-clang/lib -lsfml-graphics -lsfml-window -lsfml-system
g++ main.o -o sfml-app -L SFML-2.6.2/lib -lsfml-graphics -lsfml-window -lsfml-system
export LD_LIBRARY_PATH=SFML-2.6.2/lib && ./sfml-app Test.bin
