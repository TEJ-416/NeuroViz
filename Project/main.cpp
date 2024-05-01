#include <GLUT/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "iostream"
#include <time.h>
using namespace std;

int input_no=0;
bool start = false;
bool flag = true;
GLfloat xRotated, yRotated, zRotated;

void check(int value)
{
    if (flag == true)
    {
        flag = false;
    }
    else if (flag == false)
    {
        flag = true;
    }
    cout << flag << "\n";
    glutPostRedisplay();
    glutTimerFunc(1000, check, 0);
}


void highlight_lines(float x, float y, float z, float live_transparency_line,float output)
{
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
                glPointSize(20.0);
                glBegin(GL_POINTS);
                glColor4f(0.0, 0.0, 1.0, 1.0);
                glVertex3f(output, 0.5, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, live_transparency_line);
                glVertex3f(0.1 + b, 0.1 + a, 0.8);
                glVertex3f(output, 0.5, 1.2);
                glVertex3f(output, 0.5, 1.2);
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
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
     highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);


    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

    highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
     highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);


    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.6, 0.0, live_transparency_line, output);
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

    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output);
//                     highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output);
//                     highlight_lines(0.3, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
//                     highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
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

    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.4, 0.0, live_transparency_line, output);
    
//                     highlight_lines(0.3, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.2, 0.0, live_transparency_line, output);
//                     highlight_lines(0.8, 0.2, 0.0, live_transparency_line, output);
    
    highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
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
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
//                     highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output);
//                     highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
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
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output);


    highlight_lines(0.3, 0.5, 0.0, live_transparency_line, output);

    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output);


    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
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
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
//                     highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output);
//                     highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
//                     highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
//                     highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output);
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
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
//                     highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);
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
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.8, 0.0, live_transparency_line, output);


    highlight_lines(0.3, 0.5, 0.0, live_transparency_line, output);
//                     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);

    
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.8, 0.0, live_transparency_line, output);


    highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
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
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);


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
    highlight_lines(0.4, 0.2, 0.0, live_transparency_line, output);
     highlight_lines(0.4, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.4, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.5, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.4, 0.7, 0.0, live_transparency_line, output);

     highlight_lines(0.5, 0.5, 0.0, live_transparency_line, output);
//                    highlight_lines(0.5, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.5, 0.8, 0.0, live_transparency_line, output);
     
     highlight_lines(0.6, 0.5, 0.0, live_transparency_line, output);
//                    highlight_lines(0.6, 0.2, 0.0, live_transparency_line, output);
    highlight_lines(0.6, 0.8, 0.0, live_transparency_line, output);

//                     highlight_lines(0.7, 0.3, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.6, 0.0, live_transparency_line, output);
    highlight_lines(0.7, 0.7, 0.0, live_transparency_line, output);


 
}

void displaynetwork(void)
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-0.9, -0.75, -5.0);
    glColor3f(0.8, 0.2, 0.1);

    glTranslatef(1.0,1.0,1.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glTranslatef(-1.0,-1.0,-1.0);

    glScalef(1.5, 1.5, 1.5);

    float dead_transparency_line = 0.08;
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
                glVertex3f(0.1 + b, 0.5, 1.2);
                glVertex3f(0.1 + b, 0.5, 1.2);
                glEnd();
                glBegin(GL_LINE_LOOP);
                glColor4f(1.0, 1.0, 1.0, dead_transparency_line);
                glVertex3f(0.1 + b, 0.1 + c, 0.8);
                glVertex3f(0.1 + a, 0.5, 1.2);
                glVertex3f(0.1 + a, 0.5, 1.2);
                glEnd();
            }
        }
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
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'e':
            start=false;
            break;
        case 'f':
            glutFullScreen();
            break;
        case 'a':
            animation1=false;
            animation=!animation;
            break;
        case 'd':
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
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1350, 950);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Network Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    yRotated = 180;
    glClearColor(0.0, 0.0, 0.0, 0.0);
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
