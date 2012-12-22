//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_LOGGING_LOG_HELPER_H_INCLUDED
#define YGG_COMMON_LOGGING_LOG_HELPER_H_INCLUDED

namespace ygg::logging {

/*
 * Log a message at the given log level, from the line in the given file and with the given tag
 */
void log_helper(int logLevel, const char* tag, const char* filename, int linenum, const char* message, ...);

/*
 * Log the given message at the log level, with the tag, as coming from the file name and line number.
 *
 * This function is a platform dependent implementation.
 */
void platform_log(int logLevel, const char* tag, const char* filename, int linenumber, const char* message);

} /* namespace ygg::logging */

#endif /* YGG_COMMON_LOGGING_LOG_HELPER_H_INCLUDED */
