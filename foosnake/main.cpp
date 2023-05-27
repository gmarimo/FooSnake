#include <iostream>
#include <conio.h>
#include <ctime>
#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1);
Food food;

// int x =10, y = 10;

void drawBoard()
{
    COORD snake_pos = snake.get_pos();
    COORD food_pos = food.get_pos();
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if (i == snake_pos.Y && j == snake_pos.X)
                cout << "O";
            else if (i == food_pos.Y && j == food_pos.X)
                cout << "g";
            else
                cout << " ";
        }
        cout << "#\n";
    }
}


int main()
{
    srand(time(NULL));
    bool game_over = false;
    while (!game_over) {
        drawBoard();
        if (kbhit)
        {
            switch (getch())
            {
                case 'g' : snake.change_dir('u'); break;
                case 'i' : snake.change_dir('d'); break;
                case 'f' : snake.change_dir('l'); break;
                case 't' : snake.change_dir('r'); break;
            }
        }
        snake.move_snake();
        if (snake.eaten(food.get_pos()))
        {
            food.gen_food();
            snake.grow();
        }
        if (snake.collided()) game_over = true;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }
}
