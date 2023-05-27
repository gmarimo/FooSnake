#include <iostream>
#define HEIGHT 30
#define WIDTH 55

using namespace std;    

int x =10, y = 10;

void drawBoard()
{
    for (int i = 0; i < HEIGHT; i++)
    {
        cout << "\t\t#";
        for (int j = 0; j < WIDTH - 2; j++)
        {
            if (i == 0 || i == HEIGHT - 1)
                cout << "#";
            else if (i == y && j == x)
                cout << "O";   
            else
                cout << " ";
        }
        cout << "#\n";
    }
}


int main()
{
    drawBoard();
    return 0;
}