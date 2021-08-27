#include <stdio.h>

typedef struct _UNICODE_STRING
{
    char Buffer;
    int Length;
} UNICODE_STRING, *PUNICODE_STRING;


// Typedef in public/ndk/umtypes.h:
typedef const UNICODE_STRING* PCUNICODE_STRING;


static void func1(PUNICODE_STRING a)
{
    a->Length = 1;
    printf("func1\n");
}

static void func2(const PUNICODE_STRING a)
{
    a = NULL;
    a->Length = 2;
    printf("func1\n");
}

static void func3(const _UNICODE_STRING *a)
{
    // a->Length = 2;
    printf("func1\n");
}

static void func4(PCUNICODE_STRING a)
{
    a->Length = 2;
    printf("func1\n");
}

int main()
{
    UNICODE_STRING nonconst = { 0 };
    const UNICODE_STRING immutable = { 0 };
    // func1(&nonconst);
    // func2(&immutable);       
    // func3(&immutable);

    return 0;
}