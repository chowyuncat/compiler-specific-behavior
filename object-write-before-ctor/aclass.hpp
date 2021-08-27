#include <stdio.h>

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
