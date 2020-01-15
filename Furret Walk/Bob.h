#pragma once
#include <SFML/Graphics.hpp>
 
using namespace sf;
class Bob
{
    // All the private variables can only be accessed internally
private:
 
    // Where is Bob
    Vector2f m_Position;
	int score;
    // Of course we will need a sprite
    Sprite m_Sprite;
 
    // And a texture
    // Bob has been working out and he is now a bit more muscular than before
    // Furthermore, he fancies himself in lumberjack attire
    Texture m_Texture;
 
    // Which direction(s) is the player currently moving in
    bool m_LeftPressed;
    bool m_RightPressed;
	bool m_UpPressed;
 
    // Bob's speed in pixels per second
    float m_Speed;
 
    // Public functions
public:
    // We will set Bob up in the constructor
    Bob();
	friend class Engine;
    // Send a copy of the sprite to main
    Sprite getSprite();
 
    // Move Bob in a specific direction
    void moveLeft();
	int gety();
	int getx();
	int jumpreach;
    void moveRight();
	void moveUp();
	void setSpeed(int speed);
    // Stop Bob moving in a specific direction
    void stopLeft();
	void stopUp();
 
    void stopRight();
 
    // We will call this function once every frame
    void update(float elapsedTime);
 
};