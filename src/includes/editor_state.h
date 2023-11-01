#if !defined(EDITOR_STATE_H)
#define EDITOR_STATE_H

#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>

#define INITIAL_BUFFER_SIZE 1024
#define HISTORY_BUFFER_SIZE 1024

typedef enum
{
    NORMAL_MODE,
    INSERT_MODE,
} InputMode;

#define MODE_STRING(mode) (mode == NORMAL_MODE ? "NORMAL" : "INSERT")

typedef struct
{
    size_t x;
    size_t y;
} NormalCursor;

typedef struct
{
    size_t x;
} InputCursor;

typedef struct
{
    InputMode mode;

    NormalCursor ncursor;
    InputCursor icursor;

    struct winsize ws;

    struct termios oldt;
    struct termios newt;

    char *history_buffer[HISTORY_BUFFER_SIZE];
    size_t history_buffer_size;

    char input_buffer[INITIAL_BUFFER_SIZE];
    size_t input_buffer_size;
} EditorState;


EditorState *create_editor();
void restore_editor(EditorState *state);
void free_editor_state(EditorState *state);

void clear_input_buffer(EditorState *state);
void clear_history_buffer(EditorState *state);
void update_window_size(EditorState *state);

void inc_ncursor_x(EditorState *state);
void inc_ncursor_y(EditorState *state);
void dec_ncursor_x(EditorState *state);
void dec_ncursor_y(EditorState *state);
void home_ncursor(EditorState *state);

void inc_icursor_x(EditorState *state);
void dec_icursor_x(EditorState *state);

#endif // EDIT0R_STATE_H
