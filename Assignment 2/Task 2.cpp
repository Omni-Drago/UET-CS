#include <iostream>
using namespace std;

int main()
{
    int minutes, fps, totalFrames;

    cout << "Enter number of minutes: ";
    cin >> minutes;

    cout << "Enter frames per second (FPS): ";
    cin >> fps;

    totalFrames = minutes * 60 * fps;

    cout << "Total number of frames: " << totalFrames << endl;

    return 0;
}
