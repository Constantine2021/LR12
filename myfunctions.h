#pragma once

//====================================================================
//   заголовочный файл создан студентом группы №6 Павловым Константином
//====================================================================

//---------------------------------------------------------------------------
//вывод целого числа n в двоичном виде, bi - места пробелов
//---------------------------------------------------------------------------
void dec2bin(int n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(short n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(char n, int b1 = -1, int b2 = -1, int b3 = -1);
void dec2bin(long long n, int b1 = -1, int b2 = -1, int b3 = -1,
	int b4 = -1, int b5 = -1, int b6 = -1, int b7 = -1);
//---------------------------------------------------------------------------
//вывод nx элементов массива X в nr строк, setw(nw)
//если nr=0, вывод в одну строку без endl
//asChar задает вывод char: true - вывод символов, false - вывод чисел
//nf - параметр манипулятора setprecision
//---------------------------------------------------------------------------
void myout(int *X,const int nx, int nr = 1, int nw = 4);
void myout(short *X, const int nx, int nr = 1, int nw = 4);
void myout(char *X, const int nx, int nr = 1, int nw = 1, bool asChar = true);
void myout(double *X, const int nx, int nr = 1, int nw = 9, int nf = 3);
//---------------------------------------------------------------------------
//присваивает nx элементам массива X случайные числа из диапазона от n0 до n1
//---------------------------------------------------------------------------
void myrnd(int *X, const int nx, int n0, int n1);
void myrnd(short *X, const int nx, int n0, int n1);
void myrnd(char *X, const int nx, char c0, char c1);
//диапазон от n0/10^nf до n1/10^nf
void myrnd(double *X, const int nx, double n0, double n1, int nf = 2);
//---------------------------------------------------------------------------
//myord сортирует nx элементов массива X 
//inc: true - сортировка по возрастанию, false - сортировка по убыванию
//meth: 't' - метод перестановок, 's' - метод выбора, 'i' - метод вставок
//---------------------------------------------------------------------------
int mytransp(int *X, int nx, bool inc = true);
void mysel(int *X, int nx, bool inc = true);
void myins(int *X, int nx, bool inc = true, int newval = 0);
void myord(int *X, int nx, bool inc = true, char meth = 't');
//перегрузка для double-массива  
int mytransp(double *X, int nx, bool inc = true);
void mysel(double *X, int nx, bool inc = true);
void myins(double *X, int nx, bool inc = true, double newval = 0);
void myord(double *X, int nx, bool inc = true, char meth = 't');
//==================================================================
int mylen(const char*s);
char* mycpy(char*s, const char*t);
char* mycpy(char*s, const char*t, int n, bool addNull= false);
char* mycat(char*s, const char*t);
char* mycat(char*s, const char*t, int n, bool addNull = true);
bool mycmp(const char*s, const char*t);
bool mycmp(const char*s, const char*t, int n);
char* mystr(const char*s, const char*t);
char* mystr(const char*s, const char*t, int n);
void mydel(char*s, int nstart, int ndel);
void myins(char*s, int nstart, const char*t);
void myinput(char*s, char sep = '\n');
int myinput(char*s, char*fname, char sep = '\n', bool toConsol = false);
int  myinput(char*S[], const char*fname, bool toConsol = false);


//============================================================================
int myspn(const char*s, const char*sep);
int mycspn(const char*s, const char*sep);
int wordcount(const char*s, const char*sep);
int str2num(int*x, const char*s, const char*sep = " ");
int str2num(double*x, const char*s, const char*sep = " ");
int strcount(const char*fname);//Функция возвращает количеств острок в файде fname
//=================================================================
int * mymax(int*X, int nx);
int * mymin(int*X, int nx);
void mysrt(int*X, int nx, bool inc = true, int*P[] = NULL);
//==============================
char**mymin(char*X[], int nx);
char**mymax(char*X[], int nx);
void  mysrt(char**X, int nx, bool inc = true, char*P[] = NULL);


//перечисление 16 цветов консоли
enum colors {
	black, blue, green, cyan,
	red, magenta, brown, lightgray,
	darkgray, lightblue, lightgreen, lightcyan,
	lightred, lightmagenta, yellow, white
};
void getxy(int&x, int&y);				//возвращает столбец и строку курсора консоли
void setxy(int x, int y);				//задает     столбец и строку курсора консоли
void getcolor(int&text, int&background);	//возвращает текущий цвет текста и текущий цвет фона консоли
void setcolor(int text, int background);	//задает     текущий цвет текста и текущий цвет фона консоли


