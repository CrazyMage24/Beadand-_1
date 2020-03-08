#include "graphics.hpp"
#include <vector>
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

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
    int getW();
    int getH();
};

class Cube
{
private:
    int pos_x;
    int pos_y;
    int r;
    bool talalt;
public:
    Cube(int x, int y, int r);
    void show();
    int getPos_x();
    int getPos_y();
    int getR();
    void setTalalt(bool talalt);
    bool getTalalt();

};

class Ball
{
private:
    int pos_x;
    int pos_y;
    float vel_x;
    float vel_y;
    float r;
    bool vesztett;
public:
    Ball(int x, int y);
    void show();
    void update();
    void boundaries(int w, int h);
    void setVel_x(float x);
    void setVel_y(float y);
    void setVesztett(bool vesztett);
    void connect(Slider s);
    void connect(Cube*&c);
    int getPos_x();
    int getPos_y();
    int getVel_x();
    int getVel_y();
    bool getVesztett();
};
