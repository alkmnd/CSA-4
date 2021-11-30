//
// Created by Наталья Белова on 30.11.2021.
//

#include <stdio.h>
#include "extdata.h"

double GetQuotient(void *func);

// Вывод данных загадки.
void OutPuzzle(void *puzzle, FILE *file) {
    int length = GetQuotient(((char *) puzzle));
    fprintf(file,
            "This is puzzle: %s\tAnswer: %s\tValue of the function: %f\n", ((char *) puzzle), ((char *) puzzle + sizeof(char)*length), GetQuotient(((char *) puzzle)));

}

// Вывод данных пословицы.
void OutProverb(void *proverb, FILE *file) {
    int length = GetQuotient(((char *) proverb));
    fprintf(file,
            "This is proverb: %s\tCountry: %s\tValue of the function: %f\n", ((char *) proverb), ((char *) proverb + sizeof(char)*length), GetQuotient(((char *) proverb)));
}

// Вывод данных афоризма.
void OutAphorism(void *aphorism, FILE *file) {
    int length = GetQuotient(((char *) aphorism));
    fprintf(file,
            "This is aphorism: %s\tAuthor: %s\tValue of the function: %f\n", ((char *) aphorism), ((char *) aphorism + sizeof(char)*length), GetQuotient(((char *) aphorism)));
}
void OutWellOfWisdom(void *s, FILE *file) {
    int objectType = *((int *)s);
    if (objectType == PUZZLE) {
        OutPuzzle(s + intSize, file);
    } else if (objectType == PROVERB) {
        OutProverb(s + intSize, file);
    } else if (objectType == APHORISM) {
        OutAphorism(s + intSize, file);
    } else {
        fprintf(file, "Incorrect data!\n");
    }
}

// Вывод содержимого контейнера.
void OutContainer(void *container, int length, FILE *file) {
    void *tmp = container;
    fprintf(file, "Container with %d elements:\n", length);
    for (int i = 0; i < length; ++i) {
        fprintf(file, "%d. ", i);
        OutWellOfWisdom(tmp, file);
        tmp = tmp + wellOfWisdomSize;
    }
}