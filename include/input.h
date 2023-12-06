#ifndef INPUT_H
#define INPUT_H

//#include <stdio.h>
//#include <string.h>
#include "../include/structures.h"
#include <stdlib.h>
#include <wctype.h>
#include <locale.h>

int getCommand();
Sentence inputSentence(int *sentenceCounter);
Text inputText();
float calculateAverageWordsLength(wchar_t *sentence);

#endif