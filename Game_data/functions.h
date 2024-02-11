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
    scanf("%s\0\n", conection->playerName);
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
            if((hchose <= 15) & (hchose >= 0)){
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
                if((hchose <= freexp) & (hchose >=0)){
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
    conection->playerPotionsBag=prePlayerPB;
    system("clear");    
    printf("Вы создали персонажа!\n");
    }
    info(conection);
    system("clear");
    conection->playerStage = 1;
    conection->player_alive = true;
    conection->playerScore=0;
}

void info(struct player* conection){
    char xxx;
    printf("Нажмите Enter, чтобы перейти в меню\n");
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
    potionInfo(conection->playerPotionsBag);
    scanf("%c",&xxx);
};

int randexpf(int x){
    return rand()%(x);
};

int IntPlayerChoose(){
    char buf[80];
    int x;
    scanf("%d", &x);
    if (fgets(buf, sizeof buf, stdin)){return x;}
    else{
        return 0;
    }
};

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

void TrevelLobby(int hchose, _Bool* cheker,struct player* conection){
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

void count_hours(int clock, int var)
{
    int new_clock;
    if(clock+var>24)
    {
        new_clock=clock+var-24;
    }   
    else
    {
        new_clock=clock+var;
    }
    printf("Нынешнее время: %d час(ов/а)\n\n", new_clock);
}

void relax(int time_now, int time_spand, struct player* conecntion)
{
    int new_hp;
    count_hours(time_now, time_spand);
    new_hp = time_spand*2;
    if(conecntion->playerHP + new_hp >= conecntion->playerMaxHp)
    {
        conecntion->playerHP = conecntion->playerMaxHp;

    }   
    else
    {
        conecntion->playerHP += new_hp;
        printf("Вы чувствуете себя лучше, показатель здоровья: %dHP\n", conecntion->playerHP);
    }
}

void gameSelectMenu(struct player* conecntion, int time){
    int hchose;
    _Bool cheker;
    switch (conecntion->playerStage)
    {
    case 1:
            cheker = true;
            while (cheker)
            {
                printf("%s добро пожаловать в MAIN Town\nВы можете выбрать\n1)пойти в путешествие\n2)пойти к нпс\n3)Посмотреть статистику персоонажа\n4)Отдыхать\n5)Выйти\n",conecntion->playerName);
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
                    system("clear");
                    break;
                case 4:
                    system("clear");
                    printf("Комната в таверне стоит 1 монету. Желаете арендовать комнату?(Y/N)\n");
                    char check;
                    scanf("%s", &check);
                    if((check == 'Y') && (conecntion->playerMoney-1>=0))
                    {
                        conecntion->playerMoney -= 1;
                        relax(time, 8, conecntion);
                    }
                    else if((check == 'Y') && (conecntion->playerMoney-1<0))
                    {
                        printf("\"Нужно больше золота!\" - Недовольно кинул трактирщик\n");
                    }
                    break;
                case 5:
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
    case 2:
        printf("TOWN 2");
        printf("Программа окончена! %s\n", conecntion->playerName);
        break;
    default:
        break;
}
}

void statusEffectsPlayer(struct player* conection){
    printf("Ваши эффекты:\nброня - %d\nурон - %d\nинтелект - %d\nловкость - %d\nсила - %d\nскорость - %d\nудача - %d\n",
    conection->playerEffects.armourChanges,conection->playerEffects.damageChanges,conection->playerEffects.mindChanges,
    conection->playerEffects.agilChanges,conection->playerEffects.strongChanges,conection->playerEffects.speedChanges,
    conection->playerEffects.luckChanges);
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

void ArmorItemInfo(struct armor armor){
    switch (armor.update)
    {
    case 0:
        printf("Это \"%s\". Оно даёт %d дополнительной защиты. Стоит %d монет. Броня не улучшена\n", armor.name, armor.defence,armor.cost);
        break;
    case 1:
        printf("Это \"%s\". Оно даёт %d дополнительной защиты. Стоит %d монет. Броня улучшена\n", armor.name, armor.defence,armor.cost);
        break;
    }
    
}

void WeaponItemInfo(struct weapon weapon){
    switch (weapon.type)
    {
    case 1:
        switch (weapon.update)
        {
        case 0:
            printf("Это \"%s\" | магическое оружие. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие не улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        case 1:
            printf("Это \"%s\" | магическое оружие. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        }
        break;
    case 2:
        switch (weapon.update)
        {
        case 0:
            printf("Это \"%s\" | физическое оружие зависящее от силы. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие не улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        case 1:
            printf("Это \"%s\" | физическое оружие зависящее от силы. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        }
        break;
    case 3:
        switch (weapon.update)
        {
        case 0:
            printf("Это \"%s\" | физическое оружие зависящее от ловкости. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие не улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        case 1:
            printf("Это \"%s\" | физическое оружие зависящее от ловкости. Оно повышает урон в %.2f раз. Дальность Атаки %d. Стоимость оружия %d. Оружие улучшенно\n",weapon.name,weapon.damage,weapon.range,weapon.cost);
            break;
        }
        break;
    }
}

void EndGame(time_t begin, int time){
    time_t end,razn;
    end=time(NULL); 
    razn = end-begin;
    printf("На часах %d час(а/ов). Кажется, так окончится ваша история...\n", time);
    printf("Вы провели в игре %ldч:%ldм:%ldс\n",(razn/60/60),(razn/60)%60,razn%60);
}

void potionInfo(struct playerPotionsBag pack){
    printf("Ваши зелья:\n");
    for(int i=0;i<(sizeof(pack)/(sizeof(pack.agilSkils)+sizeof(int)));i++){
        potionChekInfo(*(&pack.healingFlask+i),*(&pack.healingFlaskCount+i));
    }
}

void potionChekInfo(struct potion potion, int count){
    if(count!=0){
        printf("%s: %d\n",potion.potionName,count);
    }
}