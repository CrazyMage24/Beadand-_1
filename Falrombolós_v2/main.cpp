#include "osztaly.h"


int w = 1000;
int h = 600;

void clear_nulls(vector<Cube*>& cubes)
{
    vector<Cube*> uj;
    for(int i = 0; i < cubes.size(); i++)
    {
        if(cubes[i]!=nullptr)
        {
            uj.push_back(cubes[i]);
        }
    }
    cubes = uj;
}

void hatter()
{
    gout << move_to(0,0);
    gout << color(0,0,0);
    gout << box(w,h);
}

int main()
{
    Ball b = Ball(w/2,h/2);
    Slider s = Slider(400,500,200,1);
    vector<Cube*> cubes;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cubes.push_back(new Cube(3 + i*50,3 + j*50,45));
        }
    }
    gin.timer(30);
    gout.open(w,h);

    event ev;
    bool mehet = false;
    bool vege = false;
    while(gin >> ev)
    {
        if(mehet)
        {
            if(ev.type == ev_timer)
            {
                hatter();
                // számláló
                stringstream ss;
                ss << "Hatralevo kockak: " << cubes.size();
                gout << move_to(w-180,h-15) << color(255,255,255) << text(ss.str());
                //Slider
                s.update();
                s.show();
                s.boundaries(w,h);
                //kockák
                for(size_t i = 0; i < cubes.size(); i++)
                {
                    cubes[i]->show();
                }
                //labda
                b.update();
                b.show();
                b.boundaries(w,h);
                b.connect(s);
                for(size_t i = 0; i < cubes.size(); i++)
                {
                    b.connect(cubes[i]);
                    if(cubes[i]->getTalalt())
                    {
                        delete cubes[i];
                        cubes[i] = nullptr;
                    }
                }
                clear_nulls(cubes);
                if(b.getVesztett())
                {
                    vege = true;
                    gout << move_to(w/2 - 50,h/3) << color(255,255,255) << text("Vesztettel");
                    gout << move_to(w/2 - 100,h/3 + 100) << color(255,255,255) << text("Nyomj Esc-t a kilepeshez");
                    gin.timer(0);
                }
                if(cubes.size()==0)
                {
                    vege = true;
                    gout << move_to(w/2 - 25,h/3) << color(255,255,255) << text("Nyertel");
                    gout << move_to(w/2 - 100,h/3 + 100) << color(255,255,255) << text("Nyomj Esc-t a kilepeshez");
                    gin.timer(0);
                }
                // refresh
                gout << refresh;
            }
            else if(ev.keycode == key_escape)
            {
                exit(0);
            }
            else if(ev.keycode == key_left)
            {
                if(s.getPos_x()!=0)
                {
                    s.setVel_x(-20);
                }
            }
            else if(ev.keycode == key_right)
            {
                if(s.getPos_x() + s.getW()!=w)
                {
                    s.setVel_x(20);
                }
            }
        }
        else if(!mehet)
        {
            hatter();
            gout << move_to(w/2 - 50,h/3) << color(255,255,255) << text("Falrombolos");
            gout << move_to(w/2 - 100,h/3 + 100) << color(255,255,255) << text("Nyomj Entert a kezdeshez");
            gout << move_to(w/2 - 100,h/3 + 200) << color(255,255,255) << text("Nyomj Esc-t a kilepeshez");
            if(ev.keycode == key_escape)
            {
                exit(0);
            }
            if(ev.keycode == key_enter)
            {
                mehet = true;
            }
            gout << refresh;
        }
    }
    return 0;
}


