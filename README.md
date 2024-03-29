# TowerofHanoi
The Tower of Hanoi is a math game or puzzle. This mathematical puzzle has the following rules (classic version): three rods are set, one of them has a tower of n disks, and under each disk, except for the lowest n-th disk, there is a disk of larger diameter. The object of the game is to move the tower to another rod according to the following rules: in one step you can move only one disk, and only the one located at the top of your stack; each disc can only be placed on a larger diameter disc.

Для того, щоб зіграти в гру потрібно відкрити проект в QtCreator, а потім скомпілювати і запустити його.
Після запуску програми на екрані буде зображено головне меню ігри (Рис. 3.1).

![image](https://user-images.githubusercontent.com/68056715/224507037-f447e8ec-75fe-4e76-be56-6282c3949340.png)

Меню зроблене таким чином, щоб користувач відразу розумів, що він відкрив гру. На перший погляд здається, що меню складається із трьох секторів, які ніякої інформації не мають. Проте при наведені вказівника «миші» на одне із полів буде відображено його дію: Так при наведені вказівника «миші» на першу кнопку відобразиться текст “NEW GAME”(Рис.3.2). При натиску на цю кнопку запускається нова гра, при наведені на наступну кнопку відобразиться “ABOUT” — виводить інформацію про гру. І при наведені на останню кнопку — “EXIT” — виходить із гри. 

![image](https://user-images.githubusercontent.com/68056715/224507114-4f2ba025-60a5-4313-8dc4-7044c9057cd0.png)
![image](https://user-images.githubusercontent.com/68056715/224507120-98c1cda7-04c4-4af0-a0a9-d51308b0b135.png)
![image](https://user-images.githubusercontent.com/68056715/224507122-61df110c-7110-4a42-b3cb-7ad9f57471f3.png)

Після вибору пункту “NEW GAME” відобразиться діагогове вікно з інформацією про правила та ціль ігри

![image](https://user-images.githubusercontent.com/68056715/224507136-b9040084-f8ec-4ac2-9c3e-3a811f311e0c.png)

Після натиску клавіші “OK” відкриється ігрове поле(Рис.3.6). Де можна відразу перекладати диски. За замовчуванням буде розміщено чотири диски на першому стержні.

![image](https://user-images.githubusercontent.com/68056715/224507146-86fb7acf-90c3-42a3-bf1c-27c736cd4987.png)

Щоб вибрати диск, потрібно натиснути на той сектор в якому він знаходься. Після вибору диск підніметься і його можна покласти на будь-який інший стержень, але тільки тоді, коли виконується умова, що там немає диску меншого розміру. У випадку, коли покласти більший диск на менший висвітлиться діалогове вікно, яке сповістить про помилку. А диск повернеться до попереднього стану і можна продовжити гру далі.

![image](https://user-images.githubusercontent.com/68056715/224507159-c0acb73b-f43f-4b11-89c9-8daab4db8d02.png)

Після перескладання усіх дисків з першого стержня до третього ігра сповістить користувача про те, що гру завершено

![image](https://user-images.githubusercontent.com/68056715/224507175-c2636ede-08ad-4d27-8796-0ebc2f95cfad.png)

Далі натискає на клавішу “ОК” вибираємо пункт “Меню” та натискаємо на “Нова гра”, а також можна скористатися “гарячими” клавішами Ctrl+N, ця дія запустить нову гру.
Також в цьому самому пункті присутня можливість вибрати кількість дисків для гри

![image](https://user-images.githubusercontent.com/68056715/224507199-0f5e4945-afcb-43d6-bc01-5e9359175d75.png)

Після вибору кількості дисків вони відобразяться на ігровому полі. На наступному рисунку зображено вежу із 8 дисків.

![image](https://user-images.githubusercontent.com/68056715/224507216-27cb6836-1f68-467e-a043-e1bd159d7a81.png)

“Автоматична гра” (гаряча клавіша Ctrl+A) — вмикає режим розв’язку задачі комп’ютером.
Перевіримо правильність алгоритму. За попередніми підрахунками мінімальна кількість кроків за яку можна перекласти диск рівна 2n-1. Візьмемо n = 8. За формулою отримаємо 28 — 1 = 255.
Результат алгоритму, що реалізований в програмному коді вирішив задачу також за 255 кроків

![image](https://user-images.githubusercontent.com/68056715/224507228-20fc8123-ff4b-4f06-82b8-8e11957ad271.png)

Як показало тестування - гра працює коректно із усіма необхідними функціями. А також коректний алгоритм розв’язання проблеми про Ханойські вежі. 
