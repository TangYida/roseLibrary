/***************************************
 *windowBase.h                         *
 *The base head file of windows        *
 *It packages the base operation of OSs*
 *                                     *
 *@author:TangYida                      *
 *                                     *
 ***************************************/



#ifndef     WINDOWBASE
#define     WINDOWBASE
#include    <string>
#include    "define.h"
#ifdef      _WIN32


enum windowLargeOrder
{
    systemDefault    = 0x0001,
    medium           = 0x0002
    /*TODO:others*/
};

enum getMode
{
    fullScreenW      = 0x1001,
    fullScreenH      = 0x1002,
    screenW          = 0x1003,
    screenH          = 0x1004,
    windowLayered    = 0x1005,
    windowX          = 0x1006,
    windowY          = 0x1007,
    windowHeight     = 0x1008,
    windowWidth      = 0x1009,
    DC               = 0x1010,
    hWnd             = 0x1011,
    title            = 0x1012,
    className        = 0x1013
};

enum colorLayeredMode
{
    colorKeyM        = 0x00000001,
    alphaM           = 0x00000002,
    colorKeyAlphaM   = 0x00000001 | 0x00000002
};

class windowBase
{

protected:

    //var
    std::string varClassName;
    std::string varTitle;
    int varHeight;
    int varWidth;
    int varX;
    int varY;
    WNDCLASS wc;
    MSG msg;
    HWND hWnd;
    HDC hdc;

    //package
    bool registerWindow(HINSTANCE hIn);

    //no coping
    windowBase(windowBase&);
    windowBase& operator=(windowBase&);

public:

    //constructor
    windowBase() = default;
    explicit windowBase(const std::string  className,
                        const std::string windowTitle,
                        const int width,const int height,
                        const int x,const int y,
                        HINSTANCE hIn);
    explicit windowBase(const std::string className,
                        const std::string windowTitle,
                        const int width,const int height,
                        const windowLargeOrder ord,
                        HINSTANCE hIn);

    //destructor
    ~windowBase() = default;

    //public window settings
    inline bool setWindowTitle(const std::string windowTitle);
    inline bool setHeightWidth(const int width,const int height);
    inline bool setXY(const int x,const int y);
    inline bool setXY(const windowLargeOrder ord);

    //public get function
    template<typename T>
    T get(getMode ord);

    //public actions
    inline void windowHide();
    inline void windowShow();
    inline void windowUpdate();
    inline void windowMax();
    inline void windowMin();

    /*TODO:window's style;window's background;window's layered setting*/

};


#endif // _WIN32
#endif // WINDOWBASE
