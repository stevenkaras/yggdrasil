//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_THREADING_RWLOCK_H_INCLUDED
#define YGG_COMMON_THREADING_RWLOCK_H_INCLUDED

/*
 * This header includes platform specific headers to define the following symbols:
 *
 * RWLOCK_ALLOC(RWLOCK) - allocate and initialize a read/write lock
 * RWLOCK_FREE(RWLOCK) - deallocate and free a read/write lock
 *
 * RWLOCK_ACQUIRE_READ(RWLOCK) - lock the read/write lock for reading
 * RWLOCK_RELEASE_READ(RWLOCK) - unlock the read/write lock for reading
 * RWLOCK_ACQUIRE_WRITE(RWLOCK) - lock the read/write lock for writing
 * RWLOCK_RELEASE_WRITE(RWLOCK) - unlock the read/write lock for writing
 */

#if defined (YGG_PLATFORM_POSIX)
#include "ygg/posix/threading/rwlock.h"
#elif defined (YGG_PLATFORM_WINDOWS)
#include "ygg/windows/threading/rwlock.h"
#else
#error No compatible rwlock implementation for this platform
#endif

namespace ygg {
namespace threading {

/**
 * Read write lock primitive
 */
class rwlock {
public:
    rwlock() { RWLOCK_ALLOC(_rwlock); }
    ~rwlock() { RWLOCK_FREE(_rwlock); }

public:
    void acquire_read() { RWLOCK_ACQUIRE_READ(_rwlock); }
    void acquire_write() { RWLOCK_ACQUIRE_WRITE(_rwlock); }
    void release_read() { RWLOCK_RELEASE_READ(_rwlock); }
    void release_write() { RWLOCK_RELEASE_WRITE(_rwlock); }

private:
    RWLOCK _rwlock;
};

/**
 * Function guard for read locking a rwlock
 */
class rwlock_read_guard {
public:
    rwlock_read_guard(rwlock* rwlock_) : _rwlock(rwlock_) { _rwlock->acquire_read(); }
    ~rwlock_read_guard() { if (_rwlock) _rwlock->release_read(); }

public:
    void reset() {
        _rwlock->release_read();
        _rwlock = NULL;
    }

private:
    rwlock *_rwlock;
};

/**
 * Function guard for write locking a rwlock
 */
class rwlock_write_guard {
public:
    rwlock_write_guard(rwlock* rwlock_) : _rwlock(rwlock_) { _rwlock->acquire_write(); }
    ~rwlock_write_guard() { if (_rwlock) _rwlock->release_write(); }

public:
    void reset() {
        _rwlock->release_write();
        _rwlock = NULL;
    }

private:
    rwlock *_rwlock;
};

}
} /* namespace ygg::threading */

#endif /* YGG_COMMON_THREADING_RWLOCK_H_INCLUDED */
