#include "graphics.hpp"

using namespace genv;

class Ball
{
private:
    int pos_x;
    int pos_y;
    float vel_x;
    float vel_y;
    float r;
public:
    Ball(int x, int y);
    void show();
    void update();
    void boundaries(int w, int h);
    void setVel_x(float x);
    void setVel_y(float y);
    int getPos_x();
    int getPos_y();
    int getVel_x();
    int getVel_y();
};

class Slider
{
private:
    int pos_x;
    int pos_y;
    float vel_x;
    int w;
    int h;
public:
    Slider(int x, int y, int w, int h);
    void show();
    void update();
    void boundaries(int w, int h);
    void setVel_x(float x);
    int getPos_x();
    int getPos_y();
    int getVel_x();
};

class Cube
{
private:
public:

};
