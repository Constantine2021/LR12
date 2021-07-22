#include <iostream>
#include <istream>
#include <iomanip>
#include <fstream>

#include "..\\..\\myfunctions.h"
struct point2 { double x; double y; };
struct stCircle { point2 center; double radius; } crc1;
struct triangle { point2 vr[3]; int type; double prm; double area; };
float midval(float &midl, int val[], int nval );
void crcnd(stCircle *pc, double x0, double x1, double y0, double y1, double r0, double r1);
void crcout(stCircle crc);
void trout(triangle**srt);

using namespace std;
int main()
{
	setlocale(LC_CTYPE, "rus");
	{cout << "===Задание 1=========" << endl; 
	const int maxlen=256, nval =4 ;
	struct session {
		char name[maxlen];
		int val[nval];
		float midl;
	};
	session s1 = { "Колесник Н.И.",{8,6,9,7}, 7.5}, s2 = {};
	char io[8];
	cout << "Данные второго студента: ";
	cout << strcpy(s2.name, "Панкратович К.С.");
	int X[] = { 7,5,6,5 };
	for (int i = 0; i < nval; i++)
		cout << " " << (s2.val[i] = X[i]);
	cout << endl;
	/*s1.midl = 0;
	s2.midl = 0;
	for (int i = 0; i < nval; i++) {
		s1.midl += s1.val[i];
		s2.midl += s2.val[i];
	}
	s1.midl /= 4;
	s2.midl /= 4;*/
	midval(s1.midl, s1.val, nval);
	midval(s2.midl, s2.val, nval);

	cout <<"\nРезультаты сессии:\n";
	cout << s1.name<<setw(8);
	for (int i = 0; i < nval; i++)
		cout << " " << s1.val[i];
	cout << " Средняя = " << s1.midl<<endl;
	cout << s2.name<<setw(5);
	for (int i = 0; i < nval; i++)
		cout << " " << s2.val[i];
	cout << " Средняя = " << s2.midl << endl;
	}
	cout << endl;
	{cout << "===Задание 2=========" << endl;
	/*struct point2 { double x; double y; };
	struct stCircle { point2 center; double radius; } crc1;*/
	/*const int np = 25; stCircle A[np];
	for (int i = 0; i < np; i++) {
		myrnd(&A[i].center.x, 1, -10, 10, 1);
		myrnd(&A[i].center.y, 1, -10, 10, 1);
		myrnd(&A[i].radius, 1, 50, 100, 1);
		cout << "(" << fixed << setprecision(1) << (A[i].center.x >= 0 ? " " : "") << A[i].center.x << "," << (A[i].center.y >= 0 ? " " : "") << A[i].center.y << ","
			<< (A[i].radius >= 0 ? " " : "") << A[i].radius << ")";
		if (i == 4 || i == 9 || i == 14 || i == 19) cout << endl;
	}*/
	const int np = 25;
	for (int i = 0; i < np; i++) {
		crcnd(&crc1, -1.0, 1.0, -1.0, 1.0, 5.0, 10.0);
		crcout(crc1);
		if (i == 4 || i == 9 || i == 14 || i == 19) cout << endl;
	}
	cout << endl;
	}
	cout << endl;
	{cout << "===Задание 3=========" << endl;
	struct session {
		char *name;
		int *val;
		float midl;
	};
	int nstud = strcount("12.3.txt");
	session *group = new session[nstud];
	char **S = new char*[nstud];
	myinput(S, "12.3.txt", 1);
	int nval = wordcount(*S, " ") - 2;
	for (int i = 0; i < nstud; i++) {
		char*p = S[i];
		p += strcspn(p, " ");
		p += strspn(p, " ");
		p += strcspn(p, " ");
		group[i].name = new char[p - S[i] + 1];
		mycpy(group[i].name, S[i], p - S[i], 1);
		group[i].val = new int[nval];
		str2num(group[i].val, p);
		/*for (int j = 0; j < nval; j++)
			group[i].midl += group[i].val[j];
		group[i].midl /= nval;*/
		midval(group[i].midl, group[i].val,nval);
	}
	delete[] S;
	cout << "\nОтличники:\n";
	for (int i = 0; i < nstud; i++) {
		int p = 0;
		for (int j = 0; j < nval; j++) if (group[i].val[j] <= 8)p++;
		if (!p) myout(group[i].name, strlen(group[i].name), 1);
	}
	cout << "\nНеуспевающие:\n";
	for (int i = 0; i < nstud; i++) {
		int p = 0;
		for (int j = 0; j < nval; j++) if (group[i].val[j] < 4)p++;
		if (p) myout(group[i].name, strlen(group[i].name), 1);
	}
	}
	cout << endl;
	{cout << "===Задание 6=========" << endl;
	struct session {
		char *name;
		int *val;
		float midl;
	};
	int nstud = strcount("12.3.txt");
	session *group = new session[nstud];
	char **S = new char*[nstud];
	myinput(S, "12.3.txt", 0);
	int nval = wordcount(*S, " ") - 2;
	for (int i = 0; i < nstud; i++) {
		char*p = S[i];
		p += strcspn(p, " ");
		p += strspn(p, " ");
		p += strcspn(p, " ");
		group[i].name = new char[p - S[i] + 1];
		mycpy(group[i].name, S[i], p - S[i], 1);
		group[i].val = new int[nval];
		str2num(group[i].val, p);
		/*for (int j = 0; j < nval; j++)
		group[i].midl += group[i].val[j];
		group[i].midl /= nval;*/
		midval(group[i].midl, group[i].val, nval);
	}
	delete[] S; 
	int *mv = new int[nstud];
	session**srtgrp = new session*[nstud];
	for (int i = 0; i < nstud; i++) {
		mv[i]= midval(group[i].midl, group[i].val, nval)*100;
		srtgrp[i] = &group[i];
	}
	mysrt(mv, nstud, 0, (int**)srtgrp);
	cout << "Отсортированный спиок студентов:" << endl;
	for (int i = 0; i < nstud; i++)
		cout << setw(25) <<left<< srtgrp[i]->name  << "(" << setprecision(2) << (float)mv[i] / 100 << ")\n";
	}
	cout << endl;
	{cout << "=====Задание 7=====\n";
	int  ntr = strcount("12.7a.txt");
	char **S = new char*[ntr];  myinput(S, "12.7a.txt");
	triangle *tr = new triangle[ntr];
	for (int i = 0; i < ntr; i++) {
		double z[6]; str2num(z, S[i], " ");
		tr[i].vr[0].x = z[0];
		tr[i].vr[0].y = z[1];
		tr[i].vr[1].x = z[2]; 
		tr[i].vr[1].y = z[3];
		tr[i].vr[2].x = z[4];
		tr[i].vr[2].y = z[5];
		double len[3];
		len[1] = sqrt(pow((z[0] - z[2]), 2) + pow((z[1] - z[3]), 2)); 
		len[2] = sqrt(pow((z[2] - z[4]), 2) + pow((z[3] - z[5]), 2)); 
		len[3] = sqrt(pow((z[4] - z[0]), 2) + pow((z[5] - z[1]), 2)); 
		tr[i].prm = len[1] + len[2] + len[3];
		double prm = tr[i].prm / 2.;
		tr[i].area = sqrt((prm)*(prm - len[1])*(prm - len[2])*(prm - len[3]));
		double Max = len[1], var;
		Max = (Max > len[2]) ? Max : len[2];
		Max = (Max > len[3]) ? Max : len[3];
		if (Max == len[1]) { var = len[3]; len[3] = len[1]; len[1] = var; }
		else if (Max == len[2]) { var = len[3]; len[3] = len[2]; len[2] = var; }
		if (abs(pow(len[3], 2) - (pow(len[1], 2) + pow(len[2], 2))) < 0.01) tr[i].type = 1;
		else tr[i].type = (((pow(len[1], 2) + pow(len[2], 2)) > pow(len[3], 2)) ? 0 : 2);
	}
	triangle **srt = new triangle*[ntr];
	int * type = new int[ntr];
	for (int i = 0; i < ntr; i++) {
		srt[i] = &tr[i];
		type[i] = tr[i].type;
	}
	mysrt(type, ntr, true, (int **)srt);
	cout << "Упорядоченный по типу список треугольников:\n";
	for (int i = 0; i < ntr; i++)	
		if ((*srt[i]).type == 0)	
			trout(&srt[i]);
	for (int i = 0; i < ntr; i++) 	
		if ((*srt[i]).type == 1)	
			trout(&srt[i]);
	for (int i = 0; i < ntr; i++) 	
		if ((*srt[i]).type == 2)	
			trout(&srt[i]);
	cout << endl << "Остроугольные треугольники с площадью >1000\n";
	for (int i = 0; i < ntr; i++)	
		if ((*srt[i]).type == 0 && (*srt[i]).area > 1000)	
			trout(&srt[i]);
	delete[] S;
	delete[] type;
	delete[] srt;
	delete[] tr;
	}
	
	
	
	
	


	system("pause");
	return 0;
}
float midval(float &midl, int val[], int nval) {
	midl = 0;
	for (int i = 0; i < nval; i++) {
		midl += val[i];
	}
	midl /= nval;
	return midl;
}
void crcnd(stCircle *pc, double x0, double x1, double y0, double y1, double r0, double r1) {
	int n1 = (x0 - x1) * 10 + 1;
	pc->center.x = (rand() % n1) / 10. + x0;
	int n2 = (y0 - y1) * 10 + 1;
	pc->center.y = (rand() % n2) / 10. + y0;
	int n3 = (r0 - r1) * 10 + 1;
	pc->radius = (rand() % n3) / 10. + r0;
}
void crcout(stCircle crc) {
	cout << "(" << fixed << setprecision(1) << (crc1.center.x >= 0 ? " " : "") << crc1.center.x << "," << (crc1.center.y >= 0 ? " " : "") << crc1.center.y << ","
				<< (crc1.radius >= 0 ? " " : "") << crc1.radius << ")";	
	}

void trout(triangle**srt) {
	cout <<fixed<<setprecision(3)<< "(" << (**srt).vr[0].x << ", " << (**srt).vr[0].y << ") (" << (**srt).vr[1].x << ", " << (**srt).vr[1].y << ") (" << (**srt).vr[2].x << ", "
		<< (**srt).vr[2].y << ") " << (**srt).type << " " << (**srt).prm << " " << (**srt).area << endl;
}
