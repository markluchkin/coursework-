#ifndef STRUCTERS_H
#define STRUCTERS_H

#include <wchar.h>

typedef struct{
    wchar_t* chars;
    int size;
}Sentence;

typedef struct{
    Sentence* sentences;
    int size;
}Text;

// typedef struct{
//     wchar_t* chars;
//     int* occurrences;
//     int occurrencesSize;
// } Word;

#endif