# Задача 2. Дилемма заключённого

### Общие сведения
Требуется реализовать консольное приложение, позволяющее симулировать повторяющуюся ["Дилемму заключённого”](http://en.wikipedia.org/wiki/Prisoner's_dilemma) для троих заключённых. [Оригинальная задача в курсе SICP](https://github.com/yangchenyun/learning-sicp/blob/master/practices/assignments/06.prisoner-s-dilemma/ps4prs.pdf )

### Устройство игры
Программа позволяет “соревноваться”  трём “заключённым” (далее - стратегиям). которые пытаются максимизировать набранные очки. Выигрывает стратегия, по результатам игры (некоторого фиксированного количества ходов) набравшая наибольшее количество очков.

Игра протекает следующим образом: пошагово, в течение некоторого количества шагов, симулятор выясняет выбор каждой стратегии: сотрудничать (C) или предать (D). После этого, симулятор сообщает каждой стратегии выбор её оппонентов и вычисляет очки за текущий раунд. Очки вычисляются по матрице игры (см. Приложение).

Стратегии делают свой выбор основываясь на накопленном опыте: истории ходов оппонентов и собственной. Алгоритмы стратегий могут быть самыми различными, начиная от тривиальных “всегда сотрудничать” или “выдавать случайный результат”. Изначально, история ходов каждой стратегии пуста.

Симуляция может проходить в трёх режимах:
+ <b>Соревнование с детализацией.</b> На каждом шаге программа ожидает нажатия клавиши от пользователя, после которого делает один шаг. Подробное состояние симуляции выводится после каждого шага (выбор каждой стратегии, очки за текущий ход, очки за текущую игру).
Игра прерывается по команде `quit`.
+ <b>Соревнование без детализации.</b> Программа вычисляет заданное количество ходов и выводит результат.
+ <b>Турнир.</b> Программа перебирает все возможные тройки (без повторений, т.е. s1,s2,s3 и s3,s2,s1 - одна и та же тройка) указанных стратегий и по общему результату выявляет победителя по сумме баллов за все игры. Результаты каждого соревнования и итоговый протокол выводятся на экран 

### Технические детали
1. На старте программе подаются следующие аргументы командной строки:
   + Имена соревнующихся стратегий `--names={strategy_names}` (3 для детализированного и быстрого режимов и 3 или более - для турнирного)
   + Название режима `--mode=[detailed|fast|tournament]` (опциональный, по умолчанию `detailed` для трех стратегий, `tournament` для >3 стратегий)
   + Число шагов симуляции `--steps=<n>` (опциональный)
   + Директория с конфигурационными файлами стратегий `--configs=<dirname>` (опциональный)
   + Файл с матрицей игры `--matrix=<filename>`(опциональный)

1. Технически, каждая стратегия представляется в виде класса. У стратегий выделяется общий абстрактный интерфейс. Нетривиальные стратегии хранят свои параметры в собственном конфигурационном файле произвольного формата. 

1. При сдаче необходимо продемонстрировать 3-5 тривиальных и 3-5 нетривиальных стратегии, включая “метастратегии” - использующие несколько других стратегий для принятия решения. Сложность/интересность стратегий не ограничивается.

1. Для конструирования классов-стратегий следует использовать шаблон проектирования “Фабрика объектов”.

1. Матрица игры описывает количество очков, получаемых стратегиями за каждый ход. Матрицу по умолчанию можно вшить в код программы. Пример правильной матрицы для игры с тремя заключёнными содержится в приложении. Формат файла с матрицей произволен.

1. При реализации программы подразумевается максимальное использование STL. Для работы с файлами необходимо использовать файловые потоки, переключенные в режим сообщения об ошибках исключениями (см. метод `std::ios::exceptions`)

1. Бизнес-логика симулятора должна быть покрыта модульными тестами.

1. При сдаче, преподаватель может потребовать интегрировать в симулятор студента стратегии другого учащегося и устроить турнир. 

1. Поощряется реализация возможности динамической загрузки стратегий из динамических библиотек.

1. Базовая функциональность игры должна быть покрыта модульными тестами.

### Приложение (Матрица игры)


|Стратегия 1|Стратегия 2|Стратегия 3|     |Стратегия 1|Стратегия 2|Стратегия 3|
|   :---:   |   :---:   |   :---:   |:---:|   :---:   |   :---:   |   :---:   |
|     C     |     C     |     C     |  ⇒  |     4     |     4     |     4     |
|     C     |     C     |     D     |  ⇒  |     3     |     3     |     9     |
|     C     |     D     |     C     |  ⇒  |     3     |     9     |     3     |
|     D     |     C     |     C     |  ⇒  |     9     |     3     |     3     |
|     C     |     D     |     D     |  ⇒  |     0     |     5     |     5     |
|     D     |     C     |     D     |  ⇒  |     5     |     0     |     5     |
|     D     |     D     |     C     |  ⇒  |     5     |     5     |     0     |
|     D     |     D     |     D     |  ⇒  |     1     |     1     |     1     |