#include "Model_3DS.h"
#include "GLTexture.h"
#include <glut.h>

#include <math.h>

void renderScene(void);
void moveCamera(void);
void drawWall(float, float, GLTexture);
void keyboard(unsigned char key, int x, int y);
void SpecialInput(int key, int x, int y);

int WIDTH = 1000;
int HEIGHT = 700;
float xEye = 0;
float yEye = 0;
float zEye = 1;
float xCenter = 0;
float yCenter = 0;
float zCenter = 0;
GLTexture tex_ground;
GLTexture tex_wall;
GLTexture tex_ceiling;
GLTexture tex_wall2;


void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    renderScene();
	//glColor3f(1, 0, 0);
	/*glPushMatrix();
	    glTranslatef(0, -1, -2);

	glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 7);
    drawWall(1, 1);
    glPopMatrix();
	glPopMatrix();*/
    
    glFlush();
}

void renderScene() {
    glColor3f(1, 1, 1);
    
    glPushMatrix();
    glTranslatef(0, -1, -2);
    
//    glTranslatef(-6, 0, -3);
//    glRotatef(-90, 0, 1, 0);
    

    glPushMatrix();
    glScalef(2, 1, 1);

    
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glScalef(1, 1, 7);
    drawWall(1, 1, tex_ground);
    glPopMatrix();
    
    //glColor3f(1, 0, 0);
    
    glPushMatrix();
    glTranslatef(0, 1, -12);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall);
    glPopMatrix();
    
    //glColor3f(0, 1, 0);
    
    
    glPushMatrix();
    glTranslatef(-1, 1, -9);
    glScalef(1, 1, 3);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall);
    glPopMatrix();
    
    //
    glPushMatrix();
    glTranslatef(-1, 1, -1.5f);
    glScalef(1, 1, 3.5f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    drawWall(1, 1, tex_wall);
    glPopMatrix();
    
    
    //glColor3f(0, 0, 1);
    
    glPushMatrix();
    glTranslatef(1, 1, -9);
    glScalef(1, 1, 3);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(1, 1, -1.5f);
    glScalef(1, 1, 3.5f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall);
    glPopMatrix();
    
    //glColor3f(0.5, 0.1, 0.7);
    glPushMatrix();
    glTranslatef(0, 2, -5);
    glScalef(1, 1, 7);
	drawWall(1, 1, tex_ceiling);
    glPopMatrix();
    
    glPopMatrix();
    
    
    //draw room 1
    //glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-3, 0, -5.5f);
    drawWall(1, 1, tex_ground);
    glPopMatrix();
    
   // glColor3f(0, 1, 1);
    glPushMatrix();
    glTranslatef(-3, 1, -6.5f);
    glRotatef(90, 1, 0, 0);
    drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-3, 1, -4.5f);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    //glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(-4, 1, -5.5f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    //glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(-3, 2, -5.5f);
	drawWall(1, 1, tex_ceiling);
    glPopMatrix();
    
    
    
    // draw room 2
    
    //glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(3, 0, -5.5f);
    drawWall(1, 1, tex_ground);
    glPopMatrix();
    
    //glColor3f(0, 1, 1);
    glPushMatrix();
    glTranslatef(3, 1, -6.5f);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(3, 1, -4.5f);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    //glColor3f(1, 1, 0);
    glPushMatrix();
    glTranslatef(4, 1, -5.5f);
    glRotatef(90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
	drawWall(1, 1, tex_wall2);
    glPopMatrix();
    
    //glColor3f(0, 0, 0);
    glPushMatrix();
    glTranslatef(3, 2, -5.5f);
	drawWall(1, 1, tex_ceiling);
    glPopMatrix();

    
    
    
    
    glPopMatrix();
}

void drawWall(float x, float y, GLTexture texture) {

	glEnable(GL_TEXTURE_2D);	// Enable 2D texturing

	glBindTexture(GL_TEXTURE_2D, texture.texture[0]);	
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
	glTexCoord2f(0, 0);		
    glVertex3f(-x, 0, -y);
	glTexCoord2f(5, 0);	
    glVertex3f(x, 0, -y);
	glTexCoord2f(5, 5);	
    glVertex3f(x, 0, y);
	glTexCoord2f(0, 5);	
    glVertex3f(-x, 0, y);
    glEnd();
}

void moveCamera() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0f, WIDTH / HEIGHT, 0.1f, 300.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xEye, yEye, zEye, xCenter, yCenter, zCenter, 0.0f, 1.0f, 0.0f);
}

void keyboard(unsigned char key, int x, int y) {
    
    
    
}

void LoadAssets()
{

	// Loading texture files
	tex_wall.Load("Textures/roughwall_2c.bmp");
	tex_wall2.Load("Textures/roughwall_3d.bmp");
	tex_ceiling.Load("Textures/wall.bmp");
	tex_ground.Load("Textures/horizontal.bmp");
}

float xAngle = 0;
float yAngle = 0;
void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            zCenter-=0.1;
            zEye-=0.1;
            break;
        case GLUT_KEY_DOWN:
            zCenter+=0.1;
            zEye+=0.1;
            break;
        case GLUT_KEY_LEFT:
            
            //xCenter = zCenter;
            xAngle += 0.01;
            yAngle += 0.01;
//            xCenter = xCenter + 0.01 * sin(xAngle);
//            zCenter = zCenter + 0.01 *cos(yAngle);
//            xCenter = xEye;
//            zCenter = zEye;
            xEye = 0.01 * sin(xAngle);
            zEye = 0.01 * cos(yAngle);
            
            

            
            
            break;
        case GLUT_KEY_RIGHT:
            //do something here
            break;
    }
    
}


void Anim() {
    //if (zEye > 0) {
        //zEye-=0.01;
    //} else {
        //zEye += 0.01;
    //}
    //zEye-=0.01;
    moveCamera();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(150, 150);
    
    glutCreateWindow("OpenGL - 3D Template");
    glutDisplayFunc(Display);
    glutIdleFunc(Anim);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(SpecialInput);

    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    
    glEnable(GL_DEPTH_TEST);

	LoadAssets();
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, WIDTH / HEIGHT, 0.1f, 300.0f);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glutMainLoop();
}