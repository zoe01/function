#include<stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
typedef struct points
{
	double x;
	double y;
}point;
extern point* analyzeFunction();



void sin()
{
	point *dot;
	dot = analyzeFunction();
	glClear(GL_COLOR_BUFFER_BIT);
	//glScalef(0.003f, 1.0f, 1.0f);//����
	glBegin(GL_LINE_STRIP /* ��������������ϣ����ģʽ */);
	for (int i = 1; i <= dot[0].x; i++){
		//printf("%lf %lf\n", dot[i].x, dot[i].y);
		glVertex2f(dot[i].x, dot[i].y);

	}
	//glVertex2f(0.0f, 0.0f);/* ������ʹ��glVertex*ϵ�к��� */
	//glVertex2f(0.5f, 0.0f);/* ָ������ϣ���Ķ���λ�� */
	//glVertex2f(0.0f, 0.5f);
	glEnd();
	glFlush();
}
int main(int argc, char *argv[])
{
	//point *dot;
	//dot = analyzeFunction();
	/*int i;
	for (i = 1; i <= dot[0].x; i++){
		printf("%lf %lf\n", dot[i].x, dot[i].y);
	}*/
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("glBegin");
	glutDisplayFunc(sin);
	glutMainLoop();
	return 0;
}


