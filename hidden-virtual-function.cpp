/* Hidden virtual function

    clang++ -Wall will complain unless you add:
        using Base::get;

    The using statement does not need to have private access.

    clang++ -Wall:
    /hidden-virtual-function.cpp:24:17: warning: 'Derived::get' hides overloaded virtual function [-Woverloaded-virtual]
        virtual int get(int index)
                ^
    ./hidden-virtual-function.cpp:15:17: note: hidden overloaded virtual function 'Base::get' declared here: different number of parameters (0 vs 1)
        virtual int get()
*/

#include <stdio.h>

class Base
{
public:
    virtual int get()
    {
        return 1;
    }
};

class Derived : public Base
{
public:
    virtual int get(int index)
    {
        return 2;
    }
private: // useless!
   using Base::get;
};

class SafelyDerived : public Base
{
public:
    virtual int get(int index)
    {
        return 3;
    }
private: // mostly useless!
   virtual int get() { return Base::get(); }
};


int main()
{
    Base b;
    printf("b.get()  = %d\n", b.get());

    Derived d;
    Base *baseD = &d;
    baseD->get(); // access is only controlled at compile time
    printf("d.get(0) = %d\n", d.get(0));
    printf("d.get()  = %d\n", d.Base::get()); // even this still works

    SafelyDerived s;
    Base *baseS = &s;
    baseS->get(); // access is only controlled at compile time
    printf("s.get(0) = %d\n", s.get(0));
    printf("s.get()  = %d\n", s.Base::get()); // even this still works
    // printf("s.get(0) = %d\n", s.get()); // compile-time error
    return 0;
}