#include "../include/input.h"

int getCommand(){
    int commandNumber;
    wscanf(L"%d", &commandNumber);

    return commandNumber;
}

Sentence inputSentence(int * sentenceCounter){
    Sentence sentence;
    sentence.chars = malloc(sizeof(wchar_t));
    int sentenceCapacity = 1;
    int sentenceSize = 0;
    wchar_t currChar = getwchar();
    int flag = 1;

    while(currChar != L'.'){
        if (currChar == L'\n'){
            (*sentenceCounter)++;
            if ((*sentenceCounter) == 2){
                break;
            }
            continue;
        }

        if (isspace(currChar) && flag){
            continue;
        }

        flag = 0;
        sentence.chars[sentenceSize++] = currChar;
        if (sentenceSize >= sentenceCapacity){
            sentenceCapacity *= 2;
            sentence.chars = realloc(sentence.chars, sentenceCapacity * sizeof(wchar_t)); 
        }

        currChar = getwchar();
    }
    sentence.chars[sentenceSize] = L'\0';
    sentence.size = sentenceSize;
    return sentence;
}

Text inputText(){
    Text text;
    text.sentences = malloc(sizeof(Sentence));
    int textCapacity = 1;
    int textSize = 0;
    int sentenceCounter = 0;

    for(;;){
        Sentence currSentence = inputSentence(&sentenceCounter);
        int identicalSentences = 0;

        for (int i = 0; i < textSize; ++i) {
            if(wcscasecmp(currSentence.chars, text.sentences[i].chars) == 0){
                identicalSentences = 1;
                break;
            }

        }

        if (sentenceCounter == 2){
            break;
        }else{
            sentenceCounter = 0;
        }

        if (identicalSentences == 1){
            continue;
        }

        
    }
}

