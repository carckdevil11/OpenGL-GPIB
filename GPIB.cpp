#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
float xrot = 0.0f;	float yrot = 0.0f;	float zrot = 0.0f;	
float xdiff = 0.0f;	float ydiff = 0.0f;	
float xpos = 0.0f;	float ypos = 0.0f;	float zpos = 0.0f;
float translation = 0;
int a,tembokenable = 1, atapenable=1,mosengenable=1;
float b;
bool mouseDown = false;
int is_depth;
void lantai(); void salib(); void atap();
void kubusaneh(float x, float y, float z, float panjang, float tinggi, float lebar);
void atap (); void genteng(); void jendela(); void posisijendela(); void posisijendela3();
void balkon(); void kursi(); void tangga(); void gentengblkg(); void gentenglite ();
void bangunanbelakang(); void mimbar();
float alf=0.7; float PI=3.14,i,h;

void kubusaneh(float x, float y, float z, float panjang, float tinggi, float lebar) {
	//Depan
	glBegin(GL_POLYGON);
	glVertex3f(x-10, y, z+10);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang +10, y, z+10);
	glEnd();

	//Belakang
	glBegin(GL_POLYGON);
	glVertex3f(x-10, y, z - lebar-10);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang+10, y, z - lebar-10);
	glEnd();

	//Atap
	glBegin(GL_POLYGON);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x, y + tinggi, z - lebar);
	glEnd();

	//Alas
	glBegin(GL_POLYGON);
	glVertex3f(x-10, y, z+10);
	glVertex3f(x + panjang+10, y, z+10);
	glVertex3f(x + panjang+10, y, z - lebar-10);
	glVertex3f(x-10, y, z - lebar-10);
	glEnd();

	//Kiri
	glBegin(GL_POLYGON);
	glVertex3f(x-10, y, z+10);
	glVertex3f(x, y + tinggi, z);
	glVertex3f(x, y + tinggi, z - lebar);
	glVertex3f(x-10, y, z - lebar-10);
	glEnd();

	//Kanan
	glBegin(GL_POLYGON);
	glVertex3f(x + panjang+10, y, z+10);
	glVertex3f(x + panjang, y + tinggi, z);
	glVertex3f(x + panjang, y + tinggi, z - lebar);
	glVertex3f(x + panjang+10, y, z - lebar -10);
	glEnd();
}

void kube(float x, float y, float z, float p, float t, float l){
	glPushMatrix();
	glTranslated(x,y,z);//cube
	glScaled(p,t,l);
	glutSolidCube(1);
	glColor3f(0,0,0);
	//glutWireCube(1);
	glPopMatrix();
	glEnd();
}

void kubewire(float x, float y, float z, float p, float t, float l){
	glPushMatrix();
	glTranslated(x,y,z);//cube
	glScaled(p,t,l);
	glutSolidCube(1);
	glColor3f(0,0,0);
	glutWireCube(1);
	glPopMatrix();
	glEnd();
}

void gentenglite(){
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(100,0,0);
	glVertex3f(100,25,-40);
	glVertex3f(0,25,-40);
	glEnd();

	//belang
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-80);
	glVertex3f(100,0,-80);
	glVertex3f(100,25,-40);
	glVertex3f(0,25,-40);
	glEnd();	
	
	//kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(100,0,0);
	glVertex3f(100,0,-80);
	glVertex3f(100,25,-40);
	glEnd();
	
	//kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,-80);
	glVertex3f(0,25,-40);
	glEnd();	
}

void bangunanbelakang(){
	glColor4f(1, 0.98, 0.80,alf);
	kube(-20,-8,-100,2,35,40);
	glColor4f(1, 0.98, 0.80,alf);
	kube(20,-8,-100,2,35,40);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,-8,-121,42,35,2);
	
		
		glPushMatrix();
		glColor4f(0.75,0.75,0.75,alf);//pintunya
		kubewire(-10,-14,-78.9,8,20,2);
		glPopMatrix();
		if (atapenable==1){
		
		gentengblkg();
		}
}

void gentengblkg(){
 glPushMatrix();
 glColor4f(0.69,0.13,0.13,alf);
 glScaled(0.6,0.7,0.45);
 glTranslated(40,12.5,-175);
 glRotated(90,0,1,0);
 gentenglite();
 glPopMatrix();	
}

void kursi(){
	glPushMatrix();
	
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(0,0,0,5,5,20);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(2.5,2.5,0,0.5,10,20);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(0,0,23,5,5,20);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(2.5,2.5,23,0.5,10,20);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(0,0,46,5,5,20);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(2.5,2.5,46,0.5,10,20);
	
	glPopMatrix();
}

void balkon(){
	glColor4f(0,0.5,1,0);
	kube(47,5,-40,0.5,15,79);
	
	glColor4f(0,0.5,1,alf); //alas
	kube(53.5,-2,-63,14,0.3,32);
	glColor4f(0,0.5,1,alf); //alas
	kube(53.5,-2,-17,14,0.3,32);
	
	glPushMatrix();//tangga balkon
	glScaled(0.6,1,1);
	glTranslated(95,5,-51);
	tangga();
	glPopMatrix();
	
	glColor4f(0,0.5,1,0);//tengah tangga
	kube(54,-14,-44,12,2,7);
	
	glPushMatrix();//tangga 2
	glRotated(180,0,1,0);
	glScaled(0.6,1,1);
	glTranslated(-84,16,29);
	tangga();
	glPopMatrix();
}

void tangga (){
	for(int x=0;x<10;x+=2){		
			glPushMatrix();
			glColor4f(0,0.5,1,0);
			glTranslatef(0,-27.5+x,13.5-x);
			glScalef(10,3,4);
			glutSolidCube(1);
			glPopMatrix();		
	}
}

void genteng(){
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(0,0,0);
	glVertex3f(100,0,0);
	glVertex3f(100,25,-40);
	glVertex3f(0,25,-40);
	glEnd();

	//belang
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-80);
	glVertex3f(100,0,-80);
	glVertex3f(100,25,-40);
	glVertex3f(0,25,-40);
	glEnd();	
	
	//kanan
	glBegin(GL_TRIANGLES);
	glVertex3f(100,0,0);
	glVertex3f(100,0,-80);
	glVertex3f(100,25,-40);
	glEnd();
	
	//kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(0,0,0);
	glVertex3f(0,0,-80);
	glVertex3f(0,25,-40);
	glEnd();
	
	//sampingan
	glPushMatrix();
	glColor4f(0.69,0.13,0.13,alf);
	glRotated(-56.5,1,0,0);
	kube(1,27.5,0,2,42,2);
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(0.69,0.13,0.13,alf);
	glRotated(-56.5,1,0,0);
	kube(99,27.5,0,2,42,2);
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(0.69,0.13,0.13,alf);
	glTranslated(0,0,-80);
	glRotated(56.6,1,0,0);
	kube(99,27.5,0,2,42,2);
	glPopMatrix();
	
	glPushMatrix();
	glColor4f(0.69,0.13,0.13,alf);
	glTranslated(0,0,-80);
	glRotated(56.6,1,0,0);
	kube(1,27.5,0,2,42,2);
	glPopMatrix();
	
}

void jendela (){

	glBegin(GL_POLYGON);
	glColor4f(0.5, 0.5, 0.5,alf);
	glVertex3f(0,0,0);
	glVertex3f(10,0,0);
	glVertex3f(10,21,0);
	glVertex3f(7.7,26.5,0);
	glVertex3f(5,30,0);
	glVertex3f(2.3,26.5,0);
	glVertex3f(0,21,0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor4f(0.5, 0.5, 0.5,alf);
	glVertex3f(12,0,0);
	glVertex3f(22,0,0);
	glVertex3f(22,21,0);
	glVertex3f(19.7,26.5,0);
	glVertex3f(17,30,0);
	glVertex3f(14.3,26.5,0);
	glVertex3f(12,21,0);
	glEnd();
	for(a=0;a<=20;a+=2){
	
	glColor3f(0.0,0,0);
	glBegin(GL_LINES);
	glVertex3f(1,1+a,-0.01);
	glVertex3f(9,1+a,-0.01);
	glEnd();	
	glBegin(GL_LINES);
	glVertex3f(13,1+a,-0.01);
	glVertex3f(21,1+a,-0.01);
	glEnd();
	}
}


void posisijendela (){
	glPushMatrix();
	glScaled(0.95,1,1);
	
	glPushMatrix();
	glTranslated(26,-15,0.1);
	jendela();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-48,-15,0.1);
	jendela();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(26,-15,-2.1);
	jendela();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-48,-15,-2.1);
	jendela();
	glPopMatrix();
	
	glPopMatrix();
	
	
}

void posisijendela2(){
	glPushMatrix();
	glTranslated(0,0,-78);
	posisijendela();
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(-3.3,32,25.01);
	glScalef(0.3,0.5,1);
	jendela();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90,0,1,0);
	glPushMatrix();
	glTranslated(16.501,32,-5.1);
	glScalef(0.3,0.5,1);
	jendela();
	glPopMatrix();
	
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(-90,0,1,0);
	glPushMatrix();
	glTranslated(16.501,32,5.1);
	glScalef(0.3,0.5,1);
	jendela();
	glPopMatrix();
	
	glPopMatrix();
}

void posisijendela3(){
 	glPushMatrix();
 	glRotated(90,0,1,0);
 	glScaled(0.4,0.7,1);
	glTranslated(-40,-20,20);
	jendela();
	glPopMatrix();
	glPushMatrix();
 	glRotated(90,0,1,0);
 	glScaled(0.4,0.7,1);
	glTranslated(-40,-20,-20);
	jendela();
	glPopMatrix();
	glPushMatrix();
 	glRotated(90,0,1,0);
 	glScaled(0.4,0.7,1);
	glTranslated(-40,-20,16.9);
	jendela();
	glPopMatrix();
	glPushMatrix();
 	glRotated(90,0,1,0);
 	glScaled(0.4,0.7,1);
	glTranslated(-40,-20,-16.9);
	jendela();
	glPopMatrix();
}

void atap(){
glColor4f(0.82,0.82,0.82,alf);
kube(0,27,-3,122,3,12);
glColor4f(0.82,0.82,0.82,alf);
kube(0,27,-77,122,3,12);

glPushMatrix();
glColor4f(0.69,0.13,0.13,alf);
glScaled(1.21,1.01,1.05);
glTranslated(-50,25,2.5);
genteng();
glPopMatrix();

}

void tembok(){
	glColor4f(1, 0.98, 0.80,alf);
	kube(-35,0,-1,50,50,2);//depan kiri
	glColor4f(1, 0.98, 0.80,alf);
	kube(35,0,-1,50,50,2);//depan kanan
	glColor4f(1, 0.98, 0.80,alf);
	kube(-60,0,-40,2,50,80);//samping kiri
	glColor4f(1, 0.98, 0.80,alf);
	kube(60,0,-40,2,50,80);//samping kanan
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,0,-79,118,50,2);//belakang
	glColor4f(1, 0.98, 0.80,alf);
	kube(0 , 13.5 , -1 , 20 , 23 , 2);//bagian atas lorong pintu
	b = -24;
	for(a=1;a<=25;a++){//aksir batu depan kiri
		glColor4f(0.392, 0.42, 0.443,alf);
		if(a%2==0){
			kubewire(-60, b , -1., 2.1 ,2.01 ,2.1 );
		}
		else{
			kubewire(-59, b , -1., 4.1 ,2.01 ,2.1 );
			glColor4f(0.392, 0.42, 0.443,alf);
			kubewire(-60, b , -2, 2.1, 2.01 ,4.1 );
		}
		b = b+2;
	}
	b = -24;
	for(a=1;a<=25;a++){//aksir batu depan kanan
		glColor4f(0.392, 0.42, 0.443,alf);
		if(a%2==0){
			kubewire(60, b , -1., 2.1 ,2.01 ,2.1 );
		}
		else{
			kubewire(59, b , -1., 4.1 ,2.01 ,2.1 );
			glColor4f(0.392, 0.42, 0.443,alf);
			kubewire(60, b , -2, 2.1 ,2.01 ,4.1 );
		}
		b = b+2;
	}
	
	b = -24;
	for(a=1;a<=25;a++){//aksir batu blkg kiri
		glColor4f(0.392, 0.42, 0.443,alf);
		if(a%2==0){
			kubewire(-60, b , -79, 2.1 ,2.01 ,2.1 );
		}
		else{
			kubewire(-59, b , -79, 4.1 ,2.01 ,2.1 );
			glColor4f(0.392, 0.42, 0.443,alf);
			kubewire(-60, b , -78, 2.1 ,2.01 ,4.1 );
		}
		b = b+2;
	}
	b = -24;
	for(a=1;a<=25;a++){//aksir batu blkg kanan
		glColor4f(0.392, 0.42, 0.443,alf);
		if(a%2==0){
			kube(60, b , -79, 2.1 ,2.01 ,2.1 );
		}
		else{
			kube(59, b , -79, 4.1 ,2.01 ,2.1 );
			glColor4f(0.392, 0.42, 0.443,alf);
			kube(60, b , -78, 2.1 ,2.01 ,4.1 );
		}
		
		b = b+2;
	}
	//bagian pintu
	glColor4f(1, 0.98, 0.80,alf);
	kube(-18 , -6, 10.5 , 2 , 40 , 25);//bagian samping kiri pintu
	glColor4f(1, 0.98, 0.80,alf);
	kube(18 , -6 , 10.5 , 2 , 40 , 25);//bagian samping kanan pintu
	glColor4f(1, 0.98, 0.80,alf);
	kube(-13 , -5 , 24 , 8 , 40 , 2);//bagian depan kiri pintu
	glColor4f(1, 0.98, 0.80,alf);
	kube(13 , -5 , 24 , 8 , 40 , 2);//bagian depan kanan pintu
	glColor3f(0.392, 0.42, 0.443);
	kube(18 , -5 , 24 , 3 , 40 , 3);//bagian depan tiang kanan pintu
	glColor3f(0.392, 0.42, 0.443);
	kube(-18 , -5 , 24 , 3 , 40 , 3);//bagian depan tiang kiri pintu
	glColor4f(1, 0.98, 0.80,alf);
	//kube(0 , 2 , 24 , 35 , 14 , 2);//bagian atas pintu
	glColor4f(0.392, 0.42, 0.443,alf);
	//kube(0 , 10.5 , 24 , 35 , 3 , 2);//bagian atas pintu
	glColor4f(0.392, 0.42, 0.443,alf);
	kube(0 , 14 , 11 , 42 , 2 , 22);//ataspintu plafom
	glColor4f(0.392, 0.42, 0.443,alf);
	//kube(20 , 10.5 , 13 , 2 , 2 , 26);//bagian atas pintu
	
	posisijendela();
	posisijendela2();
	posisijendela3();
	
	balkon();
	
	bangunanbelakang();
	
}

void lantai (){
	glColor4f(230,230,250,0);//lt dalam
	kube(0,-24,-40,118,0.5,78);	
		for(int a=-60;a<=60;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(a,-23.5,-0.5);
				glVertex3f(a,-23.5,-80);
			glEnd();
		}
		for(int a=-80;a<=1;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(-60,-23.5,a);
				glVertex3f(60,-23.5,a);
			glEnd();
		}
		
	glColor4f(0.93,0.75,0.53,alf);//lt luar
	kube(0,-24,15,42,0.5,38);
	
	glColor4f(230,230,250,0);//lt mimbar
	kube(-45.5,-23,-40,26,2,78);
		
		for(int a=-75;a<=-5;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(-59,-21.9,a);
				glVertex3f(-32.5,-21.9,a);
			glEnd();
		}/*
				glBegin(GL_LINES);
				glVertex3f(-59,-21.9,-1);
				glVertex3f(-32.5,-21.9,-1);	
				glEnd();*/
		for(int a=-55;a<=-35;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(a,-21.9,-0.5);
				glVertex3f(a,-21.9,-80);
			glEnd();
		}
		
		
	glColor4f(230,230,250,0);//lt blkg
	kube(0,-24,-100,41.99,0.5,40);
	
	
		for(int a=-20;a<=20;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(a,-23.5,-80);
				glVertex3f(a,-23.5,-121);
			glEnd();
		}
		for(int a=-121;a<=-80;a+=5){
			glColor3f(0,0,0);
			glBegin(GL_LINES);				
				glVertex3f(-20,-23.5,a);
				glVertex3f(20,-23.5,a);
			glEnd();
		}	
		
	//kursi jemaat
	for (int a=10;a<=60;a+=10){
	glPushMatrix();
	glTranslated(-20+a,-21,-65);
	kursi();
	glPopMatrix();
	}
	
	mimbar();
	
}

void salib1(){
	glColor4f(0.7,0.7,0.7,0);//kotaknya
	kube(0,34.1,15,10,40,10);
	
	glPushMatrix();//atasnya kotak
	glTranslated(0,40,5);
	glScaled(0.5,0.5,0.5);
	glColor4f(0.211,0.211,0.211,alf);
	kubusaneh(-10,28,30,20,20,20);
	glPopMatrix();
	
	glPushMatrix(); //atasnya atasnya kotak
	glTranslated(0,61,5);
	glScaled(0.5,0.5,0.5);
	glColor4f(0.211,0.211,0.211,alf);
	kubusaneh(-1,2,21.3,2.5,60,2.5);
	glPopMatrix();
	
	glColor4f(1,0,0,0);//salibnya
	kube(0,40,20,1,15,0.5);
	glColor4f(1,0,0,0);
	kube(0,43,20,6,1,0.5);
	
	/*glPushMatrix();
	glColor3f(1,0,0);
	glTranslated(0,80,15);
	glutSolidTeapot(5);
	glPopMatrix();*/
}

void salib(){
	glPushMatrix();
	glTranslatef(0,0,4.9);
	salib1();
	glPopMatrix();
}

void draw_arch(GLfloat width, GLfloat height, GLint slices,float posisi_x,float posisi_y,float posisi_z,float tebel_z,float tebelling){
	glTranslated(posisi_x,posisi_y,0);
    glPushMatrix();
        GLfloat offset = 0.5f;
        glScalef(width/2,height/(1+offset),1.0f);
        //glBegin(GL_QUADS);
        for( unsigned int i = 0; i < slices; ++i ) {
        	glBegin(GL_POLYGON);
            float curAngle = ( ( i + 0 ) / (float)slices ) * 3.14159;
            float nxtAngle = ( ( i + 1 ) / (float)slices ) * 3.14159;
            glVertex3f( cos( curAngle ), sin( curAngle ),posisi_z );
            glVertex3f( cos( nxtAngle )+tebelling, sin( nxtAngle ),posisi_z );
        	
            glVertex3f( cos( nxtAngle ), sin( nxtAngle )+tebelling ,posisi_z );
            glVertex3f( cos( curAngle )+tebelling , sin( curAngle )+tebelling ,posisi_z );//--
            glEnd();
            //==atas
            glBegin(GL_POLYGON);
            glVertex3f( cos( curAngle ), sin( curAngle ),posisi_z );
            glVertex3f( cos( nxtAngle )+tebelling , sin( nxtAngle ),posisi_z );
            glVertex3f( cos( curAngle ), sin( curAngle ),posisi_z+tebel_z );
            glVertex3f( cos( nxtAngle )+tebelling , sin( nxtAngle ),posisi_z+tebel_z );
            glEnd();
            //==bawah
            glBegin(GL_POLYGON);
            glVertex3f( cos( nxtAngle ), sin( nxtAngle )+tebelling ,posisi_z );
            glVertex3f( cos( curAngle )+tebelling , sin( curAngle )+tebelling ,posisi_z );
            glVertex3f( cos( nxtAngle ), sin( nxtAngle )+tebelling ,posisi_z+tebel_z );
            glVertex3f( cos( curAngle )+tebelling , sin( curAngle )+tebelling ,posisi_z+tebel_z );
            glEnd();
            //==tengah
            glBegin(GL_POLYGON);
            glVertex3f( cos( nxtAngle )+tebelling , sin( nxtAngle ),posisi_z );
            glVertex3f( cos( nxtAngle ), sin( nxtAngle )+tebelling ,posisi_z );
            glVertex3f( cos( nxtAngle )+tebelling , sin( nxtAngle ),posisi_z+tebel_z );
            glVertex3f( cos( nxtAngle ), sin( nxtAngle )+tebelling ,posisi_z+tebel_z );
            glEnd();
            //==antara
            glBegin(GL_POLYGON);
            glVertex3f( cos( curAngle ), sin( curAngle ),posisi_z );
            glVertex3f( cos( curAngle )+tebelling , sin( curAngle )+tebelling ,posisi_z );
            glVertex3f( cos( curAngle ), sin( curAngle ),posisi_z+tebel_z );
            glVertex3f( cos( curAngle )+tebelling , sin( curAngle )+tebelling ,posisi_z+tebel_z );
            glEnd();
        }
        //glEnd();
    glPopMatrix();
}

void batudiatap(){
	for(a=0;a<=15;a++){//kiri
	glColor3f(0.392, 0.42, 0.443);
	kube(-13+a,15+a,25,4,4,1);
	a=a+3;
	}
	
	for(a=0;a<=15;a++){//kanan
	glColor3f(0.392, 0.42, 0.443);
	kube(17-a,15+a,25,4,4,1);
	a=a+3;
	}
	
	glBegin(GL_POLYGON);//depan kiri
	glColor3f(0.392, 0.42, 0.443);
	glVertex3f(-17,15,25.1);
	glVertex3f(-3,30,25.1);
	glVertex3f(3,30,25.1);
	glVertex3f(-13,15,25.1);
	glEnd();
	
	glBegin(GL_POLYGON);//depan kiri
	glColor3f(0.392, 0.42, 0.443);
	glVertex3f(22,15,25.1);
	glVertex3f(7,30,25.1);
	glVertex3f(1,30,25.1);
	
	glVertex3f(17,15,25.1);
	glEnd();
}

void atapdepanluar(){
	glBegin(GL_POLYGON);//kanan
	glColor3f(0.7, 0.3, 0.3);
	glVertex3f(-17,15,25);
	glVertex3f(-17,15,20);
	glVertex3f(-3,30,20);
	glVertex3f(-3,30,25);
	glEnd();
	glBegin(GL_POLYGON);//kiri
	glColor3f(0.7, 0.3, 0.3);
	glVertex3f(20,15,25);
	glVertex3f(20,15,20);
	glVertex3f(6.5,30,20);
	glVertex3f(6.5,30,25);
	glEnd();
	glBegin(GL_POLYGON);//depan
	glColor4f(1, 0.98, 0.80,alf);
	glVertex3f(-17,15,25);
	glVertex3f(20,15,25);
	glVertex3f(6.5,30,25);
	glVertex3f(-3,30,25.);
	glEnd();
	glBegin(GL_POLYGON);//belakang
	glColor3f(0.784, 0.7840, 0.737);
	glVertex3f(-17,15,20);
	glVertex3f(20,15,20);
	glVertex3f(6.5,30,20);
	glVertex3f(-3,30,20);
	glEnd();
}

void atapdalam(){
	glPushMatrix();
	glRotatef(90,0,1,0);
	glColor3f(0.95,0.95,0.95);
	draw_arch(60,10,180,38,25,-60.4,120.8,0.1);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-50.0, 0.0, 0.0);
	//kanan
	
	glBegin(GL_TRIANGLES);
	glColor3f(0.784, 0.7840, 0.737);
	glVertex3f(110,25,0);
	glVertex3f(110,25,-80);
	glVertex3f(110,45,-40);
	glEnd();
	
	//kiri
	glBegin(GL_TRIANGLES);
	glVertex3f(-10,25,0);
	glVertex3f(-10,25,-80);
	glVertex3f(-10,45,-40);
	glEnd();
	glPopMatrix();
}

void atasdepanpintu(){
	glPushMatrix();
	glColor3f(0,0.5,0);
	glColor3f(0.784, 0.7840, 0.737);
	draw_arch(20,15,180,-0.1,0,1,23,0.1);
	draw_arch(20,15,180,-0.5,0,1,23,0.2);
	draw_arch(20,15,180,-1  ,0,1,23,0.3);
	glPopMatrix();
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,1.2,4,20,2,8);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,1.2,20,20,2,8);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,8,24,20,13.9,2);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,8,24,20,13.9,2);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,8,0,20,13.9,2);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,8,17,20,13.9,2);
	glColor4f(1, 0.98, 0.80,alf);
	kube(0,8,7,20,13.9,2);
	//-----------
	glColor3f(0,0.5,0);
	glColor3f(0.392, 0.42, 0.443);
	draw_arch(20,15,180,-0.1,0,25,5,0.1);
	draw_arch(20,15,180,-0.1,-0.2,25,5,0.1);
	draw_arch(20,15,180,-0.5,0,25,5,0.2);
	draw_arch(20,15,180,-1  ,0,25,5,0.3);
	//--------
	glColor3f(0.392, 0.42, 0.443);
	kube(-11.5,0,27,8,2.5,5);
	glColor3f(0.392, 0.42, 0.443);
	kube(14.5,0,27,8,2.5,5);
	atapdepanluar();
	batudiatap();
}

void lingkaran(float jari2, float jumlah_titik, float x_tengah, float y_tengah,float z,float sudut_awal, float sudut_akhir) {

glBegin(GL_POLYGON);
 for(h=0;h<=10;h++){
 for (i=sudut_awal;i<=sudut_akhir;i++){
 float sudut=i*(PI/jumlah_titik);
 float x=x_tengah+jari2*cos(sudut);
 float y=y_tengah+jari2*sin(sudut);
 glVertex3f(x,y,z);
 //glVertex3f(xx,yy,z);
 
 //glColor3f(0,0,0);
 	}
 }
 //glVertex3f(x_tengah-jari2,y_tengah+jari2+10,z);
 //glVertex3f(x_tengah+jari2,y_tengah+jari2+10,z);
 glEnd();
 }

void lawang(){
	glColor4f(0.54,0.27,0.07,alf);//kiri
	kubewire(-5,-12,25,10,25,1);
	glColor4f(0.54,0.27,0.07,alf);//kanan
	kubewire(5,-12,25,10,25,1);
	glColor3f(0,0,0);
	lingkaran(6,180,0,2,25.1,0,180);//ceritanya jendela
	glColor3f(0.392, 0.42, 0.443);//sebelahlawang
	kube(9,-12,25.001,2,25,1.1);
	glColor3f(0.392, 0.42, 0.443);//sebelahlawang
	kube(-9,-12,25.001,2,25,1.1);
}

void mimbar(){
	glPushMatrix();
	glTranslatef(-40,-18,-36.3);
	glScalef(1,1.1,1.5);
	
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(0,0,0,5,10,0.5);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(0,0,-5,5,10,0.5);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(2.5,0,-2.5,0.5,10,5);
	glColor4f(0.93,0.411,0.117,alf);
	kubewire(1.25,4.8,-2.5,3.5,0.5,6);
	
	glPopMatrix();
}

void ukuran(int lebar, int tinggi){
    if (tinggi == 0) tinggi = 1;
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);

	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		{
			mouseDown = true;
			xdiff = x - yrot;
			ydiff = -y + xrot;
		}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y){
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
 
		glutPostRedisplay();
	}
}

void idle(){
	if (!mouseDown)
	{
		if (mosengenable==1)		yrot += 0.1;
	} 
glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
  switch (key)
    {
    case ' ':
		if(mosengenable==0) mosengenable=1;
		else mosengenable=0;
        break;
    case '1':
		if(tembokenable==0) tembokenable=1;
		else tembokenable=0;
        break;
	case '2':
		if(atapenable==0) atapenable=1;
		else atapenable=0;
        break;
	case '9':
		tembokenable=1;
		atapenable=1;
        break;		
    case '0':
		tembokenable=0;
		atapenable=0;
        break;		 
	case 'w':
    case 'W':
		zpos += 3.0;
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
		xpos += 3.0;
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
		zpos += -3.0;
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
		xpos += -3.0;
        glTranslatef(-3.0, 0.0, 0.0);
        break;
	case 'q':
	case 'Q':
		ypos += 3.0;
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case 'z':
	case 'Z':
		ypos += -3.0;
        glTranslatef(0.0, -3.0, 0.0);
        break;}
    tampil();
}

void init(void){
    glClearColor(0, 0, 0, 0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    	//pencahayaan
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
		//glEnable(GL_LIGHTING);			
		glEnable(GL_LIGHT0);
		//set cahaya
		GLfloat qaAmbientLight[] = {0.2,0.2,0.2,1.0};
		GLfloat qaDiffuseLight[] = {0.2,0.2,0.2,02};
		GLfloat qaSpecularLight[] = {1,1,1,1};
		glLightfv(GL_LIGHT0, GL_AMBIENT,qaAmbientLight);
		glLightfv(GL_LIGHT0,GL_DIFFUSE,qaDiffuseLight);
		glLightfv(GL_LIGHT0,GL_SPECULAR,qaSpecularLight);
		//posisi cahaya
		GLfloat posisilampu[] = {0,160,200,1};
		glLightfv(GL_LIGHT0,GL_POSITION,posisilampu);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);    
    glLineWidth(3.0f);
//	glEnable(GL_LIGHTING);

}

void tampil(void){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);	 
	glRotatef(xrot+20, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot-20, 0.0f, 1.0f, 0.0f);	
	
	glColor4f(0.7,0.7,0.7,0);//tanah
	kube(0,-26,0,180,1,250);
	
	if(tembokenable==1){
		glPushMatrix();
		tembok();
		salib();
		glPushMatrix();
		atasdepanpintu();
		glPopMatrix();
		lawang();
		glPopMatrix();
	}
	
	if(atapenable==1){
		atap();
		atapdalam();
		
	}
	
	lantai();
		
	glFlush();
	glutSwapBuffers();

}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1080, 720);
    glutInitWindowPosition(250, 80);
    glutCreateWindow("GPIB Tamansari Salatiga");
    init();
	glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutIdleFunc(idle);
    glutReshapeFunc(ukuran);  
    glutMainLoop();
    return 0;
}
