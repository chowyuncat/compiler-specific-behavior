 #include <iostream>

class A
{
public:
    virtual void AMethod() { std::cout << "In A!" << std::endl; }
};

class B : public A
{
private:
    virtual void AMethod() { std::cout << "In B!" << std::endl; } //Hides A::AMethod
};

int main()
{
    B myB;
    myB.AMethod(); //Error: AMethod is private
    static_cast<A*>(&myB)->AMethod(); //Ok
    return 0;
}
