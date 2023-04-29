#include "./dev-utilities.h"



#ifdef NO_TRACE
  #define LOG_TRACE(message) ((void)0)
#else
  #define trace_me(message) printf("[%s:%d] %s\n", __FILE__, __LINE__, message)
#endif
