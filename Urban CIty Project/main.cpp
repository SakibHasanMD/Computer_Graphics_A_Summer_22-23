#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<math.h>
using namespace std;
bool isRaining = false;
bool isDay = true;
bool isSnow = false;
bool isRising = true;


const float yIncrement = 0.01;
const float yPeak = 41.0;
const float yBase = 0.0;
float sunMoonY = 30;
//Sun & Moon
void OBJ1_SunMoon(){
            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++){
            if(isDay){glColor3f(1.00, 0.41, 0.08);}
            else {glColor3f(1.00, 1.0, 1.0);}
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=7;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+60,y+sunMoonY );
            }
            glEnd();
}

//Clouds
//--------------------------------------------------
float cloudX[] = {-20,-110,10,-82, 60, 130, 200, 250};
float cloudY[] = {40,-20,-30,61, 50, 20, -10, 50};
const float cloudSpeed = 0.2;

void OBJ2_CloudeCircle(){
            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++){

            if(isDay){glColor3f(1.0,1.0,1.0);}
            else {glColor3f(0.77, 0.79, 0.79);}

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-82,y+61 );
            }
            glEnd();
}

void OBJ3_cloud(){
            glBegin(GL_POLYGON);

            if(isDay){glColor3f(1.0,1.0,1.0);}
            else {glColor3f(0.77, 0.79, 0.79);}

            glVertex2f(-82,61);
            glVertex2f(-65,61);
            glVertex2f(-65,78);
            glVertex2f(-82,78);
            glEnd();

            OBJ2_CloudeCircle();

            glPushMatrix();
            glTranslatef(7, -4, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(14, 0.0, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(17, 9, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-2, 9, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(2, 16, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(7, 19, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(14, 16, 0.0f);
            OBJ2_CloudeCircle();
            glPopMatrix();
}

void F1_OBJ3_AllClouds() {
    for (int i = 0; i < 8; i++) {
        glPushMatrix();
        glTranslatef(cloudX[i], cloudY[i], 0.0f);
        OBJ3_cloud();
        glPopMatrix();
    }
}


//Streets
//--------------------------------------------------
void OBJ4_Streets(){
            glBegin(GL_POLYGON);
            glColor3f(0.3,0.3,0.3);
            glVertex2f(-100,-30);
            glVertex2f(100,-30);
            glVertex2f(100,-100);
            glVertex2f(-100,-100);
            glEnd();
}
void OBJ5_StreetsBorderLine(){
            glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
            glVertex2f(-100.0,-95);
            glVertex2f(100.0,-95);
            glVertex2f(100,-97);
            glVertex2f(-100,-97);
            glEnd();
            }

void OBJ6_StreetsMiddleLine(){
            float x1=-99;
            float x2=-94;
            while(x1<100)
            {
            glBegin(GL_POLYGON);
            glColor3f(1.0,1.0,1.0);
            glVertex2f(x1,-65);
            glVertex2f(x2,-65);
            glVertex2f(x2,-67);
            glVertex2f(x1,-67);
            glEnd();
            x1+=9;
            x2+=9;
            }
            }
void F2_OBJ4_OBJ5_OBJ6_AllStreets(){
    OBJ4_Streets();
    OBJ5_StreetsBorderLine();

    glPushMatrix();
    glTranslatef(0.0, 62, 0.0f);
    OBJ5_StreetsBorderLine();
    glPopMatrix();

    OBJ6_StreetsMiddleLine();
    }

//Water View
//-------------------------------------------------

const float WaterSpeed = 0.2;
float lineX[10] = { 50, 140, 20, 150, -10, 30, 100, 130, -20, 110 };

float lineY[10] = { -18, 19, -10, 0, -13, 20, -20, -25, 5, 10 };

void OBJ7_Water(){
            glBegin(GL_POLYGON);

            if(isDay){glColor3f(0.1, 0.5, 0.8);}
            else {glColor3f(0.075, 0.375, 0.6);     }


            glVertex2f(-100,-48);
            glVertex2f(100,-48);
            glVertex2f(100,-100);
            glVertex2f(-100,-100);
            glEnd();
}

void OBJ8_WaterLine() {
    glColor3f(0.1, 0.9, 0.8);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-80, -70);
    glVertex2f( -60, -70);
    glEnd();

}

void F3_OBJ8_AllWaterLines(){

    for (int i = 0; i < 10; ++i) {
        glPushMatrix();
        glTranslatef(lineX[i], lineY[i], 0.0f);
        OBJ8_WaterLine();
        glPopMatrix();

    }
    }
//Buildings
//-------------------------------------------------
void OBJ9_Building() {
    // White base
    glColor3f(1.00, 0.94, 0.86);
    glBegin(GL_POLYGON);
    glVertex2f(-30, 30);
    glVertex2f(30, 30);
    glVertex2f(30, -160);
    glVertex2f(-30, -160);
    glEnd();

    // Blue windows
    if (isDay) {
    glColor3f( 0.23, 0.43, 0.70); // Original color
} else {
    glColor3f(0.33, 0.63, 1.00); // Darker color
}

    glBegin(GL_POLYGON);
    glVertex2f(-25 , 20);
    glVertex2f(24, 20);
    glVertex2f(24, -158);
    glVertex2f(-25, -158);
    glEnd();

    //windows separator
    glColor3f(1.00, 0.93, 0.83); // Dark blue color
    for (int i = -150; i <= 25; i += 10) {
    glLineWidth(3.0); // Adjust the line width here
    glBegin(GL_LINES);
    glVertex2f(-28, i);
    glVertex2f(27, i);
    glEnd();
}

    // White Base lines
    glColor3f(1.00, 0.93, 0.83);
    for (int i = -10; i <= 20; i += 20) {
        glLineWidth(6.0);
        glBegin(GL_LINES);
        glVertex2f(i, 30);
        glVertex2f(i, -160);
        glEnd();
    }
}

void OBJ10_Building() {


    if (isDay) {
    glColor3f(0.32, 0.34, 0.63);
} else {
    glColor3f(0.47, 0.50, 0.91);
}

    glBegin(GL_POLYGON);
    glVertex2f(-30, 30);
    glVertex2f(30, 30);
    glVertex2f(30, -160);
    glVertex2f(-30, -160);
    glEnd();


    // White Base lines
    glColor3f(1.0, 1.0, 1.0);
    for (int i = -30; i <= 20; i += 15) {
        glLineWidth(2.0);
        glBegin(GL_LINES);
        glVertex2f(i, 30);
        glVertex2f(i, -160);
        glEnd();
    }

    //windows seperator H
    for (int i = -150; i <= 35; i += 15) {
    glLineWidth(3.0);
     glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(-32, i);
    glVertex2f(31, i);
    glEnd();

    // Draw black line (shadow)
    glColor3f(0.34, 0.38, 0.86);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(-32, i-1);
    glVertex2f(31, i - 1);
    glEnd();
}

}

void OBJ11_Building() {
    // White base

    glBegin(GL_POLYGON);
    glColor3f(1.00, 0.94, 0.82);
    glVertex2f(-30, 27);
    glVertex2f(30, 35);
    glVertex2f(30, -160);
    glVertex2f(-30, -160);
    glEnd();


     // White base 2
    glBegin(GL_POLYGON);
    glColor3f(1.00, 0.85, 0.82);
    glVertex2f(30, 35);
    glVertex2f(50, 27);
    glVertex2f(50, -160);
    glVertex2f(30, -160);
    glEnd();

    // White base 2 windows
    glBegin(GL_POLYGON);
    if (isDay) {
    glColor3f(0.40, 0.23, 0.40);
} else {
     glColor3f(0.79, 0.46, 0.78);
}


    glVertex2f(38, 27);
    glVertex2f(42, 23);
    glVertex2f(42, -158);
    glVertex2f(38, -158);
    glEnd();

    // Blue windows 1
    glBegin(GL_POLYGON);
    if (isDay) {
    glColor3f(0.28, 0.29, 0.49);
} else {
     glColor3f(0.56, 0.57, 0.98);
}


    glVertex2f(-28 , 20);
    glVertex2f(27, 25);
    glVertex2f(27, -160);
    glVertex2f(-28, -165);
    glEnd();

    //windows separator base 1
    glColor3f(1.00, 0.94, 0.82);
    for (int i = -150; i <= 20; i += 10) {
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-28, i);
    glVertex2f(27, i+5);
    glEnd();
}

     //windows separator base 2
    glColor3f(1.00, 0.85, 0.82);
    for (int i = -150; i <= 25; i += 20) {
    glLineWidth(5.0);
    glBegin(GL_LINES);
    glVertex2f(35, i+5);
    glVertex2f(45, i);
    glEnd();
}

    // White Base lines
    glColor3f(1.00, 0.94, 0.82);
    for (int i = -28; i <= 20; i += 15) {
        glLineWidth(6.0);
        glBegin(GL_LINES);
        glVertex2f(i, 24);
        glVertex2f(i, -160);
        glEnd();
    }


}

void OBJ12_Building(){


        // Draw the rectangle
        glBegin(GL_POLYGON);
        if (isDay) {
      glColor3f(0.23, 0.25, 0.45);
} else {
    glColor3f(0.46, 0.50, 0.90);
}



        glVertex2f(-20.0f, -68.33f);
        glVertex2f(20.0f, -68.33f);

        if (isDay) {
    glColor3f(0.23, 0.34, 0.50);
} else { glColor3f(0.47, 0.69, 1.00);
}


        glVertex2f(20.0f, 66.67f);
        glVertex2f(-20.0f, 93.33f);
        glEnd();

        // Draw the rectangle 2nd
        glBegin(GL_POLYGON);

        if (isDay) {
      glColor3f(0.23, 0.25, 0.45);
} else {
    glColor3f(0.46, 0.50, 0.90);
}



        glVertex2f(20.0f, -68.33f);
        glVertex2f(28.0f, -68.33f);
        glVertex2f(28.0f, 64.33f);
        glVertex2f(20.0f, 64.33f);
        glEnd();



        // Draw the rectangle 2nd top
        glBegin(GL_POLYGON);
        glColor3f(1.00, 0.61, 0.67);
        glVertex2f(20.0f, 68.67f);
        glVertex2f(28.0f, 68.67f);
        glVertex2f(28.0f, 64.33f);
        glVertex2f(20.0f, 64.33f);
        glEnd();

        // Draw the rectangle top
        glBegin(GL_POLYGON);
        glColor3f(1.00, 0.85, 0.75);
        glVertex2f(-20.0f, 95.33f);
        glVertex2f(19.0f, 68.33f);
        glVertex2f(28.0f, 68.33f);
        glVertex2f(-10.0f, 95.33f);
        glEnd();



        // Draw the rectangle 2nd top
        glBegin(GL_POLYGON);
        glColor3f(1.00, 0.61, 0.67);
        glVertex2f(20.0f, 70.0f);
        glVertex2f(24.0f, 70.0f);
        glVertex2f(24.0f, 89.33f);
        glVertex2f(20.0f, 89.33f);
        glEnd();

        // Draw the rectangle 2nd top side x
        glBegin(GL_POLYGON);
        glColor3f(1.00, 0.94, 0.79);
        glVertex2f(20.0f, 70.0f);
        glVertex2f(20.0f, 89.33f);
        glVertex2f(0.0f, 102.67f);
        glVertex2f(0.0f, 83.33f);
        glEnd();


        // Draw the rectangle topmost
        glBegin(GL_POLYGON);
        glColor3f(1.00, 0.85, 0.78);
        glVertex2f(24.0f, 89.33f);
        glVertex2f(20.0f, 89.33f);
        glVertex2f(0.0f, 102.67f);
        glVertex2f(5.0f, 102.67f);
        glEnd();

        // Draw vertical lines
        glLineWidth(1);
        glColor3f(1.0, 1.0, 1.00);
        glBegin(GL_LINES);
        glVertex2f(-13.28f, 90.0f);  // First line
        glVertex2f(-13.28f, -68.33f);

        glVertex2f(-7.0f, 83.33f);  // Second line
        glVertex2f(-7.0f, -68.33f);

        glVertex2f(0.0f, 78.33f);  // Third line
        glVertex2f(0.0f, -68.33f);

        glVertex2f(7.0f, 73.33f);  // Fourth line
        glVertex2f(7.0f, -68.33f);

        glVertex2f(13.28f, 70.0f);  // Fifth line
        glVertex2f(13.28f, -68.33f);
        glEnd();



        // Draw white lines rec 2
        glColor3f(1.0, 1.0, 1.0);
        glLineWidth(1);
        glBegin(GL_LINES);

        glVertex2f(24.0f, 64.33f);
        glVertex2f(24.0f, -68.33f);

        glVertex2f(22.0f, 64.33f);
        glVertex2f(22.0f, -68.33f);

        glVertex2f(26.0f, 64.33f);
        glVertex2f(26.0f, -68.33f);
        glEnd();


        // Draw the white zigzag lines
        glLineWidth(11);
        glColor3f(1.00, 0.94, 0.79);
        for (int i = -66.67; i <= 60; i += 53.33) {
            glBegin(GL_LINES);
            glVertex2f(-20.0f, i);
            glVertex2f(20.0f, i + 26.67);
            glEnd();
            glBegin(GL_LINES);
            glVertex2f(-20.0f, i + 53.33);
            glVertex2f(20.0f, i + 26.67);
            glEnd();
        }


}

void F4_OBJ9_OBJ10_OBJ11_OBJ12_AllBuildings(){

    glPushMatrix();
    glTranslatef(-545,-135,0);
    glScalef(-2,0.8,1);
    OBJ12_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-425,0,0);
    glScalef(-1.8,1.2,1);
    OBJ11_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-340,-96,0);
    glScalef(1.6,0.6,1);
    OBJ10_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-245,-30,0);
    glScalef(1.6,1.0,1);
    OBJ9_Building();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-150,-65,0);
    glScalef(1.6,0.8,1);
    OBJ10_Building();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(248,-113,0);
    glScalef(1.95,0.5,1);
    OBJ10_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,-80,0);
    glScalef(1.5,0.7,1);
    OBJ11_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(147,-110,0);
    glScalef(1.4,0.5,1);
    OBJ9_Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(355,-30,0);
    glScalef(1.6,1.0,1);
    OBJ9_Building();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(-60,-100,0);
    glScalef(2.1,1.35,1);
    OBJ12_Building();
    glPopMatrix();

}

//-------------------------------------------------
//Car

float lamboBlueX = -80.0f;
float lamboRedX = 80.0f;
float lamboSpeed = 0.5f;

void OBJ13_carLines(){

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(-30.0f, 44.7f);
    glVertex2f(-31.6f, 86.2f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(-31.1f, 86.2f);
    glVertex2f(15.3f, 83.4f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(15.8f, 83.4f);
    glVertex2f(21.1f, 49.4f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(20.9f, 49.0f);
    glVertex2f(16.7f, 38.3f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(-85.1f, 85.0f);
    glVertex2f(-67.3f, 73.9f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(-22.0f, 73.9f);
    glVertex2f(-11.8f, 74.3f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);

    glColor3ub(0, 0, 0);
    glVertex2f(-16.9f, 68.8f);
    glVertex2f(-4.0f, 69.2f);
    glEnd();
}

void OBJ14_CarBodyNGlass(GLubyte r=255, GLubyte g=19, GLubyte b=16){
            //Car Body
            glBegin(GL_POLYGON);
            glColor3ub(r, g, b);
            glVertex2f(-13.7f, -20.8f);
            glVertex2f(3.9f, -16.8f);
            glVertex2f(53.2f, -33.8f);
            glVertex2f(73.4f, -35.8f);
            glVertex2f(77.6f, -44.1f);
            glVertex2f(84.1f, -54.7f);
            glVertex2f(84.1f, -66.6f);
            glVertex2f(82.7f, -69.4f);
            glVertex2f(81.6f, -84.8f);
            glVertex2f(75.2f, -87.2f);
            glVertex2f(75.6f, -82.4f);
            glVertex2f(42.7f, -84.0f);
            glVertex2f(42.7f, -91.1f);
            glVertex2f(-33.7f, -91.1f);
            glVertex2f(-33.7f, -84.8f);
            glVertex2f(-64.6f, -85.2f);
            glVertex2f(-62.8f, -91.9f);
            glVertex2f(-86.6f, -87.2f);
            glVertex2f(-86.6f, -85.6f);
            glVertex2f(-83.5f, -84.0f);
            glVertex2f(-84.1f, -73.7f);
            glVertex2f(-86.4f, -71.7f);
            glVertex2f(-86.8f, -67.4f);
            glVertex2f(-73.5f, -50.8f);
            glVertex2f(-60.6f, -45.3f);
            glVertex2f(-38.8f, -41.3f);
            glVertex2f(-29.0f, -31.8f);
            glEnd();
            //Front Glass
            glBegin(GL_POLYGON);
             glColor3ub(0, 0, 0);
            glVertex2f(-27.9f, -38.5f);
            glVertex2f(-31.3f, -43.3f);
            glVertex2f(-38.1f, -42.5f);
            glVertex2f(-38.1f, -42.5f);
            glVertex2f(-38.1f, -42.5f);
            glVertex2f(-39.3f, -43.3f);
            glVertex2f(-31.0f, -33.8f);
            glVertex2f(-21.3f, -25.9f);
            glVertex2f(-13.0f, -21.5f);
            glVertex2f(-11.0f, -23.5f);
            glVertex2f(-18.8f, -28.7f);
            glEnd();
            //Main Glass
            glBegin(GL_POLYGON);
             glColor3ub(0, 0, 0);
            glVertex2f(-5.5f, -22.7f);
            glVertex2f(10.1f, -22.3f);
            glVertex2f(31.4f, -31.4f);
            glVertex2f(15.0f, -37.7f);
            glVertex2f(-11.3f, -43.3f);
            glVertex2f(-27.5f, -43.7f);
            glVertex2f(-28.4f, -44.1f);
            glVertex2f(-16.1f, -29.8f);
            glEnd();
            //Headlihts
            glBegin(GL_POLYGON);
             glColor3ub(255, 255, 255);
            glVertex2f(-77.5f, -57.1f);
            glVertex2f(-81.3f, -61.9f);
            glVertex2f(-77.0f, -60.7f);
            glVertex2f(-69.5f, -52.4f);
            glEnd();
            //Back Glass
            glBegin(GL_POLYGON);
            glColor3ub(0, 0, 0);
            glVertex2f(50.7f, -35.4f);
            glVertex2f(25.2f, -25.9f);
            glVertex2f(25.4f, -23.9f);
            glVertex2f(51.2f, -33.0f);
            glEnd();
}

void OBJ15_Wheel(){
            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++){
            glColor3f(0.04, 0.13, 0.16);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=20;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-78,y-80 );
            }
            glEnd();

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++){
            glColor3f(0.78, 0.78, 0.78);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=16;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-78,y-80 );
            }
            glEnd();

            glBegin(GL_POLYGON);
            for(int i=0;i<200;i++){
            glColor3f(0.06, 0.18, 0.22);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=10;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x-78,y-80 );
            }
            glEnd();
}

void F5_OBJ13_OBJ14_OBJ15_LamboBlue(){

            OBJ14_CarBodyNGlass(0,98,255);

            glPushMatrix();
            glScalef(0.6,1,1);
            OBJ15_Wheel();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(103,0,0);
            glScalef(0.6,1,1);
            OBJ15_Wheel();
            glPopMatrix();

            glPushMatrix();
            glScalef(1,-1,1);
            OBJ13_carLines();
            glPopMatrix();


            }

void F6_OBJ13_OBJ14_OBJ15_LamboRed(){
            //Y 248, 204, 42
            OBJ14_CarBodyNGlass();

            glPushMatrix();
            glScalef(0.6,1,1);
            OBJ15_Wheel();
            glPopMatrix();

            glPushMatrix();
            glTranslatef(103,0,0);
            glScalef(0.6,1,1);
            OBJ15_Wheel();
            glPopMatrix();

            glPushMatrix();
            glScalef(1,-1,1);
            OBJ13_carLines();
            glPopMatrix();


            }

//--------------------------------------------------
//Speed Boat
float boatX = 65.0f;
float boatSpeed = 0.25f;

void OBJ16_SpeedBoat(){
    //Back Fin
    glBegin(GL_POLYGON);
    glColor3ub(244, 244, 241);
    glVertex2f(69.6f, 20.4f);
    glVertex2f(69.6f, 21.1f);
    glVertex2f(83.2f, 21.1f);
    glVertex2f(86.7f, -16.4f);
    glVertex2f(70.5f, -15.2f);
    glEnd();

    //Boat Windows
    glBegin(GL_POLYGON);
    glColor3ub(42, 69, 136);
    glVertex2f(-13.5f, 44.9f);
    glVertex2f(33.6f, 14.8f);
    glVertex2f(-24.6f, 22.7f);
    glEnd();

    //Base
    glBegin(GL_POLYGON);
    glColor3ub(244, 244, 241);
    glVertex2f(-24.4f, 24.3f);
    glVertex2f(63.4f, 9.7f);
    glVertex2f(66.3f, -1.0f);
    glVertex2f(75.6f, -4.2f);
    glVertex2f(75.9f, -21.5f);
    glVertex2f(-71.3f, -21.5f);
    glVertex2f(-83.0f, -3.8f);
    glVertex2f(-90.4f, 21.1f);
    glEnd();

    //Window Border Orange
    glBegin(GL_POLYGON);
    glColor3ub(232, 146, 64);
    glVertex2f(-14.1f, 44.1f);
    glVertex2f(24.1f, 17.6f);
    glVertex2f(25.0f, 20.0f);
    glVertex2f(-15.3f, 47.2f);
    glVertex2f(-14.8f, 42.5f);
    glEnd();

    glPushMatrix();
    glTranslatef(4,0,0);
    glBegin(GL_POLYGON);
    glColor3ub(232, 146, 64);
    glVertex2f(-10.6f, 21.5f);
    glVertex2f(-4.6f, 37.0f);
    glVertex2f(-6.8f, 38.9f);
    glVertex2f(-14.6f, 21.5f);
    glEnd();
    glPopMatrix();

    //Orange Line in Base
    glBegin(GL_POLYGON);
    glColor3ub(108, 122, 126);
    glVertex2f(-31.0f, 16.8f);
    glVertex2f(32.7f, 4.9f);
    glVertex2f(75.0f, -8.5f);
    glVertex2f(75.6f, -18.0f);
    glVertex2f(-32.8f, 8.1f);
    glVertex2f(-87.9f, 11.3f);
    glVertex2f(-89.5f, 17.6f);
    glEnd();

}

//--------------------------------------------------
//Plane
float planeX = -78.0f;
float planeSpeed = 0.8f;

void OBJ17_Plane(){
            glBegin(GL_POLYGON);
            glColor3ub(96, 109, 126);
            glVertex2f(46.1f, -5.3f);
            glVertex2f(62.5f, 3.8f);
            glVertex2f(75.4f, 55.1f);
            glVertex2f(86.5f, 54.7f);
            glVertex2f(94.7f, -12.5f);
            glVertex2f(100.3f, -16.4f);
            glVertex2f(100.1f, -29.4f);
            glVertex2f(41.6f, -52.8f);
            glVertex2f(-57.5f, -51.2f);
            glVertex2f(-84.4f, -47.2f);
            glVertex2f(-96.1f, -35.4f);
            glVertex2f(-96.4f, -20.0f);
            glVertex2f(-84.6f, -8.1f);
            glVertex2f(-67.0f, -0.6f);
            glEnd();



            glPushMatrix();
            glTranslatef(0,-5,0);
            glBegin(GL_POLYGON);
            glColor3ub(170, 183, 198);
            glVertex2f(-38.1f, -58.3f);
            glVertex2f(-52.1f, -52.4f);
            glVertex2f(-61.9f, -44.9f);
            glVertex2f(-49.0f, -32.2f);
            glVertex2f(28.5f, -29.4f);
            glVertex2f(63.2f, -44.1f);
            glVertex2f(26.3f, -57.9f);
            glEnd();
            glPopMatrix();

            glBegin(GL_POLYGON);
            glColor3ub(46, 46, 48);
            glVertex2f(-32.6f, -8.5f);
            glVertex2f(-57.3f, -6.1f);
            glVertex2f(-66.8f, -3.0f);
            glVertex2f(-45.5f, 7.7f);
            glVertex2f(-4.1f, 4.9f);
            glVertex2f(6.1f, -3.0f);
            glEnd();



            }

void OBJ18_planeLines(){
            //lines
            glLineWidth(1);
            glBegin(GL_LINES);
            glColor3ub(0, 0, 0);
            glVertex2f(72.4f, -45.5f);
            glVertex2f(82.7f, -45.8f);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0, 0, 0);
            glVertex2f(82.7f, -45.5f);
            glVertex2f(82.2f, 11.5f);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0, 0, 0);
            glVertex2f(45.3f, 6.3f);
            glVertex2f(96.4f, 11.1f);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(0, 0, 0);
            glVertex2f(44.2f, 5.9f);
            glVertex2f(49.3f, 38.7f);
            glEnd();


            glBegin(GL_LINES);
            glColor3ub(170, 183, 198);
            glVertex2f(-48.2f, -5.5f);
            glVertex2f(-48.4f, 8.7f);
            glEnd();

            glBegin(GL_LINES);
            glColor3ub(170, 183, 198);
            glVertex2f(-14.7f, -5.1f);
            glVertex2f(-14.7f, 6.7f);
            glEnd();
}

void F7_OBJ17_OBJ18_CompletePlane(){
            OBJ17_Plane();
            glPushMatrix();
            glTranslatef(-2,0,0);
            glScalef(1.0,-1.0,1.0);
            OBJ18_planeLines();
            glPopMatrix();
}

//-------------------------------------------------
//Effects-----------
//Rain and Snow Effect


void F8_keyboardCallback(unsigned char key, int x, int y) {
    if (key == 'r' || key == 'R') {
        isRaining = !isRaining;
    }
     if (key == 'd' || key == 'D') {
        isDay = true;
    }
    if (key == 'n' || key == 'n') {
        isDay = false ;
    }
    if (key == 's' || key == 'S') {
        isSnow = !isSnow;
    }
}

//Rain
const int numberOfRaindrops = 200;
const int maxRaindropLength = 10;
void OBJ19_drawRaindrops() {
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(1.0);

    glBegin(GL_LINES);
    for (int i = 0; i < numberOfRaindrops; i++) {
        int random1 = rand() % 201 - 100;
        int random2 = rand() % 201 - 100;
        float length = rand() % maxRaindropLength;
        glVertex2f(random1, random2);
        glVertex2f(random1, random2 - length);
    }
    glEnd();
}
//Snow
const int numberOfSnowflakes = 200;
const float maxSnowflakeRadius = 2.0;

void OBJ20_Snowfall() {
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0); //

    glBegin(GL_POINTS);
    for (int i = 0; i < numberOfSnowflakes; i++) {
        int randomX = rand() % 200 - 100;
        int randomY = rand() % 200 - 100;
        float radius = static_cast<float>(rand()) / RAND_MAX * maxSnowflakeRadius;

        // Draw a circle using multiple points to approximate the snowflake
        for (int j = 0; j < 360; j += 10) {
            float angle = static_cast<float>(j) * 3.14159 / 180.0;
            float x = randomX + radius * cos(angle);
            float y = randomY + radius * sin(angle);
            glVertex2f(x, y);
        }
    }
    glEnd();
}

//Display
//-------------------------------------------------
void F9_display() {
    if(isDay){glClearColor(0.53, 0.79, 1.00, 1.0f);}
    else {glClearColor(0.0, 0.0, 0.00, 1.0f);}

    glClear(GL_COLOR_BUFFER_BIT);


    //Sun Moon
    glPushMatrix();
    glScalef(1,1.8,1);
    OBJ1_SunMoon();
    glPopMatrix();

    //water
    OBJ7_Water();
    F3_OBJ8_AllWaterLines();

    //Clouds
    glPushMatrix();
    glTranslatef(0,25.0,0);
    glScalef(0.5,0.5,1);
    F1_OBJ3_AllClouds();
    glPopMatrix();

    //Buildings
    glPushMatrix();
    glTranslatef(20,74,0);
    glScalef(0.2,0.5,1);
    F4_OBJ9_OBJ10_OBJ11_OBJ12_AllBuildings();
    glPopMatrix();


    //Streets
    glPushMatrix();
    glTranslatef(0,-8.0,0);
    glScalef(1,0.4,1);
    F2_OBJ4_OBJ5_OBJ6_AllStreets();
    glPopMatrix();


    // Lambo BLUE
    glPushMatrix();
    glTranslatef(lamboRedX, -13, 0);
    glScalef(0.2, 0.2, 1);
    F6_OBJ13_OBJ14_OBJ15_LamboRed();
    glPopMatrix();

    // Lambo RED
    glPushMatrix();
    glTranslatef(lamboBlueX, -23, 0);
    glScalef(-0.2, 0.2, 1);
    F5_OBJ13_OBJ14_OBJ15_LamboBlue();
    glPopMatrix();



    //Boat
    glPushMatrix();
    glTranslatef(boatX,-80,0);
    glScalef(0.4,0.4,1);
    OBJ16_SpeedBoat();
    glPopMatrix();

    //Plane
    glPushMatrix();
    glTranslatef(planeX,87,0);
    glScalef(-0.2,0.2,1);
    F7_OBJ17_OBJ18_CompletePlane();
    glPopMatrix();


    if (isRaining) {
        OBJ19_drawRaindrops();
    }
    if (isSnow) {
        OBJ20_Snowfall();
    }
    glutSwapBuffers();
}


//-------------------------------------------
//Update Functions

void AF1_OBJ1_UpdateSun(int value) {

      if (isRising) {
        sunMoonY += yIncrement;
        if (sunMoonY >= yPeak) {
            sunMoonY = yPeak;
            isRising = false;
        }
    } else {
        sunMoonY -= yIncrement;
        if (sunMoonY <= yBase) {
            sunMoonY = yBase;
            isRising = true;
            if  (sunMoonY <= 20) {isDay=false;}
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, AF1_OBJ1_UpdateSun, 0);
}
void AF2_OBJ3_UpdateClouds(int value) {
    for (int i = 0; i < 8; i++) {
        cloudX[i] += cloudSpeed;
        if (cloudX[i] > 290)
            cloudX[i] = -140;
    }
    glutPostRedisplay();
    glutTimerFunc(16, AF2_OBJ3_UpdateClouds, 0);
}

void AF3_OBJ8_UpdateWater(int value) {
    for (int i = 0; i < 10; i++) {
        lineX[i] -= WaterSpeed;
        if (lineX[i] < -40)
            lineX[i] = 180;
    }
    glutPostRedisplay();
    glutTimerFunc(16, AF3_OBJ8_UpdateWater, 0);
}

void AF4_OBJ16_UpdateBoat(int value) {
    boatX -= boatSpeed;
    if (boatX < -340.0f) {
        boatX = 140.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, AF4_OBJ16_UpdateBoat, 0);
}

void AF5_OBJ13_UpdateLambos(int value) {
    lamboBlueX += lamboSpeed;
    lamboRedX -= lamboSpeed;

    if (lamboBlueX > 120.0f) {
        lamboBlueX = -120.0f;
    }
    if (lamboRedX < -150.0f) {
        lamboRedX = 120.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, AF5_OBJ13_UpdateLambos, 0);
}

void AF6_OBJ17_UpdatePlane(int value) {
    planeX += planeSpeed;
    if (planeX > 540.0f) {
        planeX = -128.0f;
    }
    glutPostRedisplay();
    glutTimerFunc(16, AF6_OBJ17_UpdatePlane, 0);
}
void AF7_OBJ19_rainAnimation(int value) {
    glutPostRedisplay();
    glutTimerFunc(16, AF7_OBJ19_rainAnimation, 0);
}

void AF8_OBJ20_snowfallAnimation(int value) {
    glutPostRedisplay();
    glutTimerFunc(2000, AF8_OBJ20_snowfallAnimation, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Urban City Project");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0f,100.0f,-100.0f,100.0f,-1.0f,1.0f);
    glutDisplayFunc(F9_display);
    glutTimerFunc(0, AF1_OBJ1_UpdateSun, 0);
    glutKeyboardFunc(F8_keyboardCallback);
    glutTimerFunc(0, AF2_OBJ3_UpdateClouds, 0);
    glutTimerFunc(0, AF3_OBJ8_UpdateWater, 0);
    glutTimerFunc(0, AF4_OBJ16_UpdateBoat, 0);
    glutTimerFunc(0, AF5_OBJ13_UpdateLambos, 0);
    glutTimerFunc(0, AF6_OBJ17_UpdatePlane, 0);
    if (isRaining) {
        glutTimerFunc(0, AF7_OBJ19_rainAnimation, 0);
    }

    if (isSnow) {
        glutTimerFunc(2000, AF8_OBJ20_snowfallAnimation, 0);
    }
    glutMainLoop();
    return 0;
}
