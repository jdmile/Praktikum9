#include <stdio.h>

void MAXSORT(int T[], int N) {
    int i, Pass, Temp, IMAX;

    for (Pass = 0; Pass < N-1; Pass++) {
        IMAX = Pass;
        for (i = Pass + 1; i < N; i++) {
            if (T[IMAX] < T[i]) {
                IMAX = i;
            }
        }
        Temp = T[IMAX];
        T[IMAX] = T[Pass];
        T[Pass] = Temp;
    }
}

int main() {
    int T[] = {7, 1, 7, 5, 3, 3, 6};
    int N = 7;

    MAXSORT(T, N);

    printf("Array setelah diurutkan secara descending: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}
