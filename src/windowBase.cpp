#include    "windowBase.h"
#ifdef _WIN32
///////////////////////////////////////////////////////////////////////////
/*TODO:catch the error*/
windowBase::windowBase(const std::string  className,
                       const std::string windowTitle,
                       const int height,const int width,
                       const int x,const int y,
                       HINSTANCE hIn):
    varClassName       (className),
    varTitle           (windowTitle),
    varHeight          (height),
    varWidth           (width),
    varX               (x),
    varY               (y),
    wc                 ({0}),
    msg                ({0}),
    hWnd               (nullptr),
    hdc                (nullptr)
{
    registerWindow(hIn);
}

windowBase::windowBase(const std::string className,
                       const std::string windowTitle,
                       const int height,const int width,
                       const windowLargeOrder ord,
                       HINSTANCE hIn):
    varClassName       (className),
    varTitle           (windowTitle),
    varHeight          (height),
    varWidth           (width),
    varX               (ord == systemDefault ? CW_USEDEFAULT : 0),          /*TODO:medium and other order*/
    varY               (ord == systemDefault ? CW_USEDEFAULT : 0),          /*TODO:medium and other order*/
    wc                 ({0}),
    msg                ({0}),
    hWnd               (nullptr),
    hdc                (nullptr)
{
    registerWindow(hIn);
}
////////////////////////////////////////////////////////////////////////
inline bool windowBase::setHeightWidth(const int width,const int height)
{
    varWidth         = width;
    varHeight        = height;
    return (bool)!SetWindowPos(hWnd,nullptr,varX,varY,varWidth,varHeight,NULL);
}

inline bool windowBase::setXY(const int x,const int y)
{
    varX             = x;
    varY             = y;
    return (bool)!SetWindowPos(hWnd,nullptr,varX,varY,varWidth,varHeight,NULL);
}

inline bool windowBase::setXY(const windowLargeOrder ord)
{
    varX             = ord == systemDefault ? CW_USEDEFAULT : 0;
    varY             = ord == systemDefault ? CW_USEDEFAULT : 0;
    return (bool)!SetWindowPos(hWnd,nullptr,varX,varY,varWidth,varHeight,NULL);
}
////////////////////////////////////////////////////////////////////////
template<typename T>
T windowBase::get(getMode ord)
{
    switch(ord)
    {
    /*TODO:Full screen and screen's protected var*/
    case fullScreenW:
    {
        return GetSystemMetrics(SM_CXFULLSCREEN);
        break;
    }
    case fullScreenH:
    {
        return GetSystemMetrics(SM_CYFULLSCREEN);
        break;
    }
    case screenW:
    {
        return GetSystemMetrics(SM_CXSCREEN);
        break;
    }
    case screenH:
    {
        return GetSystemMetrics(SM_CYSCREEN);
        break;
    }
    case windowLayered:
    {
        return 0;
        break;
    }
    case windowX:
    {
        return varX;
        break;
    }
    case windowY:
    {
        return varY;
        break;
    }
    case windowHeight:
    {
        return varHeight;
        break;
    }
    case windowWidth:
    {
        return varWidth;
        break;
    }
        /*Á÷Ë®ÕÊ*/
    case DC:
    {
        return hdc;
        break;
    }
    case hWnd:
    {
        return hWnd;
        break;
    }
    case title:
    {
        return varTitle;
        break;
    }
    case className:
    {
        return varClassName;
        break;
    }
    /*TODO:null catcher*/
    default:
        return 1;
    }
}
////////////////////////////////////////////////////////////////////////
inline void windowBase::windowHide()
{
    ShowWindow(hWnd,SW_HIDE);
}

inline void windowBase::windowShow()
{
    ShowWindow(hWnd,SW_SHOW);
}

inline void windowBase::windowUpdate()
{
    UpdateWindow(hWnd);
}

inline void windowBase::windowMax()
{
    ;
}

inline void windowBase::windowMin()
{
    ;
}

////////////////////////////////////////////////////////////////////////
bool windowBase::registerWindow(HINSTANCE hIn)
{
    wc.lpszClassName     = varClassName.data();
    wc.hbrBackground     = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hIcon             = LoadIcon(nullptr,IDI_APPLICATION);
    wc.hCursor           = LoadCursor(nullptr,IDC_ARROW);
    wc.hInstance         = hIn;
//    wc.lpfnWndProc       = proc;
    hWnd                 = CreateWindowExW
                           (
                               WS_EX_ACCEPTFILES |
                               WS_EX_LEFT |
                               WS_EX_LTRREADING |
                               WS_EX_TOOLWINDOW |
                               WS_EX_RIGHTSCROLLBAR,
                               (wchar_t*)(varClassName.data()),
                               (wchar_t*)(varTitle.data()),
                               WS_POPUP |
                               WS_VISIBLE |
                               WS_CLIPSIBLINGS,
                               varX,varY,
                               varWidth,varHeight,
                               0, 0, hIn, 0);
    if(!hWnd)
    {
        return 1;
    }
    hdc                  = GetDC(hWnd);
}
/////////////////////////////////////////////////////////////////////////
#endif // _WIN32

