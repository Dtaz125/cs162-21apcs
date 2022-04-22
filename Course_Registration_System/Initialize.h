#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED
#pragma once
#include <iostream>
#define _WIN32_WINNT 0x0500
#include<windows.h>
#include <conio.h>
#include"other.h"
using namespace std;

const int g_APP_WIDTH = 100;
const int g_APP_HEIGHT = 25;

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}
void SetScreenBufferSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD NewSize;
    NewSize.X = width;
    NewSize.Y = height;

    SetConsoleScreenBufferSize(hStdout, NewSize);
}
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
void InitializeConsole(){
    SetWindowSize(g_APP_WIDTH, g_APP_HEIGHT);
    SetScreenBufferSize(g_APP_WIDTH, g_APP_HEIGHT);
    DisableResizeWindow();
    ShowScrollbar(0);
}
int posCenter(string text){
    return (g_APP_WIDTH - text.size()) / 2;
}
void drawText(int x, int y, auto text){
    gotoxy(x, y);
    cout << text;
}
#endif // INITIALIZE_H_INCLUDED
