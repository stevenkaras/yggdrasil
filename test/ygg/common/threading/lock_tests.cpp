//
// See doc/LICENSE.md for license terms
//

#include "ygg/common/threading/lock.h"

static void LockTest_AllocFreeMacros_Sanity() {
    LOCK my_lock;
    LOCK_ALLOC(my_lock);
    LOCK_FREE(my_lock);
}

static void LockTest_AcquireRelease_Sanity() {
    LOCK my_lock;
    LOCK_ALLOC(my_lock);
    LOCK_ACQUIRE(my_lock);
    LOCK_RELEASE(my_lock);
    LOCK_FREE(my_lock);
}

static void LockTest_AcquireRelease_RecursiveLock() {
    LOCK my_lock;
    LOCK_ALLOC(my_lock);
    LOCK_ACQUIRE(my_lock);
    LOCK_ACQUIRE(my_lock);
    LOCK_RELEASE(my_lock);
    LOCK_RELEASE(my_lock);
    LOCK_FREE(my_lock);
}

static void LockTest_AcquireRelease_Blocks() {
    //TODO: write this test
    //
    //initialize test var to 0
    //start two threads
    //first thread acquires lock, sleeps for 2 seconds, writes 1 to test var, sleeps for 2 seconds, release lock
    //second thread sleeps for 1 seconds, acquires lock,
    //main thread sleeps for three seconds, if test var is not 1, fail
    //main thread sleeps for three seconds, if test var is not 2, fail
}

void LockTests_TestSuite() {
    LockTest_AllocFreeMacros_Sanity();
    LockTest_AcquireRelease_Sanity();
    LockTest_AcquireRelease_RecursiveLock();
    LockTest_AcquireRelease_Blocks();
}
