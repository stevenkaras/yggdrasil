//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_POSIX_THREADING_THREADS_H_INCLUDED
#define YGG_POSIX_THREADING_THREADS_H_INCLUDED

#include <pthread.h>

#define THREAD pthread_t*

#define THREAD_ALLOC(THREAD) (THREAD) = new pthread_t
#define THREAD_FREE(THREAD) delete (THREAD)

#define THREAD_START(THREAD, MAIN, ARG) pthread_create(THREAD, NULL, MAIN, ARG)

#endif /* YGG_POSIX_THREADING_THREADS_H_INCLUDED */
