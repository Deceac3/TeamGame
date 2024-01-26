#include <stdio.h> 
#include <math.h>

float arrmorK(int armor){
    float k = 0.12;
    return (1-(k*armor/(1+k*abs(armor))));
}

void main(){
    float x;
    int armor;
    for(armor = 0; armor <10; armor++){
    x = arrmorK(armor)*100;
    x= (int)x;
    printf("%f\n", x);
    }
}

//формула для расчёта доп урона к оружию от статов персонажа
void pipi(){
float agil, bafs,dopdamag,debafs;

dopdamag = sqrt((agil+bafs-debafs)*3);

}
