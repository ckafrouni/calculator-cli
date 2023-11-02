#if !defined(EDITOR_DRAW_H)
#define EDITOR_DRAW_H

#include "../includes/editor_state.h"

typedef struct
{
    size_t width;
    size_t height;

    size_t start_line;
    size_t start_col;

    char *content;

    char *bg_color;
    char *fg_color;
    char *style;
} Block;

typedef struct
{
} EditorWindow;

typedef struct
{
    Block mode;
    Block glyph;
    Block input;
} StatusBar;

void reset_graphics();
void draw_history(EditorState *state);
void draw_bottom_bar(EditorState *state);
void draw_mode(EditorState *state);
void draw_input(EditorState *state);

void draw_tui(EditorState *state);

#endif // EDITOR_DRAW_H