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
    system("clear");
    printf("Демо 1.9");
    ClassLoader();              // Догружаем микропроцессы присваивания классов и т.д. читайте прато
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion);
    }
}
