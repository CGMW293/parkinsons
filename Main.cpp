#include <windows.h>
#include <cstdlib> 
#include <ctime> 

int main()
{

    srand(time(NULL)); // seed for random number generator :)
    POINT pos;//structure for mouse position
    while (1) {
        GetCursorPos(&pos);

        //these four help for Multi-Monitor Displays
        HMONITOR wild = MonitorFromPoint(pos, MONITOR_DEFAULTTONEAREST);
        MONITORINFO Moninfo = {sizeof(Moninfo)};
        GetMonitorInfo(wild, &Moninfo);
        int screenWidth = Moninfo.rcMonitor.right - Moninfo.rcMonitor.left; //mm hmmm seems about right

        int moveval = (screenWidth / 1080);//Helps scale with different sized displays
        int direction = rand() % 4 + 1;
        switch (direction) {
        case(4):
            SetCursorPos(pos.x - moveval, pos.y - moveval);
            break;
        case(1):
            SetCursorPos(pos.x + moveval, pos.y + moveval);
            break;
        case(2):
            SetCursorPos(pos.x + moveval, pos.y - moveval);
            break;
        case(3):
            SetCursorPos(pos.x - moveval, pos.y + moveval);
            break;
        }
        int sleepTime = rand() % 251; // sleep time between 0 and 250 milliseconds, gives the "Burst" feeling
        Sleep(sleepTime);
    }
}
