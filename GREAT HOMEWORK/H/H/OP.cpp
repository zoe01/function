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
#include<gl\glut.h>
#include<math.h>


#define WDIS 900
MOUSEMSG e;

void display1();

typedef struct points
{
	double x;
	double y;
}point;
extern point* analyzeFunction(double x1, double x2, double step, char*fun);
point* dot;

point changesize(point *dot, double n){
	int i, j=0;
	double s=dot[1].x, t=dot[1].y;
	point max;
	for (i = 1; i <= n; i++){
		for (j = i + 1; j < n; j++){
			if (fabs(s) >= fabs(dot[j].x))
				s = s;
			else
				s = dot[j].x;
		}
	}
	for (i = 1; i <= n; i++){
		for (j = i + 1; j < n; j++){
			if (fabs(t) >= fabs(dot[j].y))
				t = t;
			else
				t = dot[j].y;
		}
	}
	max.x = fabs(s), max.y = fabs(t);
	return max;
}
void func()
{
	point max = changesize(dot, dot[0].x);
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef((1.0/max.x), (1.0/max.y), 1.0f);//����
	glBegin(GL_LINE_STRIP /* ��������������ϣ����ģʽ */);
	for (int i = 1; i <= dot[0].x; i++){
		glVertex2f(dot[i].x, dot[i].y);
	}
	glEnd();
	glFlush();
}
void mymenu(int value){
	if (value == 1)
	{

		HWND s = FindWindow(NULL, "����֮��");
		DestroyWindow(s);
		display1();
	}
}
void botton(){


	char  x1[50], x2[50], stepp[50], fun[100];
	double r1, r2, step;

	InputBox(x1, 50, "������x�ķ�Χ��Сֵ");
	InputBox(x2, 50, "������x�ķ�Χ���ֵ");
	InputBox(stepp, 50, "�����벽��");
	InputBox(fun, 100, "�����뷽��");

	sscanf_s(x1, "%lf", &r1);
	sscanf_s(x2, "%lf", &r2);
	sscanf_s(stepp, "%lf", &step);
	sprintf_s(fun, "%s%s", fun, "\n");
	dot = analyzeFunction(r1, r2, step, fun);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("����֮��");

	glutCreateMenu(mymenu);
	glutAddMenuEntry("�ر�", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutDisplayFunc(func);
	//glutReshapeFunc(changeSize);
	glutMainLoop();
}