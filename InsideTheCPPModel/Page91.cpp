#include <iostream>
using namespace std;

typedef int length_type;

class Test {
public:
    void foo(length_type val) { // the type of val is `int` (global typedef)
        cout << "sizeof(val)=" << sizeof(val)
             << ", typeid=" << typeid(val).name() << endl;
        _val = val;
    }
    length_type bar() { // the type of return value is `int` (global typedef)
        return _val;
    }

    // If place this line before foo() at line 8,
    // all `length_type` within this class will be `double`
    typedef double length_type;

private:
    length_type _val; // the type of _val is `double` (nested typedef)
};

int main() {
    Test test;
    test.foo(3);
    cout << "sizeof(test.bar())=" << sizeof(test.bar())
         << ", typeid=" << typeid(test.bar()).name() << endl;
    cout << "sizeof(Test::length_type)=" << sizeof(Test::length_type)
         << ", typeid=" << typeid(Test::length_type).name() << endl;
    return 0;
}
