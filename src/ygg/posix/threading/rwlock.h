//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_POSIX_THREADING_RWLOCK_H_INCLUDED
#define YGG_POSIX_THREADING_RWLOCK_H_INCLUDED

#include <pthread.h>

#define RWLOCK pthread_rwlock_t*

#define RWLOCK_ALLOC(RWLOCK) (RWLOCK) = new pthread_rwlock_t; pthread_rwlock_init((RWLOCK), NULL)
#define RWLOCK_FREE(RWLOCK) pthread_rwlock_destroy(RWLOCK); delete (RWLOCK)
#define RWLOCK_ACQUIRE_READ(RWLOCK) pthread_rwlock_rdlock(RWLOCK)
#define RWLOCK_RELEASE_READ(RWLOCK) pthread_rwlock_unlock(RWLOCK)
#define RWLOCK_ACQUIRE_WRITE(RWLOCK) pthread_rwlock_wrlock(RWLOCK)
#define RWLOCK_RELEASE_WRITE(RWLOCK) pthread_rwlock_unlock(RWLOCK)

#endif /* YGG_POSIX_THREADING_RWLOCK_H_INCLUDED */
