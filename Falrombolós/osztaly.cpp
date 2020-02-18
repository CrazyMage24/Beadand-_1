#include "osztaly.h"

Ball::Ball(int x, int y)
{
    pos_x=x;
    pos_y=y;
    vel_x=10;
    vel_y=-10;
    r=50;
}
void Ball::show()
{
    gout << color(255,0,255);
    gout << move_to(pos_x,pos_y);
    gout << box(r,r);
}
void Ball::update()
{
    pos_x+=vel_x;
    pos_y+=vel_y;
}
void Ball::boundaries(int w, int h)
{
    if(pos_x<=0)
    {
        vel_x*=-1;
    }
    if(pos_y<=0)
    {
        vel_y*=-1;
    }
    if(pos_x + r>=w)
    {
        vel_x*=-1;
    }
    if(pos_y + r>=h)
    {
        vel_y*=-1;
    }
}
void Ball::setVel_x(float x)
{
    vel_x=x;
}
void Ball::setVel_y(float y)
{
    vel_y=y;
}
int Ball::getPos_x()
{
    return pos_x;
}
int Ball::getPos_y()
{
    return pos_y;
}
int Ball::getVel_x()
{
    return vel_x;
}
int Ball::getVel_y()
{
    return vel_y;
}

/* --- */

Slider::Slider(int x, int y, int w, int h)
{
    pos_x=x;
    pos_y=y;
    vel_x=0;
    this->w=w;
    this->h=h;
}
void Slider::show()
{
    gout << color(255,255,255);
    gout << move_to(pos_x,pos_y);
    gout << box(w,h);
}
void Slider::update()
{
    pos_x+=vel_x;
}
void Slider::boundaries(int w, int h)
{
    if(pos_x<=0)
    {
        vel_x=0;
    }
    if(pos_x+this->w>=w)
    {
        vel_x=0;
    }
}
void Slider::setVel_x(float x)
{
    vel_x=x;
}
int Slider::getPos_x()
{
    return pos_x;
}
int Slider::getPos_y()
{
    return pos_y;
}
int Slider::getVel_x()
{
    return vel_x;
}
