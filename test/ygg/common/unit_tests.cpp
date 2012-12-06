//
// unit_tests.cpp
// skybit-foundation
//
// See doc/LICENSE.md for license terms
//
// Authors:
// Steven Karas <steven.karas@gmail.com>
//

#include "unit_tests.h"
#include "ygg/common/logging/logging_tests.h"
#include "ygg/common/threading/lock_tests.h"

void unit_tests() {
    LoggingTests_TestSuite();
    LockTests_TestSuite();
}
