/*
Пояснение к ведению боя!!! Во время битвы будет учитываться несколько основополагающих вещей. 1 - расстояние до цели, 2 - скорость атаки 3 - дальность атаки. 
Индетично перечислению, идёт градация приоритетов. Первым ходит тот, у кого задержка перед ударом меньше всего ходит первым. Ему на выбор будет несколько команд.
1) сделать шаг вперёд или 2) сделать шаг назад. Это либо увеличивает либо уменьшает расстояние между вами и целью. если расстояние между вами и целью будет больше дальности атаки,
то данная функция вам будет недоступна.
3) атаковать противника 4) использовать предметы( в будущем) 
*/

/*
Демо версия функции, она вызывается для создания площадки для битвы. В зависимости от рандом, выпадает количество противников от 2 до 6
*/
void RandomTrevelForTresure(struct player* conection){
    int enemys,enemyFighter;         // В бета версии будет пока что так. Енемис это рандомное количество противников в одном путешествии. Каждый противник будет выбираться рандомно каждый заход.
    enemys = rand()%4+2;      // от 2 до 6 противников будет выпадать. За каждую победу над противником будет выдаваться опыт и рандомная награда, такая ка деньги или особый предмет.
    for(int i = 0; i<=enemys; i++){
        if(conection->player_alive){
            timeChanges(1);
            enemyFighter = rand()%3+1;
            fightInRandomTrevel(conection, enemyFighter);
        }   
        else{
            break;
        }
    }
}

/*
Демо функция которая вызывается для создания противника и начинает битву с выбраным противником
*/
void fightInRandomTrevel(struct player* conection,int enemy){
    int enemyMooveSpeed;
    struct enemy NextEnemy;
    NextEnemy=EnemysArray[enemy-1];
    enemyMooveSpeed=NextEnemy.speed;
    Batle(conection,&enemyMooveSpeed,&NextEnemy);
}

/*
Демо функция создания битвы. Принимет в себя противника с которым будет сражаться герой
*/
void Batle(struct player* conection,int* enemyMooveSpeed,struct enemy* enemy){
    int range=4,playerchoose, shortplayerspeed = conection->playerSpeed-conection->playerEffects.speedChanges;
    printf("Вот уже %d час(а/ов)... Похоже, перед вами возникла очередная преграда: %s\nБитва началась!\n", main_time, enemy->enemyName);
    while(enemy->hp>0 && conection->playerHP>0){
        sleep(2);
        printf("Вы %d|%d hp            %s %d hp\n",conection->playerHP,conection->playerMaxHp,enemy->enemyName,enemy->hp);
        printf("расстояние %d метров\n", range);
        switch (nextStep(conection,enemy,&shortplayerspeed, enemyMooveSpeed))
        {
        case 1:
            textNextMoove(range,conection);
            _Bool chek=true;
            while(chek){
                playerchoose = IntPlayerChoose();
                chek = batlemoove(conection,enemy,playerchoose,&range);
            }
            break;
        case 2:
            if(range>enemy->enemyWeapon.range){
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
    if(enemy->hp<=0){
        conection->playerLvlExp += enemy->expOut;
        conection->playerMoney += enemy->moneyOut;
        conection->playerScore+=1;
        printf("Вам удалось победить %s!\n", enemy->enemyName);
        LvlExperienceUp(conection);
    }
    }
}

/*
Функция вовращает состояние хода героя и предоставляет выбор действия игроку.
*/
_Bool batlemoove(struct player* conection, struct enemy* enemy, int chose, int* rangeuk){
    switch (chose)
    {
    case 1:
        if(*rangeuk>1){
            *rangeuk =*rangeuk-1;
            return false;
        }
        else{
            printf("Вы не можете сделать шаг вперёд. Расстояние между вами и противником %d!\n",*rangeuk);
            return true;
        }
        break;
    case 2:
        if(*rangeuk>conection->playerWeapon.range){
            printf("Вы не можете атаковать. Расстояние слишком большое. %d | %d\n", conection->playerWeapon.range, *rangeuk);
            return true;
        }
        else{
            int chance,enemyAgil =3, randCh = rand()%100;
            chance = missChance(enemyAgil);
            if(randCh>chance){
                int finalDamage;
                float armor,damage;
                damage = (float)WeaponDamage(conection);
                switch (conection->playerWeapon.type)
                {
                case 1:
                    armor =magicArrmor(armBackTypeEnemy(2,*enemy));
                    finalDamage = (int)(damage*armor);
                    break;
                case 2|3|5:
                    armor = arrmorK(armBackTypeEnemy(1,*enemy));
                    finalDamage = (int)(damage*armor);
                    break;
                case 4:
                    finalDamage = (int)(damage);
                    break;
                default:
                    break;
                }
                enemy->hp=enemy->hp - (finalDamage);
                printf("Вы атакуете врага и наносите ему урона %d\nздоровье противника %d\n", finalDamage,enemy->hp);
                return false;
            }
            else{
                printf("Вы промахнулись.\n");
                return false;
            }
        }
        break;
    case 3:
        *rangeuk=*rangeuk+1;
        printf("Вы делаете шаг назад. Расстояние между вами %d\n",*rangeuk);
        return false;
        break;
    case 4:
        int count;
        potionBagUseInfo(conection->playerPotionsBag,&count);
        if(count >=1){
            _Bool cheker;
            _Bool NotUsed=false;
            int hchose;
            printf("Какое зелье вы бы хотели использовать?\n0)Если не использовать зелье\n");
            while (cheker)
            {
                hchose=IntPlayerChoose();
                switch (hchose)
                {
                case 0:
                    NotUsed= true;
                    cheker=false;
                    break;
                case (1||2||3||4||5||6||7):
                    cheker = potionBagUse(hchose,conection,&NotUsed);
                    break;
                default:
                    printf("Вы ввели номер несуществующего зелья\n");
                    break;
                }
            }
            printf("%d\n",NotUsed);
            if(NotUsed){
                _Bool shek = true;
                while (shek)
                {
                    textNextMoove(*rangeuk,conection);
                    hchose = IntPlayerChoose();
                    shek = batlemoove(conection,enemy,hchose,rangeuk);
                }
            }
            return false;
        }
        else{
            printf("У вас нет доступных зелий для использования\n");
            return true;
        }
        break;
    case 5:
        return false;
        break;
    default:
        printf("Вы выбрали несуществующее действие, попробуйте снова\n");
        return true;
        break;
    }
}

/*
Функция возвращает целочисленную констнанту того, кто будет ходить в зависимости от их скорости и прошлых действий
*/
int nextStep(struct player* conection,struct enemy* enemy, int* playerspeed, int* enemyspeed){
    int x;
    if(*playerspeed < *enemyspeed){
        *enemyspeed = *enemyspeed- *playerspeed;
        *playerspeed =  conection->playerSpeed-conection->playerEffects.speedChanges;
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
            *playerspeed = conection->playerSpeed-conection->playerEffects.speedChanges;
            return 1;
            break;
        case 1:
            *playerspeed = 1;
            *enemyspeed = enemy->speed;
            return 2;
            break;
        
        default:
            return 0;
            break;
        }
    }
}

/*
Функция выводит текст следующего хода главного героя. В случае некоторых невозможных действий, строки с действием зачёркиваются
*/
void textNextMoove(int range,struct player* conection){
    if(range>conection->playerWeapon.range){
            if (range >1){
                printf("Сейчас ваш ход что вы сделаете?\n1)Сделать шаг вперёд\n\e[9m2)Атаковать противника вашим оружием\e[m\n3)Сделать шаг назад\n4)Использовать зелье\n5)Злобно стоять на месте\n");
            }
            else{
                printf("Сейчас ваш ход что вы сделаете?\n\e[9m1)Сделать шаг вперёд\e[m\n\e[9m2)Атаковать противника вашим оружием\e[m\n3)Сделать шаг назад\n4)Использовать зелье\n5)Злобно стоять на месте\n");
            }
            }
            else{
                if (range>1){
                printf("Сейчас ваш ход что вы сделаете?\n1)Сделать шаг вперёд\n2)Атаковать противника вашим оружием\n3)Сделать шаг назад\n4)Использовать зелье\n5)Злобно стоять на месте\n");
                }
                else{
                    printf("Сейчас ваш ход что вы сделаете?\n\e[9m1)Сделать шаг вперёд\e[m\n2)Атаковать противника вашим оружием\n3)Сделать шаг назад\n4)Использовать зелье\n5)Злобно стоять на месте\n");
                }
            }
}

/*
ПОСЛЕ ЭТОЙ СТРОЧКИ НИЧЕГО МЕНЯТЬ НЕ НАДО. ТАМ ЛЕЖАТЬ ФУНКЦИИ ВЛЯЮЩИЕ НА ЧТО-ТО, 
ОНИ НЕ МЕНЯЮТ МОДЕЛЬ ФАЙТИНГА, А РАСЧИТЫВАЮТ ЗНАЧЕНИЯ И ЭФФЕКТЫ
*/

/*
функция возвращает целочисленное количество урона по его типу и всем эффектам
*/
int WeaponDamage(struct player* conection){
    switch (conection->playerWeapon.type)
    {
    case 1: // магический урон
        return (conection->playerMind+conection->playerEffects.mindChanges)*conection->playerWeapon.damage;
        break;
    case 2: // физ урон от силы
        return (conection->playerStrong+conection->playerEffects.strongChanges)*conection->playerWeapon.damage;
        break;
    case 3: // физ урон от ловкости
        return (conection->playerAgil+conection->playerEffects.agilChanges)*conection->playerWeapon.damage;
        break;
    case 4: // пронзающий урон
        return (conection->playerAgil+conection->playerEffects.agilChanges+conection->playerStrong+conection->playerEffects.strongChanges)*conection->playerWeapon.damage/2;
        break;
    case 5: // урон от оружия берсерка считается физическим
        return (5+conection->playerMaxHp-conection->playerHP)*conection->playerWeapon.damage;
        break;
    default:
        return 0;
        break;
    }
}

/*
Функция возвращает значение, которое выпадает на кубике заданного значения по Numb
*/
int DiceNumb(int Numb){
    int result;
    result = rand()%Numb;
    printf("Вы бросаете кость d%d. Вам выпадает %d\n", Numb, result);
    return result;
}

/*
функция возвращает процентный шанс промаха
*/
int missChance(int agil){
    float k = 0.07;
    return (k*agil/(1+k*abs(agil))*100);
}

/*
Функция фиксирует кооличество зелий у игрока
*/
void potionBagUseInfo(struct playerPotionsBag pack,int* count){
    for(int i=0;i<(sizeof(pack)/(sizeof(pack.agilSkils)+sizeof(int)));i++){
        *count+=potionBagChek(*(&pack.healingFlask+i),*(&pack.healingFlaskCount+i),i);
    }
}

/*
Функция возвращает количество зелий пользователя и выводит их в консоле
*/
int potionBagChek(struct potion potion, int count,int i){
    if(count!=0){
        printf("%d) %s: %d\n",i+1,potion.potionName,count);
        return 1;
    }
    else{
        return 0;
    }
}

/*
функция возвращает состояния выпитого зелья или нет. В случае если зелье не было использовано, героя возвращает в выбор действия
*/
_Bool potionBagUse(int hchose, struct player* conection,_Bool* NotUsed){
    switch (hchose)
    {
    case 1:     //Зелье исцеления
        if(conection->playerPotionsBag.healingFlaskCount>=1){
            if(conection->playerHP<conection->playerMaxHp){
                healingFlaskEffect(conection);
                printf("Вы исцелили %d здоровья!\n", conection->playerMaxHp-conection->playerHP);
                return false;
            }
            else{
                printf("Ваше здоровье полное, незачем использовать зелье\n");
                *NotUsed= true;
                return false;
            }
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 2:
        if (conection->playerPotionsBag.stoneSkinCount>=1)
        {
            stoneSkinEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 3:
        if (conection->playerPotionsBag.magicEssenceCount>=1)
        {
            magicEssenceEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 4:
        if (conection->playerPotionsBag.agilSkilsCount>=1)
        {
            agilEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 5:
        if (conection->playerPotionsBag.strongEssenceCount>=1)
        {
            strongEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 6:
        if (conection->playerPotionsBag.speedEssenceCount>=1)
        {
            speedEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    case 7:
    if (conection->playerPotionsBag.agilSkilsCount>=1)
        {
            luckEffect(conection);
            return false;
        }
        else{
            printf("У вас не осталось зелий данного типа, попробуйте другое\n");
            return true;
        }
        break;
    default:
        printf("Вы выбрали неверный номер зелья, попробуйте снова\n");
        return true;
        break;
    }
}

/*Тут собраны все эффекты зелий в виде функций их воздействия на игрока*/

void healingFlaskEffect(struct player*conecntion){
    conecntion->playerPotionsBag.healingFlaskCount--;
    conecntion->playerHP+= conecntion->playerPotionsBag.healingFlask.potionValue;
    if(conecntion->playerHP>conecntion->playerMaxHp){
        conecntion->playerHP=conecntion->playerMaxHp;
    }
}

void stoneSkinEffect(struct player* conection){
    conection->playerPotionsBag.stoneSkinCount--;
    conection->playerEffects.armourChanges+=conection->playerPotionsBag.stoneSkin.potionValue;
}

void magicEssenceEffect(struct player* conection){
    conection->playerPotionsBag.magicEssenceCount--;
    conection->playerEffects.mindChanges+= conection->playerPotionsBag.magicEssence.potionValue;
}

void agilEffect(struct player* conection){
    conection->playerPotionsBag.agilSkilsCount--;
    conection->playerEffects.agilChanges+=conection->playerPotionsBag.agilSkils.potionValue;
}

void strongEffect(struct player* conection){
    conection->playerPotionsBag.strongEssenceCount--;
    conection->playerEffects.strongChanges+=conection->playerPotionsBag.strongEssence.potionValue;
}

void speedEffect(struct player* conection){
    conection->playerPotionsBag.speedEssenceCount--;
    conection->playerEffects.speedChanges+=conection->playerPotionsBag.speedEssence.potionValue;
}

void luckEffect(struct player* conection){
    conection->playerPotionsBag.luckEssenceCount--;
    conection->playerEffects.speedChanges+=conection->playerPotionsBag.speedEssence.potionValue;
}

/*
Функция возвращает количество физического урона, поглощённого бронёй в процентном соотношении
*/
float arrmorK(int armor){
    float k = 0.12;
    return (1-(k*armor/(1+k*abs(armor))));
}

/*
функция возвращает количество магического урона, поглощёного бронёй в процентном соотношении
*/
float magicArrmor(int marr){
    float k=0.2;
    return(1-(k*marr/(1+k*abs(marr))));
}

/*
функция возвращает состояние здоровья героя PS потом будет процентное определение для отображение графически количества здоровья
*/
_Bool PlayerHealth(int helth){
    if(helth<=0){
        return true;
    }
    else{
        return false;
    }
}

/*
Функция выполняет расчёт, получит ли урон герой, сколько урона он получит
*/
void damageTaken(struct player* conection, struct enemy* enemy){
    int chance;
    int randCh = rand()%100;
    chance = missChance(conection->playerAgil+conection->playerEffects.agilChanges);
    if(randCh<chance){
        printf("Противник промахнулся\n");
    }
    else{
        printf("Противник попал по вам\n");
        int damage;
        float armor;
        switch (enemy->enemyWeapon.type)
        {
        case 1:
            armor = magicArrmor(arrBackType(2,conection)+conection->playerEffects.armourChanges);
            damage = (enemy->damage*enemy->enemyWeapon.damage)*armor;
            break;
        case 2:
            armor = arrmorK(arrBackType(1,conection)+conection->playerEffects.armourChanges);
            damage = (enemy->damage*enemy->enemyWeapon.damage)*armor;
            break;
        default:
            break;
        }
        conection->playerHP -= damage;
        printf("Вы получили %d урона.\n",damage);
        if(PlayerHealth(conection->playerHP)){
            printf("Вы погибли! игра окончена!\n");
            conection->player_alive=false;
        }
    }
}

/*
Функция возвращает количество урона по типу проходящего урона расчитывая всю броню по эффектам, броне, пасивной броне и т.д.
*/
int arrBackType(int type,struct player* conection){
    switch (type)
    {
    case 1:
        if(conection->PlayerArmor.type == 1){
            return conection->PlayerPassiveArmor+conection->PlayerArmor.defence;
        }
        else if(conection->PlayerArmor.type== 3){
            return conection->PlayerPassiveArmor+(conection->PlayerArmor.defence/2);
        }
        else{
            return conection->PlayerPassiveArmor;
        }
        break;
    case 2:
        if(conection->PlayerArmor.type == 2){
            return conection->playerPassiveMagArmor+conection->PlayerArmor.defence;
        }
        else if(conection->PlayerArmor.type == 3){
            return conection->playerPassiveMagArmor+(conection->PlayerArmor.defence/2);
        }
        else{
            return conection->playerPassiveMagArmor;
        }
        break;
    default:
        return 0;
        break;
    }
}

/*
Функция возвращает количество брони, исходя из типа урона на входе и всех расчётов брони противника
*/
int armBackTypeEnemy(int type, struct enemy enemy){
    switch (type)
    {
    case 1:
        switch (enemy.enemyArmor.type)
        {
        case 1:
            return enemy.phisArmour+enemy.enemyArmor.defence+(enemy.enemyArmor.defence);
            break;
        case 2:
            return enemy.phisArmour+enemy.enemyArmor.defence;
            break;
        case 3:
            return enemy.phisArmour+enemy.enemyArmor.defence+(enemy.enemyArmor.defence/2);
            break;
        default:
            return 0;
            break;
        }
        break;
    case 2:
        switch (enemy.enemyArmor.type)
        {
        case 1:
            return enemy.magArmour+enemy.enemyArmor.defence;
            break;
        case 2:
            return enemy.magArmour+enemy.enemyArmor.defence+(enemy.enemyArmor.defence);
            break;
        case 3:
            return enemy.magArmour+enemy.enemyArmor.defence+(enemy.enemyArmor.defence/2);
            break;
        default:
            return 0;
            break;
        }
        break;
    default:
        return 0;
        break;
    }
}
