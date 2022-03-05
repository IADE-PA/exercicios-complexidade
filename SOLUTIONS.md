# Programação e Algoritmos 2020 2021 - [IADE UE](https://www.iade.europeia.pt/)

## Laboratório 1 (Resolução)

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

| Linha | Custo         | Operações                        |
| ----- | ------------- | -------------------------------- |
| 4     | 1 + 1 + 1 = 3 | Obter `i`, aritmética, comparar. |
| 5     | &emsp; 1      | Retornar.                        |
| 8     | &emsp; 1      | Retornar.                        |

**Custo:** `3 + 1 + 1 = 5 = O(1)`

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

Definimos `n = min(idx, size)`.

| Linha | Custo                          | Operações                                                                                                               |
| ----- | ------------------------------ | ----------------------------------------------------------------------------------------------------------------------- |
| 2     | 1+1 = 2                        | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                                                                 |
|       | n iterações das linhas 2-5     |                                                                                                                         |
| 2     | 1+1+1+1+1+1+1+1+1+1 = 10       | obter `i`, obter `idx`, comparar, obter `i`, obter `size`, comparar, operação booleana, obter `i`, incrementar, afetar. |
| 3     | &emsp; 1 + 1 + 1 = 3           | Obter `i`, obter `idx`, comparar.                                                                                       |
| 4     | &emsp;&emsp; 1 + 1 + 1 + 1 = 4 | Obter `i`, obter `numbers`, obter `numbers[i]`, retornar.                                                               |
|       | &emsp; 0                       | `else` implícito.                                                                                                       |
| 5     | 1                              | Retornar.                                                                                                               |

**Custo:** `2 + n * (10 + max(3, 4, 0)) + 1 = 3 + 14n = O(n)`

## Tarefa 3

```C
01. #include <stdlib.h>
02
03. int* scale(const int* numbers, const int size, const int factor) {
04.     int* scaled = malloc(size * sizeof(int));
05.     for(int i = 0; i < size; i++) {
06.         scaled[i] = numbers[i] * factor;
07.     }
08.     return scaled;
09. }
```

Definimos `n = size`.

| Linha | Custo                        | Operações                                                                                                                          |
| ----- | ---------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
| 4     | 1+1+1+1 = 4                  | Declarar `scaled`, obter `size`, invocar `sizeof`, invocar `malloc`.                                                               |
| 5     | 1+1 = 2                      | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                                                                            |
|       | n iterações das linhas 5-7   |                                                                                                                                    |
| 5     | 1+1+1+1+1+1 = 6              | Obter `i`, obter `size`, comparar, obter `i`, incrementar, afetar.                                                                 |
| 6     | &emsp; 1+1+1+1+1+1+1+1+1 = 9 | Obter `scaled`, obter `i`, obter `scaled[i]`, obter `numbers`, obter `i`, obter `numbers[i]`, obter `factor`, multiplicar, afetar. |
| 8     | 1+1 = 2                      | Obter `scaled`, retornar.                                                                                                          |

**Custo:** `4 + 2 + n * (6 + 9) + 2 = 8 + 15n = O(n)`

## Tarefa 4

```C
01.  int find_a(const int* numbers, const int size, const int target) {
02.      for(int i = 0; i < size; i++) {
03.          if(numbers[i] == target) {
04.              return i;
05.          }
06.      }
07.      return -1;
08.  }
```

Definimos `n = size`.

| Linha | Custo                      | Operações                                                                 |
| ----- | -------------------------- | ------------------------------------------------------------------------- |
| 2     | 1+1 = 2                    | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                   |
|       | n iterações das linhas 2-7 |                                                                           |
| 2     | 1+1+1+1+1+1 = 6            | Obter `i`, obter `size`, comparar, obter `i`, incrementar, afetar.        |
| 3     | &emsp; 1+1+1+1+1 = 5       | Obter `numbers`, obter `i`, obter `numbers[i]`, obter `target`, comparar. |
| 4     | &emsp;&emsp; 1+1 = 2       | Obter i, retornar.                                                        |
|       | &emsp; 0                   | `else` implícito.                                                         |
| 7     | 1                          | Retornar.                                                                 |

**Custo:** `2 + n * (2 + max(5, 2, 0)) + 1 = 3 + 7n = O(n)`

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

Definimos `n = key_size`.

| Linha | Custo                      | Operações                                                                  |
| ----- | -------------------------- | -------------------------------------------------------------------------- |
| 3     | 1+1 = 2                    | Declarar `idx`, afetação.                                                  |
| 4     | 1+1 = 2                    | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                    |
|       | n iterações das linhas 4-6 |                                                                            |
| 4     | 1+1+1+1+1+1 = 6            | Obter `i`, obter `key_size`, comparar, obter `i`, incrementar, afetar.     |
| 5     | &emsp; 1+1+1+1+1+1 = 6     | Obter `key`, obter `i`, obter `key[i]`, obter `idx`, aritmética, afetação. |
| 7     | 1+1+1+1 = 4                | Obter `idx`, obter `map_size`, aritmética, afetação.                       |
| 8     | 1                          | Obter `strings`, obter `idx`, obter `strings[idx]`, retornar.              |

**Custo:** `2 + 2 + n * (6 + 6) + 4 + 2 = 10 + 12n = O(n)`

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

Definimos `n = size`.

| Linha | Custo                            | Operações                                                                        |
| ----- | -------------------------------- | -------------------------------------------------------------------------------- |
| 3     | 1+1 = 2                          | Declarar `low`, afetar.                                                          |
| 4     | 1+1+1+1 = 4                      | Declarar `high`, obter `size`, aritmética, afetar.                               |
| 5     |                                  | Declarar `pivot`, obter `low`, obter `hight`, aritmética, aritmética, afetar.    |
|       | `f(n)` iterações das linhas 6-17 |                                                                                  |
| 6     | 1+1+1 = 3                        | Obter `low`, obter `high`, comparar                                              |
| 7     | &emsp; 1+1+1+1+1 = 5             | Obter `numbers`, obter `pivot`, obter `numbers[pivot]`, obter `target`, comparar |
| 8     | &emsp;&emsp; 1+1 = 2             | Obter `pivot`, retorar.                                                          |
| 10    | &emsp; 1+1+1+1+1 = 5             | Obter `numbers`, obter `pivot`, obter `numbers[pivot]`, obter `target`, comparar |
| 11    | &emsp;&emsp; 1+1+1 = 3           | Obter `pivot`, aritmética, afetar `high`.                                        |
| 14    | &emsp;&emsp; 1+1+1 = 3           | Obter `pivot`, aritmética, afetar `low`.                                         |
| 16    | &emsp;                           | Obter `low`, obter `high`, aritmética, aritmética, afetar `pivot`.               |
| 18    | 1                                | Retornar.                                                                        |

O custo é determinado por `2 + 4 + f(n) * (max(5, 2, 3, 5, 3, 3)) + 1 = 6 + 5f(n) = O(f(n))`, onde `f(n)` modela a taxa de aproximação entre `high` e `low`.

Cada alteração de `high` ou `low` reduz o espaço de procura em 50%, ou seja, de um conjunto inicial de `n` elementos, após a primeira iteração o espaço reduz-se para `n/2` elementos, após a segunda para `n/4`, e assim sucessivamente.

![Seccionamento do espaço na [pesquisa binária](https://en.wikipedia.org/wiki/Binary_search_algorithm) (caso particular da [pesquisa dicotómica](https://en.wikipedia.org/wiki/Dichotomic_search)).](figures/bsearch.png)

Eventualmente, o espaço de resultados irá corresponder a apenas 1 elemento, onde será possível determinar o fim do algoritmo.

O custo de cada iteração é constante, visto que o comportamento assimptótico das linhas 6 até 17 é constante.

Com `C` igual ao custo assimptótico das linhas 6 até 17, temos que cada iteração do ciclo, onde o espaço de resultados é reduzido por um fator de `1/2`, tem custo `C`. Portanto, para determinar um resultado do algoritmo executamos `Cn + Cn/2 + Cn/4 + ... + C2 + C1`, onde `C` é executado `k` vezes, com `k` número inteiro positivo. Pretendemos expressar `k` como uma função de `n`.

Sabemos que cada iteração corresponde à aplicação do factor `1/2` ao espaço de resultados possíveis, tal como `n, n/2, n/4, ..., 2, 1`. Temos, portanto, `1 * 2 * 2 ... * 2 = n`.

Sabendo que a aplicação do fator ocorre a cada iteração, e que em cada iteração ocorre `C`, temos `1 * 2^k = n`.

Como `b^y=x` implica `log_b(x) = y`, concluímos que `2^k = n`, implica `log_2(n) = k`.

**Custo:** `O(log(n))`

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

Definimos `n = size`.

| Linha | Custo                                   | Operações                                                                                                                                                                                                   |
| ----- | --------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 2     | 1+1+1+1+1+1 = 6                         | Declarar `zeros`, obter `size`, invocar `sizeof`, aritmética, invocar `malloc`, afetar.                                                                                                                     |
| 3     | 1+1 = 2                                 | Declarar `average`, afetar.                                                                                                                                                                                 |
| 4     | 1+1 = 2                                 | Declarar `std_dev`, afetar.                                                                                                                                                                                 |
| 5     | 1+1 = 2                                 | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                                                                                                                                                     |
|       | n iterações das linhas 5-7              |                                                                                                                                                                                                             |
| 5     | 1+1+1+1+1+1 = 6                         | Obter `i`, obter `size`, comparar, obter `i`, incrementar, afetar.                                                                                                                                          |
| 6     | &emsp; 1+1+1+1+1+1 = 6                  | Obter `numbers`, obter `i`, obter `numbers[i]`, obter `average`, aritmética, afetar.                                                                                                                        |
| 8     | 1+1+1+1 = 4                             | obter `average`, obter `size`, aritmética, afetar.                                                                                                                                                          |
| 9     | 1+1 = 2                                 | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                                                                                                                                                     |
|       | n iterações das linhas 9-11             |                                                                                                                                                                                                             |
| 9     | 1+1+1+1+1+1 = 6                         | Obter `i`, obter `size`, comparar, obter `i`, incrementar, afetar.                                                                                                                                          |
| 10    | &emsp; 1+1+1+1+1+1+1+1+1+1+1+1+1+1 = 14 | Obter `numbers`, obter `i`, obter `numbers[i]`, obter `average`, artimética, obter `numbers`, obter `i`, obter `numbers[i]`, obter `average`, artimética, aritmética, obter `std_dev`,  artimética, afetar. |
| 13    | 1+1+1+1 = 4                             | Obter `std_dev`, obter `size`, artimética, afetar.                                                                                                                                                          |
| 14    | 1+1 = 2                                 | Inicializar ciclo `for`: declarar `i`, inicializar `i`.                                                                                                                                                     |
|       | n iterações das linhas 14-16            |                                                                                                                                                                                                             |
| 14    | 1+1+1+1+1+1 = 6                         | Obter `i`, obter `size`, comparar, obter `i`, incrementar, afetar.                                                                                                                                          |
| 15    | &emsp; 1+1+1+1+1+1+1+1+1+1+1 = 11       | Obter `numbers`, obter `i`, obter `numbers[i]`, obter `average`, aritmética, obter `std_dev`, aritmética, obter `zeros`, obter `i`, obter `zeros[i]`, afetar.                                               |
| 17    | 1+1 = 2                                 | Obter `zeros`, retornar.                                                                                                                                                                                    |

**Custo:** `6 + 2 + 2 + 2 + n * (6 + 6) + 4 + 2 + n * (6 + 14) + 4 + 2 + n * (6 + 11) + 2 = 26 + 49n  = O(n)`