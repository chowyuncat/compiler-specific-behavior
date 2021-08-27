#include <stdio.h>

typedef void VOID;

class Class
{
public:
    Class(bool b) :
    m_B(b)
    {};
    ~Class(VOID) {};
private:
    const bool m_B;
};

int main()
{
    Class c(false);
    Class d(true);

    return 0;
}

