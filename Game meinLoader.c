#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "functions.h"
//тут был староста
//тут была костыльная рожа
/*
пишем миниму кода здесь. Это файл инициализаций.
*/
    
int main(void)
{
    srand(time(NULL));    
    system("clear");
    printf("Демо 1.91");
    PreLoader();              // Догружаем микропроцессы присваивания классов и т.д. читайте прато
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion);
    }
}
