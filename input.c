//
// Created by Наталья Белова on 30.11.2021.
//
#include <stdio.h>
#include "extdata.h"
double GetQuotient(void *func);

// Считывание данных пословицы.
void InProverb(void *func, FILE* file) {
    fscanf(file, "%s\n", (char*) (func));
    int length = GetQuotient(func);
    fscanf(file, "%s\n", (char*) (func + sizeof(char)*length));
}

// Считывание данных для загадки.
void InPuzzle(void *func, FILE* file) {
    fscanf(file, "%s\n", (char*) (func));
    int length = GetQuotient(func);
    fscanf(file, "%s\n", (char*) (func + sizeof(char)*length));
}

// Считывание данных для афоризма.
void InAphorism(void *func, FILE* file) {
    fscanf(file, "%s\n", (char*) (func));int length = GetQuotient(func);
    fscanf(file, "%s\n", (char*) (func + sizeof(char)*length));fscanf(file, "%s\n", (char*) (func + sizeof(char *)));
}

// Считывание объекта.
int InWellOfWisdom(void *s, FILE* file) {
    int objectType;
    int status_code = fscanf(file, "%d\n", &objectType);
    if (status_code != 1) {
        return 1;
    }
    switch (objectType) {
        case 1:
            *((int *)s) = PUZZLE;
            InPuzzle(s + intSize, file);
            return 0;
        case 2:
            *((int *)s) = PROVERB;
            InProverb(s + intSize, file);
            return 0;
        case 3:
            *((int *)s) = APHORISM;
            InAphorism(s + intSize, file);
            return 0;
        default:
            return 1;
    }
}

// Ввод содержимого файла в контейнер.
void InContainer(void *c, int *length, FILE* file) {
    int status_code = fscanf(file, "%d\n", length);
    if (status_code != 1) {
        printf("Incorrect data in the input file!\n");
        return;
    }
    void *tmp = c;
    while (!feof(file)) {
        if (!InWellOfWisdom(tmp, file)) {
            tmp = tmp + wellOfWisdomSize;
        } else {
            printf("Incorrect data in the input file!\n");
            return;
        }
    }
}

