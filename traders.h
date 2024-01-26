#include "sup.h"
#include "items.c"

_Bool blacksmith(struct player* conection,int choose){
    int hchosed;
    _Bool cheker = true;
    switch (choose)
    {
    case 1:
        printf("Извини друг, Квестов у меня нет. Лучше купи у меня вещей. Пока.\n");
        return true;
        break;
    case 2:
        return true;
        //где инвентарь, лебовский?
        break;
    case 3:
        return true;
        //я не шучу
        break;
    case 4:
        printf("Привет друг. Я могу улучшить урон твоего оружия или сделать твою броню прочнее за небольшую плату в 15 монет! Но я не могу улучшать уже улучшенную броню.\nЧто тебе улучшить?\n1)оружие\n2)броню\n");
        if(conection->playerMoney>=15){
        while(cheker){
        hchosed = IntPlayerChoose();
        switch (hchosed)
        {
        case 1:
            hchosed = false;
            if(conection->playerWeapon.type==3 || conection->playerWeapon.type==2){
                conection->playerWeapon.damage=conection->playerWeapon.damage+0.5;
            }
            else{
                conection->PlayerArmor.defence=conection->PlayerArmor.defence+3;
                printf("Извини, я не умею улучшать оружие магов. Лучше обратись к чародею\n");
            }
            break;
        case 2:
            hchosed=false;
            break;
        default:
            printf("Вы ввели неверный номер функции\n попробуйте снова\n");
            break;
        }
        }
        }
        else{
            printf("Извини,у тебя не достаточно денег. Приходи когда станешь МММММ ПОБАГАЧЕ\n");
        }
        return true;
    case 5:
        printf("Ну пока :'(\n");
        return false;
        break;
    default:
        break;
    }
}

_Bool herbalist(struct player* conection,int choose){//АААААААААААААААААААААААААААААААА ЖЕНЩИНА АААААААААААААА
    _Bool cheker=true;
    int hchosed;
    switch (choose)
    {
    case 1:
        printf("Принеси мне 5 алых огненных цветка из пещеры забвения и я дам тебе священный амулет\n");//дай инвентарь
        return false;
        break;
    case 2:
        return true;
        //где инвентарь, лебовский?
        break;
    case 3:
        return true;
        //я не шучу
        break;
    case 4:
        printf("Я могу сварить для тебя настойку на травах, которая снимет все негативные эффекты и полностью исцелит тебя всего за 10 монет\n");
        if(conection->playerMoney>10 || conection->playerHP == conection->playerMaxHp){
            printf("1)Восстановить здоровье?\n2)Bruh\n");
            hchosed = IntPlayerChoose();
        }
        else{
            printf("Я чувствую что тебе это не надо\n");
        }
        return false;
    case 5:
        printf("Ну пока\n");
        return false;
        break;
    default:
        printf("Нет такой команды!\n");
        return true;
        break;
    }
}

_Bool magician(struct player* conection, int choose){
    _Bool cheker;
    int hchosed;
    switch (choose)
    {
    case 1:
        printf("Достань мне голов дриады и я улучшу твои характеристики, мой друг!\n");//дай инвентарь
        return false;
        break;
    case 2:
        return true;
        //где инвентарь, лебовский?
        break;
    case 3:
        return true;
        //я не шучу
        break;
    case 4:
        printf("Я могу сделать твоё магическое оружие ещё сильнее всего за 30 монет!\n");
        if(conection->playerMoney>30){
            if(conection->playerWeapon.type == 1){
            printf("Улучшить оружие?\n1)Да\n2)Нет\n");
            hchosed = IntPlayerChoose();
            switch (hchosed)
            {
            case 1:
                
                break;
            case 2:
                break;
            default:
                printf("Нет такой команды!\n");
                break;
            }
            }
        }
        else{
            printf("Я чувствую что тебе это не надо\n");
        }
        return false;
    case 5:
        printf("До скорых встреч\n");
        return false;
        break;
    default:
        printf("Нет такой команды!\n");
        return true;
        break;
    }
}

_Bool ovnerTavern(struct player* conection,int choose){

}

void tradersMT(struct player* conection){
    int hchose;
    _Bool cheker;
    printf("\nВы подходите к купцам. К кому подойти?\n1)кузнец\n2)травница\n3)чародей\n4)подойти к владельцу таверны\n5)отойти назад\n");
    cheker = true;
    while (cheker)
        {
        hchose=true;
        switch (hchose)
        {
            case (1 || 2 || 3 || 4):
                hchose = IntPlayerChoose();
                system("clear");
                traderSelector(conection,hchose);
                cheker = false;
                break;
            case 5:
                printf("Вы возвращаетесь к центру города\n");
                cheker = false;
                break;
                        
            default:
                printf("Вы выбрали неверный номер опции, попробуйте снова.\n");
                break;
            }
        }
}

void traderSelector(struct player* conection, int hchose){
    _Bool tradersBool=true;
    int hchosed;
    switch (conection->playerStage)
    {
    case 1:
        while(tradersBool){
        switch (hchose)
            {
            case 1:

                printf("Вы подходите к кузнецу. Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=blacksmith(conection,hchose);
                break;
            case 2:
                printf("Вы подходите к травнице. Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=herbalist(conection,hchose);
                break;
            case 3:
                printf("Вы подходите к чародею. Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=magician(conection,hchose);
                break;
            case 4:
                printf("Вы подходите к владельцу таверны. Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=ovnerTavern(conection,hchose);
                break;
            default:
                printf("Вы выбрали неверный номер опции,попробуйте снова.\n");
                break;
            }
    default:
        break;
    }
    }
}

