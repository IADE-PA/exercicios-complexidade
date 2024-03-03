int get(const int* numbers, const int size, const int idx) {
    for (int i = 0; i < idx && i < size; i++) {
        if (i == idx) {
            return numbers[i];
        }
    }
    return -1;
}