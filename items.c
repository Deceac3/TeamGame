struct weapon dagger = {"Даггер",1, 3, 10, 0,2};  // базовое оружие вора
struct weapon thiefsBlade = {"Клинок Вора",1, 3, 35, 0, 2.5};
struct weapon spire = {"Копьё",2, 2, 10, 0,1.5};  // базовое оружие танка
struct weapon twoHandedSword ={"Двуручный мечь",2, 2, 30, 0,1.75};
struct weapon staff = {"Магический посох", 4, 1, 10, 0,1};  // базовое оружие мага
struct weapon WizardStaff ={"Посох грома",5,1,50,0,1.4};
struct weapon hands = {"Руки",1,2,0,-1,1};     //   Базовое оружие любого персонажа у которого нет оружия

struct armor rags = {"rags", 3,5,0};  // Базовая броня вора
struct armor HiddenChainmail ={"Броня со скрытой кольчугой", 5,15,0};
struct armor armour = {"Броня", 6,20,0};  // Базова броня танка
struct armor MehaArmor = {"Механическая броня",8,30,0};
struct armor robe = {"Роба", 2,6,0};    // Базовая броня мага
struct armor cultRobe = {"Роба культиста",4,10,0};

struct specialItem wolfSkin = {"Волчья шкура",1,5};
struct specialItem bearSkin = {"Медвежья шкура",2, 10};
struct specialItem theMonkeyBar = {"Посох макакаки",3, 90};

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

//struct enemy wolf = {"Волк",15,4,1,20,2,35,1,wolfSkin};
//struct enemy bear = {"Медведь",40,10,0,25,1,45,1,bearSkin};
//struct enemy monkey = {"Макака",20,6,3,20,4,40,2,theMonkeyBar};
struct class mag = {1,50,1,2,3,2,4,50,2};
struct class theif = {2,70,2,6,1,3,3,30,10};
struct class tank = {3,100,4,2,1,4,1,40,7};

void ClassLoader(){
    mag.classWeapon = staff;
    mag.classArmour = robe;
    theif.classWeapon = dagger;
    theif.classArmour = rags;
    tank.classArmour = armour;
    tank.classWeapon = spire;
}