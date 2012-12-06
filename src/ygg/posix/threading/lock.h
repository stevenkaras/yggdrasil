//
// See doc/LICENSE.md for license terms
//

#ifndef POSIX_THREADING_LOCK_H_INCLUDED
#define POSIX_THREADING_LOCK_H_INCLUDED

#include <pthread.h>

#define LOCK pthread_mutex_t*

#define LOCK_ALLOC(LOCK) pthread_mutex_init(LOCK, NULL)
#define LOCK_FREE(LOCK) pthread_mutex_destroy(LOCK)

#define LOCK_ACQUIRE(LOCK) pthread_mutex_lock(LOCK)
#define LOCK_RELEASE(LOCK) pthread_mutex_unlock(LOCK)

#endif /* POSIX_THREADING_LOCK_H_INCLUDED */
