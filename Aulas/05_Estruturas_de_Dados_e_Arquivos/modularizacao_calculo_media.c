#include <stdio.h>

float media_dois_valores(float a, float b);

int main()
{
    float x, y;

    scanf("%f", &x);
    scanf("%f", &y);

    printf("%f\n", media_dois_valores(x, y));

    return 0;
}

float media_dois_valores(float a, float b)
{
    float media;

    media = (a+b) / 2;

    return media;
}