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
#define WDIS2 300
MOUSEMSG s;
extern HWND hwnd;
extern HMODULE hmod;


void display1();
void display2();
void MainPage();

void loadmusic(){
	mciSendString(TEXT("open lvdvo.mp3 alias a"), NULL, 0, NULL);
	mciSendString(TEXT("open 菊次郎的夏天.mp3 alias b"), NULL, 0, NULL);
	mciSendString(TEXT("open lm.mp3 alias c"), NULL, 0, NULL);
	mciSendString(TEXT("open Canon.mp3 alias d"), NULL, 0, NULL);
	mciSendString(TEXT("open cdaelm.mp3 alias e"), NULL, 0, NULL);
	mciSendString(TEXT("open 天空之城.mp3 alias f"), NULL, 0, NULL);
	mciSendString(TEXT("open 微光角落.mp3 alias g"), NULL, 0, NULL);	
	mciSendString(TEXT("open sd.mp3 alias h"), NULL, 0, NULL);	


}

void stopmusic(){
	mciSendString("stop a", NULL, 0, NULL);
	mciSendString("stop b", NULL, 0, NULL);
	mciSendString("stop c", NULL, 0, NULL);
	mciSendString("stop d", NULL, 0, NULL);
	mciSendString("stop e", NULL, 0, NULL);
	mciSendString("stop f", NULL, 0, NULL);
	mciSendString("stop g", NULL, 0, NULL);
	mciSendString("stop h", NULL, 0, NULL);
}

void closemusic(){
	mciSendString("close a", NULL, 0, NULL);
	mciSendString("close b", NULL, 0, NULL);
	mciSendString("close c", NULL, 0, NULL);
	mciSendString("close d", NULL, 0, NULL);
	mciSendString("close e", NULL, 0, NULL);
	mciSendString("close f", NULL, 0, NULL);
	mciSendString("close g", NULL, 0, NULL);
	mciSendString("close h", NULL, 0, NULL);
}


int SubMenu3(){
	int i = 1, j = 4, y1 = 250, y2 = 150;
	cleardevice();
	IMAGE img;

	loadimage(&img, "4.jpg", 900, 600, true);
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
	outtextxy(WDIS, 350, _T("3 菜单"));

	settextcolor(MAGENTA);
	settextstyle(30, 0, "华文行楷", 0, 0, 10000, 0, 0, 0);
	outtextxy(50, 400, _T("张宁怡"));
	outtextxy(50, 450, _T("赵彤"));
	outtextxy(50, 500, _T("王靖宇"));
	outtextxy(50, 550, _T("倾情奉献"));

	setlocale(LC_ALL, "chs");
	settextstyle(80, 0, "方正姚体", 0, 0, 10000, 0, 0, 0);
	settextcolor(LIGHTBLUE);
	outtextxy(600, 50, _T("背景音乐"));
	settextstyle(30, 0, "华文隶书", 0, 0, 10000, 0, 1, 0);
	settextcolor(BLUE);
	int WIDTH2 = textwidth(_T("Comtine D'un Autre Ete L'apres Midi"));
	outtextxy(300, 150, _T("La Valse Des Vieux Os"));
	outtextxy(300, 200, _T("菊次郎的夏天"));
	outtextxy(300, 250, _T("Le Moulin"));
	outtextxy(300, 300, _T("Canon"));
	outtextxy(300, 350, _T("Comtine D'un Autre Ete L'apres Midi"));
	outtextxy(300, 400, _T("天空之城"));
	outtextxy(300, 450, _T("微光角落"));
	outtextxy(300, 500, _T("Snow Dream"));
	outtextxy(300, 550, _T("关闭音乐"));

	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //检测
			s = GetMouseMsg();//获取鼠标状态
			if (s.uMsg == WM_LBUTTONDOWN){
				//while (s.x >= WDIS&&s.x <= WIDTH + WDIS&&s.y >= 250 && s.y <= 375 )
					//s.x >= WDIS2&&s.x <= WIDTH2 + WDIS2&&s.y >= 150 && s.y <= 525)
					while (s.x >= WDIS&&s.x <= WIDTH + WDIS&&s.y >= 250 && s.y <= 375){
						if (s.y >= y1&&s.y <= 25 + y1)
							return i;
						else if (y1 >= 350)
							break;
						else
							y1 += 50, i++;
					}
					while (s.x >= WDIS2&&s.x <= textwidth(_T("La Valse Des Vieux Os")) + WDIS2&&s.y >= 150 && s.y <= 175)
						return 4;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("菊次郎的夏天")) + WDIS2&&s.y >= 200 && s.y <= 225)
						return 5;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("Le Moulin")) + WDIS2&&s.y >= 250 && s.y <= 275)
						return 6;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("Canon")) + WDIS2&&s.y >= 300 && s.y <= 325)
						return 7;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("Comtine D'un Autre Ete L'apres Midi")) + WDIS2&&s.y >= 350 && s.y <= 375)
						return 8;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("天空之城")) + WDIS2&&s.y >= 400 && s.y <= 425)
						return 9;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("微光角落")) + WDIS2&&s.y >= 450 && s.y <= 475)
						return 10;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("Snow Dream")) + WDIS2&&s.y >= 500 && s.y <= 525)
						return 11;
					while (s.x >= WDIS2&&s.x <= textwidth(_T("关闭音乐")) + WDIS2&&s.y >= 550 && s.y <= 575)
						return 12;
			}
			if (_kbhit()){
				char c = _getch();
				if (c >= '1'&&c <= '3')
					return (c - '0');
			}
		}
	}
	_getch();
}



void settings(){

	setcliprgn(NULL);
	int choose;
	choose = SubMenu3(); 	
	switch (choose)
	{
	case 1:display1(); break;
	case 2:display2(); break;
	case 3:MainPage(); break;
	case 4:stopmusic(); mciSendString("play a repeat", NULL, 0, NULL); settings(); break;
	case 5:stopmusic(); mciSendString("play b repeat", NULL, 0, NULL); settings(); break;
	case 6:stopmusic(); mciSendString("play c repeat", NULL, 0, NULL); settings(); break;
	case 7:stopmusic(); mciSendString("play d repeat", NULL, 0, NULL); settings(); break;
	case 8:stopmusic(); mciSendString("play e repeat", NULL, 0, NULL); settings(); break;
	case 9:stopmusic(); mciSendString("play f repeat", NULL, 0, NULL); settings(); break;
	case 10:stopmusic(); mciSendString("play g repeat", NULL, 0, NULL); settings(); break;
	case 11:stopmusic(); mciSendString("play h repeat", NULL, 0, NULL); settings(); break;
	case 12:stopmusic(); settings(); break;
	default:;
	}


	_getch();
	return;
}