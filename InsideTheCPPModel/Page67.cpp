// NRV: Named Return Value
// Actually the copy constructor is not called.
// Compiler: g++ 8.1.0 (MinGW)

#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

class Test {
    friend Test foo(double);

public:
    Test() {
        memset(arr, 0, 100 * sizeof(double));
    }
    Test(const Test& t) {
        cout << "Test\n";
        memcpy(this, &t, sizeof(Test));
    }

private:
    double arr[100];
};

Test foo(double val) {
    Test local;
    local.arr[0] = local.arr[99] = val;
    return local;
}

int main() {
    clock_t start = clock();
    for (int i = 0; i < 100000000; i++) {
        Test t = foo(double(i));
    }    
    clock_t end = clock();
    cout << "Time elapsed: " << double(end - start) / CLOCKS_PER_SEC * 1000 << " ms\n";
    return 0;
}
