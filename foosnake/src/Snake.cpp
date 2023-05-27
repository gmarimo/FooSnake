#include "Snake.h"

Snake::Snake(COORD pos, int vel)
{
    this->pos = pos;
    this->vel = vel;
    len = 1;
    direction = 'n';
}

void Snake::change_dir(char dir) {direction = dir;}
void Snake::move_snake()
{
    switch(direction)
    {
        case 'u' : pos.Y -= vel;
        break;
        case 'd' : pos.Y += vel;
        break;
        case 'l' : pos.X -= vel;
        break;
        case 'r' : pos.X += vel;
        break;
    }
}

COORD Snake::get_pos() { return pos;}
bool Snake::eaten(COORD food_pos)
{
    if (food_pos.X == pos.X && food_pos.Y == pos.Y) return true;
    else return false;
    {

    }
}

void Snake::grow() {len++;}
bool Snake::collided()
{
    if (pos.X < 1 || pos.X > WIDTH || pos.Y < 1 || pos.Y > HEIGHT) return true;
    return false;

}
