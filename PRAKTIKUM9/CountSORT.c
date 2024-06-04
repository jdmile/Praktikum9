#include <stdio.h>
#include <stdlib.h> 

void CountSort(int T[], int N, int ValMin, int ValMax) {
    int range = ValMax - ValMin + 1;
    int *TabCount = (int *)malloc(range * sizeof(int));
    
    if (TabCount == NULL) {
        fprintf(stderr, "Error: Alokasi memori gagal\n");
        return;
    }

    for (int i = 0; i < range; i++) {
        TabCount[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        TabCount[T[i] - ValMin]++;
    }

    int K = 0;
    for (int i = 0; i < range; i++) {
        while (TabCount[i] > 0) {
            T[K] = i + ValMin;
            K++;
            TabCount[i]--;
        }
    }

    free(TabCount);
}

int main() {
    int T[] = {7, 1, 7, 5, 3, 3, 6};
    int N = 7;

    int ValMin = 1;
    int ValMax = 7;

    CountSort(T, N, ValMin, ValMax);

    printf("Array setelah diurutkan secara ascending: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}
