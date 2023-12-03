#include<Windows.h>
#include<GL/glut.h>
#include<time.h>
int x,y,ch = -1, win, count, aspect, px=9, py=0, endx = 8, endy = 20, n=15, m=21 , co[] = {9, 0, 8, 20};
clock_t start, endd;
char t[2];
int maze[15][21] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
					{1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1},
					{1,0,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},
					{1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1},
					{1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
					{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1},
					{1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1},
					{1,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
					{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0},
					{0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
					{1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
					{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1},
					{1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},
					{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
					{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
bool valid(int x, int y){
	return x >= 0 && x < n && y >=0  && y < m;
}
void currentPoint()
{
	int sz = 5, addx = -180 + 13 * co[1] , addy = 100 - co[0] * 13;
	glBegin(GL_QUADS);
	//top
	
	glColor3f(.3,.3,.3);
	glVertex3f( sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,sz);
    glVertex3f(sz + addx,sz + addy,sz);

	//botton
	glColor3f(1,.3,.3);
	glVertex3f( sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,-sz + addy,sz);

	//right
	glColor3f(1,.3,.3);
	glVertex3f(sz + addx,sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,sz + addy,sz);

	//left
	glColor3f(1,.5,.5);
	glVertex3f( -sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(-sz + addx,sz + addy,sz);

	//back
	glColor3f(1,.9,.9);
	glVertex3f( sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,-sz);

	//front
	glColor3f(1,.9,.9);
	glVertex3f( sz + addx,sz + addy,sz);
    glVertex3f(-sz + addx,sz + addy,sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,-sz + addy,sz);
	glEnd();	
}
void wallPoint(float x, float y)
{
	int sz = 7, addx = x , addy = y;
	glBegin(GL_QUADS);
	//top
	
	glColor3f(.3,.3,.3);
	glVertex3f( sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,sz);
    glVertex3f(sz + addx,sz + addy,sz);

	//bottom
	glColor3f(.3,.3,.3);
	glVertex3f( sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,-sz + addy,sz);

	//right
	glColor3f(.5,.5,.5);
	glVertex3f(sz + addx,sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,sz + addy,sz);

	//left
	glColor3f(.5,.5,.5);
	glVertex3f( -sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(-sz + addx,sz + addy,sz);

	//back
	glColor3f(.9,.9,.9);
	glVertex3f( sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,sz + addy,-sz);
    glVertex3f(-sz + addx,-sz + addy,-sz);
    glVertex3f(sz + addx,-sz + addy,-sz);

	//front
	glColor3f(.9,.9,.9);
	glVertex3f( sz + addx,sz + addy,sz);
    glVertex3f(-sz + addx,sz + addy,sz);
    glVertex3f(-sz + addx,-sz + addy,sz);
    glVertex3f(sz + addx,-sz + addy,sz);
	glEnd();

}
void writeStr(int x, int y, char *str,void *font)
{
	int len = strlen(str);
	glRasterPos2f(x,y);
	for (int i = 0; i < len; i++)
	{
		glutBitmapCharacter(font,str[i]);
	}
}
void keyboard(unsigned char key , int x , int y){
	if(key == '1')
	{
		ch = 1;
	    co[0] = 9;
		co[1] = 0;
		start=clock();
	}
 
	else if(key=='2')exit(0);
	else if(key=='3')ch = -1;
}
void map(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();               
	glTranslatef(0, 0, -100.0f);
	glColor3f(1.0,1.0,0);
	writeStr(100,90,"TIME REMAINING : ", GLUT_BITMAP_HELVETICA_18);
	writeStr(100,80,"HURRY UP!",GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);
	writeStr(100,40,"Press 3 to go to main menu...",GLUT_BITMAP_HELVETICA_18);
	int num = 20 - count;
	t[0] = '0' + num / 10;
	t[1] = '0' + num % 10;
	writeStr(200,90,t, GLUT_BITMAP_HELVETICA_18);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(maze[i][j]){
				wallPoint(-180 + j * 13, 100 - i * 13); 
			}
		}
	}
	currentPoint();
	glFlush();
	glutSwapBuffers();
}
void cover(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();               
	glTranslatef(0, 0, -50.0f);
	glColor3f(1.0, 1.0, 0.0);
	writeStr(-50, 50, "Welcome To \"SOLVE THE MAZE\"", GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(1.0, 1.0, 1.0);
	writeStr(-50, 20, "Press 1 to start the game", GLUT_BITMAP_TIMES_ROMAN_24);
	writeStr(-50,10, "Press 2 to close the game", GLUT_BITMAP_TIMES_ROMAN_24);
	glutSwapBuffers();
	
}

void winScreen(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();               
	glTranslatef(0, 0, -50);
	glColor3f(0, 1, 0);
	writeStr(-50, 50, "CONGRATULATIONS!", GLUT_BITMAP_TIMES_ROMAN_24);
	writeStr(-50, 30, "You have solved the maze", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	writeStr(-50, 10, "Press 1 to restart the game ", GLUT_BITMAP_TIMES_ROMAN_24);
	writeStr(-50, 0, "Press 3 to go to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
	glutSwapBuffers();
}
void loseScreen(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	glLoadIdentity();               
	glTranslatef(0, 0, -50.0f);
	glColor3f(1, 0, 0);
	writeStr(-50, 50, "TIMEOVER", GLUT_BITMAP_TIMES_ROMAN_24);
	writeStr(-50, 30, "You have lost the game", GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	writeStr(-50, 10, "Press 3 to go to main menu", GLUT_BITMAP_TIMES_ROMAN_24);
	writeStr(-50, 0, "Press 1 to restart the game", GLUT_BITMAP_TIMES_ROMAN_24);
	glutSwapBuffers();
}
void display() {

	if(ch == -1)cover();
	
	else if(ch == 1)map();
	else if(ch == 2)loseScreen();
	else if(ch == 3)winScreen();
	if(co[0] == co[2] && co[1] == co[3]){
		ch = 3;
	}
	if(ch != 1){
		co[0] = 9; co[1] = 0;
	}
}

void SpecialKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		
		if(valid(co[0] - 1, co[1]) && !maze[co[0] - 1][co[1]])
			co[0]--;
		break;
	case GLUT_KEY_DOWN:
		if(valid(co[0] + 1, co[1]) && !maze[co[0] + 1][co[1]])
			co[0]++;
		break;

	case GLUT_KEY_LEFT:
		if(valid(co[0], co[1] - 1) && !maze[co[0]][co[1] - 1])
			co[1]--;
		break;
	case GLUT_KEY_RIGHT:
		if(valid(co[0], co[1] + 1) && !maze[co[0]][co[1] + 1])
			co[1]++;
		break;
	}
	display();
}
void reshape(GLsizei width, GLsizei height) {  
	if (height == 0) height = 1;             
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity();           
	gluPerspective(100, aspect, 0.7f, 200.0f);
	gluLookAt(10,0,50,20,0,-180,0,10,1);
	glMatrixMode(GL_MODELVIEW);    
	
}
void idle()
{
	if(ch == 1)
	{
		endd=clock();
		count=(endd-start)/CLOCKS_PER_SEC;
		if(count == 20){
			ch = 2;
		}
	}
	glutPostRedisplay();
}
int main(int agrc, char** agrv) {
	glutInit(&agrc, agrv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	int width = GetSystemMetrics(SM_CXSCREEN);
	int height = GetSystemMetrics(SM_CYSCREEN);
	glutInitWindowSize(width, height);
	glutCreateWindow("Solve The Maze");
	glEnable(GL_DEPTH_TEST);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	system("pause");
	return 0;
}