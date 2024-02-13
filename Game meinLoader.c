#include "Game_data/FilesData.h"
//тут был староста
//тут была костыльная рожа
//Тут был нормальный пацан...

int main(void)
{   
    begin=time(NULL);
    EnemysArray =malloc(EnemysCount*sizeof(struct enemy));
    PreLoader();              // Догружаем микропроцессы присваивания классов и т.д. читайте прато
    srand(time(NULL));
    system("clear");
    printf("Версия 31\n");
    struct player conecntion;        // Создаём объект класса нашего пользователя, в котором всё будет храниться. Позже мы будем этот объект сохранять и вызывать в будущем
    createHero(&conecntion);        // Передаём разименнованный объект в функции с скриптами создания персоонажа
    while (conecntion.player_alive){
        gameSelectMenu(&conecntion);
    }
    EndGame(begin);
    printf("Вы накопили: %d очков\n",conecntion.playerScore);
    return 0;
}
