#ifndef WPP_GETCH
#define WPP_GETCH



#include <iostream>


namespace wpp {

    #ifdef _WIN32

        #include <windows.h>
        TCHAR getch() {
            DWORD mode, cc;
            HANDLE h = GetStdHandle( STD_INPUT_HANDLE );
            if (h == NULL) {
                return 0; // console not found
            }
            GetConsoleMode( h, &mode );
            SetConsoleMode( h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT) );
            TCHAR c = 0;
            ReadConsole( h, &c, 1, &cc, NULL );
            SetConsoleMode( h, mode );
            return c;
        }

        TCHAR getche(){
            auto fuck = getch();
            cout << fuck;
            return fuck;
        }

    #else

        #include <termios.h>
        #include <stdio.h>

        static struct termios old, new_;

        /* Initialize new_ terminal i/o settings */
        void initTermios(int echo){
            tcgetattr(0, &old); /* grab old terminal i/o settings */
            new_ = old; /* make new_ settings same as old settings */
            new_.c_lflag &= ~ICANON; /* disable buffered i/o */
            new_.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
            tcsetattr(0, TCSANOW, &new_); /* use these new_ terminal i/o settings now */
        }

        /* Restore old terminal i/o settings */
        void resetTermios(void){
            tcsetattr(0, TCSANOW, &old);
        }

        /* Read 1 character - echo defines echo mode */
        char getch_(int echo){
            char ch;
            initTermios(echo);
            ch = getchar();
            resetTermios();
            return ch;
        }

        /* Read 1 character without echo */
        char getch(void){
            return getch_(0);
        }

        /* Read 1 character with echo */
        char getche(void){
            return getch_(1);
        }

    #endif

}



#endif