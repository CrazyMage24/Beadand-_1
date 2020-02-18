#include "osztaly.h"
#include <algorithm>
#include <sstream>

int w = 1000;
int h = 600;

int main()
{
    Ball b = Ball(200,200);
    Slider s = Slider(400,400,200,50);
    gin.timer(35);
    gout.open(w,h);

    //referenciavonalak
    gout << color(255,0,0);
    gout << move_to(w/2,0);
    gout << line_to(w/2,h);

    gout << color(0,0,255);
    gout << move_to(0,h/2);
    gout << line_to(w,h/2);

    event ev;
    while(gin >> ev)
    {
        if(ev.type == ev_timer)
        {
            // háttér újrarajzolása, ezt nem engedi valamiért külön függvényben
            gout << move_to(0,0);
            gout << color(0,0,0);
            gout << box(w,h);
            //referenciavonalak
            gout << color(255,255,0);
            gout << move_to(w/2,0);
            gout << line_to(w/2,h);
            gout << move_to(0,h/2);
            gout << line_to(w,h/2);
            //Slider
            s.update();
            s.show();
            s.boundaries(w,h);
            //labda
            b.update();
            b.show();
            b.boundaries(w,h);
            // refresh
            gout << refresh;
        }
        else if(ev.keycode == key_escape)
        {
            exit(0);
        }
        else if(ev.keycode == key_left)
        {
            s.setVel_x(-20);
        }
        else if(ev.keycode == key_right)
        {
            s.setVel_x(20);
        }
    }
    return 0;
}


