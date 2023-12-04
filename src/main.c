#include "../include/main.h"

int main() {
    setlocale(LC_ALL, "");

    printCwInfo();

    switch (getCommand()){
        case 1: 
        //wprintf(L"ПРИВЕТ ITS 1\n");
        printText(inputText());
        break;
        case 2:
        wprintf(L"HELLO ITS 2\n");
        break;
        case 3:
        wprintf(L"HELLO ITS 3\n");
        break;
        case 4:
        wprintf(L"HELLO ITS 4\n");
        break;
        case 5:
        wprintf(L"HELLO ITS 5\n");
        break;
    }
    return 0;
}
