#include <stdio.h>
#include <stdlib.h>

int L, C, P;
int posX[100], posY[100];
int dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int valido(int x, int y){
    if(x<1 || x>L || y<1 || y>C) return 0;
    for(int i=0; i<P; i++){
        if(posX[i] == x && posY[i] == y) return 0;
    }
    return 1;
}

int contarVizinhos(int x, int y){
    int contagem = 0;
    for(int i=0; i<8; i++){
        if(valido(x+dir[i][0], y+dir[i][1])) contagem++;
    }
    return contagem;
}

int main(){
    FILE *fp;
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d %d", &L, &C);
    fscanf(fp, "%d", &P);
    for(int i=0; i<P; i++){
        fscanf(fp, "%d %d", &posX[i], &posY[i]);
    }
    fclose(fp);

    int maxB = 0;
    for(int i=1; i<=L; i++){
        for(int j=1; j<=C; j++){
            if(valido(i, j)){
                int vizinhos = contarVizinhos(i, j);
                if(vizinhos > 0){
                    maxB++;
                }
            }
        }
    }

    printf("%d\n", maxB);

    return 0;
}
