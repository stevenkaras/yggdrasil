//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_THREADING_LOCK_H_INCLUDED
#define YGG_COMMON_THREADING_LOCK_H_INCLUDED

/*
 * This header includes platform specific headers to define the following symbols:
 *
 * LOCK_ALLOC(LOCK) - allocate and initialize a lock
 * LOCK_FREE(LOCK) - deallocate and free a lock
 *
 * LOCK_ACQUIRE(LOCK) - lock the lock (enter a critical section)
 * LOCK_RELEASE(LOCK) - unlock the lock (leave a critical section)
 */

#if defined (YGG_PLATFORM_POSIX)
#include "ygg/posix/threading/lock.h"
#elif defined (YGG_PLATFORM_WINDOWS)
#include "ygg/windows/threading/lock.h"
#else
#error No compatible lock implementation for this platform
#endif

namespace ygg {
namespace threading {

/**
 * Mutex locking primitive
 */
class lock {
public:
    lock() { LOCK_ALLOC(_lock); }
    ~lock() { LOCK_FREE(_lock); }

public:
    void acquire() { LOCK_ACQUIRE(_lock); }
    void release() { LOCK_RELEASE(_lock); }

private:
    LOCK _lock;
};

/**
 * Function guard for lock
 */
class lock_guard {
public:
    lock_guard(lock& lock_) : _lock(&lock_) { _lock->acquire(); }
    lock_guard(lock* lock_) : _lock(lock_) { _lock->acquire(); }
    ~lock_guard() { if (_lock) _lock->release(); }

public:
    void reset() {
        _lock->release();
        _lock = NULL;
    }

private:
    lock *_lock;
};

}
} /* namespace ygg::threading */

#endif /* YGG_COMMON_THREADING_LOCK_H_INCLUDED */
