#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"


int main(void)
{
    srand(time(NULL));
    system("clear");
    printf("Демо 1.6");
    int hchose;
    _Bool cheker,cheker2;
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion);
    }
}