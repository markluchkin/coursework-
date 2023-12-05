#ifndef SORT_H
#define SORT_H

#include "../include/structures.h"
#include <stdlib.h>
#include <wctype.h>
#include <locale.h>

int compareSentences(const void *a, const void *b);
void sortSentences(Text *text);

#endif