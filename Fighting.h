#include "traders.h"

/*
Пояснение к ведению боя!!! Во время битвы будет учитываться несколько основополагающих вещей. 1 - расстояние до цели, 2 - скорость атаки 3 - дальность атаки. 
Индетично перечислению, идёт градация приоритетов. Первым ходит тот, у кого задержка перед ударом меньше всего ходит первым. Ему на выбор будет несколько команд.
1) сделать шаг вперёд или 2) сделать шаг назад. Это либо увеличивает либо уменьшает расстояние между вами и целью. если расстояние между вами и целью будет больше дальности атаки,
то данная функция вам будет недоступна.
3) атаковать противника 4) использовать предметы( в будущем) 
*/


float arrmorK(int armor){
    float k = 0.12;
    return (1-(k*armor/(1+k*abs(armor))));
}

_Bool PlayerHealth(int helth){
    if(helth<=0){
        return true;
    }
    else{
        return false;
    }
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

void fightInRandomTrevel(struct player* conection,int enemy){
    int exp,gold,enemyMooveSpeed;
    switch (enemy)
    {
    case 1:
        struct enemy wolf = {"Волк",15,4,1,20,2,35,1,wolfSkin,enemyEffects};
        enemyMooveSpeed= wolf.speed;
        Batle(conection,enemyMooveSpeed,&wolf);
        exp = wolf.expOut;
        gold = wolf.moneyOut;
        break;  
    case 2:
        struct enemy bear = {"Медведь",40,10,0,25,1,45,1,bearSkin,enemyEffects};
        enemyMooveSpeed=bear.speed;
        Batle(conection,enemyMooveSpeed,&bear);
        exp = bear.expOut;
        gold = bear.moneyOut;
        break;
    case 3:
        struct enemy monkey = {"Макака",20,6,3,20,4,40,2,theMonkeyBar,enemyEffects};
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
    while(enemy->hp>0 && conection->playerHP>0){
        sleep(3);
        system("clear");
        printf("Вы %d|%d hp            %s %d hp\n",conection->playerHP,conection->playerMaxHp,enemy->enemyName,enemy->hp);
        printf("расстояние %d метров\n", range);
        switch (nextStep(conection,enemy,&shortplayerspeed, &enemyMooveSpeed))
        {
        case 1:
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
