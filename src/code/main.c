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

void draw_block(Block *block)
{
    printf(CURSOR_SET_ROW_COL, block->start_line, block->start_col);
    printf("%s%s%s%*s", block->bg_color, block->fg_color, block->style, block->width, "");
    printf(CURSOR_LINE_START);
    printf(CURSOR_SET_ROW_COL, block->start_line, block->start_col);
    printf("%s%s%s%s", block->bg_color, block->fg_color, block->style, block->content);
    // printf(BG_COLOR(block->bg_color) FG_COLOR(block->fg_color) STYLE(block->style) "%s", block->content);
    printf(CURSOR_LINE_START);
}

int main()
{
    EditorState *state = create_editor();

    Block mode = {
        .width = 8,
        .height = 1,

        .start_line = state->ws.ws_row - 1,
        .start_col = 1,

        .content = "NORMAL",
        .bg_color = BG_YELLOW,
        .fg_color = FG_BLACK,
        .style = TXT_BOLD};

    Block glyph = {
        .width = 4,
        .height = 1,

        .start_line = state->ws.ws_row - 1,
        .start_col = mode.width + 1,

        .content = "#>",
        .bg_color = BG_BLUE,
        .fg_color = FG_BLACK,
        .style = TXT_BOLD};

    Block input = {
        .width = state->ws.ws_col - mode.width - glyph.width - 4,
        .height = 1,

        .start_line = state->ws.ws_row - 1,
        .start_col = mode.width + glyph.width + 1,

        .content = "",
        .bg_color = BG_CYAN,
        .fg_color = FG_BLACK,
        .style = TXT_BOLD};

    Block status_bar[3] = {mode, glyph, input};

    cli_mainloop(state);
    restore_editor(state);
    free_editor_state(state);

    return 0;
}
