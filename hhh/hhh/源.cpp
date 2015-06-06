//该程序的作用是在一个黑色的窗口中央画一个白色的矩形。下面对各行语句进行说明。
//首先，需要包含头文件#include <GL/glut.h>，这是GLUT的头文件。
//本来OpenGL程序一般还要包含<GL / gl.h>和<GL / glu.h>，但GLUT的头文件中已经自动将这两个文件包含了，不必再次包含。

//在glutDisplayFunc函数中，我们设置了“当需要画图时，请调用myDisplay函数”。于是myDisplay函数就用来画图。观察myDisplay中的三个函数调用，发现它们都以gl开头。这种以gl开头的函数都是OpenGL的标准函数，下面对用到的函数进行介绍。

#include <GL/glut.h>

void myDisplay(void)

{

	glClear(GL_COLOR_BUFFER_BIT); //1、glClear，清除。GL_COLOR_BUFFER_BIT表示清除颜色，glClear函数还可以清除其它的东西，但这里不作介绍。
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); //2、glRectf，画一个矩形。四个参数分别表示了位于对角线上的两个点的横、纵坐标。
	glFlush(); //3、glFlush，保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）。其作用跟fflush(stdout)类似。

}

int main(int argc, char *argv[]) //注意main函数中的各语句，除了最后的return之外，其余全部以glut开头。这种以glut开头的函数都是GLUT工具包所提供的函数，下面对用到的几个函数进行介绍。
{
	glutInit(&argc, argv); //1、glutInit，对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次。其格式比较死板，一般照抄这句glutInit(&argc, argv)就可以了。
	
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //2、 glutInitDisplayMode，设置显示方式，其中GLUT_RGB表示使用RGB颜色，与之对应的还有GLUT_INDEX（表示使用索引颜色）。GLUT_SINGLE表示使用单缓冲，与之对应的还有GLUT_DOUBLE（使用双缓冲）。更多信息，请自己Google。当然以后的教程也会有一些讲解。
	
	glutInitWindowPosition(100, 100); //3、glutInitWindowPosition，这个简单，设置窗口在屏幕中的位置。
	
	glutInitWindowSize(400, 400); //4、glutInitWindowSize，这个也简单，设置窗口的大小。
	
	glutCreateWindow("第一个OpenGL程序"); //5、glutCreateWindow，根据前面设置的信息创建窗口。参数将被作为窗口的标题。注意：窗口被创建后，并不立即显示到屏幕上。需要调用glutMainLoop才能看到窗口。
	
	glutDisplayFunc(&myDisplay); //6、glutDisplayFunc，设置一个函数，当需要进行画图时，这个函数就会被调用。（这个说法不够准确，但准确的说法可能初学者不太好理解，暂时这样说吧）。

	glutMainLoop(); //7、glutMainLoop，进行一个消息循环。（这个可能初学者也不太明白，现在只需要知道这个函数可以显示窗口，并且等待窗口关闭后才会返回，这就足够了。）

	return 0;

}