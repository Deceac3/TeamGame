#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "Game_data/functions.h"
//тут был староста
//тут была костыльная рожа
//Тут был нормальный пацан...
/*
пишем миниму кода здесь. Это файл инициализаций.
*/

int main(void)
{   
    begin=time(NULL);
    int main_time = 12;
    EnemysArray =malloc(EnemysCount*sizeof(struct enemy));
    PreLoader(EnemysArray);              // Догружаем микропроцессы присваивания классов и т.д. читайте прато
    srand(time(NULL));
    system("clear");
    printf("Версия 27\n");
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion, main_time);
    }
    EndGame(begin, main_time);
    printf("Вы накопили: %d очков\n",conecntion.playerScore);
    return 0;
}
