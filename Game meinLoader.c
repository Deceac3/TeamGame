#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"

/*
пишем миниму кода здесь. Это файл инициализаций.
*/
    
int main(void)
{
    srand(time(NULL));
    struct class mag = {1,50,1,2,3,2,4,50,2,staff,robe};
    struct class theif = {2,70,2,6,1,3,3,30,10,dagger,rags};
    struct class tank = {3,100,4,2,1,4,1,40,7,spire,armour};
    system("clear");
    printf("Демо 1.8");
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion);
    }
}
