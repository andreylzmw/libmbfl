#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ENABLE_THREADS

#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#if USE_PTHREAD
#if defined(HAVE_PTHREAD)
#include <pthread.h>
#else
#error "pthread is not available"
#endif
#elif USE_WIN32_NATIVE_THREAD
#if defined(__WIN32__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#else
#error "You can't enable win32 native thread support in this build" 
#endif
#endif

#include <assert.h>

#include "mbfl_allocators.h"
#include "mbfl_mutex.h"

MBFLAPI mbfl_mutex *mbfl_mutex_new(void)
{
#if defined(USE_PTHREAD)
	pthread_mutex_t *mutex = NULL;
	pthread_mutexattr_t mattr;

	if ((mutex = mbfl_malloc(sizeof(pthread_mutex_t))) == NULL) {
		return NULL;
	}

	pthread_mutexattr_init(&mattr);
	pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_PRIVATE);
	pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE_NP);
	pthread_mutex_init(mutex, &mattr);
	pthread_mutexattr_destroy(&mattr);
#elif defined(USE_WIN32_NATIVE_THREAD)
	CRITICAL_SECTION *mutex;

	if ((mutex = mbfl_malloc(sizeof(CRITICAL_SECTION))) == NULL) {
		return NULL;
	}

	InitializeCriticalSection(mutex);
#endif
	return (mbfl_mutex *)mutex;
}

MBFLAPI int mbfl_mutex_lock(mbfl_mutex *mutex)
{
#if defined(USE_PTHREAD)
	switch (pthread_mutex_lock((pthread_mutex_t *)mutex)) {
		case EINVAL:
		case EDEADLK:
			return -1;
	}
#elif defined(USE_WIN32_NATIVE_THREAD)
	EnterCriticalSection((CRITICAL_SECTION *)mutex);
	if (GetLastError() == STATUS_INVALID_HANDLE) {
		return -1;
	}
#endif
	return 0;
}

MBFLAPI int mbfl_mutex_unlock(mbfl_mutex *mutex)
{
#if defined(USE_PTHREAD)
	switch (pthread_mutex_unlock((pthread_mutex_t *)mutex)) {
		case EINVAL:
		case EFAULT:
			return -1;

		case EPERM:
			return 1;
	}
#elif defined(USE_WIN32_NATIVE_THREAD)
	LeaveCriticalSection((CRITICAL_SECTION *)mutex);
	if (GetLastError() == STATUS_INVALID_HANDLE) {
		return -1;
	}
#endif
	return 0;
}

MBFLAPI void mbfl_mutex_free(mbfl_mutex *mutex)
{
#if defined(USE_PTHREAD)
	pthread_mutex_destroy((pthread_mutex_t *)mutex);
#elif defined(USE_WIN32_NATIVE_THREAD)
	DeleteCriticalSection((CRITICAL_SECTION *)mutex);
#endif
	mbfl_free(mutex);
}

#endif /* ENABLE_THREADS */ 
