#include "../include/output.h"

void printCwInfo() {
    wprintf(L"Course work for option 5.2, created by Mark Luchkin.\n");
}

void printText(Text text){
    for (int i = 0; i < text.size; i++){
        wprintf(L"%ls\n", text.sentences[i].chars);
        wprintf(L"средняя длина слов - %f длина текста - %d\n", text.sentences[i].averageWordsLength, text.size);
    }
    wprintf(L"\n");
}