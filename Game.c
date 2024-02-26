#include "Game_data/FilesData.h"
//тут был староста
//тут была костыльная рожа
//Тут был нормальный пацан...
//тут было халявное камео

int main(void)
{   
    begin=time(NULL);
    EnemysArray =malloc(EnemysCount*sizeof(struct enemy));
    PreLoader();              // Догружаем микропроцессы присваивания классов и т.д. читайте прато
    srand(time(NULL));
    system("clear");
    printf("Версия 32\n");    
    struct player *p = malloc(sizeof(struct player));       //Хнакомьтесь, указатель на объект структуры персонажа, он будет передаваться в большинство функций
    createHero(p);              // создание персонажа
    while (p->player_alive)
    {
        gameSelectMenu(p);
    }
    EndGame(begin);
    printf("Вы накопили: %d очков\n",p->playerScore);
    return 0;
}
