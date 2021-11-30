//
// Created by Наталья Белова on 30.11.2021.
//

#ifndef _4_DATA_H
#define _4_DATA_H
//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------
// Константа, определяющая размер числа с плаващей точкой
int const doubleSize = sizeof(double);
// Константа определяет размер char
int const charArraySize = 10000 * sizeof(char);
// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, задающая размер для пословицы
int const proverbSize = 10000 * sizeof(char);
// Константа, задающая размер для загадки
int const puzzleSize = 10000 * sizeof(char);
// Константа, задающая размер для афоризма
int const aphorismSize = 10000 * sizeof(char);
//Контанта, задащая размер кладези мудрссти.
int const wellOfWisdomSize = sizeof(int) + aphorismSize;
// Константа, определяющая размерность массива фигур
int const maxSize = 1000000;
// Константа, задающая признак процедурный язык
int const APHORISM = 3;
// Константа, задающая признак объект-ориентированый язык
int const PROVERB = 2;
// Константа, задающая признак функциональный язык
int const PUZZLE = 1;


//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *f);

#endif //_4_DATA_H