//
// See doc/LICENSE.md for license terms
//

#include "ygg/common/logging/logging_macros.h"
#include <stdio.h>

#define LOG_MESSAGE_BUFFER_SIZE 1000

static char logtest_buffer[LOG_MESSAGE_BUFFER_SIZE];

void ygg::logging::platform_log(int log_level, const char* tag, const char* filename, int linenumber, const char* message) {
    snprintf(logtest_buffer, LOG_MESSAGE_BUFFER_SIZE, "[%d]|%s| %s:%d : %s", log_level, tag, filename, linenumber, message);
}

#include <string.h>
#define ASSERT_STRING_EQUALS(actual, expected) printf(strcmp(actual, expected) == 0 ? "" : \
        "Expected: %s\n" \
        "Actual:   %s\n", expected, actual)

static void LoggingTest_log_MacroExpandsCorrectly() {
    // one arg
    LOG_V("hello, world");
    ASSERT_STRING_EQUALS(logtest_buffer, "[0]|DEFAULT| logging_tests.cpp:23 : hello, world");

    // var args
    LOG_V("hello, %s", "world");
    ASSERT_STRING_EQUALS(logtest_buffer, "[0]|DEFAULT| logging_tests.cpp:27 : hello, world");
}

void LoggingTests_TestSuite() {
    LoggingTest_log_MacroExpandsCorrectly();
}
