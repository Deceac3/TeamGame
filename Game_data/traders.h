#include "tradersQests.h"

// Кузнец. Он улучшает оружие, броню, но не может улучшить магические предметы, артефакты и т.д. Продаёт новые виды брони, оружия и для стрелков стрелы и пули
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
        blacksmithTrade(conection);
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
                if(conection->playerWeapon.type==3){
                    conection->playerWeapon.damage=conection->playerWeapon.damage+0.5;
                }
                else{
                    conection->PlayerArmor.defence=conection->PlayerArmor.defence+3;
                }
            }
            else{
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
        printf("Вы ввели неверный номер опции\n");
        return true;
        break;
    }
}

//  Травница. Продаёт зелья хила, силы, ловкости и т.д. Даёт разные сайт квесты и может исцелить игрока.
_Bool herbalist(struct player* conection,int choose){//АААААААААААААААААААААААААААААААА ЖЕНЩИНА АААААААААААААА
    switch (choose)
    {
    case 1:
        herbalistqest(conection);
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
        int hchosed;
        printf("Я могу сварить для тебя настойку на травах, которая снимет все негативные эффекты и полностью исцелит тебя всего за 10 монет\n");
        if(conection->playerMoney>10 || conection->playerHP == conection->playerMaxHp){
            printf("1)Восстановить здоровье?\n2)Bruh\n");
            hchosed = IntPlayerChoose();
        }
        else{
            printf("Я чувствую что тебе это не надо\n");
        }
        return true;
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

//  Это колдун. он может улучшить магическое оружие или броню.
_Bool magician(struct player* conection, int choose){
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
        int hchosed;
        printf("Я могу сделать твоё магическое оружие ещё сильнее всего за 30 монет!\n");
        if(conection->playerMoney>30){
            if(conection->playerWeapon.type == 1){
            printf("Улучшить оружие?\n1)Да\n2)Нет\n");
            hchosed = IntPlayerChoose();
            switch (hchosed)
            {
            case 1:
                conection->playerWeapon.update =1;
                conection->playerWeapon.damage=conection->playerWeapon.damage+0.5; 
                return false;
                break;
            case 2:
                printf("Удачи тебе!\n");
                return false;
                break;
            default:
                printf("Нет такой команды!\n");
                return true;
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

//Квестовый герой, дающий задания, продающий усиливающее пыво
_Bool ovnerTavern(struct player* conection,int choose){
    switch (choose)
    {
    case 1:
        printf("Вот, возьми это письмо и доставь его в столицу трактирщику Нэду, как отдашь принеси его ответ, за это я тебя отблагодарю!\n");//дай инвентарь
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
        int hchosed;
        printf("Я варю лучшее пиво в округе! 1 кружка стоит 10 монет.\n");
        if(conection->playerMoney>=10){
            if(conection->playerWeapon.type == 1){
            printf("Выпыт пыва?\n1)Да\n2)Нет\n");
            hchosed = IntPlayerChoose();
            switch (hchosed)
            {
            case 1:
                printf("Прыятного пыва!\n");
                conection->playerMoney -= 10;
                conection->playerEffects.armourChanges += 3;
                conection->playerEffects.damageChanges += 3;
                conection->playerEffects.speedChanges +=5;
                conection->playerEffects.luckChanges +=3;
                return false;
                break;
            case 2:
                printf("Ну хорошо, удачи!\n");
                return false;
                break;
            default:
                printf("Нет такой команды!\n");
                return true;
                break;
            }
            }
        }
        else{
            printf("У тебя не достаточно денег!\n");
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

//трейдеры основного города MeinTown
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

//Выбор трейдеров изходя из города и выбора героя.
void traderSelector(struct player* conection, int hchose){
    _Bool tradersBool=true,cheker=true;
    switch (conection->playerStage)
    {
    case 1:
        while(cheker){
        switch (hchose)
            {
            case 1:
                printf("Вы подходите к кузнецу. ");
                while(tradersBool){
                printf("Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=blacksmith(conection,hchose);
                cheker=false;
                }
                break;
            case 2:
                printf("Вы подходите к травнице. ");
                while(tradersBool){
                printf("Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=herbalist(conection,hchose);
                cheker=false;
                }
                break;
            case 3:
                printf("Вы подходите к чародею. ");
                while(tradersBool){
                printf("Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=magician(conection,hchose);
                cheker=false;
                }
                break;
            case 4:
                printf("Вы подходите к владельцу таверны. ");
                while(tradersBool){
                printf("Что сделать?\n1) попросить задание\n2)посмотреть товары\n3)продать товары\n4)улсуги\n5)больше ничего не надо\n");
                hchose = IntPlayerChoose();
                tradersBool=ovnerTavern(conection,hchose);
                cheker=false;
                }
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

void blacksmithTrade(struct player* conection){
    _Bool cheker = true;
    int hchose;
    printf("У меня самые разнообразные товары на товй вкус! Что ты предпочтёшь? 1)Оружие или 2)броню?\n");
    while(cheker){
        hchose = IntPlayerChoose();
        switch (hchose)
        {
        case 1:
            switch (conection->playerLvl)
            {
            case 1:
                WeaponItemInfo(dagger);
                WeaponItemInfo(spire);
                cheker=false;
                break;
            case 2:
                WeaponItemInfo(dagger);
                WeaponItemInfo(thiefsBlade);
                WeaponItemInfo(spire);
                WeaponItemInfo(twoHandedSword);
                cheker=false;
                break;
            default:
                break;
            }
            break;
        case 2:
            switch (conection->playerLvl)
            {
            case 1:
                ArmorItemInfo(rags);
                ArmorItemInfo(armour);
                ArmorItemInfo(robe);
                cheker=false;
                break;
            case 2:
                ArmorItemInfo(rags);
                ArmorItemInfo(armour);
                ArmorItemInfo(robe);
                ArmorItemInfo(HiddenChainmail);
                ArmorItemInfo(MehaArmor);
                ArmorItemInfo(cultRobe);
                cheker=false;
                break;
            default:
                break;
            }
        default:
            printf("Вы ввели неверный номер опции, попробуйте ещё раз!\n");
            break;
        }
    }
}
