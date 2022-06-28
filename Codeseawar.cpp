#include <iostream>
#include <windows.h>
#include <time.h>//рандом
#include <stdlib.h>//рандом
#include <conio.h> //работа с шрифтом
#include <stdio.h> //работа с шрифтом
//#include <string.h>
//#include <io.h>
using namespace std;

HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);//указатель на дискриптор стандартного вывода
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };
struct pole { bool korab; bool vistr; bool novistr; };
void clear()
{
	for (int j = 0; j < 42; j++)
	{
		cout << "                                                                                            \n";
	}
}

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(out_handle, (WORD)((background << 4) | text));
}
void FontSize(short symbol_size = 0)//функция для изменения размера шрифта
{
	HANDLE hCon = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	if (hCon != INVALID_HANDLE_VALUE)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;
		cfi.dwFontSize.Y = symbol_size;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = 400;
		wcscpy_s(cfi.FaceName, L"Lucida Console");
		SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
	}
}

//организация окна размером 96 на 42 символа, запрет его расширения, оптимальны подбор размера шрифта для разных расширений
void centrokno() //организация окна размером 96 на 42 символа, запрет его расширения, оптимальны подбор размера шрифта для разных расширений
{
	FontSize(16);
	HWND hWnd; //переменая для дискриптора
	HMENU hm;	//переменная для меню
	hWnd = GetConsoleWindow();//извлекаем дискриптор окна
	hm = GetSystemMenu(hWnd, FALSE);//обращение к меню окна
	RemoveMenu(hm, SC_SIZE, MF_BYCOMMAND | MF_REMOVE);//запрещает сужать и расширять окно
	RemoveMenu(hm, SC_MAXIMIZE, MF_BYCOMMAND | MF_REMOVE);//запрещает разварачивать окно 
	DrawMenuBar(hWnd); //перерисовывает меню окна
	COORD maxWindow = GetLargestConsoleWindowSize(out_handle); // получение максимального размера экранного буфера (окна windows) по х и у
	short font = ((maxWindow.Y) / 2.75); //определение оптимального шрифта (больше окно больше шрифт)
	FontSize(font);//изменение размера шрифта
	maxWindow.Y = 42;//определение оптимального размера окна
	int poz = (maxWindow.X * 16 / 1.6 - maxWindow.Y*2.3*int(font / 1.6)) / 2;//определет позицию для расположения окна по средине
	maxWindow.X = int(maxWindow.Y*2.3);//определение оптимального размера окна 
	SMALL_RECT srctWindow = { 0, 0, maxWindow.X - 1, maxWindow.Y - 1 };// прописываем в srctWindow размеры окна.
	SetConsoleWindowInfo(out_handle, true, &srctWindow);//устанавливает размер окна 
	SetConsoleScreenBufferSize(out_handle, maxWindow);//устанавливает размер буфера равный размеру окна
	SetWindowPos(hWnd, 0, poz, -5, 0, 0, SWP_NOSIZE | SWP_NOZORDER);// перемещает окно посредине экрана (горизонтально)
}
void SetCursor(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(out_handle, c);
}
//прорисовка надписи в начале программы морской бой
void morboi()
{
	char** morbo = new char*[13];
	for (int f = 0; f < 13; f++)
	{
		morbo[f] = new char[56];
	}
	int NotUsed = system("color 17"); //заливка всего цвета консоли на зеленый 2 а буквы на синий 1
	morbo[0] = "                                                   ##";
	morbo[1] = "##   ##   ####   #####    ####   ##  ##   ####   ##  ##";
	morbo[2] = "### ###  ##  ##  ##  ##  ##  ##  ## ##   ##  ##  ##  ##";
	morbo[3] = "## # ##  ##  ##  ######  ##      ####    ##  ##  ## ###";
	morbo[4] = "##   ##  ##  ##  ##      ##  ##  ## ##   ##  ##  ### ##";
	morbo[5] = "##   ##   ####   ##       ####   ##  ##   ####   ##  ##";
	morbo[6] = "";
	morbo[7] = "                                  ## ";
	morbo[8] = "                #####    ####   ##  ##";
	morbo[9] = "                ##      ##  ##  ##  ##";
	morbo[10] = "                #####   ##  ##  ## ###";
	morbo[11] = "                ##  ##  ##  ##  ### ##";
	morbo[12] = "                #####    ####   ##  ##";

	int kx = (96 - 56) / 2, ky = 3;//начальные координаты чтобы текст был по середине

	for (int f = 0; f < 13; f++) //рисуем надпись
	{
		SetCursor(kx, ky + f);
		cout << morbo[f];
		SleepEx(90, TRUE);
	}
	SetCursor(95, 41); //прячем курсор в самый низ

}

//прорисовка надписи в меню "новая игра"
void menunovigra()
{
	char** nadp = new char*[7];
	for (int f = 0; f < 7; f++)
	{
		nadp[f] = new char[53];
	}

	nadp[0] = "                                                    ";
	nadp[1] = "  #  #  ##  ###   ##    ###    #  # #### ###   ##   ";
	nadp[2] = "  #  # #  # #  # #  #  #  #    # ## #    #  # #  #  ";
	nadp[3] = "  #### #  # ###  ####  ####    # ## #    ###  ####  ";
	nadp[4] = "  #  # #  # #  # #  #  #  #    ## # #    #    #  #  ";
	nadp[5] = "  #  #  ##  ###  #  # #   #    #  # #    #    #  #  ";
	nadp[6] = "                                                    ";
	int kx = (96 - 53) / 2, ky = 3 + 14 + 2;//начальные координаты чтобы текст был по середине

	for (int f = 0; f < 7; f++) //рисуем надпись
	{
		SetCursor(kx, ky + f);
		cout << nadp[f];
	}
	SetCursor(95, 41); //прячем курсор в самый низ

}

//прорисовка надписи в меню "помощь"
void menuhelp1()
{
	char** nadp = new char*[7];
	for (int f = 0; f < 7; f++)
	{
		nadp[f] = new char[37];
	}

	nadp[0] = "                                    ";
	nadp[1] = "  ####  ##  #   #  ##  # # #  #     ";
	nadp[2] = "  #  # #  # ## ## #  # # # #  #     ";
	nadp[3] = "  #  # #  # # # # #  # # # #  ###   ";
	nadp[4] = "  #  # #  # #   # #  # # # #  #  #  ";
	nadp[5] = "  #  #  ##  #   #  ##  ###### ###   ";
	nadp[6] = "                            #       ";
	int kx = (96 - 37) / 2, ky = 3 + 14 + 8 + 2;//начальные координаты чтобы текст был по середине

	for (int f = 0; f < 7; f++) //рисуем надпись
	{
		SetCursor(kx, ky + f);
		cout << nadp[f];
	}
	SetCursor(95, 41); //прячем курсор в самый низ

}

//прорисовка надписи в меню "выход"
void menuexit()
{
	char** nadp = new char*[7];
	for (int f = 0; f < 7; f++)
	{
		nadp[f] = new char[32];
	}

	nadp[0] = "                               ";
	nadp[1] = "  ###  #   # #  #  ##    ##    ";
	nadp[2] = "  #  # #   # #  # #  #  #  #   ";
	nadp[3] = "  ###  ### #  ##  #  #  #  #   ";
	nadp[4] = "  #  # #  ## #  # #  # ######  ";
	nadp[5] = "  ###  ### # #  #  ##  #    #  ";
	nadp[6] = "                               ";
	int kx = (96 - 32) / 2, ky = 3 + 14 + 8 + 8 + 2;//начальные координаты чтобы текст был по середине

	for (int f = 0; f < 7; f++) //рисуем надпись
	{
		SetCursor(kx, ky + f);
		cout << nadp[f];
	}
	SetCursor(95, 41); //прячем курсор в самый низ

}
//выделение надписей в меню при выборе
int vibormenu()
{
	int NotUsed = system("color 17");
	int flagmenu = 1;
	int i_input;
	SetColor(White, LightBlue);
	menunovigra();//выделяем вариант новая игра в меню
	do {
		i_input = _getch();//возвращает код нажатой клавиши
		switch (i_input)
		{

		case 72: //вверх
		{
			int NotUsed = system("color 17");//востанавливаем цвет по умолчанию
			flagmenu -= 1;
			SetColor(White, LightBlue);
			if (flagmenu < 1) { flagmenu = 3; }
			if (flagmenu > 3) { flagmenu = 1; }
			if (flagmenu == 1) { menunovigra(); }
			if (flagmenu == 2) { menuhelp1(); }
			if (flagmenu == 3) { menuexit(); }
		} break;
		case 80: //вниз
		{
			int NotUsed = system("color 17");//востанавливаем цвет по умолчанию
			flagmenu += 1;
			SetColor(White, LightBlue);
			if (flagmenu < 1) { flagmenu = 3; }
			if (flagmenu > 3) { flagmenu = 1; }
			if (flagmenu == 1) { menunovigra(); }
			if (flagmenu == 2) { menuhelp1(); }
			if (flagmenu == 3) { menuexit(); }
		} break;
		case 27: // Esc
		{
			flagmenu = 3;
			return flagmenu;
		} break;
		}
	} while (i_input != 13);//enter 
	return flagmenu;
}
//выделение "да" flag = 0 или "нет" flag = 1
void exitmenu(int flag = 0)
{
	int j = 3 + 14 + 2 + 1+2;
	SetCursor((95 - 36) / 2, j++);
	cout << "                                   ";
	if (flag == 0) //выделение да
	{
		SetCursor((95 - 36) / 2, j++);
		cout << "        ";
		SetColor(Black, White);
		cout << " ДА ";
		SetColor(White, Red);
		cout << "          НЕТ          ";
	}
	else //выделение нет
	{
		SetCursor((95 - 36) / 2, j++);
		cout << "         ДА          ";
		SetColor(Black, White);
		cout << " НЕТ ";
		SetColor(White, Red);cout << "         ";
	}
	SetCursor((95 - 36) / 2, j++);
	cout << "                                   ";
	SetCursor(95, 41); //прячем курсор в самый низ
}
int exitpr()
{
	int flagexit = 0;
	int i_input;
	int j = 3 + 14 + 2 + 1;
	SetCursor((95 - 36) / 2, j++);
	SetColor(White, Red);

	cout << "                                   ";
	SetCursor((95 - 36) / 2, j++);
	cout << "  Вы действительно хотите выйти ?  ";
	SetCursor((95 - 36) / 2, j++);
	cout << "                                   ";
	exitmenu(0);
	do {
		i_input = _getch();//возвращает код нажатой клавиши
		switch (i_input)
		{
		case 75: //влево
		{
			flagexit = 0;

			exitmenu(0);
		} break;
		case 77: //вправо
		{
			flagexit = 1;

			exitmenu(1);
		} break;
		case 27: // Esc
		{
			flagexit = 1;
			return flagexit;
		} break;
		}
	} while (i_input != 13);//enter 
	return flagexit;
	SetCursor(95, 41); //прячем курсор в самый низ
}
void help1()
{
	SetColor(White, LightBlue);
	clear();
	SetCursor(1, 1);
	cout << "\t \t \t Правила игры «Морской бой»\n";
	cout << "\t«Морской бой» — игра для двух участников, в которой игроки по очереди называют\nкоординаты на неизвестной им карте соперника.Если у соперника по этим координатам имеется\nкорабль (координаты заняты), то корабль или его часть «топится», а попавший получает право\nсделать ещё один ход.Цель игрока — первым поразить все корабли противника.\n";
	cout << "\n";
	cout << "\t Правила размещения кораблей(флота)\n";
	cout << "\t Игровое поле —  квадрат 10x10 у каждого игрока, на котором размещается флот кораблей.\nГоризонтали пронумерованы  сверху вниз, а вертикали помечаются слева направо буквами латинского\nалфавита от «a» до «j».\n";
	cout << "\t На поле размещаются :\n";
	cout << "1 корабль — ряд из 4 клеток(«четырёхпалубный»)\n";
	cout << "2 корабля — ряд из 3 клеток(«трёхпалубные»)\n";
	cout << "3 корабля — ряд из 2 клеток(«двухпалубные»)\n";
	cout << "4 корабля — 1 клетка(«однопалубные»)\n";
	cout << "\t При размещении корабли не могут касаться друг друга сторонами и углами, а также\nразмещаться буквой «Г», квадратом или зигзагом.\n";
	cout << "\t Рядом со «своим» полем начерчено «чужое» такого же размера, только пустое.Это участок\nморя, где плавают чужие корабли противника.\n";
	cout << "\t При попадании в корабль противника — на чужом поле ставится крестик, при холостом\nвыстреле - точка.Попавший стреляет ещё раз.\n";
	cout << "\n";
	cout << "\t Потопление кораблей противника\n";
	cout << "\t Игрок, выполняя ход, совершает выстрел — выбирая клетку на поле противника и нажимая\nЕNTER.\n";
	cout << "\t Если выстрел пришёлся в клетку, не занятую ни одним кораблём противника, то месте\nклетки появится точка.Право хода переходит к компьютеру.\n";
	cout << "\t Если выстрел пришёлся в клетку, где находится многопалубный корабль (размером больше\nчем 1 клетка), то клетка окрасится в желтый цвета и в этой клетке будет поставлен крестик.\nСтрелявший игрок получает право на ещё один выстрел.\n";
	cout << "\t Если выстрел пришёлся в клетку, где находится однопалубный корабль или последнюю\nнепоражённую клетку многопалубного корабля, то все клетки занимаемые кораблем будут красного\nцвета. Стрелявший игрок получает право на ещё один выстрел.\n";
	cout << "\t Победителем считается тот, кто первым потопит все 10 кораблей противника.\n";
	cout << "\n\t\t\t";
	SetColor(White, Red);
	cout << " НАЖМИТЕ ЛЮБУЮ КЛАВИШУ ЧТОБЫ ВЕРНУТСЯ НАЗАД \n";
	_getch();
	SetCursor(95, 41); //прячем курсор в самый низ
	}
void deck()
{
	char** nadp = new char*[13];
	for (int f = 0; f < 13; f++)
	{
		nadp[f] = new char[47];
		nadp[0] = "    | a | b | c | d | e | f | g | h | i | j | ";
		nadp[1] = "  1 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[2] = "  2 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[3] = "  3 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[4] = "  4 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[5] = "  5 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[6] = "  6 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[7] = "  7 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[8] = "  8 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[9] = "  9 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[10] = " 10 |   |   |   |   |   |   |   |   |   |   | ";
		nadp[11] = " ———————————————————————————————————————————— ";
		nadp[12] = "    |   |   |   |   |   |   |   |   |   |   | ";

	}
	int kx = 1, ky = 3;//начальные координаты доски пользователя
	SetCursor(kx + (48 - 11) / 2, ky - 2);
	cout << "Ваше поле";
	for (int f = 0, k = 0; f < 11; f++) //рисуем доску пользователя 
	{
		SetCursor(kx, ky + k);
		cout << nadp[f];
		k++;
		SetCursor(kx, ky + k);
		cout << nadp[12];
		k++;
		SetCursor(kx, ky + k);
		cout << nadp[11];
		k++;
	}
	kx = 1 + 48; ky = 3; //начальные координаты доски компьютера
	SetCursor(kx + (48 - 16) / 2, ky - 2);
	cout << "Поле компьютера";
	for (int f = 0, k = 0; f < 11; f++) //рисуем доску компьютера
	{
		SetCursor(kx, ky + k);
		cout << nadp[f];
		k++;
		SetCursor(kx, ky + k);
		cout << nadp[12];
		k++;
		SetCursor(kx, ky + k);
		cout << nadp[11];
		k++;
	}

	// подсказка снизу
	{kx = 1; ky = 3 + 33; //начальные координаты для подсказки
	SetCursor(kx, ky);
	SetColor(White, Green);
	SetCursor(kx, ky++); cout << "ВЛЕВО, ВПРАВО, ВВЕРХ и ВНИЗ - влево, вправо, ";	SetColor(White, LightBlue); cout << "    "; SetColor(White, Green); cout << " "; SetColor(White, LightGreen); cout << "  "; SetColor(White, Green); cout << " - целый корабль                          \n";
	SetCursor(kx, ky++);cout << "верх и вниз на одну клетку соответственно;   ";SetColor(White, LightBlue); cout << "    "; SetColor(White, Green);    cout << " "; SetColor(White, Yellow);     cout << "  "; SetColor(White, Green); cout << " - подбитый корабль                       \n";
	SetCursor(kx, ky++);cout << "ПРОБЕЛ - расположить корабль горизонтально   ";SetColor(White, LightBlue); cout << "    "; SetColor(White, Green);    cout << " "; SetColor(White, Red);        cout << "  "; SetColor(White, Green); cout << " - убитый корабль                         \n";
	SetCursor(kx, ky++);cout << "или вертикально;                             ";SetColor(White, LightBlue); cout << "    "; SetColor(White, Green);    cout << " "; SetColor(White, Black);      cout << "  "; SetColor(White, Green); cout << " - выбор клетки                           \n";
	SetCursor(kx, ky++);cout << "ENTER - поставить корабль на выбранное место "; SetColor(White, LightBlue); cout << "    "; SetColor(White, Green);   cout << " "; SetColor(White, Green);      cout << "F1 - помощь; F2 - автоматическая растановка \n";
	SetCursor(kx, ky++);cout << "или сделать выстрел                          "; SetColor(White, LightBlue); cout << "    "; SetColor(White, Green);   cout << " "; SetColor(White, Green);      cout << "кораблей; F3 - новая игра; Esc - выход;     ";
	SetColor(White, Blue);}
	SetCursor(95, 41); //прячем курсор в самый низ
}

 //1- если можно постаить корабль относительно раcположения их на поле "mass" с палубами "palub" начинающийся с клетки "i" "j" расположеный горизонтально b=1 или вертикально b=0
bool prover(pole **mass, int palub,int i,int j,bool b)
{
	int Summ = mass[i][j].korab;
	int  icon, jcon, ina4, jna4;
	if (b == 1) { icon = i + palub + 1, jcon = j + 2, ina4 = i - 1, jna4 = j - 1; }
	else {icon = i + 2, jcon = j + palub + 1, ina4 = i - 1, jna4 = j - 1; }
	for (i =ina4; i < icon;i++)
		{
			for (j = jna4; j < jcon; j++)
			{
				if (j <= 9 && i <= 9 && j >=0  && i >= 0) if (mass[i][j].korab == 1)  Summ++;
				if (i > 11 || j > 11)  Summ++;
			}
		}
		if  (Summ==0) return 1;
	return 0;
}
pole** randkor(pole **mass, int palub)//рандомное расположение корабля
{
	int i, j;
	bool b;
	do {
		b= rand() % 2;//1-горизонтально; 0-вертикально
		if (b == 1) { i = rand() % (10 - palub);	j = rand() % 10; }
		if (b == 0) { i = rand() % 10;	j = rand() % (10 - palub); }
		//проверка на возможность такой установки
	} while (prover(mass, palub, i, j, b) == 0);
	if (b == 1) {
		for (int x = 0; x < palub; x++)
		{
			mass[i + x][j].korab = 1;
		}
	}
	if (b == 0) {
		for (int x = 0; x < palub; x++)
		{
			mass[i][j + x].korab = 1;
		}
	}

	return mass;
}

//заполнение массива кораблями авто
pole** zapkoravto(pole **mass)

{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mass[i][j].korab = 0;
			mass[i][j].vistr = 0;
			mass[i][j].novistr = 0;
		}
	}
	for (int i = 4; i > 0; i--)
	{
		for (int j = 1; j <= 5- i; j++)
		{
     mass = randkor(mass, i);//тип корабля 4-четырех плубный...
		}
	}
	return mass;
}
//прорисовка кораблей у пользователя а=0 и компьютера а=1 
void cvetris(pole **mass, int i, int j, bool a) 
{
	int kx, ky = 3;
	if (a == 0) { kx = 1; }//начальные координаты доски пользователя
	if (a == 1) { kx = 1 + 48; } //начальные координаты доски компьютера
								 
	if ((mass[i][j].korab == 1) && (a == 0))//рисование не подбитых кораблей пользователя
	{
		SetColor(White, Green);
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		cout << "   ";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "   ";

		if (j != 9)if (mass[i][j].korab == mass[i][j + 1].korab)
		{
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 2);
			cout << "———";
		}
		if (i != 9)	if (mass[i][j].korab == mass[i + 1][j].korab)
		{
			SetCursor(kx + 5 + 4 * i + 3, ky + 3 + j * 3);
			cout << "|";
			SetCursor(kx + 5 + 4 * i + 3, ky + 3 + j * 3 + 1);
			cout << "|";
		}
	}
	if (mass[i][j].korab == 1 && a == 1)//рисование не подбитых кораблей компьютера
	{
		SetColor(White, LightBlue);
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		cout << "   ";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "   ";

	}
	//прорисовка поля с мимо 
	if (mass[i][j].vistr == 1 && mass[i][j].korab == 0)//рисование выстрелов в пустую
	{
		SetColor(Black, LightBlue);
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		cout << "\\|/";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "/|\\";
	}
	//прорисовка поля с попаданием
	if (mass[i][j].vistr == 1 && mass[i][j].korab == 1)//рисование выстрелов c попаданием
	{
		SetColor(Black, Yellow);// если ранен 
		int ubil = 0;
		//проверка по горизонтали вправо на полное уничтожение корабля
		{
			if (i + 1 > 9) ubil++; else
				if (mass[i + 1][j].korab == 0) ubil++; else
					if (i + 2 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr) ubil++; }
					else
						if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i + 2][j].korab == 0) ubil++; else
							if (i + 3 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr) ubil++; }
							else
								if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i + 3][j].korab == 0) ubil++; else
									if (i + 4 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].korab == mass[i + 3][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i][j].vistr == mass[i + 3][j].vistr) ubil++; }
									else
										if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].korab == mass[i + 3][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i][j].vistr == mass[i + 3][j].vistr && mass[i + 4][j].korab == 0) ubil++;
		}
		//проверка по горизонтали влево на полное уничтожение корабля
		{
			if (i - 1 < 0) ubil++; else
				if (mass[i - 1][j].korab == 0) ubil++; else
					if (i - 2 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr) ubil++; }
					else
						if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i - 2][j].korab == 0) ubil++; else
							if (i - 3 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr) ubil++; }
							else
								if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i - 3][j].korab == 0) ubil++; else
									if (i - 4 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].korab == mass[i - 3][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i][j].vistr == mass[i - 3][j].vistr) ubil++; }
									else
										if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].korab == mass[i - 3][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i][j].vistr == mass[i - 3][j].vistr && mass[i - 4][j].korab == 0) ubil++;
		}
		//проверка по вертикали вверх на полное уничтожение корабля
		{
			if (j - 1 < 0) ubil++; else
				if (mass[i][j - 1].korab == 0) ubil++; else
					if (j - 2 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].vistr == mass[i][j - 1].vistr) ubil++; }
					else
						if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j - 2].korab == 0) ubil++; else
							if (j - 3 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr) ubil++; }
							else
								if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr && mass[i][j - 3].korab == 0) ubil++; else
									if (j - 4 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab&& mass[i][j].korab == mass[i][j - 3].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr&& mass[i][j].vistr == mass[i][j - 3].vistr) ubil++; }
									else
										if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab&& mass[i][j].korab == mass[i][j - 3].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr&& mass[i][j].vistr == mass[i][j - 3].vistr && mass[i][j - 4].korab == 0) ubil++;
		}
		//проверка по вертикали вниз на полное уничтожение корабля
		{
			if (j + 1 > 9) ubil++; else
				if (mass[i][j + 1].korab == 0) ubil++; else
					if (j + 2 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].vistr == mass[i][j + 1].vistr) ubil++; }
					else
						if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j + 2].korab == 0) ubil++; else
							if (j + 3 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr) ubil++; }
							else
								if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr && mass[i][j + 3].korab == 0) ubil++; else
									if (j + 4 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab&& mass[i][j].korab == mass[i][j + 3].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr&& mass[i][j].vistr == mass[i][j + 3].vistr) ubil++; }
									else
										if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab&& mass[i][j].korab == mass[i][j + 3].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr&& mass[i][j].vistr == mass[i][j + 3].vistr && mass[i][j + 4].korab == 0) ubil++;
		}
		if (ubil == 4) SetColor(Black, LightRed); //если проверка прошла по всем 4 направлениям то убил
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		cout << "\\|/";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "/|\\";
		if (j != 9)if (mass[i][j].korab == mass[i][j + 1].korab &&mass[i][j].vistr == mass[i][j + 1].vistr)
		{
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 2);
			cout << "———";
		}
		if (i != 9)	if (mass[i][j].korab == mass[i + 1][j].korab&&mass[i][j].vistr == mass[i + 1][j].vistr)
		{
			SetCursor(kx + 5 + 4 * i + 3, ky + 3 + j * 3);
			cout << "|";
			SetCursor(kx + 5 + 4 * i + 3, ky + 3 + j * 3 + 1);
			cout << "|";
		}
	}
	//прорисовка пустого поля
	if (mass[i][j].vistr == 0 && mass[i][j].korab == 0)
	{
		SetColor(White, LightBlue);
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		cout << "   ";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "   ";
	}
}
//рисование кораблей на доске у пользователя а=0 и компьютера а=1 
void riskor(pole **mass, bool a)//рисование кораблей на доске
{

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cvetris(mass, i, j, a);
		}
	}
	SetCursor(95, 41); //прячем курсор в самый низ
}
pole** zapkornoavto(pole **mass);
//задание расположения корабля на поле
pole** norandkor(pole **mass, int palub, bool &avto)
{
	avto = 0;
	bool b=0;//1-горизонтально; 0-вертикально
	int kx = 1+5, ky = 3+3;//начальные координаты доски пользователя
	char** nadp = new char*[3];
	for (int f = 0; f < 7; f++)
	{
		nadp[f] = new char[5];
	}

	nadp[0] = "   |";
	nadp[1] = "———";
	nadp[2] = "   ";
	if (prover(mass, palub, 0, 0, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
	if (b==1)
	for (int i = 0; i < palub; i++)
	{
		SetCursor(kx+4*i, ky);
	if (i== 0&& palub==1)	cout << nadp[2]; 
	else if (i != palub - 1) cout << nadp[0];else cout << nadp[2];
		SetCursor(kx+4*i, ky + 1);
		if (i == 0 && palub == 1)	cout << nadp[2];
		else if (i != palub - 1) cout << nadp[0]; else cout << nadp[2];
	}
	if (b == 0)
		for (int j = 0; j < palub; j++)
		{
			SetCursor(kx, ky + 3 * j);
			cout << nadp[2];
			SetCursor(kx, ky+1+3*j);
			cout << nadp[2];
			if (palub != 1 && j != palub - 1)
			{
				SetCursor(kx, ky + 2 + 3 * j);
				cout << nadp[1];
			}
		}
	
	SetCursor(95, 41); //прячем курсор в самый низ	
	int flagmenu = 1;
	int i_input;
		int x=0, y=0;
	do {
		if (flagmenu == 2) help1();
		i_input = _getch();
		switch (i_input)
		{
		case 72: //вверх
		{
			
			SetColor(White, LightBlue);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			riskor(mass, 0);
			y = y--;
			if (y < 0) y = 0; //когда уперлись в стенку сверху
			if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
			if (b == 1)
				for (int i = x; i < palub+x; i++)
				{
					SetCursor(kx + 4 * i, ky+y*3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1+y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub+y; j++)
				{
					SetCursor(kx+x*4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx+x*4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub+y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 80: //вниз
		{
			
			SetColor(White, LightBlue);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			riskor(mass, 0);
		y = y++;
		if (b==0 && y> 9-palub+1) y = 9 - palub+1;//когда уперлись в стенку снизу
		if (y > 9) y = 9;
		if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
		if (b == 1)
			for (int i = x; i < palub + x; i++)
			{
				SetCursor(kx + 4 * i, ky + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
				SetCursor(kx + 4 * i, ky + 1 + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
			}
		if (b == 0)
			for (int j = y; j < palub + y; j++)
			{
				SetCursor(kx + x * 4, ky + 3 * j);
				cout << nadp[2];
				SetCursor(kx + x * 4, ky + 1 + 3 * j);
				cout << nadp[2];
				if (palub != 1 && j != palub + y - 1)
				{
					SetCursor(kx + x * 4, ky + 2 + 3 * j);
					cout << nadp[1];
				}
			}
		SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 75: //влево
		{
			
			SetColor(White, LightBlue);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			riskor(mass, 0);
		x = x--;
if (x < 0) x = 0;//упираемся влево 
		if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
		if (b == 1)
			for (int i = x; i < palub + x; i++)
			{
				SetCursor(kx + 4 * i, ky + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
				SetCursor(kx + 4 * i, ky + 1 + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
			}
		if (b == 0)
			for (int j = y; j < palub + y; j++)
			{
				SetCursor(kx + x * 4, ky + 3 * j);
				cout << nadp[2];
				SetCursor(kx + x * 4, ky + 1 + 3 * j);
				cout << nadp[2];
				if (palub != 1 && j != palub + y - 1)
				{
					SetCursor(kx + x * 4, ky + 2 + 3 * j);
					cout << nadp[1];
				}
			}
		SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 77: //вправо
		{
						
			SetColor(White, LightBlue);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			riskor(mass, 0);
		x = x++;
        if (b==1 && x > 9-palub+1) x = 9 - palub+1;//упираемся вправо
		if (x > 9) x = 9;
		if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
		
		if (b == 1)
			for (int i = x; i < palub + x; i++)
			{
				SetCursor(kx + 4 * i, ky + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
				SetCursor(kx + 4 * i, ky + 1 + y * 3);
				if (i == x && palub + x == 1)	cout << nadp[2];
				else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
			}
		if (b == 0)
			for (int j = y; j < palub + y; j++)
			{
				SetCursor(kx + x * 4, ky + 3 * j);
				cout << nadp[2];
				SetCursor(kx + x * 4, ky + 1 + 3 * j);
				cout << nadp[2];
				if (palub != 1 && j != palub + y - 1)
				{
					SetCursor(kx + x * 4, ky + 2 + 3 * j);
					cout << nadp[1];
				}
			}
		SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 32: //пробел
		{
			
			SetColor(White, LightBlue);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			if (b == 0) b = 1; else b = 0;
			riskor(mass, 0);
			if (b == 1 && x > 9 - palub + 1) x = 9 - palub + 1;//упираемся вправо
			if (x > 9) x = 9;
			if (b == 0 && y> 9 - palub + 1) y = 9 - palub + 1;//когда уперлись в стенку снизу
			if (y > 9) y = 9;
			if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			SetCursor(95, 41); //прячем курсор в самый низ	

		} break;
		case 59: // F1
		{
			help1();
						SetColor(White, LightBlue);
			clear();
			deck();
			riskor(mass, 0);
			if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
			if (b == 1)
				for (int i = x; i < palub + x; i++)
				{
					SetCursor(kx + 4 * i, ky + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
					SetCursor(kx + 4 * i, ky + 1 + y * 3);
					if (i == x && palub + x == 1)	cout << nadp[2];
					else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
				}
			if (b == 0)
				for (int j = y; j < palub + y; j++)
				{
					SetCursor(kx + x * 4, ky + 3 * j);
					cout << nadp[2];
					SetCursor(kx + x * 4, ky + 1 + 3 * j);
					cout << nadp[2];
					if (palub != 1 && j != palub + y - 1)
					{
						SetCursor(kx + x * 4, ky + 2 + 3 * j);
						cout << nadp[1];
					}
				}
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 60: // F2 авто растановка
		{
			SetColor(White, LightBlue);
			deck();
			mass = zapkoravto(mass);
			avto = 1; return mass;
		} break;
		case 61: // F3 начать заново
		{
			SetColor(White, LightBlue);
			clear();
			deck();//рисование поля с двумя досками и подсказками снизу без короблей
			mass = zapkornoavto(mass);//заполнение доски пользователем  
			avto = 1; return mass;
		} break;
		case 27: // Esc
		{
			int flagexit = exitpr(); //если выбрали выход 0-подтверждение выхода;  1-отмена выхода и продолжение выбора 
			if (flagexit == 0) { exit(0); }
			else
			{
				SetColor(White, LightBlue);
				clear();
				deck();
				riskor(mass, 0);
				if (prover(mass, palub, x, y, b) == 1) SetColor(White, Green); else SetColor(White, LightRed);
				if (b == 1)
					for (int i = x; i < palub + x; i++)
					{
						SetCursor(kx + 4 * i, ky + y * 3);
						if (i == x && palub + x == 1)	cout << nadp[2];
						else if (i != palub + x - 1) cout << nadp[0];else cout << nadp[2];
						SetCursor(kx + 4 * i, ky + 1 + y * 3);
						if (i == x && palub + x == 1)	cout << nadp[2];
						else if (i != palub + x - 1) cout << nadp[0]; else cout << nadp[2];
					}
				if (b == 0)
					for (int j = y; j < palub + y; j++)
					{
						SetCursor(kx + x * 4, ky + 3 * j);
						cout << nadp[2];
						SetCursor(kx + x * 4, ky + 1 + 3 * j);
						cout << nadp[2];
						if (palub != 1 && j != palub + y - 1)
						{
							SetCursor(kx + x * 4, ky + 2 + 3 * j);
							cout << nadp[1];
						}
					}
				SetCursor(95, 41); //прячем курсор в самый низ	
			}
		} break;

		}
} while (i_input != 13 || prover(mass, palub, x, y, b) == 0);//enter и можно туда установить корабль


	if (b == 1) {
	 for (int i = 0; i < palub; i++)
		{
			mass[x + i][y].korab = 1;
		}
	}
	if (b == 0) {
		for (int j = 0; j < palub; j++)
		{
			mass[x][y + j].korab = 1;
		}
	}

	return mass;
}
//заполнение массива кораблями вручную
pole** zapkornoavto(pole **mass)
{
	bool avto = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mass[i][j].korab = 0;
			mass[i][j].vistr = 0;
			mass[i][j].novistr = 0;
		}
	}
	for (int i = 4; i > 0; i--)
	{
		for (int j = 1; j <= 5 - i; j++)
		{
			mass = norandkor(mass, i,avto);//i-тип корабля 4-четырех плубный...
			if (avto == 1) { return  mass; }
		}
	}
	return mass;
}

pole **vistr(pole **mass, bool &a, int &i_pop, int &j_pop)
{

	int kx = 1, ky = 3, i, j;
	for (int l = 0; l < 10; l++)
	{
		i = rand() % 10;
		j = rand() % 10;
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
		SetColor(White, Black);
		cout << "\\|/";
		SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
		cout << "/|\\";
		Sleep(l*l);
		riskor(mass, 0);
	}

	int prom = 0,tupik = 0;
		do
	{
		if (i_pop == 11) { i = rand() % 10; j = rand() % 10; } //если прошлое было мимо или убил
		else //если прошлое было попал
		{
			int ran= rand() % 4;
			if (ran == 0) { i = i_pop + 1;j = j_pop; }
			if (ran == 1) { i = i_pop -1;j = j_pop; }
			if (ran == 2) { i = i_pop;j = j_pop + 1; }
			if (ran == 3) { i = i_pop;j = j_pop-1;}
			tupik++;
			if (tupik > 10)
			{
				if (prom >= 3) { i = i_pop + 1;j = j_pop;prom++; }
				if (prom == 2) { i = i_pop - 1;j = j_pop;prom++; }
				if (prom == 1) { i = i_pop;j = j_pop + 1; prom++; }
				if (prom == 0) { i = i_pop;j = j_pop - 1;prom++; }
			}
			if (i < 0 || j < 0 || i >9 || j >9) { i = i_pop;j = j_pop; }
			if (prom > 4) {
				for (int i = i_pop - 1;i < i_pop + 2;i++) 
			{
					for (int j = j_pop - 1;j < j_pop + 2;j++)
						if (i >= 0 && j >= 0 && i <= 9 && j <= 9 && (i != i_pop || j != j_pop))
							if (mass[i_pop][j_pop].vistr == mass[i][j].vistr &&mass[i_pop][j_pop].vistr == 1 && mass[i][j].korab == mass[i_pop][j_pop].korab)
				{
					if (i_pop == i && j > j_pop) if (mass[i][j + 1].vistr == 1) { j_pop = j_pop + 2;i = i_pop + 2; j = j_pop + 2; }
					else {j_pop = j_pop + 1;i = i_pop + 2; j = j_pop + 2;}
					if (i_pop == i && j < j_pop) if (mass[i][j - 1].vistr == 1) { j_pop = j_pop - 2;i = i_pop + 2; j = j_pop + 2; }
					else { j_pop = j_pop - 1;i = i_pop + 2; j = j_pop + 2; }
					if (j_pop == j && i > i_pop) if (mass[i + 1][j].vistr == 1) { i_pop = i_pop + 2;i = i_pop + 2; j = j_pop + 2; }
					else { i_pop = i_pop + 1;i = i_pop + 2; j = j_pop + 2; }
					if (j_pop == j && i < i_pop) if (mass[i - 1][j].vistr == 1) { i_pop = i_pop - 2;i = i_pop + 2; j = j_pop + 2; }
					else { i_pop = i_pop - 1;i = i_pop + 2; j = j_pop + 2; }
					prom = 0; 
				}
			}
		}
		}
	} //конечный выстрел
while (mass[i][j].vistr == 1 || mass[i][j].novistr == 1);
	SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
	SetColor(White, Black);
	cout << "\\|/";
	SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
	cout << "/|\\";
	SetCursor(95, 41); //прячем курсор в самый низ	
	mass[i][j].vistr = 1;


	if (mass[i][j].korab == 1)
	{
		a = 0;
		// запрещение угловых выстрелов от места попадания
		if (i - 1 >= 0 && j - 1 >= 0) mass[i - 1][j - 1].novistr = 1;
		if (j + 1 <= 9 && i - 1 >= 0) mass[i - 1][j + 1].novistr = 1;
		if (i + 1 <= 9 && j - 1 >= 0) mass[i + 1][j - 1].novistr = 1;
		if (i + 1 <= 9 && j + 1 <= 9) mass[i + 1][j + 1].novistr = 1;
		//запрещение выстрелов вокруг уже убитого корабля

		int ubil = 0;		
		int palub = 0, b = 0;//сколько палуб и как расположен корабль определяется при поиске
			//проверка по горизонтали вправо на полное уничтожение корабля
		{
			if (i + 1 > 9) { ubil++;palub = 1;b = 1; }
			else
				if (mass[i + 1][j].korab == 0) { ubil++;palub = 1;b = 1; }
				else
					if (i + 2 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr) { ubil++;palub = 2;b = 1; } }
					else
						if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i + 2][j].korab == 0) { ubil++;palub = 2;b = 1; }
						else
							if (i + 3 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr) { ubil++;palub = 3;b = 1; } }
							else
								if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i + 3][j].korab == 0) { ubil++;palub = 3;b = 1; }
								else
									if (i + 4 > 9) { if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].korab == mass[i + 3][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i][j].vistr == mass[i + 3][j].vistr) { ubil++;palub = 4;b = 1; } }
									else
										if (mass[i][j].korab == mass[i + 1][j].korab && mass[i][j].korab == mass[i + 2][j].korab && mass[i][j].korab == mass[i + 3][j].korab && mass[i][j].vistr == mass[i + 1][j].vistr && mass[i][j].vistr == mass[i + 2][j].vistr && mass[i][j].vistr == mass[i + 3][j].vistr && mass[i + 4][j].korab == 0) { ubil++;palub = 4;b = 1; }
		}
		//проверка по горизонтали влево на полное уничтожение корабля
		{
			if (i - 1 < 0) { ubil++;palub = 1;b = 1; }
			else
				if (mass[i - 1][j].korab == 0) { ubil++;palub = 1;b = 1; }
				else
					if (i - 2 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr) { ubil++;palub = 2;b = 1; } }
					else
						if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i - 2][j].korab == 0) { ubil++;palub = 2;b = 1; }
						else
							if (i - 3 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr) { ubil++;palub = 3;b = 1; } }
							else
								if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i - 3][j].korab == 0) { ubil++;palub = 3;b = 1; }
								else
									if (i - 4 < 0) { if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].korab == mass[i - 3][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i][j].vistr == mass[i - 3][j].vistr) { ubil++;palub = 4;b = 1; } }
									else
										if (mass[i][j].korab == mass[i - 1][j].korab && mass[i][j].korab == mass[i - 2][j].korab && mass[i][j].korab == mass[i - 3][j].korab && mass[i][j].vistr == mass[i - 1][j].vistr && mass[i][j].vistr == mass[i - 2][j].vistr && mass[i][j].vistr == mass[i - 3][j].vistr && mass[i - 4][j].korab == 0) { ubil++;palub = 4;b = 1; }
		}
		//проверка по вертикали вверх на полное уничтожение корабля
		{
			if (j - 1 < 0) { ubil++;palub = 1;b = 0; }
			else
				if (mass[i][j - 1].korab == 0) { ubil++;palub = 1;b = 0; }
				else
					if (j - 2 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].vistr == mass[i][j - 1].vistr) { ubil++;palub = 2;b = 0; } }
					else
						if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j - 2].korab == 0) { ubil++;palub = 2;b = 0; }
						else
							if (j - 3 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr) { ubil++;palub = 3;b = 0; } }
							else
								if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr && mass[i][j - 3].korab == 0) { ubil++;palub = 3;b = 0; }
								else
									if (j - 4 < 0) { if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab&& mass[i][j].korab == mass[i][j - 3].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr&& mass[i][j].vistr == mass[i][j - 3].vistr) { ubil++;palub = 4;b = 0; } }
									else
										if (mass[i][j].korab == mass[i][j - 1].korab && mass[i][j].korab == mass[i][j - 2].korab&& mass[i][j].korab == mass[i][j - 3].korab && mass[i][j].vistr == mass[i][j - 1].vistr && mass[i][j].vistr == mass[i][j - 2].vistr&& mass[i][j].vistr == mass[i][j - 3].vistr && mass[i][j - 4].korab == 0) { ubil++;palub = 4;b = 0; }
		}
		//проверка по вертикали вниз на полное уничтожение корабля
		{
			if (j + 1 > 9) { ubil++;palub = 1;b = 0; }
			else
				if (mass[i][j + 1].korab == 0) { ubil++;palub = 1;b = 0; }
				else
					if (j + 2 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].vistr == mass[i][j + 1].vistr) { ubil++;palub = 2;b = 0; } }
					else
						if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j + 2].korab == 0) { ubil++;palub = 2;b = 0; }
						else
							if (j + 3 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr) { ubil++;palub = 3;b = 0; } }
							else
								if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr && mass[i][j + 3].korab == 0) { ubil++;palub = 3;b = 0; }
								else
									if (j + 4 > 9) { if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab&& mass[i][j].korab == mass[i][j + 3].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr&& mass[i][j].vistr == mass[i][j + 3].vistr) { ubil++;palub = 4;b = 0; } }
									else
										if (mass[i][j].korab == mass[i][j + 1].korab && mass[i][j].korab == mass[i][j + 2].korab&& mass[i][j].korab == mass[i][j + 3].korab && mass[i][j].vistr == mass[i][j + 1].vistr && mass[i][j].vistr == mass[i][j + 2].vistr&& mass[i][j].vistr == mass[i][j + 3].vistr && mass[i][j + 4].korab == 0) { ubil++;palub = 4;b = 0; }
		}
		int  icon, jcon, ina4, jna4;
		if (b == 1) { icon = i + palub + 1, jcon = j + 2, ina4 = i - 1, jna4 = j - 1; }
		else { icon = i + 2, jcon = j + palub + 1, ina4 = i - 1, jna4 = j - 1; }
		if (ubil == 4) {
			for (int k = ina4; k < icon;k++)
			{
				for (int l = jna4; l < jcon; l++)
				{
					if (k <= 9 && l <= 9 && k >= 0 && l >= 0)
					{
						mass[k][l].novistr = 1;
					}
				}
			}
			i_pop = 11;j_pop = 11;//отключение ИИ если убил
		}
		if (ubil < 4)
		{
			Sleep(500);
			riskor(mass, 0);
			SetCursor(95, 41);
			i_pop = i;j_pop = j;
		 mass = vistr(mass, a, i_pop, j_pop);
		}
	}
	else a = 1;
	Sleep(500);
	riskor(mass, 0);
	SetCursor(95, 41); //прячем курсор в самый низ
	return mass;
}
int viborkletki(pole **mass, int &i, int &j, pole **mass1 )
{
	int kx = 1+48, ky = 3;
	SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
	SetColor(White, Black);
	cout << "\\|/";
	SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
	cout << "/|\\";
	SetCursor(95, 41); //прячем курсор в самый низ	
	int flagmenu = 1;
	int i_input;
	while (_kbhit())//очистка потока старого
	{
		i_input = _getch();
	}

	do {
		i_input = _getch();//возвращает код нажатой клавиши
		
		switch (i_input)
		{

		case 72: //вверх
		{
			riskor(mass, 1);
			j = j--;
			if (j < 0) j = 0;
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
			SetColor(White, Black);
			cout << "\\|/";
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
			cout << "/|\\";
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 80: //вниз
		{riskor(mass, 1);
			j = j++;
			if (j > 9) j = 9;
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
			SetColor(White, Black);
			cout << "\\|/";
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
			cout << "/|\\";
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 75: //влево
		{riskor(mass, 1);
			i = i--;
			if (i < 0) i = 0;
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
			SetColor(White, Black);
			cout << "\\|/";
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
			cout << "/|\\";
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 77: //вправо
		{riskor(mass, 1);
			i = i++;
			if (i > 9) i = 9;
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
			SetColor(White, Black);
			cout << "\\|/";
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
			cout << "/|\\";
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;
		case 59: // F1
		{
			help1();
			SetColor(White, LightBlue);
			clear();
			deck();
			riskor(mass1, 0);
			riskor(mass, 1);
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3);
			SetColor(White, Black);
			cout << "\\|/";
			SetCursor(kx + 5 + 4 * i, ky + 3 + j * 3 + 1);
			cout << "/|\\";
			SetCursor(95, 41); //прячем курсор в самый низ	
		} break;

		case 61: // F3
		{
		SetColor(White, LightBlue);
		clear();
		deck();//рисование поля с двумя досками и подсказками снизу без короблей
		mass = zapkoravto(mass);//заполнение доски компьютера случайным образом 
		mass1 = zapkornoavto(mass1);//заполнение доски пользователем  
		riskor(mass1, 0);
		riskor(mass, 1); return 2;
		}
		break;
		case 27: // Esc
		{
			flagmenu = 3;
			return flagmenu;
		} break;
		}
		Sleep(50);
	} while (i_input != 13);//enter 
	riskor(mass, 1);
	return flagmenu;
}
int gameend(pole **mass)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (mass[i][j].korab == 1 && mass[i][j].vistr == 0) { return 0; }
		}
	}
	return 1;
}
int exitigra(bool a)
{
	int flagexit = 0;
	int i_input;
	int j = 3 + 14 + 2 + 1;
	SetCursor((95 - 36) / 2, j++);
	if (a == 0) //проиграл пользователь
	{
		SetColor(White, Red);
	cout << "          Вы проиграли             ";	
	} else
	{
		SetColor(White, Green);
	cout << "          Вы выграли !!!           ";
	}
	SetCursor((95 - 36) / 2, j++);
	cout << "      Вы хотите сыграть еще?       ";
	SetCursor((95 - 36) / 2, j++);
	cout << "                                   ";
	SetColor(White, Red);
	exitmenu(0);
	do {
		i_input = _getch();//возвращает код нажатой клавиши
		switch (i_input)
		{
		case 75: //влево
		{
			flagexit = 0;

			exitmenu(0);
		} break;
		case 77: //вправо
		{
			flagexit = 1;

			exitmenu(1);
		} break;
		case 27: // Esc
		{
			flagexit = 1;
			return flagexit;
		} break;
		}
	} while (i_input != 13);//enter 
	return flagexit;
	SetCursor(95, 41); //прячем курсор в самый низ
}
int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	//for (size_t i = 0; ; i++)
	//{
	//int i_input=_getch();
	//cout << i_input << ";   ";
	//_getch();
	//}

	
	centrokno();/*организация окна размером 96 на 42 символа, оптимальный подбор размера шрифта для разных расширений экрана */
	int flagmenu = 0;//переход в началькую страницу игры
	do {
		if (flagmenu == 0)//начальная страница 
		{
			morboi();//выход надписи морской бой
			menunovigra();//меню надпись новая игра 
			menuhelp1();//меню надпись помощь
			menuexit();//меню надпись  выход 
			flagmenu = vibormenu();//реализация выбора одного из пунктов меню 1-новая игра; 2-помощь; 3 - выход
		}
		if (flagmenu == 3)//если в меню выбрали выход
		{
			int flagexit = exitpr(); //если выбрали выход 0-подтверждение выхода;  1-отмена выхода и продолжение выбора 
			if (flagexit == 0) { return(0); }
			else flagmenu = vibormenu();
		}
		if (flagmenu == 2)//если в меню выбрали помощь
		{
			help1();
			clear();
			flagmenu = 0;
		}
	} while (flagmenu != 1);
	pole **korpol = new pole*[10];//создание массивы доски пользователя 10 на 10
	for (int i = 0; i < 10; i++)
	{
		korpol[i] = new pole[10];
	}

	pole **korpc = new pole*[10];//создание массивы доски компьютера 10 на 10
	for (int i = 0; i < 10; i++)
	{
		korpc[i] = new pole[10];
	}
	do {	//если в меню выбрали новая игра
	SetColor(White, LightBlue);
	clear();
	deck();//рисование поля с двумя досками и подсказками снизу без короблей
	korpc=zapkoravto(korpc);//заполнение доски компьютера случайным образом 
	korpol=zapkornoavto(korpol);//заполнение доски пользователем  
	riskor(korpc,1);//рисование кораблей на доске 0 - для пользователя; 1-для компьютера
	riskor(korpol, 0);
	bool move = 1;//move=0 ход компьютера, move=1 ход пользователя
	int i = 0, j = 0;//начальные координаты выбора пользователя
	int i_pop = 11, j_pop = 11;// координаты при попадании компьютера //часть реализации ИИ
	do {
	if (move == 1)//ход пользователя
	{
		int nov = viborkletki(korpc, i, j, korpol);
		if ( nov== 3)//если при выборе клетки нажали ескейп
		{
			int flagexit = exitpr(); //если выбрали выход 0-подтверждение выхода;  1-отмена выхода и продолжение выбора 
			if (flagexit == 0) { return(0); }
			else
			{
				SetColor(White, LightBlue);
				clear();
				deck();
				riskor(korpol, 0);
				riskor(korpc, 1);
			}
		}
		else move = 0;
		if (nov == 2) {
			nov = viborkletki(korpc, i, j, korpol); i = 0; j = 0;i_pop = 11; j_pop = 11;move == 1;
		}
		if (move == 0)//все еще ход пользователя
		{
			korpc[i][j].vistr = 1;
			if (korpc[i][j].vistr == korpc[i][j].korab) 
			{
				move = 1; 
				int j = 3 + 14;
				SetCursor(65, j++);
				SetColor(White, Green);
				cout << "             ";
				SetCursor(65, j++);
				cout << "  ПОПАЛ !!!  ";
				SetCursor(65, j++);
				cout << "             ";
				Sleep(600);
				j = 3 + 14;
				SetCursor(65, j++);
				SetColor(White, LightBlue);
				cout << "——————————————";
				SetCursor(65, j++);
				cout << "|   |   |   |";
				SetCursor(65, j++);
				cout << "|   |   |   |";
				riskor(korpc, 1);
			}
			else {
				move = 0;
				int j = 3 + 14;
				SetCursor(65, j++);
				SetColor(White, Red);
				cout << "              ";
				SetCursor(65, j++);
				cout << "   МИМО !!!   ";
				SetCursor(65, j++);
				cout << "              ";
				Sleep(600);
					j = 3 + 14;
				SetCursor(65, j++);
				SetColor(White, LightBlue);
			    cout << "——————————————";
				SetCursor(65, j++);
				cout << "|   |   |   |";
				SetCursor(65, j++);
				cout << "|   |   |   |";
				riskor(korpc, 1);
			}
			riskor(korpc, 1);
		}
	}
	if (move == 0)//ход компьютера
	{
		korpol = vistr(korpol, move, i_pop, j_pop);//выстрел компьютера рандом, попал move=0 мимо move=1
		riskor(korpol, 0);
	}
	} while (gameend(korpc) != 1 && gameend(korpol) != 1);// еще есть корабли и у игрока и у компьютера
		
	if (gameend(korpol)==1) flagmenu=exitigra(false);
	else flagmenu = exitigra(true);
} while (flagmenu != 1);
}