// Include the necessary libraries for OpenGL, math, windows, and sound
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

// Declare some global variables for the position, rotation, and score of the cat
float fXPos = 0, fYPos = 0, fRot = 0, j = 0, mx = 0, my = 0, c1 = -190, c2 = 100;

// Set up the transformations for the OpenGL window
void SetTransformations() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0, 476, 660, 0);
}

// Define the display function for the OpenGL window and move function
void OnDisplay();
void move();


// needed shapes that help me to draw like Circles and oval
// Define a function to draw a filled circle with a given center and radius
void drawFilledCircle(GLfloat a, GLfloat b, GLfloat radius) {

    float PI = 3.14;
    int triangleAmount = 36; //# of triangles used to draw circle

    GLfloat twicePi = 2.0 * PI;
    glEnable(GL_LINE_SMOOTH);
    glBegin(GL_POLYGON);
    //glVertex2f(a, b); // center of circle
    for (int i = 0; i <= triangleAmount; i++) {

        float theta = i * twicePi / triangleAmount;  //get the current angle
        glVertex2f(                  //glVertex2f(x,y)
                a + (radius * cos(theta)),
                b + (radius * sin(theta))
        );
    }
    glEnd();
}

// Define a function to draw stars with a given center and radius
void drawstars(GLfloat a, GLfloat b, GLfloat radius) {
    glPushMatrix();
    glRotatef(j += 0.0001, 0, 0, 1);
    float PI = 3.14;
    int triangleAmount = 15; //# of triangles used to draw circle

    GLfloat twicePi = 2.0 * PI;
    glEnable(GL_LINE_SMOOTH);
    glPointSize(0.3);
    glBegin(GL_POINTS);
    for (int i = 0; i <= triangleAmount; i++) {

        float theta = i * twicePi / triangleAmount;
        glVertex2f(
                a + (radius * cos(theta)),
                b + (radius * sin(theta))
        );
    }
    glEnd();
    glPopMatrix();
}

// Define a function to draw an oval with a given center and radius
void oval(GLfloat a, GLfloat b, GLfloat radius) {

    float PI = 3.14;
    int triangleAmount = 36;

    GLfloat twicePi = 2.0 * PI;
    glEnable(GL_LINE_SMOOTH);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= triangleAmount; i++) {

        float theta = i * twicePi / triangleAmount;
        glVertex2f(
                a + (radius * cos(theta)),
                b + (radius * 2.5 * sin(theta))
        );
    }
    glEnd();
}

// Define a function to draw a hollow circle with a given center and radius
void drawHollowCircle(GLfloat a, GLfloat b, GLfloat radius) {

    float PI = 3.14;
    int lineAmount = 100; //# of Lines used to draw circle

    GLfloat twicePi = 2.0f * PI;
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);

    for (int i = 0; i <= lineAmount; i++) {

        float theta = i * twicePi / lineAmount;

        glVertex2f(
                a + (radius * cos(theta)),
                b + (radius * sin(theta))
        );
    }
    glEnd();
}


// Define a function to draw the background for the scene
void background() {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3ub(23, 42, 38);
    glVertex3f(476, 0, 0);
    glVertex3f(0, 0, 0);
    glColor3ub(41, 70, 65);
    glVertex3f(476, 330, 0);
    glVertex3f(0, 330, 0);
    glColor3ub(41, 70, 65);
    glVertex3f(476, 330, 0);
    glVertex3f(0, 330, 0);
    glColor3ub(42, 86, 50);
    glVertex3f(476, 660, 0);
    glVertex3f(0, 660, 0);
    glEnd();
}

// drawing the cat.
// Define a function to draw a small triangle for the cat's nose
void small_triangle() {
    glColor3ub(204, 136, 153);
    glBegin(GL_TRIANGLES);
    glVertex3f(211, 220, 0);
    glVertex3f(251, 220, 0);
    glVertex3f(234, 245, 0);
    glEnd();
    //BORD
    glColor3f(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(211, 220, 0);
    glVertex3f(251, 220, 0);
    glVertex3f(234, 245, 0);
    glEnd();
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor4f(0, 0, 0, 1);
    glVertex2f(234, 245);
    glVertex2f(234, 275);
    glEnd();
    glColor3f(1, 0.498039215686275, 0);
}

// Define a function to draw some lines for the cat's body and face
void lines() {
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(10);
    glColor4f(0, 0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(245, 128);
    glVertex2f(245, 82);
    glVertex2f(229, 81);
    glVertex2f(229, 136);
    glVertex2f(213, 82);
    glVertex2f(213, 128);
    glVertex2f(355, 204);
    glVertex2f(318, 204);
    glVertex2f(309, 221);
    glVertex2f(354, 221);
    glVertex2f(318, 235);
    glVertex2f(350, 235);
    glVertex2f(113, 207);
    glVertex2f(152, 207);
    glVertex2f(160, 224);
    glVertex2f(113, 224);
    glVertex2f(117, 238);
    glVertex2f(152, 238);
    glEnd();
}

// Define a function to draw the body of the cat
void body() {
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(234, 322, 0);
    glVertex3f(372, 610, 0);
    glVertex3f(98, 610, 0);
    glEnd();
    //BORD
    glColor4f(0, 0, 0, 1);
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(234, 322, 0);
    glVertex3f(372, 610, 0);
    glVertex3f(98, 610, 0);
    glEnd();
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(15);
    glBegin(GL_LINES);
    glColor4f(0, 0, 0, 1);
    glVertex2f(270, 396);
    glVertex2f(200, 396);
    glVertex2f(307, 474);
    glVertex2f(163, 474);
    glVertex2f(346, 555);
    glVertex2f(125, 555);
    glEnd();
    //feet
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(178, 531, 0);
    glVertex3f(221, 610, 0);
    glVertex3f(130, 610, 0);
    glEnd();
    //BORD
    glColor4f(0, 0, 0, 1);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(178, 531, 0);
    glVertex3f(221, 610, 0);
    glVertex3f(130, 610, 0);
    glEnd();
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(282, 531, 0);
    glVertex3f(328, 610, 0);
    glVertex3f(237, 610, 0);
    glEnd();
    //BORD
    glColor4f(0, 0, 0, 1);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(282, 531, 0);
    glVertex3f(328, 610, 0);
    glVertex3f(237, 610, 0);
    glEnd();
}

// Define a function to draw the tail of the cat
void tail() {
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(430, 475, 0);
    glVertex3f(372, 611, 0);
    glVertex3f(332, 533, 0);
    glEnd();
    //BORD
    glColor4f(0, 0, 0, 1);
    glLineWidth(5.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(430, 475, 0);
    glVertex3f(372, 611, 0);
    glVertex3f(332, 533, 0);
    glEnd();
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(9);
    glBegin(GL_LINES);
    glColor4f(0, 0, 0, 1);
    glVertex2f(397, 492);
    glVertex2f(411, 520);
    glVertex2f(394, 559);
    glVertex2f(365, 512);
    glEnd();
}

// Define a function to draw the face and mouth of the cat
void face_mouth() {
    glEnable(GL_LINE_SMOOTH);
    drawFilledCircle(232, 240, 36);
    glColor3f(1, 0.498039215686275, 0);
    drawFilledCircle(230, 230, 40);
    glPushMatrix();
    glTranslatef(mx, my, 0);
    glColor3ub(1, 1, 1);
    glEnable(GL_LINE_SMOOTH);
    drawHollowCircle(232, 240, 33);
    glPopMatrix();
    glColor3f(1, 0.498039215686275, 0);
    drawFilledCircle(230, 230, 40);
}

// Define a function to draw the face of the cat
void Face() {
    glColor4f(0, 0, 0, 1);
    glEnable(GL_LINE_SMOOTH);
    drawFilledCircle(282, 170, 32);
    glColor3ub(255, 255, 255);
    drawFilledCircle(282, 170, 29);
    glColor4f(0, 0, 0, 1);
    glPushMatrix();
    move();
    oval(283, 170.9, 12.5);
    glColor3f(0.419607843137255, 0.627450980392157, 0.0235294117647059);
    oval(283, 170.9, 11);
    glPopMatrix();
    glPushMatrix();
    move();
    glColor4f(0, 0, 0, 1);
    oval(283, 170, 4);
    glPopMatrix();
    glColor4f(0, 0, 0, 1);
    glEnable(GL_LINE_SMOOTH);
    drawFilledCircle(189, 170, 32);
    glColor3ub(255, 255, 255);
    drawFilledCircle(189, 170, 29);
    glColor4f(0, 0, 0, 1);
    glPushMatrix();
    move();
    oval(190, 170.9, 12.5);
    glColor3f(0.419607843137255, 0.627450980392157, 0.0235294117647059);
    oval(190, 170.9, 11);
    glPopMatrix();
    glPushMatrix();
    move();
    glColor4f(0, 0, 0, 1);
    oval(190, 168, 4);
    glPopMatrix();
}

// Define a function to draw the features of the cat's face, such as eyes and nose
void face_figuer() {
    glColor4f(0, 0, 0, 1);
    drawFilledCircle(234, 201, 125);
    glColor3f(1, 0.498039215686275, 0);
    drawFilledCircle(234, 201, 120);
    Face();
}


// Define a function to draw the two ears of the cat
void two_ears() {
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(287, 91, 0);
    glVertex3f(327, 125, 0);
    glVertex3f(358, 50, 0);
    glEnd();
    //BORD
    glColor4f(0, 0, 0, 1);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(287, 91, 0);
    glVertex3f(327, 125, 0);
    glVertex3f(358, 50, 0);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(327, 84, 0);
    glVertex3f(317, 117, 0);
    glVertex3f(302, 102, 0);
    glEnd();
    glColor3f(1, 0.498039215686275, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(97, 59, 0);
    glVertex3f(175, 94, 0);
    glVertex3f(137, 130, 0);
    glEnd();
    //BORD
    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(97, 59, 0);
    glVertex3f(175, 94, 0);
    glVertex3f(137, 130, 0);
    glEnd();
    glColor3ub(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex3f(136, 93, 0);
    glVertex3f(148, 121, 0);
    glVertex3f(162, 104, 0);
    glEnd();
}

// Define a function to draw some stars in the background
void stars() {
    glColor3ub(255, 255, 255);
    drawstars(228, 113, 230);
    glColor3ub(255, 255, 255);
    drawstars(234, 59, 200);
    glColor3ub(255, 255, 255);
    drawstars(234, 59, 120);
    glColor3ub(255, 255, 255);
    glPointSize(0.3);
    glPushMatrix();
    glRotatef(j += 0.0001, 0, 0, 1);
    glBegin(GL_POINTS);
    glVertex3f(201, 50, 0);
    glVertex3f(242, 37, 0);
    glVertex3f(133, 402, 0);
    glVertex3f(338, 402, 0);
    glVertex3f(221, 640, 0);
    glVertex3f(319, 641, 0);
    glVertex3f(112, 635, 0);
    glVertex3f(319, 641, 0);
    glVertex3f(458, 618, 0);
    glVertex3f(294, 383, 0);
    glVertex3f(155, 361, 0);
    glVertex3f(19, 559, 0);
    glPopMatrix();
    glColor3ub(255, 255, 255);
    drawstars(235, 340, 230);
    glColor3ub(255, 255, 255);
    drawstars(235, 340, 200);
    glColor3ub(255, 255, 255);
    drawstars(235, 340, 170);
    glColor3ub(255, 255, 255);
    drawstars(230, 585, 170);
}

// Define a function to draw the first part of the Santa Claus
void babnoel1() {
    glPushMatrix();
    glTranslatef(c1 += 0.1, c2, 0);
    if (c1 >= 302.401) c1 = -190;
    glColor3ub(255, 46, 46);
    glBegin(GL_TRIANGLES);
    glVertex3f(271, 82, 0);
    glVertex3f(192, 82, 0);
    glVertex3f(230, 15, 0);
    glEnd();
}

// Define a function to draw the second part of the Santa Claus
void babnoel2() {
    glColor3ub(163, 61, 104);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
    glColor3ub(245, 245, 245);
    drawFilledCircle(198, 74, 10);
    drawFilledCircle(205, 76, 10);
    drawFilledCircle(220, 76, 10);
    drawFilledCircle(235, 76, 10);
    drawFilledCircle(250, 76, 10);
    drawFilledCircle(262, 76, 10);
    drawFilledCircle(230, 16, 14);
    glPopMatrix();
}


// Define the display function for the OpenGL window
void OnDisplay() {
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    SetTransformations();
    background();
    babnoel1();
    babnoel2();
    stars();
    two_ears();
    body();
    face_figuer();
    face_mouth();
    lines();
    tail();
    small_triangle();
    glFlush();
    glutSwapBuffers();

}

// Define a function to move the cat according to the keyboard input
void move() {
    glTranslatef(fXPos, fYPos, 0);
    glRotatef(fRot, 0, 0, 1);
}

// Define a function to handle the keyboard input for the cat
void OnKeyPress(unsigned char key, int x, int y) {
    switch (key) {
    };
}

// Define a function to handle the special keyboard input for the cat
void OnSpecialKeyPress(int key, int x, int y) {

    if (key == GLUT_KEY_LEFT) {
        fXPos = -4;
    }
    if (key == GLUT_KEY_RIGHT) {
        fXPos = 4;
    }
    if (key == GLUT_KEY_UP && my > -10) {
        my = 0;
    }
    if (key == GLUT_KEY_DOWN) {
        if (my <= 10.5) {
            my = 11;
            PlaySound("D:\\mymeoow.wav", NULL, SND_ASYNC); //sound file path

        }


    }

}

// Initialize the graphics for the OpenGL window
void InitGraphics(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowPosition(550, 36);
    glutInitWindowSize(476, 660);
    glutCreateWindow("Cat in Space");
    glutDisplayFunc(OnDisplay);
    glutIdleFunc(OnDisplay);
    glutKeyboardFunc(OnKeyPress);
    glutSpecialFunc(OnSpecialKeyPress);
    SetTransformations();
    glutMainLoop();
}

// Define the main function for the program
int main(int argc, char *argv[]) {
    InitGraphics(argc, argv);
    return 0;
}
