#include <stdio.h>

int fatorial_i(int v);
int fatorial_r(int v);
int localizar_nr(int n, int *v);
int localizar_nr_recursiva(int n, int *v, int pos);

int main()
{
    int n = 5, numeros[10] = {42, 37, 28, 9, 55, 127, 144, 101, 1200, 48};
    int numero = 55;

    printf("O fatorial (i) de %d eh %d\n", n, fatorial_i(n));
    printf("O fatorial (r) de %d eh %d\n", n, fatorial_r(n));
    printf("O numero %d esta/ou em numeros na pos: %d\n", numero, localizar_nr_recursiva(numero, numeros, 0));

    return 0;
}

int fatorial_i(int v)
{
    int fat = 1;

    for (int i = v; i > 1; i--) {
        fat = fat * i;
    }

    return fat;
}

int fatorial_r(int v)
{
    if (v == 1) return 1;
    return v * fatorial_r(v-1);
}

int localizar_nr(int n, int *v)
{
    for (int i = 0; i < 10; i++) {
        if (*(v+i) == n) return i;
    }
    return -1;
}

int localizar_nr_recursiva(int n, int *v, int pos)
{
    // Definitivamente não achei
    if (pos == 10) return -1;
    // Se achei
    if (n == *(v+pos)) return pos;
    // Ainda nao achei    
    return localizar_nr_recursiva(n, v, ++pos);

}
