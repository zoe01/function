//�ó������������һ����ɫ�Ĵ������뻭һ����ɫ�ľ��Ρ�����Ը���������˵����
//���ȣ���Ҫ����ͷ�ļ�#include <GL/glut.h>������GLUT��ͷ�ļ���
//����OpenGL����һ�㻹Ҫ����<GL / gl.h>��<GL / glu.h>����GLUT��ͷ�ļ����Ѿ��Զ����������ļ������ˣ������ٴΰ�����

//��glutDisplayFunc�����У����������ˡ�����Ҫ��ͼʱ�������myDisplay������������myDisplay������������ͼ���۲�myDisplay�е������������ã��������Ƕ���gl��ͷ��������gl��ͷ�ĺ�������OpenGL�ı�׼������������õ��ĺ������н��ܡ�

#include <GL/glut.h>

void myDisplay(void)

{

	glClear(GL_COLOR_BUFFER_BIT); //1��glClear�������GL_COLOR_BUFFER_BIT��ʾ�����ɫ��glClear������������������Ķ����������ﲻ�����ܡ�
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); //2��glRectf����һ�����Ρ��ĸ������ֱ��ʾ��λ�ڶԽ����ϵ�������ĺᡢ�����ꡣ
	glFlush(); //3��glFlush����֤ǰ���OpenGL��������ִ�У��������������ڻ������еȴ����������ø�fflush(stdout)���ơ�

}

int main(int argc, char *argv[]) //ע��main�����еĸ���䣬��������return֮�⣬����ȫ����glut��ͷ��������glut��ͷ�ĺ�������GLUT���߰����ṩ�ĺ�����������õ��ļ����������н��ܡ�
{
	glutInit(&argc, argv); //1��glutInit����GLUT���г�ʼ�����������������������GLUTʹ��֮ǰ����һ�Ρ����ʽ�Ƚ����壬һ���ճ����glutInit(&argc, argv)�Ϳ����ˡ�
	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //2�� glutInitDisplayMode��������ʾ��ʽ������GLUT_RGB��ʾʹ��RGB��ɫ����֮��Ӧ�Ļ���GLUT_INDEX����ʾʹ��������ɫ����GLUT_SINGLE��ʾʹ�õ����壬��֮��Ӧ�Ļ���GLUT_DOUBLE��ʹ��˫���壩��������Ϣ�����Լ�Google����Ȼ�Ժ�Ľ̳�Ҳ����һЩ���⡣
	
	glutInitWindowPosition(100, 100); //3��glutInitWindowPosition������򵥣����ô�������Ļ�е�λ�á�
	
	glutInitWindowSize(400, 400); //4��glutInitWindowSize�����Ҳ�򵥣����ô��ڵĴ�С��
	
	glutCreateWindow("��һ��OpenGL����"); //5��glutCreateWindow������ǰ�����õ���Ϣ�������ڡ�����������Ϊ���ڵı��⡣ע�⣺���ڱ������󣬲���������ʾ����Ļ�ϡ���Ҫ����glutMainLoop���ܿ������ڡ�
	
	glutDisplayFunc(&myDisplay); //6��glutDisplayFunc������һ������������Ҫ���л�ͼʱ����������ͻᱻ���á������˵������׼ȷ����׼ȷ��˵�����ܳ�ѧ�߲�̫����⣬��ʱ����˵�ɣ���

	glutMainLoop(); //7��glutMainLoop������һ����Ϣѭ������������ܳ�ѧ��Ҳ��̫���ף�����ֻ��Ҫ֪���������������ʾ���ڣ����ҵȴ����ڹرպ�Ż᷵�أ�����㹻�ˡ���

	return 0;

}