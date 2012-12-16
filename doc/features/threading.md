Multithreading support with Yggdrasil
=====================================
At the moment, yggdrasil provides basic multithreading services:

  * Basic synchronization locks

In the future, we will provide these services as well:

  * Starting and joining threads
  * Read write locks


Basic Synchronization
=====================
To use basic synchronization features, simply `#include "ygg/common/threading/lock.h"`.

You can then use either the primitive LOCK with its corresponding macros, or use the lock and lock_guard classes.
