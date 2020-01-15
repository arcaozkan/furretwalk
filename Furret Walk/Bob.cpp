#include "windows.h"
#include "bob.h"
 
Bob::Bob()
{
    // How fast does Bob move?
    m_Speed = 400;
	score=0;
    // Associate a texture with the sprite
    m_Texture.loadFromFile("Images/furret1.png");
    m_Sprite.setTexture(m_Texture);     
 
    // Set the Bob's starting position
    m_Position.x = 500;
    m_Position.y = 800;
	jumpreach=600;
}
 void Bob::setSpeed(int speed){
	 m_Speed=speed;
 }
// Make the private spite available to the draw() function
Sprite Bob::getSprite()
{
    return m_Sprite;
}
int Bob::getx()
{
	return m_Position.x;
}
int Bob::gety()
{
	return m_Position.y;
}
void Bob::moveLeft()
{
    m_LeftPressed = true;  
}
 
void Bob::moveRight()
{
    m_RightPressed = true;
}
void Bob::moveUp()
{
    m_UpPressed = true;
}
void Bob::stopUp()
{
    m_UpPressed = false;
}
void Bob::stopLeft()
{
    m_LeftPressed = false;

}
 
void Bob::stopRight()
{
    m_RightPressed = false;
 
}
bool onland;
bool fall=false; 
// Move Bob based on the input this frame,
// the time elapsed, and the speed
void Bob::update(float elapsedTime)
{
	if (fall==true){
		if(jumpreach==600){
			if (m_Position.y<=jumpreach+50)
				m_Position.y += m_Speed * 0.003;
			else if (m_Position.y<=jumpreach+100)
				m_Position.y += m_Speed * 0.006;
			else if (m_Position.y<jumpreach+200)
				m_Position.y += m_Speed * 0.009;
			else if(m_Position.y>=800){
				fall=false;
			}
		}
		else if(jumpreach==400){
			if (m_Position.y<=jumpreach+50)
				m_Position.y += m_Speed * 0.002;
			else if (m_Position.y<=jumpreach+200)
				m_Position.y += m_Speed * 0.004;
			else if (m_Position.y<jumpreach+400)
				m_Position.y += m_Speed * 0.006;
			else if(m_Position.y>=800){
				fall=false;
			}
		}
	}
	if (m_UpPressed){
		if (m_Position.y>=jumpreach+100 && fall==false)
			m_Position.y -= m_Speed * 0.009;
		else if (m_Position.y>=jumpreach+50 && fall==false)
			m_Position.y -= m_Speed * 0.006;
		else if (m_Position.y>=jumpreach && fall==false)
			m_Position.y -= m_Speed * 0.002;
		else if (m_Position.y<jumpreach){
			fall=true;
		}
	}
	
	else if (m_UpPressed==false && onland==false && fall==false){
		m_Position.y += m_Speed * 0.009;
	}
	if (m_Position.y>800)
		onland=true;
	if(m_Position.y<800)
		onland=false;

    if (m_LeftPressed)
    {
		int  var_b = (int)m_Position.x;
		if((var_b/10)%10==0){
			m_Texture.loadFromFile("Images/furret1.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==1){
			m_Texture.loadFromFile("Images/furret2.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==2){
			m_Texture.loadFromFile("Images/furret3.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==3){
			m_Texture.loadFromFile("Images/furret4.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==4){
			m_Texture.loadFromFile("Images/furret5.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==5){
			m_Texture.loadFromFile("Images/furret6.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==6){
			m_Texture.loadFromFile("Images/furret7.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==7){
			m_Texture.loadFromFile("Images/furret8.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==8){
			m_Texture.loadFromFile("Images/furret9.png");
			m_Sprite.setTexture(m_Texture);
		}
		else{
			m_Texture.loadFromFile("Images/furret10.png");
			m_Sprite.setTexture(m_Texture);
		}
        m_Position.x -= m_Speed * elapsedTime;

    }
	    if (m_RightPressed)
    {
		int  var_b = (int)m_Position.x;
		if((var_b/10)%10==0){
			m_Texture.loadFromFile("Images/furret1.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==1){
			m_Texture.loadFromFile("Images/furret2.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==2){
			m_Texture.loadFromFile("Images/furret3.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==3){
			m_Texture.loadFromFile("Images/furret4.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==4){
			m_Texture.loadFromFile("Images/furret5.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==5){
			m_Texture.loadFromFile("Images/furret6.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==6){
			m_Texture.loadFromFile("Images/furret7.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==7){
			m_Texture.loadFromFile("Images/furret8.png");
			m_Sprite.setTexture(m_Texture);
		}
		else if((var_b/10)%10==8){
			m_Texture.loadFromFile("Images/furret9.png");
			m_Sprite.setTexture(m_Texture);
		}
		else{
			m_Texture.loadFromFile("Images/furret10.png");
			m_Sprite.setTexture(m_Texture);
		}
        m_Position.x += m_Speed * elapsedTime;
    }
    // Now move the sprite to its new position
    m_Sprite.setPosition(m_Position);
 
}