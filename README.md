07.02.2024
Пишем игру на си. На данный момент игра находится в стадии написании бета версии. 
Компиляция:
gcc -Wall -o prog Game\ meinLoader.c
======================================================================================
Что где и как лежит.

##  Game meinLoader.c - лежит основной кода для запуска игры, там находятся инициализации объектов, экспорт всех нужных файлов и т.д.

##  Game_data/functions.h - сюда записываются основные команды, которые используются при взаимодействии с игроков, интерфейсом и т.д.

##  Fighting.h - это заголовочный файл, в котором хранится вся логика боя, все функции просчитывания урона и противников, которые передаются нам.

##  traders.h - там будет лежать вся логика всех торговцев, покупка, продажа, покупка услуг.

##  tradersQests.h - тут лежит вся логика выполнения квестов каждого торговца, который обладает своей веткой заданий.

##  FilesData.h - связывающий файл, содержащий все прототипы функций в нём лежит 2 заголовочных файла

##  struct.h - в этом файле лежат все прототипы структур. Для удобства они лежат в отдельном файле, чтобы можно было всегда обратиться и посмотреть что и где лежит

##  items.c - содержит в себе все инициализации объекто структуры, кроме некоторых иссключений. Так же в файле находится функция, производящая микропроцессы для присваивания некоторых параметров для структур

======================================================================================
Выход бета 1.0
По планам намечается выход первого прототипа игры, когда все стандартные функции игры будут работать. 
Первая версия будет компилироваться в терминале, содердержать обычный текст без символов и все действия будут происходить посредством набора номера определённой функции. 
Игра не будет содержать определённой концовки на стадии бета 1.0
