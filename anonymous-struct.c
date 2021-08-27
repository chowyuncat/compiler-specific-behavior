#include <stdio.h>

struct Base
{
    int base_field;
};

union DerivedUnion
{
    struct
    {
        int base_field;
    };
    int derived_field;
};


struct DerivedStruct
{
    struct Base;
    int derived_field;
};

static void show_base(const struct Base* b)
{
    printf("base_field: %d\n", b->base_field);
}

int main()
{
    struct Base b = { 0 };
    union DerivedUnion d_u;
    struct DerivedStruct d_s;

    d_u.base_field = 1;
    d_u.derived_field = 2;

    d_s.base_field = 3;
    d_s.derived_field = 4;


    show_base(&b);
    show_base((struct Base*)&d_u);
    show_base((struct Base*)&d_s);

    return 0;
}