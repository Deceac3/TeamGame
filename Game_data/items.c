struct weapon dagger = {"Даггер",1, 3, 10, 0,2};  // базовое оружие вора
struct weapon thiefsBlade = {"Клинок Вора",1, 3, 35, 0, 2.5};
struct weapon spire = {"Копьё",2, 2, 10, 0,1.5};  // базовое оружие танка
struct weapon twoHandedSword ={"Двуручный мечь",2, 2, 30, 0,1.75};
struct weapon staff = {"Магический посох", 4, 1, 10, 0,1};  // базовое оружие мага
struct weapon WizardStaff ={"Посох грома",5,1,50,0,1.4};
struct weapon hands = {"Руки",1,2,0,-1,1};     //   Базовое оружие любого персонажа у которого нет оружия

struct armor rags = {"rags",3, 3,5,0};  // Базовая броня вора
struct armor armour = {"Броня",1, 6,20,0};  // Базова броня танка
struct armor robe = {"Роба",2, 2,6,0};    // Базовая броня мага
struct armor HiddenChainmail ={"Броня со скрытой кольчугой",3,5,15,0};
struct armor MehaArmor = {"Механическая броня",1,8,30,0};
struct armor cultRobe = {"Роба культиста",2,4,10,0};

struct GameItem wolfSkin = {"Волчья шкура",1,5};
struct GameItem bearSkin = {"Медвежья шкура",1, 10};
struct GameItem theMonkeyBar = {"Посох макакаки",1, 90};
struct GameItem flowerOfRestoration = {"Цветок востановления",1,6};
struct GameItem OvnerTavernLatter ={"Письмо в другой город",2,0};

/*
Это базовый пак зелек  
*/

struct potion healingFlask ={"Зелье востаноления", 1, 15, 8};
struct potion stoneSkin = {"Зелье каменной кожи",2,5,14};
struct potion magicEssence={"Зелье магической эсенсии",3,8,10};
struct potion agilSkils ={"Зелье ловкости",4,8,10};
struct potion strongEssence={"Зелье силы",5,8,10};
struct potion speedEssence ={"Зелье скорости", 6,5,20};
struct potion luckEssence ={"Зелье удачи",7,2,30};

struct effects playerEffects = {0,0,0,0,0,0,0};     //  базовый объект эффектов для игрока
struct effects enemyEffects = {0,0,0,0,0,0,0};     //   отсутствие эффектов на противнике тоже должно записываться. Если противников будет несколько то нужно больше объектов этих структур

struct playerPotionsBag prePlayerPB = {.healingFlaskCount = 1,.stoneSkinCount = 0,.magicEssenceCount=0,.agilSkilsCount=0,.strongEssenceCount=0,.speedEssenceCount=0,.luckEssenceCount=0};

struct enemy wolf = {"Волк",15,4,20,2,35,1};
struct armor wolfArm ={"Волчья шкура",1,1,0,0};
struct weapon wolfClaws ={"Волчьи когти",1,2,0,0,1.5};
struct enemy bear = {"Медведь",40,10,25,1,45,1};
struct enemy monkey = {"Макака",20,6,20,4,40,2};

struct class mag = {1,50,1,2,3,2,4,50,2};
struct class theif = {2,70,2,6,1,3,3,30,10};
struct class tank = {3,100,4,2,1,4,1,40,7};

struct enemy* EnemysArray;
int EnemysCount=3;//Хочешь сделать больше противников? Добавь +1 к этому счётчику и запиши противника в массив. Потом будем делить их по локам

int main_time,main_day;
void PreLoader(){
    QestLoading();
    enemyLoading();
    //снизу представленна запись оружия и брони в структуры классов
    mag.classWeapon = staff;
    mag.classArmour = robe;
    theif.classWeapon = dagger;
    theif.classArmour = rags;
    tank.classArmour = armour;
    tank.classWeapon = spire;
    //Снизу запись всех видов зелий в портфель героя
    prePlayerPB.healingFlask=healingFlask;
    prePlayerPB.stoneSkin=stoneSkin;
    prePlayerPB.magicEssence=magicEssence;
    prePlayerPB.agilSkils=agilSkils;
    prePlayerPB.strongEssence=strongEssence;
    prePlayerPB.speedEssence=speedEssence;
    prePlayerPB.luckEssence=luckEssence;
    main_time=12;
    main_day=1;
}

void enemyLoading(){
    //снизу представленна запись предметов в массив структур
    EnemysArray[0]=wolf;
    EnemysArray[1]=bear;
    EnemysArray[2]=monkey;
    //снизу представленна запись особых предметов в структуры противников
    wolf.GameItem = wolfSkin;
    bear.GameItem = bearSkin;
    monkey.GameItem = theMonkeyBar;
    //снизу представлена запись брони вражеским существам
    wolf.enemyArmor=wolfArm;
    //снизу представлена запись оружия вражеским сущствам
    wolf.enemyWeapon=wolfClaws;
}
time_t begin;