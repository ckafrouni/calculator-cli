#if !defined(ANSI_CODES_H)
#define ANSI_CODES_H

// Cursor Movements
#define CURSOR_UP "\033[1A"
#define CURSOR_DOWN "\033[1B"
#define CURSOR_RIGHT "\033[1C"
#define CURSOR_LEFT "\033[1D"

#define CURSOR_NEXT_LINE "\033[1E"
#define CURSOR_PREV_LINE "\033[1F"

#define CURSOR_LINE_START "\033[1G"

// Save/Restore Cursor Position
#define CURSOR_SAVE "\033[s"
#define CURSOR_RESTORE "\033[u"

// Set Cursor Position
#define CURSOR_HOME "\033[1;1H"
#define CURSOR_SET_ROW "\033[%d;1H"
#define CURSOR_SET_COL "\033[1;%dH"
#define CURSOR_SET_ROW_COL "\033[%d;%dH"

// Scroll
#define SCROLL_UP "\033[S"
#define SCROLL_DOWN "\033[T"

// Alternate Screen Buffer
#define ALTERNATE_SCREEN_BUFFER "\033[?1049h"
#define NORMAL_SCREEN_BUFFER "\033[?1049l"

// Erase
#define ERASE_LINE "\033[2K"
#define ERASE_LINE_LEFT "\033[1K"
#define ERASE_LINE_RIGHT "\033[0K"

#define ERASE_SCREEN "\033[2J"
#define ERASE_SCREEN_DOWN "\033[0J"
#define ERASE_SCREEN_UP "\033[1J"
#define ERASE_SCREEN_BUFFER "\033[3J"

// Set Graphics Mode
#define SET_GRAPHICS_MODE "\033[%dm"

// Reset Graphics Mode
#define RESET_GRAPHICS_MODE "\033[0m"

// Reset
#define STYLE_RESET "\033[0m"

// Text Styles
#define TXT_BOLD "\033[1m"
#define TXT_DIM "\033[2m"
#define TXT_UNDERLINE "\033[4m"
#define TXT_BLINK "\033[5m"
#define TXT_REVERSE "\033[7m"
#define TXT_HIDDEN "\033[8m"

#define TXT_NO_BOLD "\033[21m"
#define TXT_NO_DIM "\033[22m"
#define TXT_NO_UNDERLINE "\033[24m"
#define TXT_NO_BLINK "\033[25m"
#define TXT_NO_REVERSE "\033[27m"
#define TXT_NO_HIDDEN "\033[28m"

#define INVERT_FGS "\033[7m"

// Text Colors
#define FG_BLACK "\033[30m"
#define FG_RED "\033[31m"
#define FG_GREEN "\033[32m"
#define FG_YELLOW "\033[33m"
#define FG_BLUE "\033[34m"
#define FG_MAGENTA "\033[35m"
#define FG_CYAN "\033[36m"
#define FG_WHITE "\033[37m"

#define FG_BRIGHT_BLACK "\033[90m"
#define FG_BRIGHT_RED "\033[91m"
#define FG_BRIGHT_GREEN "\033[92m"
#define FG_BRIGHT_YELLOW "\033[93m"
#define FG_BRIGHT_BLUE "\033[94m"
#define FG_BRIGHT_MAGENTA "\033[95m"
#define FG_BRIGHT_CYAN "\033[96m"
#define FG_BRIGHT_WHITE "\033[97m"

// Background Colors
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

#define BG_BRIGHT_BLACK "\033[100m"
#define BG_BRIGHT_RED "\033[101m"
#define BG_BRIGHT_GREEN "\033[102m"
#define BG_BRIGHT_YELLOW "\033[103m"
#define BG_BRIGHT_BLUE "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN "\033[106m"
#define BG_BRIGHT_WHITE "\033[107m"

#endif // ANSI_CODES_H
