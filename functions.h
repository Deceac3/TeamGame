#include "traders.h"
/*  
ПОСЛАНИЕ ПРЕДКАМ!!!! Нужно помнить что язык си работает с памятью и очень любит её копировать. 
Мы передаём struct player* conection потому что мы будем менять значение в функции. 
В случае с другими структурами, мы просто копируем из них данные, либо создаём клон структуры на определённый ход.
*/
float arrmorK(int armor){
    float k = 0.12;
    return (1-(k*armor/(1+k*abs(armor))));
}

_Bool batlemoove(struct player* conection, struct enemy* enemy, int chose, int* rangeuk){
    system("clear");
    switch (chose)
    {
    case 1:
        *rangeuk =*rangeuk-1;
        printf("Вы делаете шаг вперёд. Растояние между вами %d\n",*rangeuk);
        return false;
        break;
    case 2:
        if(*rangeuk>conection->playerWeapon.range){
            printf("Вы не можете атаковать. Расстояние слишком большое. %d | %d\n", conection->playerWeapon.range, *rangeuk);
            return true;
        }
        else{
            int damage,finalDamage;
            float armor,perdamage;
            damage = WeaponDamage(conection);
            perdamage = (float)damage;
            armor = arrmorK(enemy->armor);
            finalDamage = (int)(perdamage*armor);
            enemy->hp=enemy->hp - (finalDamage);
            printf("Вы атакуете врага и наносите ему урона %d\nздоровье противника %d\n", finalDamage,enemy->hp);
            return false;
        }
        break;
    case 3:
        *rangeuk=*rangeuk+1;
        printf("Вы делаете шаг назад. Расстояние между вами %d\n",*rangeuk);
        return false;
        break;
    case 4:
        return false;
    default:
        printf("Вы выбрали несуществующее действие, попробуйте снова\n");
        break;
    }
}



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
                conection->PlayerPassiveArmor = 2;
                conection->playerClass = 1;
                conection->playerMind = 3;
                conection->playerAgil = 2;
                conection->playerStrong = 1;
                conection->playerMoney = 2;
                conection->playerLuck = 4;
                conection->playerSpeed = 40;
                conection->playerWeapon = staff;
                conection->PlayerArmor = robe;
                conection->playerMaxHp = 50;
                conection->playerHP = 50;
                cheker = false;
                break;
            case 2:
                printf("Вы выбрали класс вора\n");
                conection->PlayerPassiveArmor = 3;
                conection->playerClass = 2;
                conection->playerMind = 1;
                conection->playerAgil = 6;
                conection->playerStrong = 2;
                conection->playerMoney = 10;
                conection->playerLuck = 3;
                conection->playerSpeed = 20;
                conection->playerWeapon =dagger;
                conection->PlayerArmor = rags;
                conection->playerMaxHp = 70;
                conection->playerHP = 70;
                cheker = false;
                break;
            case 3:
                printf("Вы выбрали класс танка\n");
                conection->PlayerPassiveArmor = 4;
                conection->playerClass = 3;
                conection->playerMind = 1;
                conection->playerAgil = 2;
                conection->playerStrong = 3;
                conection->playerMoney = 7;
                conection->playerLuck = 1;
                conection->playerSpeed = 30;
                conection->playerWeapon = spire;
                conection->PlayerArmor = armour;
                conection->playerMaxHp = 100;
                conection->playerHP = 100;
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
            printf("Сколько очков вы бы хотели вложить в интелект? свободных очков у вас: 15\15 \n");
            while(cheker){
            hchose = IntPlayerChoose();
            if(hchose <= 15 & hchose >= 0){
                conection->playerMind = hchose;
                freexp = freexp-conection->playerMind;
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
                    conection->playerStrong = hchose;
                    freexp = freexp - conection->playerStrong;
                    cheker = false;
                    printf("Вы вложили %d очков в силу. У вас осталось %d очков\n", conection->playerStrong,freexp);
                }
                else{
                    printf("Вы ввели неправильное количество очков: %d. Число не должно превышать %d и не должно быть меньше 0!\n",hchose, freexp);
                }
                }
            }
            conection->playerAgil = freexp;
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
};

int randexpf(int x){
    return rand()%(x);
};

int IntPlayerChoose(){
    char buf[80];
    int x;
    scanf("%d", &x);
    if (fgets(buf, sizeof buf, stdin))
    return x;
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

void RandomTrevelForTresure(struct player* conection){
    int enemys,enemyFighter;         // В бета версии будет пока что так. Енемис это рандомное количество противников в одном путешествии. Каждый противник будет выбираться рандомно каждый заход.
    enemys = rand()%6+2;      // от 2 до 8 противников будет выпадать. За каждую победу над противником будет выдаваться опыт и рандомная награда, такая ка деньги или особый предмет.
    for(int i = 0; i<=enemys; i++){
        if(conection->player_alive){
            enemyFighter = rand()%3+1;
            fightInRandomTrevel(conection, enemyFighter);
        }   
        else{
            break;
        }
    }
}

/*
Пояснение к ведению боя!!! Во время битвы будет учитываться несколько основополагающих вещей. 1 - расстояние до цели, 2 - скорость атаки 3 - дальность атаки. 
Индетично перечислению, идёт градация приоритетов. Первым ходит тот, у кого задержка перед ударом меньше всего ходит первым. Ему на выбор будет несколько команд.
1) сделать шаг вперёд или 2) сделать шаг назад. Это либо увеличивает либо уменьшает расстояние между вами и целью. если расстояние между вами и целью будет больше дальности атаки,
то данная функция вам будет недоступна.
3) атаковать противника 4) использовать предметы( в будущем) 
*/
void fightInRandomTrevel(struct player* conection,int enemy){
    int exp,gold,enemyMooveSpeed;
    switch (enemy)
    {
    case 1:
        struct enemy wolf = {"Волк",15,4,1,20,2,35,1,wolfSkin};
        enemyMooveSpeed= wolf.speed;
        Batle(conection,enemyMooveSpeed,&wolf);
        exp = wolf.expOut;
        gold = wolf.moneyOut;
        break;  
    case 2:
        struct enemy bear = {"Медведь",40,10,0,25,1,45,1,bearSkin};
        enemyMooveSpeed=bear.speed;
        Batle(conection,enemyMooveSpeed,&bear);
        exp = bear.expOut;
        gold = bear.moneyOut;
        break;
    case 3:
        struct enemy monkey = {"Макака",20,6,3,20,4,40,2,theMonkeyBar};
        enemyMooveSpeed=monkey.speed;
        Batle(conection,enemyMooveSpeed,&monkey);
        exp = monkey.expOut;
        gold = monkey.moneyOut;
        break;
    default:
        break;
    }
    
    conection->playerLvlExp += exp;
    conection->playerLvlExp += gold;
    printf("Вам удалось победить противника!\n");
    LvlExperienceUp(conection);
}

void Batle(struct player* conection,int* enemyMooveSpeed,struct enemy* enemy){
    int playerMooveSpeed=conection->playerSpeed, range=4,playerchoose, shortplayerspeed = conection->playerSpeed;
    printf("В ходе вашего путешествия перед вами появляется %s\nБитва началась!\n", enemy->enemyName);
    printf("Вы %d|%d hp            противник %d hp\n",conection->playerHP,conection->playerMaxHp,enemy->hp);
    sleep(1);
    while(enemy->hp>0 && conection->playerHP>0){
        system('clear');
        printf("между вами и противником %d метров\n", range);
        switch (nextStep(conection,enemy,&shortplayerspeed, &enemyMooveSpeed))
        {
        case 1:
        printf("%d к %d",range,conection->playerWeapon.range);
            if(range>conection->playerWeapon.range){
                printf("Сейчас ваш ход что вы сделаете?\n1)Сделать шаг вперёд\n\e[9m2)Атаковать противника вашим оружием\e[m\n3)Сделать шаг назад\n4)Злобно стоять на месте\n");
            }
            else{
                printf("Сейчас ваш ход что вы сделаете?\n1)Сделать шаг вперёд\n2)Атаковать противника вашим оружием\n3)Сделать шаг назад\n4)Злобно стоять на месте\n");
            }
            _Bool chek=true;
            while(chek){
                playerchoose = IntPlayerChoose();
                chek = batlemoove(conection,enemy,playerchoose,&range);
            }
            break;
        case 2:
            if(range>enemy->rangeAtack){
                printf("%s делает 1 шаг в вашем направлении\n", enemy->enemyName);
                range =range-1;
            }
            else{
                printf("%s нападает на вас\n", enemy->enemyName);
                damageTaken(conection,enemy); 
            }
            break;
        default:
            break;
        }
    }
}

void damageTaken(struct player* conection, struct enemy* enemy){
    int chance;
    int randCh = rand()%100;
    chance = missChance(conection->playerAgil);
    if(randCh<chance){
        printf("Противник промахнулся\n");
    }
    else{
        printf("Противник попал по вам\n");
        int damage;
        float armor;
        armor = arrmorK(conection->PlayerPassiveArmor+ conection->PlayerArmor.defence);
        damage = enemy->damage*armor;
        conection->playerHP -= damage;
        printf("Вы получили %d урона. У вас осталос %d|%d здоровья\n",damage,conection->playerHP, conection->playerMaxHp);
        if(PlayerHealth(conection->playerHP)){
            printf("Вы погибли! игра окончена!\n");
            exit(1);
        }
    }
}

int missChance(int agil){
    float k = 0.07;
    return (k*agil/(1+k*abs(agil))*100);
}

int nextStep(struct player* conection,struct enemy* enemy, int* playerspeed, int* enemyspeed){
    int x;
    if(*playerspeed < *enemyspeed){
        *enemyspeed = *enemyspeed- *playerspeed;
        *playerspeed =  conection->playerSpeed;
        return 1;
    }
    else if (*playerspeed > *enemyspeed)
    {
        *playerspeed = *playerspeed-*enemyspeed;
        *enemyspeed = enemy->speed;
        return 2;
    }
    else{
        x = rand()%1;
        switch (x)
        {
        case 0:
            *enemyspeed = 1;
            *playerspeed = conection->playerSpeed;
            return 1;
            break;
        case 1:
            *playerspeed = 1;
            *enemyspeed = enemy->speed;
            return 2;
            break;
        
        default:
            break;
        }
    }
}

int WeaponDamage(struct player* conection){
    switch (conection->playerWeapon.type)
    {
    case 1: // магический урон
        return conection->playerMind*conection->playerWeapon.damage;
        break;
    case 2: // физ урон от силы
        return conection->playerStrong*conection->playerWeapon.damage;
        break;
    case 3: // физ урон от ловкости
        return conection->playerAgil*conection->playerWeapon.damage;
        break;
    default:
        break;
    }
}

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
