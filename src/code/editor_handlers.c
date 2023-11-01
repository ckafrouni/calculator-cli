#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "../includes/editor_state.h"
#include "../includes/ansi_codes.h"

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
    else if (input == 'c')
    {
        clear_history_buffer(state);
    }
    return 0;
}

int handle_input_insert(char input, EditorState *state)
{
    switch (input)
    {
    case 27: // ESC
        state->mode = NORMAL_MODE;
        break;

    case '\n':
        if (state->input_buffer_size == 0)
            break;
        
        if (state->history_buffer_size == HISTORY_BUFFER_SIZE)
        {
            clear_history_buffer(state);
        }

        state->input_buffer[state->input_buffer_size++] = '\0';
        char *new_line = (char *)malloc(state->input_buffer_size);
        strcpy(new_line, state->input_buffer);
        (state->history_buffer)[state->history_buffer_size] = new_line;
        (state->history_buffer_size)++;

        clear_input_buffer(state);
        break;

    case 127: // BACKSPACE
        state->input_buffer[strlen(state->input_buffer) - 1] = '\0';
        break;
    
    default:
        if (state->input_buffer_size == INITIAL_BUFFER_SIZE - 1)
            break;
        strncat(state->input_buffer, &input, 1);
        state->input_buffer_size++;
        break;
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