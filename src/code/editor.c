#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../includes/editor.h"
#include "../includes/ansi_codes.h"

void draw_tui(EditorState *state)
{
    int term_width = state->window_width - 1;
    int term_height = state->window_height - 1;

    printf(ERASE_SCREEN);
    printf(CURSOR_SET_ROW_COL(% d, % d), term_height, 1);
    printf(BG_BRIGHT_CYAN "%*s", term_width, "");
    printf(CURSOR_LINE_START);
    printf(BG_BRIGHT_YELLOW FG_BLACK " %s #> " BG_BRIGHT_BLUE, MODE_STRING(state->mode));
    printf("%s", state->input_buffer);
}


int handle_input_normal(char input, EditorState *state)
{
    if (input == 'q')
    {
        return 1;
    }
    else if (input == 'i')
    {
        state->mode = INSERT_MODE;
    }
    return 0;
}


int handle_input_insert(char input, EditorState *state)
{
    if (input == 27) // ESC
    {
        state->mode = NORMAL_MODE;
    }
    else if (input == '\n')
    {
        state->mode = NORMAL_MODE;
        strcat(state->content_buffer, "\n");
    }
    else if (input == 127) // BACKSPACE
    {
        state->content_buffer[strlen(state->content_buffer) - 1] = '\0';
    }
    else
    {
        strncat(state->input_buffer, &input, 1);
    }
    return 0;
}

int handle_input(char input, EditorState *state)
{
    if (state->mode == NORMAL_MODE)
    {
        return handle_input_normal(input, state);
    }
    else if (state->mode == INSERT_MODE)
    {
        return handle_input_insert(input, state);
    }
    return 0;
}
