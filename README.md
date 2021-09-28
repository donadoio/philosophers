# philosophers
Implementation of a solution to the Dining Philosophers Problem using; memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock.

### usleep()
##### int usleep(microseconds)
The usleep() function suspends execution of the calling thread until either microseconds microseconds
have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching
function or to terminate the process.  System activity or limitations may lengthen the sleep by an
indeterminate amount.

The usleep() function returns the value 0 if successful; otherwise the value -1 is returned and the
global variable errno is set to indicate the error.

### gettimeofday()
##### int gettimeofday(struct timeal *restrict tp, void *restrict tzp);
The system's notion of the current Greenwich time and the current time zone is obtained with the gettimeofday() call. The time is expressed in seconds and microseconds since midnight (0 hour), January 1, 1970. If tp is NULL and tzp is non-NULL, gettimeofday() will populate the timezone struct in tzp.  If tp is non-NULL and tzp is NULL, then only the timeval struct in tp is populated. If both tp and tzp are NULL, nothing is returned.

### pthread_create()
##### int pthread_create(p_thread_t *thread, const pthread_attr_t *attr, void *(start_routine)(void *), void *arg);
