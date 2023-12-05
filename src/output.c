#include "../include/output.h"

void printCwInfo() {
    wprintf(L"Course work for option 5.2, created by Mark Luchkin.\n");
}

void printText(Text text){
    for (int i = 0; i < text.size; i++){
        wprintf(L"%ls\n", text.sentences[i].chars);
        //wprintf(L"средняя длина слов - %f кол-во слов - %d", text.sentences[i].averageWordsLength, text.sentences[i].wordCounter);
    }
    wprintf(L"\n");
}

