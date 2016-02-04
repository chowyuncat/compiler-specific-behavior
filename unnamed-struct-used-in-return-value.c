/* This should compile without warnings under C, but issue warnings under C++:
    e.g.

    clang: ok

    clang++:
    clang: warning: treating 'c' input as 'c++' when in C++ mode, this behavior is deprecated
    ./unnamed-struct-used-in-return-value.c:31:42: error: '(anonymous struct at ./unnamed-struct-used-in-return-value.c:31:42)' cannot be defined in a
          type specifier
        printf("alignment of char is %ld\n", TYPE_ALIGNMENT(char));
                                             ^
    ./unnamed-struct-used-in-return-value.c:18:41: note: expanded from macro 'TYPE_ALIGNMENT'
     #define TYPE_ALIGNMENT(t) FIELD_OFFSET(struct { char x; t test; }, test)
                                            ^
    ./unnamed-struct-used-in-return-value.c:11:62: note: expanded from macro 'FIELD_OFFSET'
     #define FIELD_OFFSET(Type, Field) ((LONG)__builtin_offsetof(Type, Field))
*/

/* BEGIN REACTOS */
typedef long LONG;
typedef long* LONG_PTR;

/* Returns the byte offset of the specified structure's member */
#ifndef __GNUC__
 #define FIELD_OFFSET(Type, Field) ((LONG)(LONG_PTR)&(((Type*) 0)->Field))
#else
 #define FIELD_OFFSET(Type, Field) ((LONG)__builtin_offsetof(Type, Field))
#endif /* __GNUC__ */

/* Returns the type's alignment */
#if defined(_MSC_VER)
 #define TYPE_ALIGNMENT(t) __alignof(t)
#else
 #define TYPE_ALIGNMENT(t) FIELD_OFFSET(struct { char x; t test; }, test)
#endif /* _MSC_VER */
/* END REACTOS */

#include <stdio.h>

int main()
{
#ifdef _MSC_VER
    printf("_MSC_VER is %d\n", _MSC_VER);
#else
    printf("_MSC_VER is undefined\n");
#endif

    printf("alignment of char is %ld\n", TYPE_ALIGNMENT(char));
    printf("alignment of double is %ld\n", TYPE_ALIGNMENT(double));

    return 0;
}
