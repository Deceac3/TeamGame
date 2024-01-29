#include <stdbool.h>
#define NAMES   20

/*
1) магическое оружие. Скелится от магии.
2) физическое оружие, Склится от количества силы
3) физическое оружие, которое скелится от ловкости
4) оружия берсерка - скелится от количества хп\ от количества потерянного хп и т.д 
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

struct armor
{
    char* name;
    int defence;
    int cost;
    int update;
};

struct enemy
{
    char* enemyName;
    int hp;
    int damage;
    int armor;
    int expOut;
    int moneyOut;
    int speed;
    int rangeAtack;
    struct specialItem specialItem;
    struct effects enemyEffects;
};

struct specialItem
{
    char* itemName;
    int itemCode;
    int itemCost;
};

struct effects
{
    int armourChanges,damageChanges,mindChanges,strongChanges,agilChanges,speedChanges,luckChanges;
};

struct playerPotionsBag
{
    int healingFlaskCount,stoneSkinCount,magicEssenceCount,agilSkilsCount,strongEssenceCount,speedEssenceCount,luckEssenceCount;
    struct potion healingFlask,stoneSkin,magicEssence,agilSkils,strongEssence,speedEssence,luckEssence;
};

struct player 
{
    _Bool player_alive;
    char playerName[20];
    int playerHP,playerMaxHp, playerClass, playerMind, playerStrong, playerAgil, playerMoney, playerLvl, playerLvlExp,playerLvlExpNext, playerStage,playerLuck,playerSpeed,PlayerPassiveArmor;
    struct armor PlayerArmor;
    struct weapon playerWeapon;
    struct effects playerEffects;
    struct playerPotionsBag playerPotionsBag;
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
