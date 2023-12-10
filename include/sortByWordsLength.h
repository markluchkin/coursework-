#ifndef SORTBYWORDSLENGTH_H
#define SORTBYWORDSLENGTH_H

#include "../include/structures.h"
#include <stdlib.h>
#include <wctype.h>
#include <locale.h>

int compareWords(const void* a, const void* b);
void sortWords(Text* text);
#endif