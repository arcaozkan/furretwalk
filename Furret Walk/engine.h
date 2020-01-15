#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h";
#include "food.h";
#include "stone.h";
#include "candy.h"
#include <string>
using namespace sf;
class Engine
{
private:
    // A regular RenderWindow
    RenderWindow m_Window;  
	int map;
    // Declare a sprite and a Texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
	bool eaten;
	bool hit;
    // An instance of Bob
    Bob m_Bob;
	food m_food;
	food m_food2;
	food m_food3;
	stone m_stone;
	stone m_stone2;
	candy m_candy;
 
    // Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
 
public:
    // The Engine constructor
    Engine();
	void maprandomizer();
    // start will call all the private functions
    void start();
 
};