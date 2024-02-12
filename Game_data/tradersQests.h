//Квесты Кузнеца
int blacksmithQestCount=1;


//Квесты Травницы
int herbalistQestCount = 1;
struct QestTypeCollect herbalistFlowers = {.ItemCounts=5};
//Функция сдачи квестов
void herbalistqest(struct player* conection){
    switch (herbalistQestCount)
    {
    case 1:
        printf("Принеси мне 5 алых цветков регенерации из туманных лесов и я тебе неплохо заплачу!\n");
        if(conection->playerLvl == conection->playerLvl){       //Пишем условие есть ли 5 цветочков. Зависит от типо как инвентарь пон
            _Bool cheker;
            int hchose;
            while (cheker){
                printf("Передать 5 алых цветков травнице?\n1)Да\n2)Нет\n");
                hchose=IntPlayerChoose();
                switch (hchose)
                {
                case 1:
                    printf("Спасобо за помощь путник! Приходи в следующий день и я дам тебе новый квест!\n");
                    herbalistQestCount++;
                    conection->playerMoney+=25;
                    cheker =false;
                    //Будет инвентарь, уничтожаем их пон брат
                    break;
                case 2:
                    printf("Увидимся позже, путник!\n");
                    cheker=false;
                    break;
                default:
                    cheker=true;
                    break;
                }
            }
        }
        else{
            printf("Приходи когда принесёшь их мне\n");
        }
        break;
    
    default:
        break;
    }
}

//Квесты Колдуна
int magicianQestCounter = 1;


// Квесты владельца таверны
int ovnerTavernQestCounter = 1;
struct QestTypeCollect ovnerTavernLatterQ={.ItemCounts=0};
int hchose;
_Bool cheker = true;
void ovnerTavernQests(struct player* conection){
    switch (ovnerTavernQestCounter)
    {
    case 1:
        printf("У меня есть задание для тебя. Мне нужно доставить это письмо моему другу из другого города. Доставишь это письмо и возвращайся ко мне с его ответом, за это я тебе заплачу и угощу своим пивом.\n");
        while(cheker){
            printf("Принёс отнёс письмо?\n1)да\n2)нет\n");
            hchose=IntPlayerChoose();
            switch (hchose)
            {
            case 1:
                printf("Спасибо друг, вот тебе небольшое вознаграждение. Приходи на следующий день, может появятся новые задания\n");
                cheker=false;
                ovnerTavernQestCounter++;
                conection->playerMoney+=10;
                break;
            case 2:
                printf("НУ ТАК ХУЛИ ТЫ СТОИШЬ, ПИЗДУЙ\n");
                cheker=false;
                break;
            default:
                printf("Вы ввели неверный номер опции.\n");
                break;
            }
        }
        break;
    
    default:
        printf("У меня нет больше заданий, приходи позже.\n");
        break;
    }
}


//подругрзка квестовых предметов через функцию
void QestLoading(){
    herbalistFlowers.GameItem = flowerOfRestoration;
    ovnerTavernLatterQ.GameItem = OvnerTavernLatter;
}