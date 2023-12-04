#ifndef STRUCTERS_H
#define STRUCTERS_H

#include <wchar.h>

typedef struct{
    wchar_t* chars;
    int size;
    float averageWordsLength;
}Sentence;

typedef struct{
    Sentence* sentences;
    int size;
}Text;

#endif