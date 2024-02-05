#include "struct.h"
#include "items.c"

//Квесты Кузнеца



//Квесты Травницы
struct QestTypeCollect herbalistFlowers = {.ItemCounts=5};


//Квесты Колдуна



// Квесты владельца таверны



//подругрзка квестовых предметов через функцию
void QestLoading(){
    herbalistFlowers.GameItem = flowerOfRestoration;
}