#ifndef RECURSION_ENGINE__SRC__UTILS__OPTIMIZATIONS__CPU_OPT_HH
#define RECURSION_ENGINE__SRC__UTILS__OPTIMIZATIONS__CPU_OPT_HH

// all macros start with OPT_ prefix.


#ifdef __GNUC__ 

    #define OPT_LIKELY(EXPR) __builtin_expect((bool)(EXPR), true)
    #define OPT_UNLIKELY(EXPR) __builtin_expect((bool)(EXPR), false)
    #define OPT_PREFETCH(address, rw, locality) __builtin_prefetch((address), (rw), (locality))
    #define OPT_FORCE_INLINE __attribute__((always_inline)) 

#else // if compiler is not GNU
    #define OPT_LIKELY(EXPR) EXPR
    #define OPT_UNLIKELY(EXPR) EXPR
    #define OPT_PREFETCH(address, rw, locality)
    #define OPT_FORCE_INLINE 
#endif

#endif