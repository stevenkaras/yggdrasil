//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_LOGGING_LOGGING_MACROS_H_INCLUDED
#define YGG_COMMON_LOGGING_LOGGING_MACROS_H_INCLUDED

// These macros provide a logging system that dumps information in a platform independent manner.
//
// You can control which log messages are used by setting the LOG_LEVEL define
// Additionally, if the LOG_TAG define is set, it will be passed to the log function as well
//
// it is left to the user to implement both platformLog, as defined in log_helper.h

#include "log_helper.h"

#define LOG_LEVEL_VERBOSE  0
#define LOG_LEVEL_DEBUG    1
#define LOG_LEVEL_INFO     2
#define LOG_LEVEL_WARNING  3
#define LOG_LEVEL_ERROR    4
#define LOG_LEVEL_FATAL    5

#ifndef LOG_LEVEL
#define LOG_LEVEL LOG_LEVEL_VERBOSE
#endif

#ifndef LOG_TAG
#define LOG_TAG "DEFAULT"
#endif

#if (LOG_LEVEL<=LOG_LEVEL_VERBOSE)
#define LOG_V(...) ygg::logging::log_helper(LOG_LEVEL_VERBOSE, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_V(...)
#endif

#if (LOG_LEVEL<=LOG_LEVEL_DEBUG)
#define LOG_D(...) ygg::logging::log_helper(LOG_LEVEL_DEBUG, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_D(...)
#endif

#if (LOG_LEVEL<=LOG_LEVEL_INFO)
#define LOG_I(...) ygg::logging::log_helper(LOG_LEVEL_INFO, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_I(...)
#endif

#if (LOG_LEVEL<=LOG_LEVEL_WARNING)
#define LOG_W(...) ygg::logging::log_helper(LOG_LEVEL_WARNING, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_W(...)
#endif

#if (LOG_LEVEL<=LOG_LEVEL_ERROR)
#define LOG_E(...) ygg::logging::log_helper(LOG_LEVEL_ERROR, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_E(...)
#endif

#if (LOG_LEVEL<=LOG_LEVEL_FATAL)
#define LOG_F(...) ygg::logging::log_helper(LOG_LEVEL_FATAL, LOG_TAG, __FILE__, __LINE__, ## __VA_ARGS__)
#else
#define LOG_F(...)
#endif

#endif /* YGG_COMMON_LOGGING_LOGGING_MACROS_H_INCLUDED */
