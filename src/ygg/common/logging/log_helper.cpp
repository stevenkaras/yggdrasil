//
// See doc/LICENSE.md for license terms
//

#include "log_helper.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define LOG_MESSAGE_BUFFER_SIZE 4096

void ygg::logging::log_helper(int log_level, const char* tag, const char* filename, int linenum, const char* message, ...) {
    char buffer[LOG_MESSAGE_BUFFER_SIZE];

    va_list args;
    va_start(args, message);
    vsnprintf(buffer, LOG_MESSAGE_BUFFER_SIZE, message, args);

    // adjust the filename to be just the basename, without the extension
    //TODO: make this platform indepedent (FS_SEPARATOR)
    const char* basename = strrchr(filename, '/');
    if (basename != NULL)
        filename = ++basename;

    platform_log(log_level, tag, filename, linenum, buffer);

    va_end(args);
}
