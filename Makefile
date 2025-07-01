link: compile
	g++ Game.o -o sfml-app -L"Path to library folder in SFML folder" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network  

compile:
    g++ -c Game.cpp -I"Path to include folder in SFML folder"