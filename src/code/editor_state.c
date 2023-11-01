#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "../includes/editor_state.h"
#include "../includes/ansi_codes.h"

EditorState *create_editor()
{
    EditorState *state = (EditorState *)malloc(sizeof(EditorState));

    // Initialize the editor state
    state->mode = NORMAL_MODE;
    state->history_buffer_size = 0;
    state->input_buffer_size = 0;

    // Initialize the cursor position
    state->cursor_x = 0;
    state->cursor_y = 0;

    // Get the current window size
    update_window_size(state);

    // Get the current terminal settings
    tcgetattr(STDIN_FILENO, &state->oldt);
    state->newt = state->oldt;

    // Disable canonical mode and echo
    state->newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &state->newt);

    printf(ALTERNATE_SCREEN_BUFFER);
    return state;
}

void restore_editor(EditorState *state)
{
    // Restore the old terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &state->oldt);
    printf(NORMAL_SCREEN_BUFFER);
}

void free_editor_state(EditorState *state)
{
    free(state);
}

void clear_input_buffer(EditorState *state)
{
    memset(state->input_buffer, 0, state->input_buffer_size);
    state->input_buffer_size = 0;
}

void clear_history_buffer(EditorState *state)
{
    memset(state->history_buffer, 0, state->history_buffer_size);
    state->history_buffer_size = 0;
}

void update_window_size(EditorState *state)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    state->window_width = w.ws_col;
    state->window_height = w.ws_row;
}
