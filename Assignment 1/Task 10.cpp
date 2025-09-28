#include <iostream>
using namespace std;

int main()
{
    int win, loss, draw, win_points, loss_points, draw_points, total_points;

    cout<<"Enter Wins: ";
    cin>>win;

    cout<<"Enter Losses: ";
    cin>>loss;

    cout<<"Enter Draws: ";
    cin>>draw;

    win_points = win * 3;
    loss_points = loss * 0;
    draw_points = draw * 1;
    
    total_points = win_points + loss_points + draw_points;

    cout<<"Total Points: "<< total_points;

    return 0;
}

