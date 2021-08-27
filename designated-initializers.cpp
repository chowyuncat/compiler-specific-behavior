#include <stdio.h>

struct Complicated {
    int x;
    int y;
};

struct Simple {
    int y;
};

Complicated MakeComplicated(const Simple &simple) {
   Complicated c = {
     .x = 2,
     .y = simple.y
   };

   return c;
}


int main()
{
    Complicated c = MakeComplicated({ .y = 1 });
    printf("%d\n", c.x);
    printf("%d\n", c.y);
}
