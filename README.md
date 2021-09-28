# philosophers
Implementation of a solution to the Dining Philosophers Problem using; memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock.

### usleep()
#####int usleep(microseconds)
The usleep() function suspends execution of the calling thread until either microseconds microseconds
have elapsed or a signal is delivered to the thread and its action is to invoke a signal-catching
function or to terminate the process.  System activity or limitations may lengthen the sleep by an
indeterminate amount.

The usleep() function returns the value 0 if successful; otherwise the value -1 is returned and the
global variable errno is set to indicate the error.

### gettimeofday()
#####int gettimeofday(struct timeal *restrict tp, void *restrict tzp);
