#ifndef     DEFINE
#define     DEFINE

#ifdef _WIN32
#include    <windows.h>
#define WINVER 0x1000
#define main() _stdcall WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, BOOL)
#endif // _WIN32

#endif //DEFINE
