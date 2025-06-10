     #include <X11/Xlib.h>
     #include <stdio.h>
     #include <stdlib.h>
     #include<unistd.h>

     #define DEBUG_LINE  printf ("LINE %d\n", __LINE__);
     int main() {
         Display *display;
         Window window;
         XEvent event;

         display = XOpenDisplay(NULL);
         if (display == NULL) {
             fprintf(stderr, "Cannot open display\n");
             exit(1);
         }
         DEBUG_LINE

         int screen = DefaultScreen(display);
         window = XCreateSimpleWindow(display, RootWindow(display, screen), 0, 0, 500, 500, 1,
                                     BlackPixel(display, screen), WhitePixel(display, screen));
         XSelectInput(display, window, ExposureMask | KeyPressMask);
         XMapWindow(display, window);

         DEBUG_LINE
         while (1) {
             XNextEvent(display, &event);
             if (event.type == Expose) {
                 XFillRectangle(display, window, DefaultGC(display, screen), 50, 50, 400, 400);
         DEBUG_LINE
		 XFontStruct *ft=XLoadQueryFont(display,"*-helvetica-*-24-*");
         DEBUG_LINE
		 //XSetFont (display, DefaultGC(display,screen), ft->fid);
         DEBUG_LINE
                 XDrawString(display, window, DefaultGC(display, screen), 50, 50, "Hello World", 11);
             }
             if (event.type == KeyPress)
                 break;
         }
         DEBUG_LINE
	 sleep(3000);
         XCloseDisplay(display);
         DEBUG_LINE
	 return 0;

     }
