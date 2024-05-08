#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "iostream"
#include <time.h>
#include <random>
using namespace std;



GLfloat cameraPosX = 0.4, cameraPosY = 0.4, cameraPosZ = 2.0;
GLfloat lookAtX = 0.4, lookAtY = 0.4, lookAtZ = 0.0;
GLfloat upX = 0.0, upY = 1.0, upZ = 0.0;

GLfloat cameraSpeed = 0.1;

bool ctrl=true;

void setCamera() {
    gluLookAt(cameraPosX, cameraPosY, cameraPosZ,
              lookAtX, lookAtY, lookAtZ,
              upX, upY, upZ);
}

int input_no=0;
bool start = false;
bool flag = true;
bool fullscreen = false;
GLfloat xRotated, yRotated, zRotated;



void check(int value)
{
    if(ctrl){
        if (flag == true)
        {
            flag = false;
        }
        else if (flag == false)
        {
            flag = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(1000, check, 0);
}



void highlight_lines(float x, float y, float z, float live_transparency_line,float output,int no)
{
    float c1,c2,c3;
    switch(no){
        case 0:
            c1=1.0;
            c2=0.0;
            c3=0.0;
            break;
        case 1:
            c1=1.0;
            c2=0.5;
            c3=0.0;
            break;
        case 2:
            c1=1.0;
            c2=0.84;
            c3=0.0;
            break;
        case 3:
            c1=0.0;
            c2=1.0;
            c3=0.0;
            break;
        case 4:
            c1=0.0;
            c2=0.4;
            c3=0.0;
            break;
        case 5:
            c1=0.0;
            c2=1.0;
            c3=1.0;
            break;
        case 6:
            c1=0.29;
            c2=0.0;
            c3=0.51;
            break;
        case 7:
            c1=0.5;
            c2=0.0;
            c3=1.0;
            break;
        case 8:
            c1=1.0;
            c2=0.0;
            c3=1.0;
            break;
        case 9:
            c1=1.0;
            c2=0.0;
            c3=0.5;
            break;
    }
    float a, b, c;
    for (float i = 0; i <= 0.5; i = i + 0.1)
    {
        for (float j = 0; j <= 0.5; j = j + 0.1)
        {
            for (float k = 0; k <= 0.5; k = k + 0.1)
            {
                //First Hidden Layer Plane 1
                a=i+0.2;
                b=j+0.2;
                c=k+0.2;
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(x, y, z);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();

                //First Hidden Layer Plane 4
                if (k < 0.44)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(x, y, z);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                    glVertex3f(x, y, z);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                }

                //Second Hidden Layer Plane 1
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();

                //output layer
                glPointSize(15.0);
                glBegin(GL_POINTS);
                glColor4f(0.0, 0.0, 1.0, 1.0);
                glVertex3f(output, 0.55, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.8);
                glVertex3f(output, 0.55, 1.2);
                glVertex3f(output, 0.55, 1.2);
                glEnd();

            }
        }
    }
}

void display0(float live_transparency_line,float output){
    

    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(1.0, 0.0, 0.0, 1.0);


    glVertex3f(0.4, 0.3, 0.0);
     glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);

    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);


    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);


    glVertex3f(0.7, 0.3, 0.0);
     glVertex3f(0.7, 0.4, 0.0);
    glVertex3f(0.7, 0.5, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,0);
     highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,0);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output,0);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,0);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,0);


    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,0);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,0);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,0);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,0);

    highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,0);
     highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output,0);
    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output,0);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,0);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,0);


    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,0);
    highlight_lines(0.5, 0.6, 0.0, live_transparency_line, output,0);
}
void display1(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(1.0, 0.5, 0.0, 1.0);

    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.3, 0.0);
    glVertex3f(0.6, 0.4, 0.0);
    glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.6, 0.0);
    glVertex3f(0.6, 0.7, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.7, 0.2, 0.0);
//                     glVertex3f(0.7, 0.2, 0.0);

    glVertex3f(0.7, 0.7, 0.0);
//                     glVertex3f(0.7, 0.6, 0.0);
//                     glVertex3f(0.3, 0.2, 0.0);
    glEnd();

    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.3, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.4, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.6, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.7, 0.0, live_transparency_line, output,1);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,1);

    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,1);
    highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output,1);
//                     highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output,1);
//                     highlight_lines(0.3, 0.2, 0.0, live_transparency_line, output,1);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,1);
//                     highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,1);
}
void display2(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(1.0, 0.84, 0.0, 1.0);



    glVertex3f(0.7, 0.7, 0.0);
    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(0.5, 0.8, 0.0);
    glVertex3f(0.4, 0.7, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.6, 0.4, 0.0);

//                     glVertex3f(0.3, 0.2, 0.0);
    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.7, 0.2, 0.0);
//                     glVertex3f(0.8, 0.2, 0.0);
    
    glVertex3f(0.7, 0.3, 0.0);
    glEnd();

    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,2);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,2);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,2);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,2);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,2);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,2);
    highlight_lines(0.6, 0.4, 0.0, live_transparency_line, output,2);
    
//                     highlight_lines(0.3, 0.2, 0.0, live_transparency_line, output,2);
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output,2);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,2);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,2);
    highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output,2);
//                     highlight_lines(0.8, 0.2, 0.0, live_transparency_line, output,2);
    
    highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,2);
}
void display3(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(0.0, 1.0, 0.0, 1.0);

     glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);

     glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);

     glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

     glVertex3f(0.7, 0.3, 0.0);
//                     glVertex3f(0.7, 0.4, 0.0);
//                     glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,3);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,3);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,3);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,3);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,3);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,3);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,3);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,3);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,3);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,3);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,3);
//                     highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output,3);
//                     highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,3);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,3);
}
void display4(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(0.0,0.4,0.0, 1.0);

    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);
    glVertex3f(0.4, 0.8, 0.0);

    glVertex3f(0.3, 0.5, 0.0);

    glVertex3f(0.7, 0.5, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);
    glVertex3f(0.7, 0.8, 0.0);

    glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);


    glEnd();
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,4);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output,4);


    highlight_lines(0.3, 0.5, 0.0, live_transparency_line, output,4);

    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output,4);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,4);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,4);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output,4);


    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,4);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,4);
}
void display5(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(0.0,1.0,1.0, 1.0);

     glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
//                     glVertex3f(0.4, 0.5, 0.0);
//                     glVertex3f(0.4, 0.7, 0.0);
    glVertex3f(0.4,0.8,0.0);

     glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);

     glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

     glVertex3f(0.7, 0.3, 0.0);
//                     glVertex3f(0.7, 0.5, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);
    glVertex3f(0.7,0.8,0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,5);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,5);
//                     highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output,5);
//                     highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,5);
//                     highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,5);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output,5);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,5);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,5);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,5);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,5);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,5);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,5);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,5);
//                     highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output,5);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,5);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,5);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output,5);
}
void display6(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(0.29, 0.0, 0.51, 1.0);

     glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
//                     glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);

     glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);

     glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

     glVertex3f(0.7, 0.3, 0.0);
    glVertex3f(0.7, 0.4, 0.0);
    glVertex3f(0.7, 0.5, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,6);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,6);
//                     highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,6);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,6);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,6);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,6);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,6);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,6);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,6);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,6);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,6);
    highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output,6);
    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output,6);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,6);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,6);
}
void display7(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(0.5, 0.0, 1.0, 1.0);

    glVertex3f(0.4, 0.2, 0.0);
    glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);
    glVertex3f(0.4, 0.8, 0.0);

    glVertex3f(0.3, 0.5, 0.0);
//                     glVertex3f(0.5, 0.5, 0.0);

    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(0.5, 0.8, 0.0);
    glVertex3f(0.7, 0.8, 0.0);

    glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);


    glEnd();
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,7);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output,7);


    highlight_lines(0.3, 0.5, 0.0, live_transparency_line, output,7);
//                     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,7);

    
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,7);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,7);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output,7);


    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,7);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,7);
}
void display8(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(1.0, 0.0, 1.0, 1.0);

     glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);

     glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);

     glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

     glVertex3f(0.7, 0.3, 0.0);
    glVertex3f(0.7, 0.4, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,8);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,8);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,8);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,8);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,8);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,8);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,8);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,8);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,8);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,8);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,8);
    highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output,8);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,8);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,8);


}
void display9(float live_transparency_line,float output){
    glPointSize(20.0);
    glBegin(GL_POINTS);
    glColor4f(1.0, 0.0,0.5,  1.0);

    glVertex3f(0.4, 0.2, 0.0);
     glVertex3f(0.4, 0.3, 0.0);
    glVertex3f(0.4, 0.4, 0.0);
    glVertex3f(0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.6, 0.0);
    glVertex3f(0.4, 0.7, 0.0);

     glVertex3f(0.5, 0.5, 0.0);
//                    glVertex3f(0.5, 0.2, 0.0);
    glVertex3f(0.5, 0.8, 0.0);

     glVertex3f(0.6, 0.5, 0.0);
//                    glVertex3f(0.6, 0.2, 0.0);
    glVertex3f(0.6, 0.8, 0.0);

//                     glVertex3f(0.7, 0.3, 0.0);
    glVertex3f(0.7, 0.6, 0.0);
    glVertex3f(0.7, 0.7, 0.0);

    /*glVertex3f(0.6, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);*/


    glEnd();
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output,9);
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output,9);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output,9);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output,9);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output,9);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output,9);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output,9);
//                    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output,9);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output,9);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output,9);
//                    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output,9);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output,9);

//                     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output,9);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output,9);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output,9);


 
}


void displaynetwork(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    setCamera();
    glTranslatef(-0.9, -0.75, -5.0);
    glColor3f(0.8, 0.2, 0.1);

    glTranslatef(1.0,0.0,1.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glTranslatef(-1.0,0.0,-1.0);

    glScalef(1.5, 1.5, 1.5);

    float dead_transparency_line = 0.06;
    float live_transparency_line = 0.15;
    float a, b, c;
    for (a = 0; a <= 1.0; a = a + 0.1)
    {
        for (b = 0; b <= 1.0; b = b + 0.1)
        {
            for (c = 0; c <= 1.0; c = c + 0.1)
            {
               
                //Input Layer
                glPointSize(15.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glEnd();

                //First Hidden Layer Plane 1
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.4);
                glEnd();

                //First Hidden Layer Plane 2
                if (c < 0.47)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glVertex3f(0.13 + b, 0.13 + c, 0.42);
                    glEnd();
                }

                //First Hidden Layer Plane 3
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.0);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glVertex3f(0.07 + b, 0.07 + c, 0.42);
                glEnd();

                //First Hidden Layer Plane 4
                if (c < 0.44)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glVertex3f(0.17 + b, 0.16 + c, 0.44);
                    glEnd();
                }

                //Second Hidden Layer Plane 1
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.4);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glEnd();

                //Second Hidden Layer Plane 2
                if (c < 0.47)
                {
                    glPointSize(3.0);
                    glBegin(GL_POINTS);
                    glVertex3f(0.1 + b, 0.1 + a, 0.42);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glEnd();
                    glBegin(GL_LINE_LOOP);
                    glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                    glVertex3f(0.1 + b, 0.1 + a, 0.0);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glVertex3f(0.13 + b, 0.13 + c, 0.82);
                    glEnd();
                }

                //Output Layer
                glPointSize(3.0);
                glBegin(GL_POINTS);
                glColor4f(1.0, 1.0, 1.0, 0.05);
                glVertex3f(0.1 + b, 0.55, 1.2);
                glVertex3f(0.1 + b, 0.55, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + a, 0.55, 1.2);
                glVertex3f(0.1 + a, 0.55, 1.2);
                glEnd();
            }
        }
    }

    int cnt=0;
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for(float i=0;i<1.0;i=i+0.1){
        glColor3f(0.0, 1.0, 1.0);
        glRasterPos3f(0.08 + i, 0.58, 1.2);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, digits[cnt++]);
    }
    
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    if (flag == true)
        {
            
            if (start == true) {
                float output = input_no * 0.1+0.1;
                switch(input_no){
                    case 0:
                        display0(live_transparency_line,output);
                        break;
                    case 1:
                        display1(live_transparency_line,output);
                        break;
                    case 2:
                        display2(live_transparency_line,output);
                        break;
                    case 3:
                        display3(live_transparency_line,output);
                        break;
                    case 4:
                        display4(live_transparency_line,output);
                        break;
                    case 5:
                        display5(live_transparency_line,output);
                        break;
                    case 6:
                        display6(live_transparency_line,output);
                        break;
                    case 7:
                        display7(live_transparency_line,output);
                        break;
                    case 8:
                        display8(live_transparency_line,output);
                        break;
                    case 9:
                        display9(live_transparency_line,output);
                        break;
                }
            }
        }
    glFlush();
    glDisable(GL_DEPTH_TEST);
    glutSwapBuffers();
}

void reshapenetwork(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
    glViewport(0, 0, x, y);
}

bool animation = false;
bool animation1 = false;

void idlenetwork(void)
{
    if(animation){
        yRotated -= 0.5;
        displaynetwork();
    }
    else if(animation1){
        yRotated += 0.5;
        displaynetwork();
    }
}

bool spin=false;
void spinFunc(int value){
    if(spin){
        if(value==10)
            value=0;
        input_no=value;
        glutPostRedisplay();
        glutTimerFunc(500, spinFunc, value + 1);
        }
}
bool spin1=false;
void spinFunc1(int value){
    if(spin1){
        if(value==-1)
            value=9;
        input_no=value;
        glutPostRedisplay();
        glutTimerFunc(500, spinFunc1, value - 1);
        }
}
void handleKeypress(unsigned char key, int x, int y) {
    GLfloat dirX = lookAtX - cameraPosX;
    GLfloat dirY = lookAtY - cameraPosY;
    GLfloat dirZ = lookAtZ - cameraPosZ;
    GLfloat length = sqrt(dirX * dirX + dirY * dirY + dirZ * dirZ);
    dirX /= length;
    dirY /= length;
    dirZ /= length;
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'r':
            spin=false;
            spin1=!spin1;
            if(spin1){
                ctrl=false;
                start=true;
                animation1=false;
                animation=true;
            }
            else{
                ctrl=true;
                start=false;
                animation=false;
            }
            glutTimerFunc(0, spinFunc1, 9);
            break;
        case 't':
            spin1=false;
            spin=!spin;
            if(spin){
                ctrl=false;
                start=true;
                animation=false;
                animation1=true;
            }
            else{
                ctrl=true;
                start=false;
                animation1=false;
            }
            glutTimerFunc(0, spinFunc, 0);
            break;
        case 'p':
            start=false;
            break;
        case 'f':
            if(fullscreen){
                glutReshapeWindow(1350,950);
                glutPositionWindow(50,50);
            }
            else{
                glutFullScreen();
            }
            fullscreen=!fullscreen;
            break;
        case 'k':
            animation1=false;
            animation=!animation;
            break;
        case 'l':
            animation=false;
            animation1=!animation1;
            break;

        case '0':
            start = true;
            input_no = 0;
            break;
        case '1':
            start = true;
            input_no = 1;
            break;
        case '2':
            start = true;
            input_no = 2;
            break;
        
        case '3':
            start = true;
            input_no = 3;
            break;
        case '4':
            start = true;
            input_no = 4;
            break;
        case '5':
            start = true;
            input_no = 5;
            break;
        case '6':
            start = true;
            input_no = 6;
            break;
        case '7':
            start = true;
            input_no = 7;
            break;
        case '8':
            start = true;
            input_no = 8;
            break;
        case '9':
            start = true;
            input_no = 9;
            break;
        case 'w':
           cameraPosY += cameraSpeed;
           break;
       case 's':
           cameraPosY -= cameraSpeed;
           break;
       case 'a':
           cameraPosX -= cameraSpeed;
           break;
       case 'd':
           cameraPosX += cameraSpeed;
           break;
       case 'q':
           cameraPosZ += cameraSpeed;
           break;
       case 'e':
           cameraPosZ -= cameraSpeed;
           break;
        case 'x':
            yRotated += 1.0;
            break;
        case 'z':
            yRotated -= 1.0;
            break;
}
    lookAtX = cameraPosX + dirX;
    lookAtY = cameraPosY + dirY;
    lookAtZ = cameraPosZ + dirZ;

    glutPostRedisplay();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1350, 950);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Network Rotating Animation");
    yRotated = 315;
    glClearColor(0.1, 0.1, 0.1, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(displaynetwork);
    glutReshapeFunc(reshapenetwork);
    glutIdleFunc(idlenetwork);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(100, check, 0);
    glutMainLoop();
    return 0;
}
