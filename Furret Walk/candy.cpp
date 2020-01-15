#include "windows.h"
#include "candy.h"
#include "randgen.h"
#include <thread>
#include <chrono>
#include "SFML/Audio.hpp"

candy::candy()
{
    // How fast does Bob move?
    m_Speed = 300;

    // Associate a texture with the sprite
    m_Texture.loadFromFile("Images/candy.png");
    m_Sprite.setTexture(m_Texture);     
 
    // Set the Bob's starting position
	RandGen randnum;
    m_Position.x =randnum.RandInt(0,1800);
	RandGen randnum2;
    m_Position.y = randnum2.RandInt(-3000,-20000);
	candyeaten = false;
}
 
// Make the private spite available to the draw() function
Sprite candy::getSprite()
{
    return m_Sprite;
}
 
 void candy::setSpeed(int speed){
	 m_Speed=speed;
 }
 
// Move Bob based on the input this frame,
// the time elapsed, and the speed
void candy::update(float elapsedTime,int xpos,int & score,int ypos,bool & eaten)
{

	m_Position.y=m_Position.y+m_Speed * elapsedTime;
 
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);  
	if (m_Position.y>=ypos && m_Position.y<=ypos+60&& m_Position.x >= xpos+50 && m_Position.x <= xpos+230){ //eat
		m_Position.y=1100;
		candyeaten=true;
		eaten=true;
		score++;
		
	}
	if (m_Position.y>=1100){
		RandGen randnum3;
		m_Position.x =randnum3.RandInt(0,1800);
		RandGen randnum2;
		m_Position.y = randnum2.RandInt(-3000,-20000);
	}
 
}