#include <GL/glut.h>
#include<math.h>
#define PI 3.1415927



void sin(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(0.001f, 1.0f, 1.0f);//����
	glBegin(GL_LINE_STRIP /* ��������������ϣ����ģʽ */);
	float x, y;
	for (x = 0; x <= 360; x++){
		y = sin(x*PI / 180);
		glVertex2f(x, y);

	}
	//glVertex2f(0.0f, 0.0f);/* ������ʹ��glVertex*ϵ�к��� */
	//glVertex2f(0.5f, 0.0f);/* ָ������ϣ���Ķ���λ�� */
	//glVertex2f(0.0f, 0.5f);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("glBegin");
	glutDisplayFunc(sin);
	glutMainLoop();
	return 0;

}