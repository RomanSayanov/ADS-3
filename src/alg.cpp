// Copyright 2021 NNTU-CS

int cbinsearch(int *arr, int size, int value) {
    int count = 0;
    int s = size-1;
    if (*arr == value) {
        int i = 0;
        while (arr[i] == value) {
            count++;
            i++;
        }
        return count;
    }
    if (arr[size-1] == value) {
        int i = size-1;
        while (arr[i] == value) {
            count++;
            i--;
        }
        return count;
    }
    int min = size;
    int max = 0;
    for (int i = 0; arr[min] != value && arr[max] != value && i != size / 2;i++) {
        if (arr[(min+max)/2] > value) {
            int i = max;
            max = (min + max) / 2;
            if (min > i) {
                min = i;
            }
        } else if (arr[(min + max) / 2] == value) {
            min =(min + max) / 2;
        } else {
            int i = min;
            min = ((min + max) / 2);
            if (max < i) {
                max = i;
            }
        }
    }
    if (arr[max] == value) {
        for (int i = max; arr[i] == value; i--) {
            count++;
        }
        for (int i = max; arr[i] == value; i++) {
            count++;
        }
        return count;
    }
    if (arr[min] == value) {
        for (int i = min; arr[i] == value; i--) {
            count++;
        }
        for (int i = min+1; arr[i] == value; i++) {
            count++;
        }
        return count;
    }
    return count;
}
