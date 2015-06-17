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
MOUSEMSG u;//“分形”页中的鼠标变量
MOUSEMSG m1;//“分形”图像中的鼠标变量
extern HWND hwnd;

void display1();
void display2();
void settings();
void MainPage();
void H();
void S();
void J();

//分形图像中的返回键
int Return(){
	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //检测
			m1 = GetMouseMsg();//获取鼠标状态
			if (m1.uMsg == WM_LBUTTONDOWN)
			while (m1.x >= 700 && m1.x <= 700 + textwidth("Return") && m1.y >= 550 && m1.y <= 600){
				display2();
				return 1;
			}
		}
	}
}

//“分形”页的菜单
int SubMenu2(){

	int i = 1, y1 = 250;

	initgraph(1000, 600);
	cleardevice();
	IMAGE img;

	loadimage(&img, "5.gif", 900, 600, true);
	putimage(0, 0, &img);

	//设置菜单文字
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

	//设置分形图像菜单文字
	settextcolor(LIGHTMAGENTA);
	settextstyle(50, 0, "方正姚体", 0, 0, 1000, 0, 1, 0);
	outtextxy(350, 100, _T("然而这些并不是重点"));

	settextcolor(LIGHTBLUE);
	settextstyle(50, 0, "华文行楷", 0, 0, 1000, 0, 1, 0);
	outtextxy(550, 200, _T("Hilbert"));
	outtextxy(550, 300, _T("Sierpinski"));
	outtextxy(550, 400, _T("Julia Set"));
	
	//获取鼠标信息
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
				while (u.x >= 550 && u.x <= textwidth("Hilbert") + 550&&u.y >= 200 && u.y <= 250)
					return 5;
				while (u.x >= 550 && u.x <= textwidth("Sierpinski") + 550&&u.y >= 300 && u.y <= 350)
					return 6;
				while (u.x >= 550 && u.x <= textwidth("Julia Set") + 550&&u.y >= 400 && u.y <= 450)
					return 7;
			}
		}
		//通过按键也可实现菜单跳转
		if (_kbhit()){
			char c = _getch();
			if (c >= '1'&&c <= '4')
				return (c - '0');
		}
	}
	_getch();
	closegraph();
}

//“分形”页主函数
void display2(){
	int choose;
	
	choose = SubMenu2();
	switch (choose){
	case 1:display1(); break;
	case 2:display2(); break;
	case 3:settings(); break;
	case 4:MainPage(); break;
	case 5:H();  break;
	case 6:S(); break;
	case 7:J(); break;
	default:;
	}
	_getch();
	return;

}