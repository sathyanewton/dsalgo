
#define DEBUG
#if defined(DEBUG)
#define debug(...)				\
    do { fprintf(stdout,  __VA_ARGS__); fflush(NULL); } while (0)
#else
#define debug(...);
#endif
