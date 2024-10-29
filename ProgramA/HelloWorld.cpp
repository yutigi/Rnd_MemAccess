#include <iostream>
#include <Windows.h>
using namespace std;

static const char static_value[] = "Test12345";

int main() {
    //int static_value = 99;
    cout << static_value << endl;
    cout << &static_value << endl;

    HWND dummyHWND = ::CreateWindowA("STATIC","dummy",
        WS_VISIBLE,0,0,100,100,NULL,NULL,NULL,NULL);
    ::SetWindowTextA(dummyHWND,"Dummy Window!");
    ShowWindow(dummyHWND,SW_SHOW);

    system("pause");
    return 0;
}
