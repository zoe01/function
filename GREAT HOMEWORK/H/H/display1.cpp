#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<locale.h>

#pragma comment (lib, "WinMM.lib")
#define WDIS 900
MOUSEMSG o;
HRGN hrgn;

void MainPage();
void settings();
void display2();
void botton();

int SubMenu1(){
	int i = 1, y1 = 250;
	FILE *hint,*hintdes;
	int b1,b2;
	char line[100],linedes[100];
	cleardevice();
	IMAGE img;

	loadimage(&img, "2.jpg", 900, 600, true);
	putimage(0, 0, &img);
	setlocale(LC_ALL, "chs");//解决中文乱码，在头文件locale.h中
	settextstyle(40, 0, "幼圆", 0, 0, 10000, 0, 0, 0);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);/*处理文字后面的黑色，使文字后的背景为图片*/
	outtextxy(WDIS, 150, "菜单");

	settextstyle(20, 0, "Buxton Sketch", 0, 0, 8000, 0, 0, 0);
	settextcolor(LIGHTMAGENTA);
	outtextxy(20, 20, "HINT!");
	outtextxy(620, 20, "输入函数时别忘了括号哦~");
	outtextxy(620, 38, "神秘之旅的正确退出方式是右键哦~");
	b1 = 50;
	hint = fopen("hint.txt", "r");
	while (!feof(hint)){
		if (fgets(line, 100, hint)){
			outtextxy(20, b1, line);
			b1 = b1 + 20;
		}
	}
	b2 = 50;
	hintdes = fopen("hintdes.txt", "r");
	while (!feof(hintdes)){
		if (fgets(linedes, 100, hintdes)){
			outtextxy(70, b2, linedes);
			b2 = b2 + 20;
		}
	}

	settextcolor(WHITE);
	settextstyle(30, 0, "幼圆", 0, 0, 1000, 0, 1, 0);

	int WIDTH = textwidth(_T("4 菜单"));
	outtextxy(WDIS, 250, _T("1 画图"));
	outtextxy(WDIS, 300, _T("2 分形"));
	outtextxy(WDIS, 350, _T("3 配置"));
	outtextxy(WDIS, 400, _T("4 菜单"));

	settextcolor(YELLOW);
	settextstyle(30, 0, "幼圆", 0, 0, 1000,0,0,0);

	outtextxy(700, 550, _T("开启神秘之旅"));

	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //检测
			o = GetMouseMsg();//获取鼠标状态
			if (o.uMsg == WM_LBUTTONDOWN){
				while (o.x >= WDIS&&o.x <= WIDTH + WDIS&&o.y >= 250 && o.y <= 425){
					if (o.y >= y1&&o.y <= 25 + y1)
						return i;
					else if (y1 >= 400)
						break;
					else
						y1 += 50, i++;
				}
				while (o.x >= 700 && o.x <= textwidth("开启神秘之旅") + 700 && o.y >= 550 && o.y <= 575)
					return 5;
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
void display1()
{
	int choose = 0;
	choose = SubMenu1();
	switch (choose){
	case 1:display1(); break;
	case 2:display2(); break;
	case 3:settings(); break;
	case 4:MainPage(); break;
	case 5:botton(); break;
	default:;
	}
	_getch();
	return ;
}