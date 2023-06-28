#ifdef _WIN32
#include <Windows.h>
#elif __APPLE__
#include <Carbon/Carbon.h>
#else
#include <X11/Xlib.h>
#endif

int main() {
#ifdef _WIN32
    // Windows implementation
    BlockInput(TRUE);
#elif __APPLE__
    // macOS implementation
    CGEventRef eventRef = CGEventCreate(NULL);
    CGEventFlags flags = CGEventGetFlags(eventRef);
    CGEventSetFlags(eventRef, flags | kCGEventFlagMaskAlphaShift);
    CGEventPost(kCGHIDEventTap, eventRef);
    CFRelease(eventRef);
#else
    // Linux implementation
    Display* display = XOpenDisplay(NULL);
    XGrabKeyboard(display, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync, CurrentTime);
    XEvent event;
    while (true) {
        XNextEvent(display, &event);
        // handle events or use XSendEvent to redirect events to another window
    }
    XUngrabKeyboard(display, CurrentTime);
    XCloseDisplay(display);
#endif

    // The program will lock the keyboard until it is closed
    while (true) {
        // You can add additional functionality or just keep the program running
    }

    return 0;
}
