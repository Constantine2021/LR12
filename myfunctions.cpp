#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include "myfunctions.h"
#include <windows.h>
using namespace std;

//=== dec2bin ====================================================
void dec2bin(int n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(short n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(char n, int b1, int b2, int b3) {
	const int nd = sizeof(n) * 8; unsigned m = n;
	for (int i = nd - 1; i >= 0; i--)
		cout << (m&(1 << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 ? " " : "");
}
void dec2bin(long long n, int b1, int b2, int b3, int b4, int b5, int b6, int b7) {
	const int nd = sizeof(n) * 8; unsigned long long m = n, k = 1;
	for (int i = nd - 1; i >= 0; i--) {
		cout << (m&(k << i) ? 1 : 0) << (i == b1 || i == b2 || i == b3 || i == b4 || i == b5 || i == b6 || i == b7 ? " " : "");
	}
}
//=== myout ====================================================
void myout(int *X, int nx, int nr, int nw) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << setw(nw) << X[i]; if ((i + 1) % nc == 0) cout << endl;
	}
}
void myout(short *X, int nx, int nr, int nw) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << setw(nw) << X[i]; if ((i + 1) % nc == 0) cout << endl;
	}
}
void myout(char *X, int nx, int nr, int nw, bool asChar) {
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	if (asChar) for (int i = 0; i<nx; i++) cout << setw(nw) << X[i] << ((i + 1) % nc ? "" : "\n");
	else       for (int i = 0; i<nx; i++) cout << setw(nw) << X[i] + 0 << ((i + 1) % nc ? "" : "\n");
}
void myout(double *X, int nx, int nr, int nw, int nf) {
	ios init(NULL); init.copyfmt(cout); //сохран€ем текущий формат cout
	if (nr<0) nr = 1;			//вывод в одну строку при nr<0
	int nc = nr ? nx / nr : nx + 1;	//nc=количество столбцов, при nr=0 вывод без endl
	for (int i = 0; i<nx; i++) {
		cout << fixed << setw(nw) << setprecision(nf) << X[i];
		if ((i + 1) % nc == 0) cout << endl;
	}
	cout.copyfmt(init); //восстанавливаем текущий формат cout
}
//=== myrnd ====================================================
void myrnd(int *X, const int nx, int n0, int n1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (n1 - n0 + 1) + n0;
}
void myrnd(short *X, const int nx, int n0, int n1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (n1 - n0 + 1) + n0;
}
void myrnd(char *X, const int nx, char c0, char c1) {
	for (int i = 0; i<nx; i++) X[i] = rand() % (c1 - c0 + 1) + c0;
}
void myrnd(double *X, const int nx, double n0, double n1, int nf) {
	double p = pow(10, nf);
	for (int i = 0; i<nx; i++) X[i] = (rand() % (int)(n1 - n0 + 1) + n0) / p;
}
//=== myord, ... =================================================
int mytransp(int *X, int nx, bool inc) {
	int n = 0, t;
	if (inc)
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]>X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	else
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]<X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	return n;
}
void mysel(int *X, int nx, bool inc) {
	int mx = X[0], imx = 0;
	if (inc) for (int i = 1; i<nx; i++) { if (X[i]>mx) { mx = X[i]; imx = i; } }
	else  for (int i = 1; i<nx; i++) { if (X[i]<mx) { mx = X[i]; imx = i; } }
	if (imx != nx - 1) { int t = X[imx]; X[imx] = X[nx - 1]; X[nx - 1] = t; }
}
void myins(int *X, int nx, bool inc, int newval) {
	int i;
	if (inc) for (i = nx - 1; i >= 0 && X[i]>newval; i--) X[i + 1] = X[i];
	else  for (i = nx - 1; i >= 0 && X[i]<newval; i--) X[i + 1] = X[i];
	X[i + 1] = newval;
}
void myord(int *X, int nx, bool inc, char meth) {
	if (meth == 't') for (int i = nx; i>1 && mytransp(X, i, inc); i--);
	else if (meth == 's') for (int i = nx; i>1; i--) mysel(X, i, inc);
	else if (meth == 'i') for (int i = 1; i<nx; i++) myins(X, i, inc, X[i]);
}
//--- перегрузка дл§ double -----
int mytransp(double *X, int nx, bool inc) {
	int n = 0; double t;
	if (inc)
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]>X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	else
		for (int i = 0; i<nx - 1; i++) {
			if (X[i]<X[i + 1]) { t = X[i]; X[i] = X[i + 1]; X[i + 1] = t; n++; }
		}
	return n;
}
void mysel(double *X, int nx, bool inc) {
	int  imx = 0; double mx = X[0];
	if (inc) for (int i = 1; i<nx; i++) { if (X[i]>mx) { mx = X[i]; imx = i; } }
	else  for (int i = 1; i<nx; i++) { if (X[i]<mx) { mx = X[i]; imx = i; } }
	if (imx != nx - 1) { int t = X[imx]; X[imx] = X[nx - 1]; X[nx - 1] = t; }
}
void myins(double *X, int nx, bool inc, double newval) {
	int i;
	if (inc) for (i = nx - 1; i >= 0 && X[i]>newval; i--) X[i + 1] = X[i];
	else  for (i = nx - 1; i >= 0 && X[i]<newval; i--) X[i + 1] = X[i];
	X[i + 1] = newval;
}
void myord(double *X, int nx, bool inc, char meth) {
	if (meth == 't') for (int i = nx; i>1 && mytransp(X, i, inc); i--);
	else if (meth == 's') for (int i = nx; i>1; i--) mysel(X, i, inc);
	else if (meth == 'i') for (int i = 1; i<nx; i++) myins(X, i, inc, X[i]);
}


int mylen(const char*s) {
	char*p = (char*)s;
	while (*p) p++;
	return p - s;
}
char* mycpy(char*s, const char*t) {
	char *p = s, *q = (char*)t;
	while (*p = *q) { p++; q++; }
	return s;
}
char* mycpy(char*s, const char*t, int n, bool addNull) {
	char *p = s, *q = (char*)t;
	int i = 0;
	while (i < n && (*p = *q)) { p++; q++; i++; }
	if (addNull)*p = '\0';
	return s;
}
char* mycat(char*s, const char*t) {
	char*p = s + mylen(s), *q = (char*)t;
	while (*p = *q) { p++; q++; }
	return s;
}
char* mycat(char*s, const char*t, int n, bool addNull) {
	char*p = s + mylen(s), *q = (char*)t;
	int i = 0;
	while (i < n && (*p = *q)) { p++; q++; i++; }
	if (addNull)*p = '\0';
	return s;
}
bool mycmp(const char*s, const char*t) {
	for (char*p = (char*)s, *q = (char*)t; *p || *q; p++, q++) {
		if (*p != *q) return true;
	}
	return false;
}
bool mycmp(const char*s, const char*t, int n) {
	int i = 0;
	for (char*p = (char*)s, *q = (char*)t; (*p || *q) && (i < n); p++, q++, i++) {
		if (*p != *q) return true;
	}
	return false;
}
char* mystr(const char*s, const char*t) {
	int n = mylen(t); if (!n) return NULL;
	for (char*p = (char*)s; *p; p++)
		if (!mycmp(p, t, n)) return p;
	return false;
}
char* mystr(const char*s, const char*t, int n) {
	if (n <= 0) return NULL;
	for (char*p = (char*)s; *p; p++)
		if (!mycmp(p, t, n)) return p;
	return false;
}
void mydel(char*s, int nstart, int ndel) {
	if (nstart < 0 || ndel <= 0 || nstart >= mylen(s)) return;
	if (nstart + ndel > mylen(s)) ndel = mylen(s) - nstart;
	mycpy(s + nstart, s + nstart + ndel);
}
void myins(char*s, int nstart, const char*t) {
	int ns = mylen(s), nt = mylen(t);
	if (nstart<0 || nstart>ns) return;
	for (char*p = s + ns, *end = s + nstart; p >= end; p--)
		*(p + nt) = *p;
	mycpy(s + nstart, t, nt);
}
void myinput(char*s, char sep) {
	const int nmax = 256; char t[nmax];
	mycpy(s, "");
	while (1) {
		cin.getline(t, nmax);
		int n = mylen(s);
		if (!n) break;
		mycat(t, &sep, 1);
		mycat(s, t);

	}
}
int myinput(char*s, char*fname, char sep, bool toConsol) {
	ifstream fin;
	fin.open(fname, ios_base::in);
	const int nmax = 256; char t[nmax];
	mycpy(s, ""); int n;
	for (n = 0; !fin.eof(); n++) {
		fin.getline(t, nmax); if (toConsol) cout << t << endl;
		mycat(s, t);
		mycat(s, &sep, 1);
	}
	fin.close(); return n;

}
int myinput(char*S[], const char*fname, bool toConsol) {
	ifstream fin; fin.open(fname, ios_base::in);
	const int nmax = 256; char t[nmax]; int n;
	for (n = 0; !fin.eof(); n++) {
		fin.getline(t, nmax); if (*t == 0 && fin.eof()) break;
		S[n] = new char[strlen(t) + 1]; strcpy(S[n], t);
		if (toConsol) cout << t << endl;
	}
	fin.close(); return n;
}


int myspn(const char*s, const char*sep) {
	char*p;
	for (p = (char*)s; mystr(sep, p, 1); p++);
	return p - s;
}
int mycspn(const char*s, const char*sep) {
	char*p;
	for (p = (char*)s; !mystr(sep, p, 1) && *p; p++);
	return p - s;
}
int wordcount(const char*s, const char*sep) {
	char*p = (char*)s;
	for (int n = 0;; n++) {
		int nsep = myspn(p, sep); p += nsep;
		int nword = mycspn(p, sep); if (!nword) return n;
		p += nword;
	}
}
int str2num(int*x/*прин*/, const char*s/*отдает*/, const char*sep) {
	char*p = (char*)s; int*q = x;
	for (int n = 0; ; n++) {
		int nsel = myspn(p, sep); p += nsel;/*сдвиг*/
		int nword = mycspn(p, sep); if (!nword) return n;
		*q = atoi(p)/*помещат число в €чейку*/;	if (*q == 0 && *p != '0') { q--; n--; }
		q++; p += nword;
	}
}
int str2num(double*x, const char*s, const char*sep) {
	char*p = (char*)s; double*q = x;
	for (int n = 0; ; n++) {
		int nsel = myspn(p, sep); p += nsel;
		int nword = mycspn(p, sep); if (!nword) return n;
		*q = atof(p);	if (*q == 0 && *p != '0') { q--; n--; }
		q++; p += nword;
	}
}
int strcount(const char*fname) {
	ifstream fin; fin.open(fname, ios_base::in);
	const int nmax = 256; char t[nmax]; int n;
	for (n = 0; !fin.eof(); n++)
		fin.getline(t, nmax);
	if (!*t)n--;
	fin.close(); return n;
}
//=========================================================================================
int * mymax(int*X, int nx) {  // min число
	int *pmax = X;
	for (int *p = X + 1, *end = X + nx; p < end; p++)
		if (*p > *pmax) pmax = p;
	return pmax;
}
int * mymin(int*X, int nx) {//макс число
	int *pmin = X;
	for (int *p = X + 1, *end = X + nx; p < end; p++)
		if (*p < *pmin) pmin = p;
	return pmin;
}
void mysrt(int*X, int nx, bool inc, int*P[]) { //сортирует по возрастанию
	if (inc)
		for (int i = nx - 1; i > 0; i--) {
			int j = mymax(X, i + 1) - X;
			if (j == i) continue;
			int n = X[j]; X[j] = X[i]; X[i] = n;
			if (P) {
				int*p = P[j]; P[j] = P[i]; P[i] = p;
			}
		}
	else
		for (int i = nx - 1; i > 0; i--) {
			int j = mymin(X, i + 1) - X;
			if (j == i) continue;
			int n = X[j]; X[j] = X[i]; X[i] = n;
			if (P) {
				int*p = P[j]; P[j] = P[i]; P[i] = p;
			}
		}
}
//--- перегрузка дл€ строк -----------------
char** mymax(char*X[], int nx) {
	char **pmax = X;
	for (char**p = X + 1, **end = X + nx; p<end; p++)
		if (strcmp(*p, *pmax)>0) pmax = p;
	return pmax;
}
char** mymin(char*X[], int nx) {
	char **pmin = X;
	for (char**p = X + 1, **end = X + nx; p<end; p++)
		if (strcmp(*p, *pmin)<0) pmin = p;
	return pmin;
}

void mysrt(char**X, int nx, bool inc, char*P[]) {
	if (inc)
		for (int i = nx - 1; i>0; i--) {
			int j = mymax(X, i + 1) - X;			//j-индекс максимума
			if (j == i) continue;				//если максимум на своем месте, перестановка не нужна
			char*n = X[j]; X[j] = X[i]; X[i] = n;	//переставл€ем элементы X и P	
			if (P) { char*p = P[j]; P[j] = P[i]; P[i] = p; }
		}
	else
		for (int i = nx - 1; i>0; i--) {
			int j = mymin(X, i + 1) - X;			//j-индекс минимума
			if (j == i) continue;				//если максимум на своем месте, перестановка не нужна
			char*n = X[j]; X[j] = X[i]; X[i] = n;	//переставл€ем элементы X и P	
			if (P) { char*p = P[j]; P[j] = P[i]; P[i] = p; }
		}
}


//===================================================================================
void getxy(int &x, int &y) {
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	x = sbi.dwCursorPosition.X; y = sbi.dwCursorPosition.Y;
}
void setxy(int x, int y) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Coor;	Coor.X = x; Coor.Y = y;
	SetConsoleCursorPosition(hStdOut, Coor);
}
void getcolor(int &text, int &background) {
	CONSOLE_SCREEN_BUFFER_INFO sbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	int n = sbi.wAttributes; text = n % 16; background = n / 16 % 16;
}
void setcolor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

