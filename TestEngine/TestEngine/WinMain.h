#pragma once

#ifndef _WINMAIN_H
#define _WINMAIN_H

#ifndef _WINDOW_
	#include <Windows.h>
#endif

int _tmain(int argc, char* argv[]);
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

#endif // _WINMAIN_H
