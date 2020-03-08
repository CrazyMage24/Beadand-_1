#include "osztaly.h"

void kor(int x, int y, int r)
{
    for(int i = x-r; i<x+r; i++)
    {
        for(int j = y-r; j<y+r; j++)
        {
            if((i-x)*(i-x) + (j-y)*(j-y) <= r*r)
            {
                gout << move_to(i,j) << dot;
            }
        }
    }
}

/* --- */

Ball::Ball(int x, int y)
{
    pos_x=x;
    pos_y=y;
    vel_x=10;
    vel_y=-10;
    r=25;
    vesztett=false;
}
void Ball::show()
{
    gout << color(255,0,0);
    kor(pos_x,pos_y,r);
}
void Ball::update()
{
    pos_x+=vel_x;
    pos_y+=vel_y;
}
void Ball::boundaries(int w, int h)
{
    if(pos_x - r<=0 && vel_x<0)
    {
        vel_x*=-1;
    }
    if(pos_y - r<=0 && vel_y<0)
    {
        vel_y*=-1;
    }
    if(pos_x + r>=w && vel_x>0)
    {
        vel_x*=-1;
    }
    if(pos_y + r>=h && vel_y>0)
    {
        vel_y*=-1;
        vesztett = true;
    }
}
void Ball::setVel_x(float x)
{
    vel_x*=x;
}
void Ball::setVel_y(float y)
{
    vel_y*=y;
}
void Ball::setVesztett(bool vesztett)
{
    this->vesztett=vesztett;
}
void Ball::connect(Slider s)
{
    if(pos_x>=s.getPos_x() && pos_x<=s.getPos_x()+s.getW())
    {
        if(pos_y+r >= s.getPos_y() && pos_y - r <= s.getPos_y() + s.getH())
        {
            if(vel_y>0)
            {
                if(vel_x>0)
                {
                    float off_x = 1;
                    if(s.getVel_x()>0)
                    {
                        off_x = 1.1;
                    }
                    else if(s.getVel_x()<0)
                    {
                        off_x = 0.9;
                    }
                    else if(s.getVel_x()==0)
                    {
                        off_x = 1;
                    }
                    setVel_x(off_x);
                    setVel_y(-1);
                }
                else if(vel_x<0)
                {
                    float off_x = 1;
                    if(s.getVel_x()<0)
                    {
                        off_x = 1.1;
                    }
                    else if(s.getVel_x()>0)
                    {
                        off_x = 0.9;
                    }
                    else if(s.getVel_x()==0)
                    {
                        off_x = 1;
                    }
                    setVel_x(off_x);
                    setVel_y(-1);
                }
                else
                {
                    float off_x = s.getVel_x() * 0.06;
                    vel_x += off_x;
                }

            }
        }
    }
}
void Ball::connect(Cube*&c)
{
    // alulrol
    if(pos_x >=c->getPos_x() && pos_x <=c->getPos_x()+c->getR())
    {
        if(pos_y - r <= c->getPos_y() + c->getR() && pos_y - r >= c->getPos_y())
        {
            if(vel_y<0)
            {
               setVel_y(-1);
               c->setTalalt(true);
            }
        }
    }
    // felulrol
    else if(pos_x>=c->getPos_x() && pos_x<=c->getPos_x()+c->getR())
    {
        if(pos_y + r >= c->getPos_y() && pos_y + r <= c->getPos_y() + c->getR())
        {
            if(vel_y>0)
            {
               setVel_y(-1);
               c->setTalalt(true);
            }
        }
    }
    // balrol
    else if(pos_x + r <= c->getPos_x() && pos_x + r >= c->getPos_x() - (c->getR()/2))
    {
        if(pos_y>=c->getPos_y() && pos_y <= c->getPos_y() + c->getR())
        {
            if(vel_x>0)
            {
                setVel_x(-1);
                c->setTalalt(true);
            }
        }
    }
    // jobbrol
    else if(pos_x - r >= c->getPos_x() + c->getR() && pos_x - r <= c->getPos_x())
    {
        if(pos_y>=c->getPos_y() && pos_y <= c->getPos_y() + c->getR())
        {
            if(vel_x<0)
            {
                setVel_x(-1);
                c->setTalalt(true);
            }
        }
    }
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
bool Ball::getVesztett()
{
    return vesztett;
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
int Slider::getW()
{
    return w;
}
int Slider::getH()
{
    return h;
}

/* --- */

Cube::Cube(int x, int y, int r)
{
    pos_x=x;
    pos_y=y;
    this->r=r;
    talalt= false;
}
void Cube::show()
{
    if(!talalt)
    {
        gout << color(200,0,255);
        gout << move_to(pos_x,pos_y);
        gout << box(r,r);
    }
    else
    {
        gout << color(100,200,0);
        gout << move_to(pos_x,pos_y);
        gout << box(r,r);
    }

}
int Cube::getPos_x()
{
    return pos_x;
}
int Cube::getPos_y()
{
    return pos_y;
}
int Cube::getR()
{
    return r;
}
void Cube::setTalalt(bool talalt)
{
    this->talalt=talalt;
}
bool Cube::getTalalt()
{
    return talalt;
}
