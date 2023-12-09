#include "../include/input.h"

int getCommand(){
    int commandNumber;
    wscanf(L"%d", &commandNumber);

    return commandNumber;
}

Sentence inputSentence(int *newLineCounter){
    Sentence sentence;
    sentence.chars = malloc(sizeof(wchar_t));
    int sentenceCapacity = 1;
    int sentenceSize = 0;
    wchar_t currChar = getwchar();
    int flag = 1;

    do{
        currChar = getwchar();
        if (currChar == L'\n'){
            (*newLineCounter)++;
            if ((*newLineCounter) == 2){
                break;
            }
            continue;
        }

        if (iswspace(currChar) && flag){
            continue;
        }

        flag = 0;
        sentence.chars[sentenceSize++] = currChar;
        if (sentenceSize >= sentenceCapacity){
            sentenceCapacity *= 2;
            sentence.chars = realloc(sentence.chars, sentenceCapacity * sizeof(wchar_t)); 
        }

         
    }while(currChar != L'.');
    sentence.chars[sentenceSize] = L'\0';
    sentence.size = sentenceSize;
    
    int wordCounter = 0;
    wchar_t* tokenBuffer;
    wchar_t* copy = wcsdup(sentence.chars); 
    wchar_t* word = wcstok(copy, L" ,", &tokenBuffer);

    while (word != NULL) {
        wordCounter++;
        word = wcstok(NULL, L" ,", &tokenBuffer);
    }

    sentence.wordCounter = wordCounter;

    return sentence;
}

Text inputText(){
    Text text;
    text.sentences = malloc(sizeof(Sentence));
    int textCapacity = 1;
    int textSize = 0;
    int newLineCounter = 0;

    for(;;){
        Sentence currSentence = inputSentence(&newLineCounter);
        int identicalSentences = 0;

        for (int i = 0; i < textSize; ++i) {
            if(wcscasecmp(currSentence.chars, text.sentences[i].chars) == 0){
                identicalSentences = 1;
                break;
            }

        }

        if (newLineCounter == 2){
            break;
        }else{
            newLineCounter = 1;
        }

        if (identicalSentences == 1){
            continue;
        }

        wchar_t *tokenBuffer;
        wchar_t *token = wcstok(wcsdup(currSentence.chars), L" .,", &tokenBuffer);
        if ((token) == NULL){
            continue;
        }

        text.sentences[textSize] = currSentence;
        text.sentences[textSize].averageWordsLength = calculateAverageWordsLength(currSentence.chars);
        text.sentences[textSize].punctuation = getPunctuation(currSentence);
        textSize++;
        text.size = textSize;

        if (textSize >= textCapacity){
            textCapacity *= 2;
            text.sentences = realloc(text.sentences, textCapacity * sizeof(Sentence));
        }
    }

    if (text.sentences[0].chars == NULL){
        wprintf(L"Error: Incorrect input.\n");
        exit(0);

    }

    return text;
}

float calculateAverageWordsLength(wchar_t *sentence){
    int wordCounter = 0;
    float totalLength = 0;
    wchar_t* tokenBuffer;
    wchar_t* token = wcstok(wcsdup(sentence), L" .,", &tokenBuffer);
    
    while (token != NULL) {
        wordCounter++;
        totalLength += wcslen(token);
        token = wcstok(NULL, L" .,", &tokenBuffer);
    }

    return wordCounter > 0 ? (float)(totalLength / wordCounter) : 0.0f;
}


wchar_t **getPunctuation(Sentence sentence){
    int punctuationCapacity = 1;
    int punctuationSize = 0;
    wchar_t **punctuation = malloc(punctuationCapacity * sizeof(wchar_t *));

    for (int i = 0; i <= sentence.size; i++){
        if (sentence.chars[i] == L' ' || sentence.chars[i] == L',' || sentence.chars[i] == L'.'){
            int capacity = 1;
            int size = 0;
            int index = 0;
            wchar_t *currChars = malloc(capacity * sizeof(wchar_t));
            while (!iswalnum(sentence.chars[i + index])){
                currChars[size] = sentence.chars[i + index];
                index++;
                size++;
                if (size >= capacity){
                    capacity *= 2;
                    currChars = realloc(currChars, capacity * sizeof(wchar_t));
                }
                
            }

            punctuation[punctuationSize] = currChars;
            punctuationSize++;
            if (size >= capacity){
                punctuationCapacity *= 2;
                punctuation = realloc(punctuation, capacity * sizeof(wchar_t*));
            }
        }
    }
    return punctuation;
}
