#include "../include/output.h"

void printCwInfo() {
    wprintf(L"Course work for option 5.2, created by Mark Luchkin.\n");
}

void printText(Text text){
    for (int i = 0; i < text.size; i++){
        wprintf(L"%ls\n", text.sentences[i].chars);
        for (int j = 0; j < text.sentences[i].wordCounter; j++){
            wprintf(L"%ls ", text.sentences[i].punctuation[j]);
        }


        //wprintf(L"средняя длина слов - %f кол-во слов - %d", text.sentences[i].averageWordsLength, text.sentences[i].wordCounter);
        free(&(text.sentences[i]));

    }    
    wprintf(L"\n");
}

void printNeededSentences(Text text){
    for (int i = 0; i < text.size; i++){
        if (text.sentences[i].wordCounter > 5  || text.sentences[i].wordCounter < 2){
            continue;
        }
        wprintf(L"%ls\n", text.sentences[i].chars);
    }
}