#if !defined(EDITOR_DRAW_H)
#define EDITOR_DRAW_H

#include "../includes/editor_state.h"

void reset_graphics();
void draw_history(EditorState *state);
void draw_bottom_bar(EditorState *state);
void draw_mode(EditorState *state);
void draw_input(EditorState *state);

void draw_tui(EditorState *state);

#endif // EDITOR_DRAW_H