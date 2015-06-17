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
	setlocale(LC_ALL, "chs");//����������룬��ͷ�ļ�locale.h��
	settextstyle(40, 0, "��Բ", 0, 0, 10000, 0, 0, 0);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);/*�������ֺ���ĺ�ɫ��ʹ���ֺ�ı���ΪͼƬ*/
	outtextxy(WDIS, 150, "�˵�");

	settextstyle(20, 0, "Buxton Sketch", 0, 0, 8000, 0, 0, 0);
	settextcolor(LIGHTMAGENTA);
	outtextxy(20, 20, "HINT!");
	outtextxy(620, 20, "���뺯��ʱ����������Ŷ~");
	outtextxy(620, 38, "����֮�õ���ȷ�˳���ʽ���Ҽ�Ŷ~");
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
	settextstyle(30, 0, "��Բ", 0, 0, 1000, 0, 1, 0);

	int WIDTH = textwidth(_T("4 �˵�"));
	outtextxy(WDIS, 250, _T("1 ��ͼ"));
	outtextxy(WDIS, 300, _T("2 ����"));
	outtextxy(WDIS, 350, _T("3 ����"));
	outtextxy(WDIS, 400, _T("4 �˵�"));

	settextcolor(YELLOW);
	settextstyle(30, 0, "��Բ", 0, 0, 1000,0,0,0);

	outtextxy(700, 550, _T("��������֮��"));

	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //���
			o = GetMouseMsg();//��ȡ���״̬
			if (o.uMsg == WM_LBUTTONDOWN){
				while (o.x >= WDIS&&o.x <= WIDTH + WDIS&&o.y >= 250 && o.y <= 425){
					if (o.y >= y1&&o.y <= 25 + y1)
						return i;
					else if (y1 >= 400)
						break;
					else
						y1 += 50, i++;
				}
				while (o.x >= 700 && o.x <= textwidth("��������֮��") + 700 && o.y >= 550 && o.y <= 575)
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