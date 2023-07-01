#include <windows.h>

int main()
{
	POINT pos;//Structure for the position of a cursor.
	int width = 1080;//Gets X value of resolution. Helps with scaling jitter for different resolutions
	int moveval = (width / 540) * 1.5; //idk i made this shit up |3 for 1080|11 for 4k |;
	while (1) {
		int direction = rand() % 4 + 1;
		GetCursorPos(&pos);
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
		Sleep(pos.x / (direction * 20));
	}
}