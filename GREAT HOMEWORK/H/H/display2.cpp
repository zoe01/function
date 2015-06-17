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
MOUSEMSG u;//�����Ρ�ҳ�е�������
MOUSEMSG m1;//�����Ρ�ͼ���е�������
extern HWND hwnd;

void display1();
void display2();
void settings();
void MainPage();
void H();
void S();
void J();

//����ͼ���еķ��ؼ�
int Return(){
	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //���
			m1 = GetMouseMsg();//��ȡ���״̬
			if (m1.uMsg == WM_LBUTTONDOWN)
			while (m1.x >= 700 && m1.x <= 700 + textwidth("Return") && m1.y >= 550 && m1.y <= 600){
				display2();
				return 1;
			}
		}
	}
}

//�����Ρ�ҳ�Ĳ˵�
int SubMenu2(){

	int i = 1, y1 = 250;

	initgraph(1000, 600);
	cleardevice();
	IMAGE img;

	loadimage(&img, "5.gif", 900, 600, true);
	putimage(0, 0, &img);

	//���ò˵�����
	setlocale(LC_ALL, "chs");//����������룬��ͷ�ļ�locale.h��
	settextstyle(40, 0, "��Բ", 0, 0, 10000, 0, 0, 0);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);/*�������ֺ���ĺ�ɫ��ʹ���ֺ�ı���ΪͼƬ*/
	outtextxy(WDIS, 150, "�˵�");

	settextcolor(WHITE);
	settextstyle(30, 0, "��Բ", 0, 0, 1000, 0, 1, 0);
	int WIDTH = textwidth(_T("4 �˵�"));
	outtextxy(WDIS, 250, _T("1 ��ͼ"));
	outtextxy(WDIS, 300, _T("2 ����"));
	outtextxy(WDIS, 350, _T("3 ����"));
	outtextxy(WDIS, 400, _T("4 �˵�"));

	//���÷���ͼ��˵�����
	settextcolor(LIGHTMAGENTA);
	settextstyle(50, 0, "����Ҧ��", 0, 0, 1000, 0, 1, 0);
	outtextxy(350, 100, _T("Ȼ����Щ�������ص�"));

	settextcolor(LIGHTBLUE);
	settextstyle(50, 0, "�����п�", 0, 0, 1000, 0, 1, 0);
	outtextxy(550, 200, _T("Hilbert"));
	outtextxy(550, 300, _T("Sierpinski"));
	outtextxy(550, 400, _T("Julia Set"));
	
	//��ȡ�����Ϣ
	FlushMouseMsgBuffer();
	while (true){
		if (MouseHit()){   //���
			u = GetMouseMsg();//��ȡ���״̬
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
		//ͨ������Ҳ��ʵ�ֲ˵���ת
		if (_kbhit()){
			char c = _getch();
			if (c >= '1'&&c <= '4')
				return (c - '0');
		}
	}
	_getch();
	closegraph();
}

//�����Ρ�ҳ������
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