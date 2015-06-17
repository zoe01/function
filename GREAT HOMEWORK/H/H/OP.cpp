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
point max;

point zoom(point *dot, double n){
	int i, j = 0;
	double s = dot[1].x, t = dot[1].y;
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


void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45, ratio, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
}

void func()
{
	max = zoom(dot, dot[0].x);
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef((1.0 / max.x), (1.0 / max.y), 1.0f);//缩放

	glBegin(GL_LINES);
	glVertex2f(-(max.x), 0);
	glVertex2f(max.x, 0);
	glEnd();
	glFlush();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.95*max.x, 0.05*max.y);
	glVertex2f(max.x, 0);
	glVertex2f(0.95*max.x, -0.05*max.y);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
	glVertex2f(0, max.y);
	glVertex2f(0, -(max.y));
	glEnd();
	glFlush();

	glBegin(GL_LINE_STRIP);
	glVertex2f(0.05*max.x, 0.95*max.y);
	glVertex2f(0, max.y);
	glVertex2f(-0.05*max.x, 0.95*max.y);
	glEnd();
	glFlush();

	glBegin(GL_LINE_STRIP /* 在这里填上你所希望的模式 */);
	for (int i = 1; i <= dot[0].x; i++){
		glVertex2f(dot[i].x, dot[i].y);
	}
	glEnd();
	glFlush();
}
void mymenu(int value){
	if (value == 1)
	{
		HWND s = FindWindow(NULL, "神秘之旅");
		DestroyWindow(s);
		display1();
	}
}
void botton(){


	char  x1[50], x2[50], stepp[50], fun[100];
	double r1, r2, step;

	InputBox(x1, 50, "请输入x的范围最小值");
	InputBox(x2, 50, "请输入x的范围最大值");
	InputBox(stepp, 50, "请输入步长");
	InputBox(fun, 100, "请输入方程");

	sscanf_s(x1, "%lf", &r1);
	sscanf_s(x2, "%lf", &r2);
	sscanf_s(stepp, "%lf", &step);
	sprintf_s(fun, "%s%s", fun, "\n");
	dot = analyzeFunction(r1, r2, step, fun);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("神秘之旅");
	glutDisplayFunc(func);
	
	glutReshapeFunc(changeSize);
	HWND hWnd = ::FindWindow(NULL, "神秘之旅");
	HINSTANCE hInstance;

	HWND funcname = ::CreateWindowA("Static", "", WS_CHILD | WS_VISIBLE | WS_HSCROLL, 0, 0, 200, 35, hWnd, NULL, NULL, NULL);
	//创建编辑框，hWnd是父窗口句柄,hInstance是程序句柄 

	ShowWindow(funcname, SW_SHOW);
	//显示编辑框 

	::SetWindowText(funcname, fun);

	
	glutCreateMenu(mymenu);
	glutAddMenuEntry("关闭", 1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
}