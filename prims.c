#include<stdio.h>
#include<stdlib.h>

#define V 4 // Düðüm sayýsý

int main() {
    int selected[V] = {0}; // Baþlangýçta hiçbir düðüm seçilmemiþ
    int G[V][V] = { {0, 1, 2, 0},
                    {1, 0, 3, 5},
                    {2, 3, 0, 5},
                    {0, 5, 5, 0} }; // Aðýrlýklý grafik
    
    int edge = 0;
    selected[0] = 1; // Ýlk düðümü seçtik
    while (edge < V - 1) {
        int min = 1000, i, j, x, y;
        for (i = 0; i < V; i++) {
            if (selected[i]) {
                for (j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] && min > G[i][j]) {
                        min = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (min == 1000) {
            printf("Minimum aðaç bulunamadý.\n");
            break;
        }
        printf("%d %d -- %d\n", x, y, G[x][y]);
        selected[y] = 1; // Yeni düðümü secildi, isaretlendi.
        edge++;
    }

    return 0;
}

