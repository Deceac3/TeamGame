#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "struct.h"
#include "items.c"
/*
Во прикол. Все функции после их создания помещайте сюда. Так проще будет отслеживать, что где лежит и позволит вам распологать функции 
в коде так, как вам хочется, иначе такие функции как: floar, _Bool или другого вида (не void\int функци) будут автоматом записываться
в виде int функций.
*/
_Bool blacksmith(struct player*,int);
_Bool herbalist(struct player*,int);
_Bool magician(struct player*, int);
_Bool ovnerTavern(struct player*,int);
_Bool PlayerHealth(int);
_Bool batlemoove(struct player*, struct enemy*, int, int*);
_Bool potionBagUse(int, struct player*, _Bool*);
_Bool potionBuying(struct player*);

float arrmorK(int);

int missChance(int);
int nextStep(struct player*,struct enemy*, int*, int*);
int WeaponDamage(struct player*);
int DiceNumb(int);
int randexpf(int);
int IntPlayerChoose();
int potionBagChek(struct potion, int,int);

void PreLoader(struct enemy*);
void potionBagUseInfo(struct playerPotionsBag,int*);
void TrevelLobby(int,_Bool*,struct player*);
void LvlStatsUp(struct player*);
void LvlExperienceUp(struct player*);
void damageTaken(struct player*, struct enemy*);
void Batle(struct player*,int*,struct enemy*);
void fightInRandomTrevel(struct player*,int);
void RandomTrevelForTresure(struct player*);
void herbalistqest(struct player*);
void ovnerTavernQests(struct player*);
void tradersMT(struct player*);
void traderSelector(struct player*, int);
void blacksmithTrade(struct player*);
void createHero(struct player*);
void info(struct player*);
void relax(int, struct player*);
void gameSelectMenu(struct player*);
void statusEffectsPlayer(struct player*);
void classSelector(struct player*, struct class);
void ArmorItemInfo(struct armor);
void WeaponItemInfo(struct weapon);
void EndGame(time_t);
void potionInfo(struct playerPotionsBag);
void potionChekInfo(struct potion, int);
void healingFlaskEffect(struct player*);
void stoneSkinEffect(struct player*);
void magicEssenceEffect(struct player*);
void agilEffect(struct player*);
void strongEffect(struct player*);
void speedEffect(struct player*);
void luckEffect(struct player*);
void textNextMoove(int,struct player*);
void potionArr();
void QestLoading();
void QestComplyteRevards(int, int,struct player*);

#include "tradersQests.h"
#include "traders.h"
#include "Fighting.h"
#include "functions.h"
