#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "../includes/editor_state.h"
#include "../includes/ansi_codes.h"

void reset_graphics()
{
    printf(RESET_GRAPHICS_MODE);
    printf(ERASE_SCREEN);
}

void draw_history(EditorState *state)
{
    // Draw the history buffer (The last history_viewport_heigth lines)
    size_t history_viewport_heigth = state->window_height - 2;
    size_t start = state->history_buffer_size > history_viewport_heigth ? state->history_buffer_size - history_viewport_heigth : 0;
    size_t end = state->history_buffer_size;
    printf(CURSOR_SET_ROW_COL, 1, 1);
    for (size_t i = start; i < end; i++)
    {
        printf("#%lu -> " "%s\n", i, state->history_buffer[i]);
    }
}

void draw_bottom_bar(EditorState *state)
{
    // Draw the bottom bar
    printf(CURSOR_SET_ROW_COL, state->window_height - 1, 1);
    printf(BG_CYAN "%*s", state->window_width - 1, "");
    printf(CURSOR_LINE_START);

    // Status section
    printf(BG_YELLOW FG_BLACK " %s " BG_BLUE " #> " BG_CYAN " ", MODE_STRING(state->mode));

    // Input section
    printf("%s", state->input_buffer);
}

void draw_mode(EditorState *state)
{
    printf(CURSOR_SET_ROW_COL, state->window_height - 1, 1);
    printf(BG_YELLOW FG_BLACK " %s " BG_BLUE " #> " BG_CYAN " ", MODE_STRING(state->mode));
}

void draw_input(EditorState *state)
{
    printf("%s", state->input_buffer);
}

void draw_tui(EditorState *state)
{
    update_window_size(state);

    reset_graphics();
    draw_history(state);
    draw_bottom_bar(state);
    draw_mode(state);
    draw_input(state);

    // Move the cursor to the correct position
    printf(CURSOR_SET_ROW_COL, state->cursor_y + 1, state->cursor_x + 1);
}