#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "../includes/ansi_codes.h"
#include "../includes/editor.h"

void cli_mainloop()
{
    char input;
    struct winsize w;
    struct termios oldt, newt;

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    EditorState *state = (EditorState *)malloc(sizeof(EditorState));
    state->mode = NORMAL_MODE;
    state->content_buffer = (char *)malloc(sizeof(char) * 1024);
    state->input_buffer = (char *)malloc(sizeof(char) * 1024);

    while (1)
    {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        state->window_width = w.ws_col;
        state->window_height = w.ws_row;

        draw_tui(state);

        input = getchar();

        if (handle_input(input, state))
        {
            break;
        }
    }

    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int main()
{
    cli_mainloop();
    return 0;
}
