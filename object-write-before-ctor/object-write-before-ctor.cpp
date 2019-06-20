#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <new>

typedef struct _POD
{
    int Field0;
    int Field1;
} POD;

class AClass
{
public:
 
    AClass() 
    {
        if (m_PodMember.Field0 == -1)
        {
            printf("observed\n");
        }
        else
        {
            printf("not observed\n"); 
        }

    }

public:
        POD m_PodMember; 
};

void undefined_behavior(int argc)
{
    AClass *aClass = static_cast<AClass*>(malloc(sizeof(*aClass)));
    if (argc > 1)
    {
        aClass->m_PodMember.Field0 = -1;
    }
    // printf("read before ctor: %d\n", aClass->m_PodMember.Field0);
    new (aClass) AClass();
}


int main(int argc, char **argv)
{
    undefined_behavior(argc);
    undefined_behavior(argc + 1);
}
