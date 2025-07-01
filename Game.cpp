#include"Game.h"
int main()
{
	// Window size, making, framerate limit, and event
	const int width = 1920, height = 1080;
	sf::RenderWindow window(sf::VideoMode(width, height), "Battleships", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(30);
	sf::Event ev;



	//************************************************************************************************** */
	//every picture	
	//startpage
	sf::Texture startpic; // Background image for the start page
	if (!startpic.loadFromFile("./assets/images/finalintro.jpg")){
		std::cout << "error loading start page pic\n";
	}
	sf::Sprite start;
	start.setTexture(startpic);
	// Game over page
	sf::Texture tex_over; // Game over texture
	if (!tex_over.loadFromFile("./assets/images/finalgameover.jpg")){ 
		std::cout << "game over texture not loaded\n";
	}
	sf::Sprite over;
	over.setTexture(tex_over);
	// Leaderboard page
	sf::Texture tex_leaderboard; // Leaderboard texture
	if (!tex_leaderboard.loadFromFile("./assets/images/finalldbrd.jpg"))
		std::cout << "leaderboard texture not loaded\n";
	sf::Sprite leaderboard;
	leaderboard.setTexture(tex_leaderboard);
	// Win texture
	sf::Texture tex_win; 
	if (!tex_win.loadFromFile("./assets/images/finalwin.jpg"))
		std::cout << "win texture not loaded\n";
	sf::Sprite win;
	win.setTexture(tex_win);
	// Background image for the ship placement and game play page
	sf::Texture back_sea; 
	if (!back_sea.loadFromFile("./assets/images/sea.jpg"))
	{
		std::cout << "error loading sea\n";
	}
	sf::Sprite sea;
	sea.setTexture(back_sea);
	//********************************************************************************************** */
	


	//********************************************************************************************** */
	//FONTS
	sf::Font font_last;
	if (!font_last.loadFromFile("./assets/fonts/times.ttf")){
		std::cout << "WIN PAGE font not loaded\n";
	}
	//INPUT NAME
	sf::Text inputText("", font_last, 34);
	inputText.setFillColor(sf::Color::Black);
	//place ship and computer thing: DURING GAMEPLAY
	sf::Font justfont;
	if (!justfont.loadFromFile("./assets/fonts/Font_for_startpage.ttf")){
		std::cout << "error loading font of gameplay page, named just font\n";
	}
	sf::Text place("Place Ship", justfont, 50);
	place.setPosition(offset1x + 170, offset1y - 70);
	sf::Text guess("Guess the Ship", justfont, 50);
	guess.setPosition(offset2x + 170, offset2y - 70);
	//WIN PAGE
	sf::Text txtagn;
	txtagn.setFont(font_last);
	txtagn.setString("Play Again");
	txtagn.setCharacterSize(34);
	txtagn.setFillColor(sf::Color::White);
	txtagn.setPosition(215, 910);
	
	sf::Text txtexit;
	txtexit.setFont(font_last);
	txtexit.setString("Exit Game");
	txtexit.setCharacterSize(34);
	txtexit.setFillColor(sf::Color::White);
	txtexit.setPosition(575, 910);
	//******************************************************************************************** */



	//******************************************************************************************** */
	//ALL MUSICS
	//Load background music
	 sf::Music backgroundMusic;
	 if (!backgroundMusic.openFromFile("./assets/audios/horror_background.ogg")) 
	 {
	 	std::cout<<"error loading music 1\n"; // Error loading music
	 }
	 backgroundMusic.setLoop(true); 
	 backgroundMusic.play();

	 sf::Music backgroundMusic2;
	 if (!backgroundMusic2.openFromFile("./assets/audios/horror_background2.ogg")) 
	 {
	 	std::cout << "error loading music 2\n"; // Error loading music
	 }
	 backgroundMusic2.setLoop(true);
	 ////game over
	 
	 sf::Music backgroundMusic3;
	 if (!backgroundMusic3.openFromFile("./assets/audios/over_background.ogg"))
	 {
		 std::cout << "error loading music 2\n"; // Error loading music
	 }
	 backgroundMusic3.setLoop(true);
	 backgroundMusic3.setVolume(100);
	 ////win page sound
	 //Load background music
	 sf::Music horror_win;
	 if (!horror_win.openFromFile("./assets/audios/horror_win.ogg"))
	 {
		 std::cout << "error loading horror win\n";
	 }
	 horror_win.setLoop(true);
	 horror_win.setVolume(100);
	 ////game over buffer
	 sf::SoundBuffer click2;
	 if (!click2.loadFromFile("./assets/audios/game_over.ogg"))
	 {
		 std::cout << "error has occured, load horror click\n";
	 }
	 sf::Sound game_over;
	 game_over.setBuffer(click2);
	 game_over.setVolume(100);
	 //the sound behind the leader board
	 sf::Music lb;
	 if (!lb.openFromFile("./assets/audios/leaderboard.ogg"))
	 {
		 std::cout << "error loading leader board music \n"; 
	 }
	 lb.setLoop(true);
	 
	 ////click sound
	 sf::SoundBuffer click1;
	 if (!click1.loadFromFile("./assets/audios/click1_audio.ogg")) 
	 {
	 	std::cout << "error has occured, load horror click\n";
	 }
	 sf::Sound start_click;
	 start_click.setBuffer(click1);
	 //explosion
	 sf::SoundBuffer explo;
	 if (!explo.loadFromFile("./assets/audios/explosion.ogg"))
	 {
		 std::cout << "error loading splash\n";

	 }
	 sf::Sound explosion;
	 explosion.setBuffer(explo);
	 explosion.setVolume(100);
	 
	 //sounds
	 sf::SoundBuffer spla;
	 if (!spla.loadFromFile("./assets/audios/splash.ogg"))
	 {
		 std::cout << "error loading splash\n";

	 }
	 sf::Sound splash;
	 splash.setBuffer(spla);
	 splash.setVolume(100);
	//******************************************************************************************************* */



	//******************************************************************************************************** */
	//BUTTONS WHICH ARE CLICKABLE
	sf::Texture stbut; // Start button
	stbut.loadFromFile("./assets/images/play.png");
	sf::Sprite start_button;
	start_button.setTexture(stbut);
	start_button.setPosition(60, 560);

	sf::Texture exbut; // Exit button
	exbut.loadFromFile("./assets/images/exit.png");
	sf::Sprite exit_button;
	exit_button.setTexture(exbut);

	sf::Texture viewlb; // View leaderboard button
	viewlb.loadFromFile("./assets/images/lboard.png");
	sf::Sprite view_button;
	view_button.setTexture(viewlb);

	sf::Texture trybut; //Play again button
	trybut.loadFromFile("./assets/images/again.png");
	sf::Sprite again_button;
	again_button.setTexture(trybut);

	//******************************************************************************************************** */



	//******************************************************************************************************** */
	//GRIDS AND HIT MISS SHOTS
	sf::Texture texture_bg; // Background image for the grid
	if (!texture_bg.loadFromFile("./assets/images/squarebackground.png"))
		std::cout << "ja mar ja chullo bhar pani mein\n";
	texture_bg.setRepeated(true);
	sf::Sprite bg;
	bg.setTexture(texture_bg);

	sf::Texture comp_hit; // Image for missed shot
	comp_hit.loadFromFile("./assets/images/hit.png");
	comp_hit.setRepeated(1);
	sf::Sprite hit;
	hit.setTexture(comp_hit);

	sf::Texture player_hit; // Image for hit shot
	player_hit.loadFromFile("./assets/images/hit2.png");
	player_hit.setRepeated(1);
	sf::Sprite phit;
	phit.setTexture(player_hit);
	//********************************************************************************************************* */



	//********************************************************************************************************* */
	// Ship Textures
	//ship1
	sf::Texture ship1;
	ship1.loadFromFile("./assets/images/ship1.png");
	sf::Sprite destroyer;
	destroyer.setTexture(ship1);
	//ship2
	sf::Texture ship2;
	ship2.loadFromFile("./assets/images/ship2.png");
	sf::Sprite submarine;
	submarine.setTexture(ship2);
	//ship3
	sf::Texture ship3;
	ship3.loadFromFile("./assets/images/ship3.png");
	sf::Sprite cruiser;
	cruiser.setTexture(ship3);
	//ship4
	sf::Texture ship4;
	ship4.loadFromFile("./assets/images/ship4.png");
	sf::Sprite battleship;
	battleship.setTexture(ship4);
	//ship5
	sf::Texture ship5;
	ship5.loadFromFile("./assets/images/ship5.png");
	sf::Sprite aircraft;
	aircraft.setTexture(ship5);
	//***************************************************************************************************************** */
	


	//mouse position
	float x, y;
	//computer placing the ships
	comp_place_ship();


	//main game starting
	while (window.isOpen())
	{
		//update here
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window.close();
			else if (ev.type == sf::Event::KeyPressed)
			{
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
			}
			

			if (start_page)
			{
				sf::Vector2f mousePos(sf::Mouse::getPosition(window));
				if (start_button.getGlobalBounds().contains(mousePos))
				{	
					start_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
					{
						start_page = false;
						ship_placement_page = true;
						backgroundMusic.stop();
						start_click.play();
						backgroundMusic2.play();
					}

				}
				else
					start_button.setColor(sf::Color::Blue);
				
				if (exit_button.getGlobalBounds().contains(mousePos))
				{
					exit_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
						window.close();
				}
				else
					exit_button.setColor(sf::Color::Blue);
				
			}
			
			else if (ship_placement_page)
			{
				bool leftMousePressed = false, rightMousePressed = false;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (!leftMousePressed)
					{
						leftMousePressed = true;
						x = (sf::Mouse::getPosition(window).x - offset1x) / 64.0;
						y = (sf::Mouse::getPosition(window).y - offset1y) / 64.0;
						place_ship(x, y, 'h', window);
					}
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					if (!rightMousePressed)
					{
						rightMousePressed = true;
						x = (sf::Mouse::getPosition(window).x - offset1x) / 64.0;
						y = (sf::Mouse::getPosition(window).y - offset1y) / 64.0;
						place_ship(x, y, 'v', window);
					}
				}
			}
			else if (game_play_page)
			{
				
			}
			else if (game_over_page)
			{
				sf::Vector2f mousePos(sf::Mouse::getPosition(window));
				if (exit_button.getGlobalBounds().contains(mousePos))
				{
					exit_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
						window.close();
				}
				else
					exit_button.setColor(sf::Color::Blue);
				
				if (again_button.getGlobalBounds().contains(mousePos))
				{
					again_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
					{
						reset();
						playerName.clear();
						game_over_page = false;
						start_page = true;
						backgroundMusic3.stop();
						backgroundMusic.play();
					}
				}
				else
					again_button.setColor(sf::Color::Blue);

				if (view_button.getGlobalBounds().contains(mousePos))
				{
					view_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
					{
						reset();
						game_over_page = false;
						leaderboard_page = true;
						game_over.stop();
						lb.play();
					}
				}
				else
					view_button.setColor(sf::Color::Blue);
			}
			else if (win_page)
			{
				if (ev.type == sf::Event::TextEntered)// && !nameSubmitted)
				{
					if (ev.text.unicode == '\b')
					{
						if (!playerName.empty())
							playerName.pop_back();
					}
					else if (ev.text.unicode == '\r')
					{
						nameSubmitted = true;
						std::cout << "Player Name: " << playerName << "\n";
					}
					else if (playerName.length() < 15)
					{
						playerName += static_cast<char>(ev.text.unicode);
					}
				}

				sf::Vector2f mousePos(sf::Mouse::getPosition(window));
				if (view_button.getGlobalBounds().contains(mousePos))
				{
					view_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
					{
						std::cout << "bache ko leaderboard dekhna hai :)" << std::endl;

						win_page = false;
						leaderboard_page = true;
						lb.play();
						lboard(playerName, score);
						horror_win.stop();
					}
				}
				else
					view_button.setColor(sf::Color::Blue);

				if (exit_button.getGlobalBounds().contains(mousePos))
				{
					exit_button.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
						window.close();
				}
				else
					exit_button.setColor(sf::Color::Blue);

			}
			else if (leaderboard_page)
			{
				sf::Vector2f mousePos(sf::Mouse::getPosition(window));
				if (txtexit.getGlobalBounds().contains(mousePos))
				{
					//txtexit.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
						window.close();
				}
				else
				//txtexit.setColor(sf::Color::White);

				if (txtagn.getGlobalBounds().contains(mousePos))
				{
					//txtagn.setColor(sf::Color::Red);
					if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
					{
						leaderboard_page = false;
						start_page = true;
						reset();
						playerName.clear();
						lb.stop();
						backgroundMusic.play();
					}
				}
				else
				{
					//txtagn.setColor(sf::Color::White);

				}
			}

		}
		

		window.clear();


		//draw objects here
		//window.draw(sea);

		if(start_page)
		{
			window.draw(start);
			window.draw(start_button);
			exit_button.setPosition(620, 560);
			window.draw(exit_button);
		}
		else if (ship_placement_page)
		{
			window.draw(sea);
			window.draw(place);
			draw_grid(window, bg, offset1x, offset1y);
			draw_grid(window, bg, offset2x, offset2y);
			
			if (pos[0])
			{

				destroyer.setPosition(ship_pos[0][0], ship_pos[0][1]);
				if (vertical[0])
					destroyer.setRotation(90);
				window.draw(destroyer);

			}
			if (pos[1])
			{

				submarine.setPosition(ship_pos[1][0], ship_pos[1][1]);
				if (vertical[1])
					submarine.setRotation(90);
				window.draw(submarine);
			}
			if (pos[2])
			{

				cruiser.setPosition(ship_pos[2][0], ship_pos[2][1]);
				if (vertical[2])
					cruiser.setRotation(90);
				window.draw(cruiser);
			}
			if (pos[3])
			{

				battleship.setPosition(ship_pos[3][0], ship_pos[3][1]);
				if (vertical[3])
					battleship.setRotation(90);
				window.draw(battleship);
			}
			if (pos[4])
			{

				aircraft.setPosition(ship_pos[4][0], ship_pos[4][1]);
				if (vertical[4])
					aircraft.setRotation(90);
				window.draw(aircraft);
			}
		}
		else if (game_play_page)
		{
			window.draw(sea);
			draw_grid(window, bg, offset1x, offset1y);
			draw_grid(window, bg, offset2x, offset2y);
			
			static bool turn = true;
			
			if (turn)
			{
					window.draw(guess);
					while (!shootplayer(window, explosion, splash))
						std::cout << "out of bound\n";
					score--;
					if (isover(compGrid))
					{
						std::cout << "unfortunately you win! :( Just a coincidence, no skill\n";
						game_play_page = false;
						win_page = true;
						backgroundMusic2.stop();
						horror_win.play();
					}
					else
						turn = !turn;
			}
			else
			{
				static sf::Clock delayclock;
				static bool delay = false;
				if (!delay)
				{
				
					delay = true;
					delayclock.restart();
					
				}
				if(delay&&delayclock.getElapsedTime().asSeconds()>=1.5)
				{
					computer_guess(explosion, splash);
					computer_score--;
					if (isover(Grid))
					{
						std::cout << "noob player go and learn how to play\n";
						game_play_page = false;
						game_over_page = true;

						backgroundMusic2.stop();
						backgroundMusic3.play();
						game_over.play();
					}
					else
						turn = !turn;
					delay = false;
				}
			}


			//drawing the ships
			
			window.draw(destroyer);
			window.draw(submarine);
			window.draw(cruiser);
			window.draw(battleship);
			window.draw(aircraft);

			//drawing the hits and misses
			draw_hit_miss(window, phit, hit, offset2x, offset2y, compGrid);
			draw_hit_miss(window, phit, hit, offset1x, offset1y, Grid);

		}
		else if (game_over_page)
		{
			window.draw(over);
			again_button.setPosition(1380, 620);
			window.draw(again_button);
			exit_button.setPosition(820, 830);
			window.draw(exit_button);
			view_button.setPosition(380, 620);
			window.draw(view_button);
		}
		else if (win_page)
		{
			//printing win
			window.draw(win);
			sf::Text text_name;
			text_name.setFont(font_last);
			text_name.setString("Your Name: ");
			text_name.setCharacterSize(36);
			text_name.setFillColor(sf::Color::Black);
			text_name.setPosition(100, 890);
			inputText.setString(playerName);
			inputText.setPosition(280, 890);
			window.draw(text_name);
			window.draw(inputText);
			view_button.setPosition(100, 940);
			window.draw(view_button);
			exit_button.setPosition(1400, 940);
			window.draw(exit_button);

		}
		else if (leaderboard_page)
		{
			//printing leaderboard
			window.draw(leaderboard);
			drawtxt(window, font_last);
			window.draw(txtagn);
			window.draw(txtexit);
		}


		window.display();
	}




	return 0;
}