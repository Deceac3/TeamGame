struct weapon dagger = {"Даггер",1, 3, 10, 0,2};  // базовое оружие вора
struct weapon spire = {"Копьё",2, 2, 10, 0,1.5};  // базовое оружие танка
struct weapon staff = {"Магический посох", 4, 1, 10, 0,1};  // базовое оружие мага
struct weapon hands = {"Руки",1,2,0,-1,1};     //   Базовое оружие любого персонажа у которого нет оружия
struct armor rags = {"rags", 3,1,0};  // Базовая броня вора
struct armor armour = {"armour", 6,1,0};  // Базова броня танка
struct armor robe = {"robe", 2,1,0};    // Базовая броня мага
struct specialItem wolfSkin = {"Волчья шкура",1,5};
struct specialItem bearSkin = {"Медвежья шкура",2, 10};
struct specialItem theMonkeyBar = {"Посох макакаки",3, 90};
struct potion healingFlask ={"Зелье востаноления", 1, 15, 8};
struct potion stoneSkin = {"Зелье каменной кожи",2,5,14};


//struct enemy wolf = {"Волк",15,4,1,20,2,35,1,wolfSkin};
//struct enemy bear = {"Медведь",40,10,0,25,1,45,1,bearSkin};
//struct enemy monkey = {"Макака",20,6,3,20,4,40,2,theMonkeyBar};
