//
// See doc/LICENSE.md for license terms
//

#ifndef YGG_COMMON_THREADING_THREADS_H_INCLUDED
#define YGG_COMMON_THREADING_THREADS_H_INCLUDED

/*
 * This header includes platform specific headers to define the following symbols:
 *
 * THREAD - datatype for a thread handle
 *
 * THREAD_ALLOC(THREAD) - allocate a thread handle
 * THREAD_FREE(THREAD) - deallocate a thread handle
 *
 * THREAD_START(THREAD, MAIN, ARG) - start the THREAD with the MAIN function, passing in the data from ARG
 */

#if defined (YGG_PLATFORM_POSIX)
#include "ygg/posix/threading/threads.h"
#elif defined (YGG_PLATFORM_WINDOWS)
#include "ygg/windows/threading/threads.h"
#else
#error No compatible threads implementation for this platform
#endif

#endif /* YGG_COMMON_THREADING_THREADS_H_INCLUDED */
