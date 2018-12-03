#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param m
 * @param n
 * @return
 */
int **construireMatrice(int *m, int *n) {
    printf("Introduceti numarul de linii si de coloane: ");
    scanf("%d %d", m, n);
    int **matrix;
    matrix = (int **) malloc((*m) * sizeof(int *));
    for (int i = 0; i < *m; i++)
        matrix[i] = (int *) malloc((*n) * sizeof(int));

    printf("Introduceti elementele matricei:");
    for (int i = 0; i < (*m); i++) {
        for (int j = 0; j < (*n); j++)
            scanf("%d", *(matrix + i) + j);
    };
    return matrix;
}

/**
 *
 * @param a
 * @param m
 * @param n
 */
void afisareMatrice(int **a, int m, int n) {
    printf("Matricea este \n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", *(*(a + i) + j));
        printf("\n");
    }
}

/**
 *
 * @param a
 * @param m
 * @param n
 */
void construiesteMatrice1(int ***a, int *m, int *n) {
    printf("Introduceti numarul de linii si de coloane: ");
    scanf("%d %d", m, n);
    *a = (int **) malloc((*m) * sizeof(int *));
    for (int i = 0; i < (*m); i++) {
        *((*a) + i) = (int *) malloc((*n) * sizeof(int));
    }

    printf("Introduceti elementele matricei:");
    for (int i = 0; i < (*m); i++) {
        for (int j = 0; j < (*n); j++)
            scanf("%d", *((*a) + i) + j);
    }
}

/**
 *
 * @param n
 * @return
 */
int **construiesteMatriceInferiorTriunghiulara(int n) {
    int **matriceInferioara = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matriceInferioara[i] = (int *) malloc((i + 1) * sizeof(int));

    printf("Introduceti elementele matricei inferior triunghiulare\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%d", &matriceInferioara[i][j]);
        }
    }
    return matriceInferioara;
}

/**
 *
 * @param a
 * @param n
 */
void afiseazaMatriceInferiorTriunghiulara(int **a, int n) {
    printf("Matricea inferior triughiulara este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/**
 *
 * @param n
 * @return
 */

int **construiesteMatriceSuperiorTriunghiulara(int n) {
    int **matriceSuperioara = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        matriceSuperioara[i] = (int *) malloc((n - i) * sizeof(int));
    printf("Introduceti elementele matricei superior triunghiulare:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            scanf("%d", &matriceSuperioara[i][j]);
    }

    return matriceSuperioara;
}

/**
 *
 * @param matriceSuperioara
 * @param n
 */

void afiseazaMatriceSuperiorTriunghiulara(int **matriceSuperioara, int n) {
    printf("Matricea superior triunghiulara este:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            printf("%d ", matriceSuperioara[i][j]);
        printf("\n");
    }
}

/**
 *
 * @param n
 * @return
 */
int **construiesteMatriceK(int n) {
    int **matriceK, numarLinii, numarColoane;
    numarLinii = 2 * n - 1;
    numarColoane = n;

    matriceK = malloc(numarLinii * sizeof(int *));

    for (int i = 0; i < numarLinii; i++)
        if (i < n) {
            matriceK[i] = malloc(numarColoane * sizeof(int));
            for (int j = 0; j < numarColoane; j++)
                scanf("%d", &matriceK[i][j]);
            numarColoane--;
        } else {
            if (i == n) numarColoane = 2;
            matriceK[i] = malloc(numarColoane * sizeof(int));
            for (int j = 0; j < numarColoane; j++)
                scanf("%d", &matriceK[i][j]);
            numarColoane++;
        }

    return matriceK;
}

/**
 *
 * @param matriceK
 * @param n
 */
void afiseazaMatriceK(int **matriceK, int n) {
    int numarLinii, numarColoane;
    numarLinii = 2 * n - 1;
    numarColoane = n;
    printf("Matricea in forma de K estte:\n");

    for (int i = 0; i < numarLinii; i++)
        if (i < n) {
            for (int j = 0; j < numarColoane; j++)
                printf("%d ", matriceK[i][j]);
            numarColoane--;
            printf("\n");
        } else {
            if (i == n) numarColoane = 2;
            for (int j = 0; j < numarColoane; j++)
                printf("%d ", matriceK[i][j]);
            numarColoane++;
            printf("\n");
        }
}

int main() {
    int **a, **b, **matriceInferioara, **matriceSuperioara, **matriceK, m, n;
//    b = construireMatrice(&m, &n);
//    afisareMatrice(b, m, n);
//    construiesteMatrice1(&a, &m, &n);
//    afisareMatrice(a, m, n);
    printf("Introduceti n = ");
    scanf("%d", &n);
//    matriceInferioara = construiesteMatriceInferiorTriunghiulara(n);
//    afiseazaMatriceInferiorTriunghiulara(matriceInferioara, n);
//    matriceSuperioara = construiesteMatriceSuperiorTriunghiulara(n);
//    afiseazaMatriceSuperiorTriunghiulara(matriceSuperioara, n);
    matriceK = construiesteMatriceK(n);
    afiseazaMatriceK(matriceK, n);
    return 0;
}