#pragma once

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<fstream>
#include<sstream>
#include<algorithm>
//SFML LIBRARIES
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

//page switching variables
bool start_page = true,
ship_placement_page = false,
game_play_page = false,
game_over_page = false,
win_page = false,
leaderboard_page = false;

bool nameSubmitted = false;
std::string playerName = "";
int score = 100;
int computer_score = 100;
//offset variables
const int startx = 360, starty = 60;
const int offset1x =210 , offset1y = 220, offset2x = 1070;
const int& offset2y = offset1y;


//grids
char Grid[10][11] = {
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww"
};
char compGrid[10][11] = {
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww"
};
char hit_grid[10][11] = {
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww",
	"wwwwwwwwww"
};



//ships
std::string destroyer = "ss",
submarine = "sss", cruiser = "sss",
battleship = "ssss", aircraft = "sssss";

//variables
float ship_pos[5][2] = {
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0}
};
bool pos[5] = { 0,0,0,0,0 };
bool vertical[5] = { 0,0,0,0,0 };
bool comp_pos[5] = { 0,0,0,0,0 };
int loop = 0;
int global_r, global_c;

//the function to draw the grids on the main gameplay page
void draw_grid(sf::RenderWindow& window, sf::Sprite& sprite, const int &offx, const int& offy)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			sprite.setPosition(offx + j * 64, offy + i * 64);
			window.draw(sprite);
		}
	}
}

void draw_hit_miss(sf::RenderWindow& window, sf::Sprite& hit, sf::Sprite& miss, const int& offx, const int& offy, char grid[10][11])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 'h')
			{
				hit.setPosition(j * 64 + offx, i * 64 + offy);
				window.draw(hit);
			}
			else if (grid[i][j] == 'm')
			{
				miss.setPosition(j * 64 + offx, i * 64 + offy);
				window.draw(miss);
			}
		}
	}
}




int call_ships()
{
	int length = 0;

	if (loop == 0)
	{
		length = destroyer.length();
		std::cout << "Destroyer,length=" << length << std::endl;
	}
	else if (loop == 1)
	{
		length = submarine.length();
		std::cout << "submarine,length=" << length << std::endl;
	}
	else if (loop == 2)
	{
		length = cruiser.length();
		std::cout << "cruiser,length=" << length << std::endl;
	}
	else if (loop == 3)
	{
		length = battleship.length();
		std::cout << "battleship,length=" << length << std::endl;
	}
	else if (loop == 4)
	{
		length = aircraft.length();
		std::cout << "aircraft,length=" << length << std::endl;
	}
	if (loop == 5)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				std::cout << Grid[i][j] << "   ";
			std::cout << "\n";

		}
		loop++;
		ship_placement_page = false;
		game_play_page = true;
		
		length = INT_MAX;
		
	}



	return length;
}


bool can_place_ship(const float& coli, const float& rowi, const char& orient)
{
	int row = rowi;
	int col = coli;
	if (orient == 'h')
	{
		int length = call_ships();
		if (length + coli > 10)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (Grid[row][col + i] != 'w')
				return false;
		}
		for (int i = 0; i < length; i++)
		{
			Grid[row][col + i] = 's';

		}
		return true;
	}
	else if (orient == 'v')
	{
		int length = call_ships();
		if (length + rowi > 10)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (Grid[row + i][col] != 'w')
				return false;
		}
		for (int i = 0; i < length; i++)
		{
			Grid[row + i][col] = 's';

		}
		return true;
	}
	return true;
}


void place_ship(float& coli, float& rowi, char orient, sf::RenderWindow& window)
{

	while (!can_place_ship(coli, rowi, orient))
	{

		bool leftMousePressed = false;
		bool rightMousePressed = false;

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			if (sf::Mouse::isButtonPressed)
			{
				if (ev.mouseButton.button == sf::Mouse::Left)
				{
					if (!leftMousePressed)
					{
						leftMousePressed = true;
						orient = 'h';
						coli = (sf::Mouse::getPosition(window).x-offset1x) / 64.0;
						rowi = (sf::Mouse::getPosition(window).y-offset1y) / 64.0;
					}
				}
				else if (ev.mouseButton.button == sf::Mouse::Right)
				{
					if (!rightMousePressed)
					{
						rightMousePressed = true;
						orient = 'v';
						coli = (sf::Mouse::getPosition(window).x-offset1x) / 64.0;
						rowi = (sf::Mouse::getPosition(window).y-offset1y) / 64.0;
					}
				}
			}
		}
	}
	int col = coli;
	int row=rowi;
	if (loop < 5)
	{
		ship_pos[loop][0] = col * 64+offset1x;
		ship_pos[loop][1] = row * 64+offset1y;
		
		if (orient == 'v')
		{
			ship_pos[loop][0] += 64;
			vertical[loop] = true;
		}
		pos[loop++] = true;
	}


}
void print_grid_real(char grid[10][11])
{
	std::cout << "\n\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			std::cout << grid[i][j] << "   ";
		std::cout << std::endl;

	}
}

bool can_place_ship_computer(const int& col, const int& row, const char& orient, char grid[][11])
{
	if (orient == 'h')
	{
		int length = call_ships();
		if (length + col > 10)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (grid[row][col + i] != 'w')
				return false;
		}
		for (int i = 0; i < length; i++)
		{
			grid[row][col + i] = 's';

		}
		return true;
	}
	else if (orient == 'v')
	{
		int length = call_ships();
		if (length + row > 10)
			return false;
		for (int i = 0; i < length; i++)
		{
			if (grid[row + i][col] != 'w')
				return false;
		}
		for (int i = 0; i < length; i++)
		{
			grid[row + i][col] = 's';

		}
		return true;
	}
	return true;
}



void comp_place_ship()
{
	srand(time(0));
	int col, row;
	char orient;
	for (int i = 0; i < 5; i++)
	{
		do
		{
			col = rand() % 10;
			row = rand() % 10;
			if (rand() % 2 == 0)
				orient = 'h';
			else
				orient = 'v';
		} while (!(can_place_ship_computer(col, row, orient, compGrid)));
		comp_pos[loop++] = true;
	}
	print_grid_real(compGrid);
	loop = 0;
	

}


// void print_grid()
// {
// 	//system("CLS");
// 	std::cout << "\n\n\nhit grid\n";
// 	for (int i = 0; i < 10; i++)
// 	{
// 		for (int j = 0; j < 10; j++)
// 			std::cout << hit_grid[i][j] << "   ";
// 		std::cout << std::endl;

// 	}

// 	std::cout << "\n\n\nGrid\n";
// 	for (int i = 0; i < 10; i++)
// 	{
// 		for (int j = 0; j < 10; j++)
// 			std::cout << Grid[i][j] << "   ";
// 		std::cout << std::endl;

// 	}
// }







//from here is the mechanism of computer hitting 
//players grid like ai

void computer_hit_grid_update(const int& row, const int& col)
{
	hit_grid[row][col] = 'h';
	
}



bool check_hit_repetition(const int row, const int col)
{
	//this function makes sure that only that cell is hit which has not been hit before

	if (hit_grid[row][col] == 'h')
		return false;
	return true;
}


bool check_hit(const int& row, const int& col, sf::Sound& explosion, sf::Sound& splash)
{
	if (Grid[row][col] == 's')
	{
		explosion.play();
		Grid[row][col] = 'h';
		return true;
	}
	else
	{
		splash.play();
		Grid[row][col] = 'm';
		return false;
	}
}
bool hit_random(int& row, int& col, sf::Sound& explosion, sf::Sound& splash)
{
	//using h for hit and m for miss
	srand(time(0));
	do
	{
		row = rand() % 10;
		col = rand() % 10;
	} while (!check_hit_repetition(row, col));
	global_r = row, global_c = col;
	computer_hit_grid_update(row, col);
	
	if (check_hit(row, col,explosion,splash))
	{
		
		return true;
	}
	return false;
}

//functions for ai
bool will_go_right(const int& row, const int& col)
{
	if (col >= 9)
		return false;

	return true;
}
bool will_go_left(const int& row, const int& col)
{
	if (col <= 0)
		return false;

	return true;
}
bool will_go_up(const int& row, const int& col)
{
	if (row <= 0)
		return false;

	return true;
}
bool will_go_down(const int& row, const int& col)
{
	if (row >= 9)
		return false;

	return true;
}

bool ai_hit(int& row, int& col, sf::Sound& explosion, sf::Sound& splash,bool& ai_behaviour)
{
	
	// now everything is in ai hit
	// this ai hit will hit vertical and horizontal
	static bool left = true, right = true, up = true, down = true;

	// Start with trying to move right

	if (right && will_go_right(row, col)) 
	{
		col++;
		
		computer_hit_grid_update(row, col);
		right = (check_hit(row, col,explosion,splash) &&  will_go_right(row, col)   && check_hit_repetition(row, col + 1)); // Update the state of right

		if (!right)
			row = global_r, col = global_c;
		return true;
	}
	// If moving right is blocked, try moving left
	else if (left && will_go_left(row, col)) 
	{
		col--;
		
		computer_hit_grid_update(row, col);
		left = (check_hit(row, col, explosion, splash) && will_go_left(row, col)  && check_hit_repetition(row, col - 1)); // Update the state of left
		if (!left)
			row = global_r, col = global_c;
		return true;
	}
	// If moving left is blocked, try moving up
	else if (up && will_go_up(row, col))
	{
		row--;
		
		computer_hit_grid_update(row, col);
		up = (check_hit(row, col, explosion, splash) && will_go_up(row, col) && check_hit_repetition(row - 1, col)); // Update the state of up
		if (!up)
			row = global_r, col = global_c;
		return true;
	}
	// If moving up is blocked, try moving down
	else if (down && will_go_down(row, col)) 
	{
		row++;
		
		computer_hit_grid_update(row, col);
		down = ( check_hit(row, col, explosion, splash) && will_go_down(row, col) && check_hit_repetition(row + 1, col)); // Update the state of down
		if (!down)
			row = global_r, col = global_c;
		return true;
	}

	else 
	{
		
		ai_behaviour = hit_random(row, col, explosion, splash);
		right = true, left = true, down = true, up = true;
		return ai_behaviour;
	}

	

}


void computer_guess( sf::Sound & explosion, sf::Sound& splash)
{

	static int col, row;

	static bool ai_behaviour = false;
	
	if (!ai_behaviour)
	{
		ai_behaviour = hit_random(row, col,explosion,splash);

	}
	else
	{
		ai_behaviour = ai_hit(row, col,explosion,splash,ai_behaviour);
	}
	
	
}

bool isover(char grid[10][11])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (grid[i][j] == 's')
				return false;
		}
	}
	return true;
}

////ali hassan, two functions, player hit and leader board
bool shootplayer(sf::RenderWindow& window,sf::Sound&explosion,sf::Sound&splash)
{
	bool fired = false;
	while (!fired)
	{
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed && (event.mouseButton.button == sf::Mouse::Left||event.mouseButton.button==sf::Mouse::Right))
			{
				float coli = (sf::Mouse::getPosition(window).x-offset2x) / 64.0;
				float rowi = (sf::Mouse::getPosition(window).y-offset2y) / 64.0;
				if (!(coli>=0&&coli<10&&rowi>=0&&rowi<10))
					return false;
				int col = coli;
				int row = rowi;
				if (compGrid[row][col] == 's')
				{
					compGrid[row][col] = 'h';
					std::cout << "yay hit\n";
					explosion.play();
					fired = true;
				}
				else if (compGrid[row][col] == 'w')
				{
					compGrid[row][col] = 'm';
					std::cout << "mis :(\n";
					splash.play();
					fired = true;
				}
				else
					std::cout << "kitni dafa idher fire kare ga bewakoof\n";
			}
		}
	}
	return true;
}

void lboard(std::string name, int& score)
{
	std::string tmpdata;
	std::ifstream fr("./assets/texts/leaderboard.txt");
	std::string names[4];
	int scores[4];
	int i = 0;
	while (std::getline(fr, tmpdata))
	{
		std::stringstream sr(tmpdata);
		sr >> names[i] >> scores[i];
		i++;
	}
	fr.close();

	for (i = 0; i < 4; i++)
	{
		if (score > scores[i])
		{
			std::swap(score, scores[i]);
			std::swap(name, names[i]);
		}
	}

	std::ofstream fw("./assets/texts/leaderboard.txt");
	for (i = 0; i < 4; i++)
		fw << names[i] << " " << scores[i] << std::endl;

	fw.close();
}


void drawtxt(sf::RenderWindow& window, sf::Font& font_last)
{
	std::ifstream fr("./assets/texts/leaderboard.txt");
	std::string dispname; int dispscore; std::string tmpdata;
	int i = 0;
	while (std::getline(fr, tmpdata))
	{
		std::stringstream sr(tmpdata);
		sr >> dispname >> dispscore;

		sf::Text text1;
		text1.setFont(font_last);
		text1.setString(dispname);
		text1.setCharacterSize(28);
		text1.setFillColor(sf::Color::White);
		text1.setPosition(360, 480 + i * 100); // for score-> 700, 480
		

		tmpdata = std::to_string(dispscore);
		sf::Text text2;		
		text2.setFont(font_last);
		text2.setString(tmpdata);
		text2.setCharacterSize(28);
		text2.setFillColor(sf::Color::White);
		text2.setPosition(480, 480 + i * 100); // for score-> 700, 480
		window.draw(text1);
		window.draw(text2);

		i++;
	}
	fr.close();
}





////RESET FUNCTION
////VERY IMPRTANT, KEEP THIS RESET FUNCTION AT THE VERY END, PLEASE
void reset()
{
	system("CLS");
	loop = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Grid[i][j] = 'w';
			compGrid[i][j] = 'w';
			hit_grid[i][j] = 'w';
		}
	}
	score = 100;
	computer_score = 100;
	nameSubmitted = false;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ship_pos[i][j] = 0;
			
		}
	}
	for (int i = 0; i < 5; i++)
	{
		pos[i] = 0;
		vertical[i] = 0;
		comp_pos[i] = 0;
	}
	playerName = "";
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << compGrid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << hit_grid[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << Grid[i][j] << " ";
		}
		std::cout << std::endl;
	}

	comp_place_ship();
	loop = 0;
}