#if !defined(EDITOR_STATE_H)
#define EDITOR_STATE_H

#include <stdlib.h>
#include <termios.h>

#define INITIAL_BUFFER_SIZE 1024
#define HISTORY_BUFFER_SIZE 1024

typedef enum
{
    NORMAL_MODE,
    INSERT_MODE,
} InputMode;

typedef struct
{
    InputMode mode;
    int cursor_x;
    int cursor_y;
    int window_width;
    int window_height;
    struct termios oldt;
    struct termios newt;

    char *history_buffer[HISTORY_BUFFER_SIZE];
    size_t history_buffer_size;

    char input_buffer[INITIAL_BUFFER_SIZE];
    size_t input_buffer_size;
} EditorState;

#define MODE_STRING(mode) (mode == NORMAL_MODE ? "NORMAL" : "INSERT")

EditorState *create_editor();
void restore_editor(EditorState *state);
void free_editor_state(EditorState *state);

void clear_input_buffer(EditorState *state);
void clear_content_buffer(EditorState *state);
void update_window_size(EditorState *state);



#endif // EDIT0R_STATE_H
