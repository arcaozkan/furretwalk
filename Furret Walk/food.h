
#include <SFML/Graphics.hpp>

#include "randgen.h"

using namespace sf;
class food
{
    // All the private variables can only be accessed internally
private:
 
    // Where is Bob
    Vector2f m_Position;
 
    // Of course we will need a sprite
    Sprite m_Sprite;
 
    // And a texture
    // Bob has been working out and he is now a bit more muscular than before
    // Furthermore, he fancies himself in lumberjack attire
    Texture m_Texture;
 
 
    // Bob's speed in pixels per second
    float m_Speed;
 
    // Public functions
public:
	friend class Engine;
	void setMap(int map);
    // We will set Bob up in the constructor
    food();
 void setSpeed(int speed);
    // Send a copy of the sprite to main
    Sprite getSprite();
 
 
    // We will call this function once every frame
    void update(float elapsedTime,int xpos,int & score,int ypos,bool & eaten);
 
};