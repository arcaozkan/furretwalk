#include "windows.h"
#include "Engine.h"
#include "SFML/Audio.hpp"
#include <ctime>
Engine::Engine()
{
    // Get the screen resolution and create an SFML window and View
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y),
        "Simple Game Engine",
        Style::Fullscreen);
	eaten=false;
	hit=false;
    // Load the background into the texture
    // Be sure to scale this image to your screen size
	RandGen randmap;
	map=randmap.RandInt(1,4);
	std::string whichmaps=std::to_string(map);
    m_BackgroundTexture.loadFromFile("Images/background"+whichmaps+".png");
	m_food.setMap(map);
	m_food2.setMap(map);
	m_food3.setMap(map);
    // Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
 
}
 
void Engine::start()
{
    // Timing
    Clock clock;
	Clock gametime;
	Clock candyclock;
	bool clockcheck=false;
 	sf::Music music;
	if (!music.openFromFile("Audio/furret.wav"))
		return; // error
	music.play();
	music.setLoop(true);
	sf::Text score;
	sf::Font font;
	sf::Text score2;
	font.loadFromFile("sansation.ttf");
	score.setFont(font);
	std::string s=std::to_string(m_Bob.score);
	int dt2 = gametime.getElapsedTime().asSeconds();
	std::string gametimes=std::to_string(dt2);
	score.setString("Score: " + s + "   " + gametimes);
	score.setCharacterSize(48);
	if(map!=5)
		score.setFillColor(sf::Color::Black);
	else
		score.setFillColor(sf::Color::White);
	score.setStyle(sf::Text::Bold);
	bool gameover=false;
	sf::SoundBuffer buffereat;
	buffereat.loadFromFile("Audio/eat.wav");
	sf::Sound sound1;
	sound1.setBuffer(buffereat);
	sf::SoundBuffer bufferhit;
	bufferhit.loadFromFile("Audio/hit.wav");
	sf::Sound sound2;
	sound2.setBuffer(bufferhit);
    while (m_Window.isOpen())
    {
		if(eaten==true){

			sound1.play();
			eaten=false;
		}
		if(hit==true){
			sound2.play();
			hit=false;
		}
        // Restart the clock and save the elapsed time into dt
        Time dt = clock.restart();
 
        // Make a fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
        input();
		if(Keyboard::isKeyPressed(Keyboard::M)&& gameover==true){ //secret level MO
			if(Keyboard::isKeyPressed(Keyboard::O)&& gameover==true){
				gameover=false;
				gametime.restart();
				m_Bob.score=0;
				map=5;
				std::string whichmaps=std::to_string(map);
				m_BackgroundTexture.loadFromFile("Images/background"+whichmaps+".png");
				m_food=food();
				m_food2=food();
				m_food3=food();
				m_food.setSpeed(100);
				m_food2.setSpeed(100);
				m_food3.setSpeed(100);
				m_stone.setSpeed(100);
				m_stone2.setSpeed(100);
				m_candy.setSpeed(100);
				m_Bob.jumpreach=400;
				m_food.setMap(map);
				m_food2.setMap(map);
				m_food3.setMap(map);
				m_food.m_Position.y=1100;
				m_food2.m_Position.y=1100;
				m_food3.m_Position.y=1100;
				m_candy.m_Position.y=1100;
				m_stone.m_Position.y=1100;
				m_stone2.m_Position.y=1100;
				score.setFillColor(sf::Color::White);
				m_Bob.setSpeed(300);
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::S)&& gameover==true){ //secret level SU
			if(Keyboard::isKeyPressed(Keyboard::U)&& gameover==true){
				gameover=false;
				gametime.restart();
				m_Bob.score=0;
				map=6;
				std::string whichmaps=std::to_string(map);
				m_BackgroundTexture.loadFromFile("Images/background"+whichmaps+".png");
				m_food=food();
				m_food2=food();
				m_food3=food();
				m_Bob.jumpreach=600;
				m_stone.setSpeed(300);
				m_stone2.setSpeed(300);
				m_candy.setSpeed(300);
				m_food.setMap(map);
				m_food2.setMap(map);
				m_food3.setMap(map);
				m_food.m_Position.y=1100;
				m_food2.m_Position.y=1100;
				m_food3.m_Position.y=1100;
				m_candy.m_Position.y=1100;
				m_stone.m_Position.y=1100;
				m_stone2.m_Position.y=1100;
				m_Bob.setSpeed(400);
				score.setFillColor(sf::Color::Black);
			}
		}
		 if (Keyboard::isKeyPressed(Keyboard::Space)&& gameover==true) //Setting Up New Game
			{
				gameover=false;
				gametime.restart();
				m_Bob.score=0;
				RandGen randmap;
				int newmap=randmap.RandInt(1,4);
				while(newmap==map){
					newmap=randmap.RandInt(1,4);
				}
				map=newmap;
				std::string whichmaps=std::to_string(map);
				m_BackgroundTexture.loadFromFile("Images/background"+whichmaps+".png");
				m_food=food();
				m_food2=food();
				m_food3=food();
				m_Bob.jumpreach=600;
				m_food.setMap(map);
				m_food2.setMap(map);
				m_food3.setMap(map);
				m_stone.setSpeed(300);
				m_stone2.setSpeed(300);
				m_candy.setSpeed(300);
				m_food.m_Position.y=1100;
				m_food2.m_Position.y=1100;
				m_food3.m_Position.y=1100;
				m_candy.m_Position.y=1100;
				m_stone.m_Position.y=1100;
				m_stone2.m_Position.y=1100;
				score.setFillColor(sf::Color::Black);
		 }
		 if(!gameover)
			update(dtAsSeconds);
        //draw();
		 // Rub out the last frame
		m_Window.clear(Color::White);

    // Draw the background
	m_Window.draw(m_BackgroundSprite);
	int dt3 = gametime.getElapsedTime().asSeconds();
	std::string s=std::to_string(m_Bob.score);
	int timeleft=150-dt3; //ADJUSTING THE TIME
	if (timeleft<=0)
		gameover=true;
	std::string timelefts=std::to_string(timeleft);
	if(gameover==false){
		score.setString("Score: " + s + "                 Time Left: "+ timelefts +    "                 Furret Walk v2.0         Created by Arca Özkan"   );
		m_Window.draw(score);
		m_Window.draw(m_Bob.getSprite());
		m_Window.draw(m_food.getSprite());
		m_Window.draw(m_food2.getSprite());
		m_Window.draw(m_food3.getSprite());
		m_Window.draw(m_stone.getSprite());
		m_Window.draw(m_stone2.getSprite());
		m_Window.draw(m_candy.getSprite());
	}
	if (gameover==true){
		std::string finalscore=s;
		score.setString("Final Score: " + finalscore + "                       Press SPACE to play again                        Press ESC to leave");
		if(std::stoi(finalscore)>=80)
			
			score2.setString("\n\n\n                      WOW!!! YOU'VE BEATEN 80!! YOU ARE A TRUE FURRET!! \n                 SECRET MAP UNLOCKED! HOLD \"M\" AND PRESS \"O\" TO PLAY ");
			score2.setFont(font);
			score2.setFillColor(sf::Color::Red);
			score2.setStyle(sf::Text::Bold);
			score2.setCharacterSize(48);
			score2.setPosition(50.f, 50.f);

		m_Window.draw(score);
		m_Window.draw(score2);
	}
	if(m_candy.candyeaten==true){
		if (clockcheck==false){
			clockcheck=true;
			candyclock.restart();
		}
		m_Bob.setSpeed(800);
		music.setPitch(1.5f);
		float dt2 = candyclock.getElapsedTime().asSeconds();
		if(dt2>=10){
			m_Bob.setSpeed(400);
			music.setPitch(1.0f);
			m_candy.candyeaten=false;
			clockcheck=false;
		}
	}
 
    // Show everything we have just drawn
    m_Window.display();
		
    }
}