#include <iostream>
#include <Windows.h>

using namespace std;

int main(){

    constexpr int BufferSize = 10;
    void* readTest;
    SIZE_T size = sizeof(char) * BufferSize;
    constexpr int Address = 0x0057AC50;

    HWND hwnd = FindWindowA(NULL, "Dummy Window!"); // HWND (Windows window) by Window Name

    // Check if HWND found the Window
    if (hwnd == NULL) {
        cout << "Can't find Process." << endl;
        exit(-1); // Exit the program if it did not find the Window
    } else {
        DWORD procID; // A 32-bit unsigned integer, DWORDS are mostly used to store Hexadecimal Addresses
        GetWindowThreadProcessId(hwnd, &procID); // Getting our Process ID, as an ex. like 000027AC
        HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID); // Opening the Process with All Access

        if (procID == NULL) {
            cout << "Can't find Process." << endl;
            exit(-1);
        } else
        {
            // Read the Process Memory, we read the Value from and save it in readTest
            ReadProcessMemory(handle, (PBYTE*)Address, &readTest,size, 0);

            cout << readTest << endl;

            // convert to store Hexadecimal Addresses
            DWORD* Address = (DWORD*)&readTest;
            cout << ((char*)Address) << endl;
            cout << &Address << endl;

            // same but if you want to offset the bytes. use char* intead using DWORD* 
            cout << "CharAddress" << endl;
            constexpr int OFFSET = 0;
            char* CharAddress = (char*)&readTest + OFFSET;
            cout << CharAddress << endl;
            exit(0);
        }
    }
    free(readTest);
}