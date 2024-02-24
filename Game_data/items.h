struct weapon dagger = {.name="Даггер",.range=1,.type=3, .cost=10, .update=0,.damage=2};  // базовое оружие вора
struct weapon thiefsBlade = {.name="Клинок Вора",.range=1,.type=3, .cost=35, .update=0, .damage=2.5};
struct weapon spire = {.name="Копьё",.range=2, .type=2, .cost=10, .update=0,.damage=1.5};  // базовое оружие танка
struct weapon twoHandedSword ={.name="Двуручный мечь",.range=2, .type=2, .cost=30, .update=0,.damage=1.75};
struct weapon staff = {.name="Магический посох", .range=4, .type=1, .cost=10, .update=0,.damage=1};  // базовое оружие мага
struct weapon WizardStaff ={.name="Посох грома",.range=5,.type=1,.cost=50,.update=0,.damage=1.4};
struct weapon hands = {.name="Руки",.range=1,.type=2,.cost=0,.update=-1,.damage=1};     //   Базовое оружие любого персонажа у которого нет оружия

struct armor rags = {.name="rags",.type=3,.defence=3,.cost=5,.update=0};  // Базовая броня вора
struct armor armour = {.name="Броня",.type=1, .defence=6,.cost=20,.update=0};  // Базова броня танка
struct armor robe = {.name="Роба",.type=2, .defence=2,.cost=6,.update=0};    // Базовая броня мага
struct armor HiddenChainmail ={.name="Броня со скрытой кольчугой",.type=3,.defence=5,.cost=15,.update=0};
struct armor MehaArmor = {.name="Механическая броня",.type=1,.defence=8,.cost=30,.update=0};
struct armor cultRobe = {.name="Роба культиста",.type=2,.defence=4,.cost=10,.update=0};

struct GameItem wolfSkin = {.itemName = "Волчья шкура",.itemCode=1,.itemCost=5};
struct GameItem bearSkin = {.itemName ="Медвежья шкура",.itemCode=1, .itemCost=10};
struct GameItem theMonkeyBar = {.itemName ="Посох макакаки",.itemCode=1, .itemCost=90};
struct GameItem flowerOfRestoration = {.itemName ="Цветок востановления",.itemCode=1,.itemCost=6};
struct GameItem OvnerTavernLatter ={.itemName ="Письмо в другой город",.itemCode=2,.itemCost=0};

/*
Это базовый пак зелек  
*/

struct potion healingFlask ={.potionName="Зелье востаноления",.potionType=1,.potionValue=15,.cost=8};
struct potion stoneSkin = {.potionName="Зелье каменной кожи",.potionType=2,.potionValue=5,.cost=14};
struct potion magicEssence={.potionName="Зелье магической эсенсии",.potionType=3,.potionValue=8,.cost=10};
struct potion agilSkils ={.potionName="Зелье ловкости",.potionType=4,.potionValue=8,.cost=10};
struct potion strongEssence={.potionName="Зелье силы",.potionType=5,.potionValue=8,.cost=10};
struct potion speedEssence ={.potionName="Зелье скорости",.potionType=6,.potionValue=5,.cost=20};
struct potion luckEssence ={.potionName="Зелье удачи",.potionType=7,.potionValue=2,.cost=30};

struct effects playerEffects = {0,0,0,0,0,0,0};     //  базовый объект эффектов для игрока
struct effects enemyEffects = {0,0,0,0,0,0,0};     //   отсутствие эффектов на противнике тоже должно записываться. Если противников будет несколько то нужно больше объектов этих структур

struct playerPotionsBag prePlayerPB = {.healingFlaskCount = 1,.stoneSkinCount = 0,.magicEssenceCount=0,.agilSkilsCount=0,.strongEssenceCount=0,.speedEssenceCount=0,.luckEssenceCount=0};

struct enemy wolf = {"Волк",15,4,20,2,35,0,0};
struct armor wolfArm ={"Волчья шкура",1,1,0,0};
struct weapon wolfClaws ={"Волчьи когти",1,2,0,0,1};

struct enemy bear = {"Медведь",40,10,25,1,45,0,0};
struct armor bearArm ={"Медвежья шкура",1,2,0,0};
struct weapon bearClaws={"Медвежьи когти",1,2,0,0,1};

struct enemy monkey = {"Макака",20,6,20,4,40,1,1};
struct armor monkeyArm ={"Мех макаки",3,4,0,0};
struct weapon monkeyBar={"Палка макаки",2,2,0,0,1};

struct class mag = {.classId =1,.hp=50,.str=1,.agil=2,.mind=4,.armourPassive=2,.magArmourPassive=1,.luck=4,.startSpeed=50,.money=2};
struct class theif = {.classId =2,.hp=70,.str=2,.agil=5,.mind=3,.armourPassive=3,.magArmourPassive=1,.luck=3,.startSpeed=30,.money=10};
struct class tank = {.classId =3,.hp=100,.str=4,.agil=2,.mind=1,.armourPassive=4,.magArmourPassive=1,.luck=1,.startSpeed=40,.money=7};

int EnemysCount=3;//Хочешь сделать больше противников? Добавь +1 к этому счётчику и запиши противника в массив. Потом будем делить их по локам
struct enemy* EnemysArray;

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
    wolf.GameItem = wolfSkin;
    wolf.enemyArmor=wolfArm;
    wolf.enemyWeapon=wolfClaws;
    EnemysArray[0]=wolf;

    bear.GameItem = bearSkin;
    bear.enemyArmor=bearArm;
    bear.enemyWeapon=bearClaws;
    EnemysArray[1]=bear;

    monkey.GameItem = theMonkeyBar;
    monkey.enemyArmor=monkeyArm;
    monkey.enemyWeapon=monkeyBar;
    EnemysArray[2]=monkey;
}
time_t begin;