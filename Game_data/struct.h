struct effects
{
    int armourChanges,damageChanges,mindChanges,strongChanges,agilChanges,speedChanges,luckChanges;
};

/*
Предметы будет содержать интовое значение типа.
1) Обычный лут, выпадающий с монстров, с случайных событий и т.д.
2) квестовый особый лут, который нельзя продать, передать удалить и т.д. 
*/
struct GameItem
{
    char* itemName;
    int itemCode;
    int itemCost;
};

/*
Зелья будут разделяться на некоторые типы:
Зелья типа 1 - лечащие, востанавливают хп
зелья типа 2 - защитные, увеличивают броню
зелья типа 3,4,5 - увеличивают статы интелект, ловкость и силу.
зелья типа 6 - повышают скорость
зулья типа 7 - повышают удачу
*/
struct potion
{
    char* potionName;
    int potionType;
    int potionValue;
    int cost;
};

/*
1) магическое оружие. Скелится от интелекта.
2) физическое оружие, Склится от количества силы
3) физическое оружие, которое скелится от ловкости
4) пронзающее оружие, оно наносит урон сквозь любую броню, скелится (ловкость+сила)\2
5) оружия берсерка - скелится от количества хп\ от количества потерянного хп и т.д 
*/
struct weapon
{
    char* name;
    int range;
    int type;       // Тип оружия это то, от чего оно скелится. Выше список всех типов будет
    int cost;
    int update;
    float damage;       // константа множителя урона
};
/*
Есть 2 типа брони:
1) даёт только физическую броню и защищает от физических атак
2) даёт только магическую броню и защищает от магических атак
3) гибридная броня даёт половину брони в магию и половину брони в
*/
struct armor
{
    char* name;
    int type;
    int defence;
    int cost;
    int update;
};

struct class
{
    int classId;
    int hp;
    int str;
    int agil;
    int mind;
    int armourPassive;
    int luck;
    int startSpeed;
    int money;
    struct weapon classWeapon;
    struct armor classArmour;
};

struct enemy
{
    char* enemyName;
    int hp;
    int damage;
    int expOut;
    int moneyOut;
    int speed;
    int phisArmour;
    int magArmour;
    struct armor enemyArmor;
    struct weapon enemyWeapon;
    struct GameItem GameItem;
    struct effects enemyEffects;
};

struct playerPotionsBag
{
    struct potion healingFlask,stoneSkin,magicEssence,agilSkils,strongEssence,speedEssence,luckEssence;
    int healingFlaskCount,stoneSkinCount,magicEssenceCount,agilSkilsCount,strongEssenceCount,speedEssenceCount,luckEssenceCount;
};

struct player 
{
    struct playerPotionsBag playerPotionsBag;
    struct effects playerEffects;
    struct weapon playerWeapon;
    struct armor PlayerArmor;
    char playerName[20];
    int playerHP,playerMaxHp, playerClass, playerMind, playerStrong, playerAgil, playerMoney, playerLvl, playerLvlExp,playerLvlExpNext, playerStage,playerLuck,playerSpeed,PlayerPassiveArmor,playerScore,playerPassiveMagArmor;
    _Bool player_alive;
};

//структура квеста, в котором нужно принести определённое количество определённого предмета в неё так же входят задания с письмами и т.д.
struct QestTypeCollect
{
    struct GameItem GameItem;
    int ItemCounts;
};
