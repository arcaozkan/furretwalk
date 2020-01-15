#include "windows.h"
#include "Engine.h"
 
using namespace sf;
 
void Engine::update(float dtAsSeconds)
{
	int xpos=m_Bob.getx();
	int ypos=m_Bob.gety();
    m_Bob.update(dtAsSeconds);
		m_food.update(dtAsSeconds,xpos,m_Bob.score,ypos,eaten);
		m_food2.update(dtAsSeconds,xpos,m_Bob.score,ypos,eaten);
		m_food3.update(dtAsSeconds,xpos,m_Bob.score,ypos,eaten);
	m_stone.update(dtAsSeconds,xpos,m_Bob.score,ypos,hit);
	m_stone2.update(dtAsSeconds,xpos,m_Bob.score,ypos,hit);
	m_candy.update(dtAsSeconds,xpos,m_Bob.score,ypos,eaten);
}