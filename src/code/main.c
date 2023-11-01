#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#include "../includes/ansi_codes.h"
#include "../includes/editor_state.h"
#include "../includes/editor_draw.h"
#include "../includes/editor_handlers.h"

void cli_mainloop(EditorState *state)
{
    while (1)
    {
        draw_tui(state);

        char input = getchar();
        if (handle_input(input, state))
            break;
    }
}

int main()
{
    EditorState *state = create_editor();
    cli_mainloop(state);
    restore_editor(state);
    free_editor_state(state);

    return 0;
}
