#include <stdio.h>

#include <X11/Xlib.h>

int main(int, char*[])
{
    Display* display = XOpenDisplay(NULL);
    Window window = XCreateSimpleWindow(
        display, XDefaultRootWindow(display),
        100, 100, 200, 200, 4, 0, 0);
    XEvent event;

    XMapWindow(display, window);
    XSelectInput(display, window, KeyPressMask | ButtonPressMask | ExposureMask);

    while (True) {
      XNextEvent(display, &event);
      printf("%d\n", event.type);
    }

    return 0;
}

