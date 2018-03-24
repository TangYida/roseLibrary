#include    "define.h"
#include    "windowBase.h"
#include	"cairo.h"

int main()
{
    windowBase wb(
                  "wb",
                  "Hello,World",
                  400,
                  300,
                  systemDefault,
                  hInstance);
    wb.windowShow();
    return 0;
}
