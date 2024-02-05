#include "struct.h"
#include "items.c"

//Квесты Кузнеца
int blacksmithQestCount=1;


//Квесты Травницы
int herbalistQestCount = 1;
struct QestTypeCollect herbalistFlowers = {.ItemCounts=5};
//Функция сдачи квестов
void herbalistqest(struct player* conection){
    switch (herbalistQestCount)
    {
    case 1:
        printf("Принеси мне 5 алых цветков регенерации из туманных лесов и я тебе неплохо заплачу!\n");
        if(conection->playerLvl == conection->playerLvl){       //Пишем условие есть ли 5 цветочков. Зависит от типо как инвентарь пон
            _Bool cheker;
            int hchose;
            while (cheker){
                printf("Передать 5 алых цветков травнице?\n1)Да\n2)Нет\n");
                hchose=IntPlayerChoose();
                switch (hchose)
                {
                case 1:
                    printf("Спасобо за помощь путник! Приходи в следующий день и я дам тебе новый квест!\n");
                    herbalistQestCount++;
                    conection->playerMoney+=25;
                    cheker =false;
                    //Будет инвентарь, уничтожаем их пон брат
                    break;
                case 2:
                    printf("Увидимся позже, путник!\n");
                    cheker=false;
                    break;
                default:
                    cheker=true;
                    break;
                }
            }
        }
        else{
            printf("Приходи когда принесёшь их мне\n");
        }
        break;
    
    default:
        break;
    }
}

//Квесты Колдуна
int magicianQestCounter = 1;


// Квесты владельца таверны
int ovnerTavernQestCounter = 1;
struct QestTypeCollect ovnerTavernLatterQ={.ItemCounts=0};


//подругрзка квестовых предметов через функцию
void QestLoading(){
    herbalistFlowers.GameItem = flowerOfRestoration;
    ovnerTavernLatterQ.GameItem = OvnerTavernLatter;
}