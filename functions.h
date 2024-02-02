#include "Fighting.h"
/*  
ПОСЛАНИЕ ПРЕДКАМ!!!! Нужно помнить что язык си работает с памятью и очень любит её копировать. 
Мы передаём struct player* conection потому что мы будем менять значение в функции. 
В случае с другими структурами, мы просто копируем из них данные, либо создаём клон структуры на определённый ход.
*/

void createHero(struct player* conection){
    int hchose; 
    _Bool cheker,cheker2;
    printf("\nПриветствую тебя путешественник? Как тебя зовут?\n");
    scanf("%s\0\n", &conection->playerName);
    printf("Привет %s! Какой класс ты выберешь?\n1)маг\n2)вор\n3)Танк\n",conection->playerName);
    cheker = true;
    while(cheker){
        hchose = IntPlayerChoose();
        system("clear");
        switch (hchose)
            {
            case 1:
                printf("Вы выбрали класс мага\n");
                classSelector(conection,mag);
                cheker = false;
                break;
            case 2:
                printf("Вы выбрали класс вора\n");
                classSelector(conection,theif);
                cheker = false;
                break;
            case 3:
                printf("Вы выбрали класс танка\n");
                classSelector(conection,tank);
                cheker = false;
                break;
            default:
                printf("Вы выбрали несущетсвующий класс попробуйте снова!\n");
                break;
            }
    }
    printf("Какую модель прокачки вы выберете?\n1)Использовать автоматическое распределение очков навыков\n2)Самостоятельно выбрать очки навыков\n");
    cheker2 = true;
    while(cheker2){
        hchose = IntPlayerChoose();
        switch (hchose)
        {
        case 1:
            printf("Вы выбрали автоматическое распределение очков навыков! Вы получаете:\n");
            int randexp=15, randexpi;
            randexpi = randexpf(randexp);
            randexp= randexp-randexpi;
            conection->playerMind=conection->playerMind+randexpi;
            randexpi = randexpf(randexp);
            randexp= randexp-randexpi;
            conection->playerStrong =conection->playerStrong+randexpi;
            conection->playerAgil =conection->playerAgil+randexp;
            printf("Интелект: %d\nСила: %d\nЛовкость: %d\n", conection->playerMind,conection->playerStrong,conection->playerAgil);
            cheker2 = false;    
            break;
        case 2:
            cheker=true;
            int freexp = 15;
            printf("Сколько очков вы бы хотели вложить в интелект? свободных очков у вас: 15/15 \n");
            while(cheker){
            hchose = IntPlayerChoose();
            if(hchose <= 15 & hchose >= 0){
                conection->playerMind += hchose;
                freexp = freexp-hchose;
                cheker = false;
                printf("Вы вложили %d очков в интелект. У вас осталось %d очков\n", conection->playerMind, freexp);
            }
            else{
                printf("Вы выбрали не правильное количество очков: %d. Число не должно превышать %d и не должно быть меньше 0!\n", hchose, freexp);
            }
            }
            cheker = true;
            if(freexp !=0){
                printf("Сколько очков вы бы хотели вложить в силу?\n");
                while(cheker){
                hchose =IntPlayerChoose();
                if(hchose <= freexp & hchose >=0){
                    conection->playerStrong += hchose;
                    freexp = freexp - hchose;
                    cheker = false;
                    printf("Вы вложили %d очков в силу. У вас осталось %d очков\n", conection->playerStrong,freexp);
                }
                else{
                    printf("Вы ввели неправильное количество очков: %d. Число не должно превышать %d и не должно быть меньше 0!\n",hchose, freexp);
                }
                }
            }
            conection->playerAgil += freexp;
            printf("Оставшиеся очки опыта добавляются вашей ловкости. Ваша ловкость: %d\n", conection->playerAgil);
            cheker2 = false;
            break;
        default:
            printf("Вы выбрали неправильную настройку очков навыков. Выбирайте?\n1)автоматическое рапределение\n2)самостоятельное рапределение\n");
            break;
        }
    conection->playerLvl=1;
    conection->playerLvlExpNext =100;
    conection->playerEffects=playerEffects;
    system("clear");    
    printf("Вы создали персонажа!\n");
    }
    info(conection);
    sleep(3);
    printf("Переносим вас в город!\n");
    system("clear");
    conection->playerStage = 1;
    conection->player_alive = true;
}

void info(struct player* conection){
    switch(conection->playerClass)
    {
    case 1:
        printf("%s класс маг, интелект %d, сила %d, ловкость %d, золото %d\n", conection->playerName, conection->playerMind, conection->playerStrong,conection->playerAgil, conection->playerMoney);
        break;
    case 2:
        printf("%s класс вор, интелект %d, сила %d, ловкость %d, золото %d\n", conection->playerName, conection->playerMind, conection->playerStrong,conection->playerAgil, conection->playerMoney);
        break;
    case 3:
        printf("%s класс убийца, интелект %d, сила %d, ловкость %d, золото %d\n", conection->playerName, conection->playerMind, conection->playerStrong,conection->playerAgil, conection->playerMoney);
        break;
    default:
        break;
    }
    printf("Опыт %d/%d. Уровень %d, здоровье %d/%d, скорость в бою %d и броня %d.\n", conection->playerLvlExp,conection->playerLvlExpNext,conection->playerLvl,conection->playerHP,conection->playerMaxHp,conection->playerSpeed,conection->PlayerPassiveArmor+conection->PlayerArmor.defence);
    printf("Ваше оружие %s, ваша броня %s\n", conection->playerWeapon.name,conection->PlayerArmor.name);
};

int randexpf(int x){
    return rand()%(x);
};

int IntPlayerChoose(){
    char buf[80];
    int x;
    scanf("%d", &x);
    if (fgets(buf, sizeof buf, stdin))return x;
};

_Bool PlayerHealth(int helth){
    if(helth<=0){
        return true;
    }
    else{
        return false;
    }
}
void LvlExperienceUp(struct player* conection){
    switch (conection->playerLvl)
    {
    case 1:
        if (conection->playerLvlExp >=100)
        {
            conection->playerLvl++;
            conection->playerLvlExp = conection->playerLvlExp-100;
            LvlStatsUp(conection);
            if(conection->playerLvlExp >=250){LvlExperienceUp(conection);}
        }
        break;
    case 2:
        if (conection->playerLvlExp >=250)
        {
            conection->playerLvl++;
            conection->playerLvlExp = conection->playerLvlExp-250;
            conection->playerLvlExpNext = 500;
            LvlStatsUp(conection);
            if(conection->playerLvlExp >=500){LvlExperienceUp(conection);}
        }
        break;
    case 3:
        if (conection->playerLvlExp >=500)
        {
            conection->playerLvl++;
            conection->playerLvlExp = conection->playerLvlExp-500;
            conection->playerLvlExpNext = 1000;
            LvlStatsUp(conection);
            if(conection->playerLvlExp >=1000){LvlExperienceUp(conection);}
        }
        break;
    case 4:
        if (conection->playerLvlExp >=1000)
        {
            conection->playerLvl++;
            conection->playerLvlExp = conection->playerLvlExp-1000;
            conection->playerLvlExpNext = 500;
            LvlStatsUp(conection);
            if(conection->playerLvlExp >=500){LvlExperienceUp(conection);}
        }
        break;
    default:
        if (conection->playerLvlExp >=500){
            conection->playerLvl++;
            conection->playerLvlExp = conection->playerLvlExp-500;
            LvlStatsUp(conection);
            if(conection->playerLvlExp >=500){LvlExperienceUp(conection);}
        }
        break;
    }
}

void LvlStatsUp(struct player* conection){
    printf("Вы повысили уровень! Теперь ваш уровень %d\n", conection->playerLvl);
    switch (conection->playerClass)
    {
    case 1:
        conection->playerMind += 3;
        conection->playerAgil += 1;
        conection->playerStrong +=1;
        conection->playerMaxHp +=5;
        conection->playerHP +=5;
        break;
    case 2:
        conection->playerMind += 1;
        conection->playerAgil += 4;
        conection->playerStrong +=2;
        conection->playerMaxHp +=7;
        conection->playerHP +=7;
        break;
    case 3:
        conection->playerMind += 1;
        conection->playerAgil +=2;
        conection->playerStrong +=4;
        conection->playerMaxHp +=10;
        conection->playerHP +=10;
        break;
    default:
        break;
    }
}

void TrevelLobby(int hchose, int* cheker,struct player* conection){
    switch (hchose)
    {
    case 1:
        printf("%s отправляется в случайное путешествие!\n", conection->playerName);
        RandomTrevelForTresure(conection);
        break;
    case 2:    
        break;
    case 3:
        cheker= false;
        break;
    default:
        break;
    }
}

/*
Пояснение к ведению боя!!! Во время битвы будет учитываться несколько основополагающих вещей. 1 - расстояние до цели, 2 - скорость атаки 3 - дальность атаки. 
Индетично перечислению, идёт градация приоритетов. Первым ходит тот, у кого задержка перед ударом меньше всего ходит первым. Ему на выбор будет несколько команд.
1) сделать шаг вперёд или 2) сделать шаг назад. Это либо увеличивает либо уменьшает расстояние между вами и целью. если расстояние между вами и целью будет больше дальности атаки,
то данная функция вам будет недоступна.
3) атаковать противника 4) использовать предметы( в будущем) 
*/

void gameSelectMenu(struct player* conecntion){
    int hchose;
    _Bool cheker;
    switch (conecntion->playerStage)
    {
    case 1:
            cheker = true;
            while (cheker)
            {
                printf("%s добро пожаловать в MAIN Town\nВы можете выбрать\n1)пойти в путешествие\n2)пойти к нпс\n3)Посмотреть статистику персоонажа\n4)выйти\n",conecntion->playerName);
                hchose = IntPlayerChoose();
                switch (hchose)
                {
                case 1:
                    system("clear");
                    printf("Вы отправляетесь в путеществие. Куда вы пойдёте?\n1) Отправиться в путешествие ради сокровищ и золота.\n2) Отправиться в путешествию по заданию одного из нпс.\n3)Я передумал, вернуться назад.\n");
                    hchose = IntPlayerChoose();
                    system("clear");
                    TrevelLobby(hchose,&cheker, conecntion);
                    cheker = false;
                    break;
                case 2:
                    system("clear");
                    tradersMT(conecntion);
                    break;
                case 3:
                    system("clear");
                    info(conecntion);
                    sleep(4);
                    system("clear");
                    break;
                case 4:
                    system("clear");
                    printf("\nВы покинули игру\n");
                    conecntion->player_alive =false;
                    cheker = false;
                    break;
                default:
                    printf("Вы выбрали неверный номер опции, попробуйте снова.\n");
                    break;
                }
            }
            break;
        break;
    
    default:
        break;
    case 2:
        printf("TOWN 2");
    printf("Программа окончена! %s\n", conecntion->playerName);
    return 0;
}
}

void statusEffectsPlayer(struct player* conection){
    printf("");
}

void classSelector(struct player* conection, struct class class){
    conection->PlayerPassiveArmor = class.armourPassive;
    conection->playerClass = class.classId;
    conection->playerMind = class.mind;
    conection->playerAgil = class.agil;
    conection->playerStrong = class.str;
    conection->playerMoney = class.money;
    conection->playerLuck =class.luck;
    conection->playerSpeed = class.startSpeed;
    conection->playerWeapon = class.classWeapon;
    conection->PlayerArmor = class.classArmour;
    conection->playerMaxHp = class.hp;
    conection->playerHP = class.hp;
}