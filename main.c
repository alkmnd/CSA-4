#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/unistd.h>
#include <unistd.h>
#include "data.h"

// Метод для получения входного файла.
FILE* GetInputFile(char* argv[]) {
    if(access(argv[1], F_OK)!=-1){
        return fopen(argv[1],   "r");
    }
    else{
        printf("Could not open input file!\n");
        return NULL;
    }
}
// Получение выходного файла.
FILE* GetOutputFile(char* argv[], int number){
    if(access(argv[number], F_OK)!=-1){
        return fopen(argv[number], "w");
    } else {
        printf("Could not open output file!\n");
        return NULL;
    }
}

int main(int argc, char *argv[]) {
    time_t start, end;
    start = clock();
    unsigned char container[maxSize];
    int length = 0;
    if (argc < 3) {
        end = clock();
        printf("Incorrect input!\n");
        printf("Elapsed: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
        return 1;
    } else if (argc == 3) {
        FILE *file = GetInputFile(argv);
        if (file == NULL) {
            return 1;
        }
        InContainer(container, &length, file);
        FILE *output_file = GetOutputFile(argv, 2);
        if (output_file == NULL) {
            return 1;
        }
        OutContainer(container, length, output_file);

    } else if ((argc == 4) && !strcmp(argv[1], "-r")) {
        int numberOfObjects = atoi(argv[2]);
        if ((numberOfObjects < 1) || (numberOfObjects > 100)) {
            printf("The number of objects must be in the range 1 to 10000\n");
            end = clock();
            printf("Elapsed: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
            return 1;
        }
        srand((unsigned int) (time(0)));
        InRndContainer(container, &length, numberOfObjects);
        FILE *output_file = GetOutputFile(argv, 3);
        if (output_file == NULL) {
            return 1;
        }
        OutContainer(container, length, output_file);
    } else {
        end = clock();
        printf("incorrect command line!\n");
        printf("Elapsed time: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
        return 1;
    }

    end = clock();
    printf("Elapsed time: %f\n", difftime(end, start) / CLOCKS_PER_SEC);
    return 0;
}