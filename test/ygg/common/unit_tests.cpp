//
// See doc/LICENSE.md for license terms
//

#include "unit_tests.h"
#include "ygg/common/logging/logging_tests.h"
#include "ygg/common/threading/lock_tests.h"
#include "ygg/common/threading/rwlock_tests.h"

#include <stdio.h>

void unit_tests() {
    LoggingTests_TestSuite();
    LockTests_TestSuite();
    RWLockTests_TestSuite();
    printf("All common tests passed!\n");
}
