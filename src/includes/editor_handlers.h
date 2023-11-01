#if !defined(EDITOR_HANDLERS_H)
#define EDITOR_HANDLERS_H

#include "../includes/editor_state.h"

int handle_input_normal(char input, EditorState *state);

int handle_input_insert(char input, EditorState *state);

int handle_input(char input, EditorState *state);

#endif // EDITOR_HANDLERS_H
