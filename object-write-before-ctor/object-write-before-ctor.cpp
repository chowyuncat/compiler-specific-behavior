#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <new>


class AClass {
public:
    AClass() {
        if (Field0 == -1) {
            printf("write observed\n");
        }
        else {
            printf("write not observed\n"); 
        }
    }

    void MemberFunction() {
        if (Field0 == -1) {
            printf("write observed\n");
        }
        else {
            printf("write not observed\n"); 
        }
    }
    int Field0; 
};


int undefined_behavior(int argc) {
    AClass* aClass = static_cast<AClass*>(malloc(sizeof(*aClass)));
    
    memset(aClass, 0x0, sizeof(*aClass));

    if (argc > 1) {
        // write_object(aClass);
        // printf("write should be observed after:\n");
        aClass->Field0 = -1;
        // memset(aClass, 0xFF, sizeof(*aClass));
    }

    return (new (aClass) AClass())->Field0;
    // aClass->MemberFunction();
    // return aClass->Field0;
}

int main(int argc, char **argv) {
    if (undefined_behavior(argc) == undefined_behavior(argc + 1))
    {
        printf("warning: undefined behavior observed for %s\n", COMPILER_DESC);
    }
    else
    {
        printf("undefined behavior not observed for %s\n", COMPILER_DESC);
    }
}
