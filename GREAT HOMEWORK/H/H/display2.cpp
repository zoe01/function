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

#define WDIS 900
MOUSEMSG u;
extern HWND hwnd;
extern HMODULE hmod;


void display1();
void display2();
void settings();
void MainPage();

int SubMenu2(){

	int i = 1, y1 = 250;

	//initgraph(1000, 600);
	cleardevice();
	IMAGE img;

	loadimage(&img, "5.gif", 900, 600, true);
	putimage(0, 0, &img);
	setlocale(LC_ALL, "chs");//解决中文乱码，在头文件locale.h中
	settextstyle(40, 0, "幼圆", 0, 0, 10000, 0, 0, 0);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);/*处理文字后面的黑色，使文字后的背景为图片*/
	outtextxy(WDIS, 150, "菜单");




	settextcolor(WHITE);
	settextstyle(30, 0, "幼圆", 0, 0, 1000, 0, 1, 0);

	int WIDTH = textwidth(_T("4 菜单"));
	outtextxy(WDIS, 250, _T("1 画图"));
	outtextxy(WDIS, 300, _T("2 分形"));
	outtextxy(WDIS, 350, _T("3 配置"));
	outtextxy(WDIS, 400, _T("4 菜单"));


	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //检测
			u = GetMouseMsg();//获取鼠标状态
			if (u.uMsg == WM_LBUTTONDOWN){
				while (u.x >= WDIS&&u.x <= WIDTH + WDIS&&u.y >= 250 && u.y <= 425){
					if (u.y >= y1&&u.y <= 25 + y1)
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


void display2(){
	setcliprgn(NULL);
	int choose;
	
	choose = SubMenu2();
	switch (choose){
	case 1:display1(); break;
	case 2:display2(); break;
	case 3:settings(); break;
	case 4:MainPage();
	default:;
	}
	

	_getch();
	return;

}