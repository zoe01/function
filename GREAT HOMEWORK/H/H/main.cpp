#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<tchar.h>
#include <ctime>
#include<windows.h>
#include<mmsystem.h>
#include<graphics.h>
#include<easyx.h>
#include<conio.h>
#include<locale.h>

#pragma comment(lib,"WinMM.lib");
#define WDIS 440
MOUSEMSG m;
extern HWND hwnd;
extern HMODULE hmod;

int mainmenu();
void display1();
void display2();
void settings();
void loadmusic();
void closemusic();

int MainMenu(){
	int i = 1, y1 = 250;

	//initgraph(1000, 600);
	cleardevice();
	IMAGE img;

	loadimage(&img, "1.jpg", 1000, 600, true);
	putimage(0, 0, &img);
	setlocale(LC_ALL, "chs");//����������룬��ͷ�ļ�locale.h��
	settextstyle(80, 0, "���Ĳ���",0,0,10000,0,0,0);
	settextcolor(MAGENTA);
	setbkmode(TRANSPARENT);/*�������ֺ���ĺ�ɫ��ʹ���ֺ�ı���ΪͼƬ*/
	outtextxy(400, 150, "�˵�");

	

	
	settextcolor(DARKGRAY);
	settextstyle(40, 0, "��Բ",0,0,1000,0,1,0);
	
	int WIDTH = textwidth(_T("1 ��ͼ"));
	outtextxy(WDIS, 250, _T("1 ��ͼ"));
	outtextxy(WDIS, 300, _T("2 ����"));
	outtextxy(WDIS, 350, _T("3 ����"));
	outtextxy(WDIS, 400, _T("4 �˳�"));
	

	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //���
			m = GetMouseMsg();//��ȡ���״̬
			if (m.uMsg == WM_LBUTTONDOWN){
				while (m.x >= WDIS&&m.x <=  WIDTH+WDIS&&m.y >= 250 && m.y <= 425){
					if (m.y >= y1&&m.y <= 25 + y1)
						return i;
					else if (y1 >= 400)
						break;
					else
						y1 += 50, i++;
				}
			}
			

		}
		if (_kbhit()){
			char c = _getch();
			if (c >= '1'&&c <= '4')
				return (c - '0');
		}
	}
	_getch();
	closegraph();

}

void MainPage(){
	setcliprgn(NULL);
	int choose = 0;

	choose = MainMenu();
	switch (choose){
	case 1: display1(); break;
	case 2: display2(); break;
	case 3:  settings();  break;
	case 4:  closemusic(); closegraph(); exit(1);
	default:;
	}
	_getch();
}

void main(void){	
	initgraph(1000, 600);
	loadmusic();
	mciSendString("play d repeat", NULL, 0, NULL);
	MainPage();	
	_getch();
	return ;
}