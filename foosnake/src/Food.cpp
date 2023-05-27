#include "Food.h"

Food::Food()
{
    gen_food();
}


void Food::gen_food()
{
    pos.X = rand() % WIDTH + 1;
    pos.Y = rand() % HEIGHT + 1;
}

COORD Food::get_pos() { return pos; }
