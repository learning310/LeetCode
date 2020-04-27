class X {
public:
    X();
};

X::X()
{
}

void f(int i)
{
    if (i < 10)
    {
        //!goto jump1;//Error: goto bypasses init
    }
    X x1; //Constructor called here
jump1:
    switch (i)
    {
    case1:
        X x2; //Constructor called here
        break;
        //!case2: //Error: case bypasses init
        X x3;
        break;
    }
}