//
// Created by Наталья Белова on 30.11.2021.
//
#include <stdlib.h>

#include "extdata.h"

int Random(int x) {
    x++;
    return rand() % x;
}

// Генерация данных для объекта.
void InRnd(void *object) {
    const char symbols[] = "qwertyuiopasdfghjkl;:zxcvbnm,.!?";
    int first = Random(20) + 1;
    char* type_parameter = malloc(sizeof(char) * first);
    for (int i = 0; i < first; ++i) {
        int key = Random(31);
        type_parameter[i] = symbols[key];
    }
    type_parameter[first] = '\0';

    *(char *) (object) = *type_parameter;
    int second = Random(20) + 1;
    char* general_parameter = malloc(sizeof(char) * second);
    
        
        for (int i = 0; i < second; ++i) {
            int key = Random(31);
            general_parameter[i] = symbols[key];
        }
        general_parameter[second] = '\0';
    
    *(char *) (object + first * sizeof(char)) = *general_parameter;
}

// Генерация данных для объекта.
int InRndWellOfWisdom(void *s) {
    int objectType = Random(2) + 1;
    switch (objectType) {
        case 1:
            *((int *)s) = PUZZLE;
            InRnd(s + intSize);
            return 0;
        case 2:
            *((int *)s) = PROVERB;
            InRnd(s + intSize);
            return 0;
        case 3:
            *((int *)s) = APHORISM;
            InRnd(s + intSize);
            return 0;
        default:
            return 1;

    }
}

// Генеарция данных для контейнера.
void InRndContainer(void *c, int *length, int size) {
    void *tmp = c;
    while (*length < size) {
        if (!InRndWellOfWisdom(tmp)) {
            tmp = tmp + wellOfWisdomSize;
            (*length)++;
        }
    }
}
