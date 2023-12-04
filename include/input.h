#ifndef INPUTTEXT_H
#define INPUTTEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include <wctype.h>
#include <wchar.h>
#include <locale.h>
#include "../include/structures.h"

int getCommand();
Sentence inputSentence(int *sentenceCounter);
Text inputText();


#endif