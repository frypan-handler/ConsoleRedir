// ConsoleRedirChild.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include<windows.h>
#pragma comment(lib, "User32.lib")

void mainLoop();

int _tmain(int argc, _TCHAR* argv[])
{
	
	mainLoop();
	return 0;
}

void mainLoop() {
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);

	while (true) {
		INPUT_RECORD inputRecords[8];
		INPUT_RECORD* record;
		DWORD recordsRead, i;
		

		printf("Before ReadConsoleInput...--");
		fflush(stdout);
		ReadConsoleInput (handle, inputRecords, sizeof(inputRecords) / sizeof(*inputRecords), &recordsRead);
		printf("--...After ReadConsoleInput\n");
		fflush(stdout);
		for (i = 0, record = inputRecords; i < recordsRead; ++i, ++record) {
				int codePoint, keyCode;
				
				if ((record->EventType != KEY_EVENT) || !record->Event.KeyEvent.bKeyDown)
					continue;
				keyCode   = record->Event.KeyEvent.wVirtualKeyCode;
				codePoint = record->Event.KeyEvent.uChar.UnicodeChar;

				switch (keyCode) {
					default: {
						printf("Entered: %c\n",codePoint);
						fflush(stdout);
						break;
							 }
				}
		}

		// small delay to keep CPU free
		Sleep(1000);
	}
}
