#if !defined(EDIT0R_H)
#define EDIT0R_H

typedef enum
{
    NORMAL_MODE,
    INSERT_MODE,
} InputMode;

typedef struct
{
    InputMode mode;
    char *content_buffer;
    char *input_buffer;
    int cursor_x;
    int cursor_y;
    int window_width;
    int window_height;
} EditorState;

#define MODE_STRING(mode) (mode == NORMAL_MODE ? "NORMAL" : "INSERT")

void draw_tui(EditorState *state);

int handle_input_normal(char input, EditorState *state);


int handle_input_insert(char input, EditorState *state);

int handle_input(char input, EditorState *state);

#endif // EDIT0R_H
