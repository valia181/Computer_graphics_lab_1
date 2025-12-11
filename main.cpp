#include <GL/glut.h>
#include <cstdio>

float posX = 0.0f;
float posY = 0.0f;

const float speedX = 0.05f;
const float speedY = 0.1f;

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glColor3f(1.0f, 0.6f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    glColor3f(1.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void drawBird() {
    glPushMatrix();

    glTranslatef(posX, posY, 0.0f);

    drawTriangle(-0.3f, 0.4f, -0.15f, 0.5f, -0.15f, 0.4f);

    drawQuad(-0.15f, 0.5f,  -0.05f, 0.4f,  -0.05f, 0.25f,  -0.15f, 0.35f);

    drawQuad(-0.15f, 0.35f,  -0.05f, 0.25f,  -0.15f, 0.15f,  -0.25f, 0.25f);

    drawTriangle(-0.15f, 0.15f, 0.0f, 0.3f, 0.15f, 0.15f);

    drawTriangle(-0.15f, 0.15f, 0.1f, 0.15f, 0.1f, -0.1f);

    drawTriangle(0.05f, -0.05f, 0.2f, -0.2f, 0.05f, -0.35f);

    drawTriangle(0.1f, -0.3f, 0.1f, -0.45f, -0.05f, -0.45f);

    glPopMatrix();
}

void display() {
    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    drawBird();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    printf("Key: %c \n", key);

    switch (key) {
        case 'w': case 'W':
            posY += speedY;
            break;
        case 's': case 'S':
            posY -= speedY;
            break;
        case 'a': case 'A':
            posX -= speedX;
            break;
        case 'd': case 'D':
            posX += speedX;
            break;
        case 27:
            exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Lab 1: Tangram Bird");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutMainLoop();
    return 0;
}