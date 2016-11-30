#include<stdio.h>
#include<stdlib.h>
#include<gl\glut.h>
#include<math.h>
#define PI 3.1415926
int width = 800;
int height = 800;

void Render();
void Reshape(int w, int h);
void SetupViewTransform();
void SetupViewVolume();
void DrawBox();
void DrawWall();
void KeyboardFunc(unsigned char key, int x, int y);
void collide();

int angle;
int distance_x;
int distance_y;
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("CarGame");
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardFunc);
	glutMainLoop();

	return 0;
}
void Reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	w = width;
	h = height;
}
void SetupViewTransform()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -10.0);

}
void SetupViewVolume()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10, 10, -10, 10, -100, 100);
}
void Render()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetupViewTransform();
	SetupViewVolume();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	{

		glTranslatef(5, 5, 0);
		DrawWall();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-2, 5, 0);
		DrawWall();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-7, 7, 0);
		DrawWall();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(-4, -3, 0);
		DrawWall();
	}
	glPopMatrix();

	glPushMatrix();
	{

		glTranslatef(distance_x, distance_y, 0);
		//glRotatef(angle, 0.0, 0.0, 1.0);
		DrawBox();
	}
	glPopMatrix();
	glutSwapBuffers();
}

void DrawBox() {
	glColor3f(0.5f, 1.0f, 0.5f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(-1.0, 1.0, 0.0);
	glEnd();
}
void KeyboardFunc(unsigned char key, int x, int y)
{
	if (key == 'd')
	{
		distance_x += 1;
	}
	if (key == 'a')
	{
		distance_x -= 1;
	}
	if (key == 'w')
	{
		distance_y += 1;
	}
	if (key == 's')
	{
		distance_y -= 1;
	}
	if (key == 'k')
	{
		angle += 5;
	}
	if (key == 'j')
	{
		angle -= 5;
	}
	glutPostRedisplay();
}
void DrawWall()
{
	glColor3f(0.5f, 1.0f, 0.5f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(-2.0, 1.0, 0.0);
	glEnd();
}
void collide()
{

}