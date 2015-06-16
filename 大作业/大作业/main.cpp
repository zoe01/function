#include<stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
typedef struct points
{
	double x;
	double y;
}point;
extern point* analyzeFunction();

point *dot;

//void changeSize(int w, int h) {
//
//	// Prevent a divide by zero, when window is too short
//	// (you cant make a window of zero width).
//	if (h == 0)
//		h = 1;
//	float ratio = w * 1.0 / h;
//	// Use the Projection Matrix
//	glMatrixMode(GL_PROJECTION);
//
//	// Reset Matrix
//	glLoadIdentity();
//
//	// Set the viewport to be the entire window
//	glViewport(0, 0, w, h);
//
//	// Set the correct perspective.
//	gluPerspective(45, ratio, 1, 100);
//
//	// Get Back to the Modelview
//	glMatrixMode(GL_MODELVIEW);
//}
void func()
{
	
	//dot = analyzeFunction();
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(0.01f, 0.001f, 1.0f);//缩放
	glBegin(GL_LINE_STRIP /* 在这里填上你所希望的模式 */);
	for (int i = 1; i <= dot[0].x; i++){
		//printf("%lf %lf\n", dot[i].x, dot[i].y);
		glVertex2f(dot[i].x, dot[i].y);

	}
	//glVertex2f(0.0f, 0.0f);/* 在这里使用glVertex*系列函数 */
	//glVertex2f(0.5f, 0.0f);/* 指定你所希望的顶点位置 */
	//glVertex2f(0.0f, 0.5f);
	glEnd();
	glFlush();
}
int main(int argc, char *argv[])
{
	dot = analyzeFunction();
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("glBegin");
	
	glutDisplayFunc(func);
	//glutReshapeFunc(changeSize);

	glutMainLoop();
	return 0;
}


