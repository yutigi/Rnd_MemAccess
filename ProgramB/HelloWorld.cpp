// #include <iostream>
// using namespace std;
//
// int main() {
//     int* mem = (int*)(0x002DC044);
//     cout << "Memory address: " << mem << endl;
//     cout << *mem << endl;
//     cout << &mem << endl;
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <Windows.h>

using namespace std;

int main(){

    int readTest = 0; // We store the Value we read from the Process here

    HWND hwnd = FindWindowA(NULL, "Dummy Window!"); // HWND (Windows window) by Window Name

    // Check if HWND found the Window
    if (hwnd == NULL) {
        cout << "Can't find Process." << endl;
        Sleep(2000); // Sleep 2 seconds
        exit(-1); // Exit the program if it did not find the Window
    } else {
        DWORD procID; // A 32-bit unsigned integer, DWORDS are mostly used to store Hexadecimal Addresses
        GetWindowThreadProcessId(hwnd, &procID); // Getting our Process ID, as an ex. like 000027AC
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); // Opening the Process with All Access

        if (procID == NULL) {
            cout << "Can't find Process." << endl;
            Sleep(2000); // Sleep 2 seconds
            exit(-1); // Exit the program if it did not find the Window
        } else {
            // Read the Process Memory, 03007640 is the Address, we read the Value from and save it in readTest
            ReadProcessMemory(handle, (PBYTE*)0x00E4A000, &readTest, sizeof(readTest), 0);
            cout << readTest << endl;
            Sleep(5000); // Sleep 5 seconds
        }
    }
}