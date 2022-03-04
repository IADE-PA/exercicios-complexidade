# Programação e Algoritmos 2020 2021 - [IADE UE](https://www.iade.europeia.pt/)

## Laboratório 1

Este laboratório propõe vários exercícios sobre cálculo de complexidade.

Para cada tarefa, é necessário identificar a função que melhor descreve o comportamento assimptótico de cada algoritmo. É também necessário identificar o que representa cada parâmetro da função.

# Tarefas

## Tarefa 1

```C
01. #include <stdbool.h> 
02. 
03. bool is_even(const int i) {
04.     if(i % 2 == 0) {
05.         return true;
06.     }
07.     else {
08.         return false;
09.     }
10. }
```

## Tarefa 2

```C
01. int get(const int* numbers, const int size, const int idx) {
02.     for(int i = 0; i < idx && i < size; i++) {
03.         if(i == idx) {
04.             return numbers[i];
05.         }
06.     }
07.     return -1;
08. }
```

## Tarefa 3

```C
01. int* scale(const int* numbers, const int size, const int factor) {
02.     int* scaled = malloc(size * sizeof(int));
03.     for(int i = 0; i < size; i++) {
04.         scaled[i] = numbers[i] * factor;
05.     }
06.     return scaled;
07. }
```

## Tarefa 4

```C
01. int find_a(const int* numbers, const int size, const int target) {
02.     for(int i = 0; i < size; i++) {
03.         if(numbers[i] == target) {
04.             return i;
05.         }
06.     }
07.     return -1;
08. }
```

## Tarefa 5

```C
01. char find_b(const char* strings, const int map_size, 
02.             const char* key, const int key_size) {
03.     int idx = 0;
04.     for(int i=0; i<key_size; i++) {
05.         idx += key[i];
06.     }
07.     idx = idx % map_size;
08.     return strings[idx];
09. }
```

## Tarefa 6

```C
01. // numbers é uma lista de números, ordenada.
02. int b_search(const int* numbers, const int size, const int target) {
03.     int low = 0;
04.     int high = size - 1;
05.     int pivot = (low + high) / 2;
06.     while(low <= high) {
07.         if(numbers[pivot] == target) {
08.             return pivot;
09.         }
10.         else if(numbers[pivot] > target) {
11.             high = pivot - 1;
12.         }
13.         else {
14.             low = pivot + 1;
15.         }
16.         pivot = (low + high) / 2;
17.     }
18.     return -1;
19. }
```

## Tarefa 7

```C
01. double* zscore(const int* numbers, const int size) {
02.     double* zeros = malloc(size * sizeof(double));
03.     double average = 0;
04.     double std_dev = 0;
05.     for(int i = 0; i < size; i++) {
06.         average += numbers[i];
07.     }
08.     average = average / size;
09.     for(int i = 0; i < size; i++) {
10.         std_dev += (numbers[i] - average) * (numbers[i] - average);
11.     }
12.     std_dev = sqrt(std_dev / size);
13.     int count = 0;
14.     for(int i = 0; i < size; i++) {
15.         zeros[i] = (numbers[i] - average) / std_dev;
16.     }
17.     return zeros;
18. }
```
