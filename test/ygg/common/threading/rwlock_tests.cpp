//
// See doc/LICENSE.md for license terms
//

#include "ygg/common/threading/rwlock.h"

static void RWLockTest_AllocFreeMacros_Sanity() {
    RWLOCK my_lock;
    RWLOCK_ALLOC(my_lock);
    RWLOCK_FREE(my_lock);
}

static void RWLockTest_ReadAcquireRelease_Sanity() {
    RWLOCK my_lock;
    RWLOCK_ALLOC(my_lock);
    RWLOCK_ACQUIRE_READ(my_lock);
    RWLOCK_RELEASE_READ(my_lock);
    RWLOCK_FREE(my_lock);
}

static void RWLockTest_WriteAcquireRelease_Sanity() {
    RWLOCK my_lock;
    RWLOCK_ALLOC(my_lock);
    RWLOCK_ACQUIRE_WRITE(my_lock);
    RWLOCK_RELEASE_WRITE(my_lock);
    RWLOCK_FREE(my_lock);
}

static void RWLockTest_ReadAcquireRelease_RecursiveLock() {
    RWLOCK my_lock;
    RWLOCK_ALLOC(my_lock);
    RWLOCK_ACQUIRE_READ(my_lock);
    RWLOCK_ACQUIRE_READ(my_lock);
    RWLOCK_RELEASE_READ(my_lock);
    RWLOCK_RELEASE_READ(my_lock);
    RWLOCK_FREE(my_lock);
}

static void RWLockTest_WriteAcquireRelease_RecursiveLock() {
    RWLOCK my_lock;
    RWLOCK_ALLOC(my_lock);
    RWLOCK_ACQUIRE_WRITE(my_lock);
    RWLOCK_ACQUIRE_WRITE(my_lock);
    RWLOCK_RELEASE_WRITE(my_lock);
    RWLOCK_RELEASE_WRITE(my_lock);
    RWLOCK_FREE(my_lock);
}

static void RWLockTest_AcquireRelease_ReadersDontBlock() {
    //TODO: write this test
}

static void RWLockTest_AcquireRelease_WritersBlock() {
    //TODO: write this test
}

static void RWLockTest_AcquireRelease_WriterBlocksReaders() {
    //TODO: write this test
}

static void RWLockTest_AcquireRelease_ReadersBlockWriter() {
    //TODO: write this test
}

void RWLockTests_TestSuite() {
    RWLockTest_AllocFreeMacros_Sanity();
    RWLockTest_ReadAcquireRelease_Sanity();
    RWLockTest_WriteAcquireRelease_Sanity();
    RWLockTest_ReadAcquireRelease_RecursiveLock();
    RWLockTest_WriteAcquireRelease_RecursiveLock();
    RWLockTest_AcquireRelease_ReadersDontBlock();
    RWLockTest_AcquireRelease_WritersBlock();
    RWLockTest_AcquireRelease_ReadersBlockWriter();
}
