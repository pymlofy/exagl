/*
 * exagl.cpp
 *
 *  Created on: Sep 23, 2012
 *      Author: rob
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string>
#include "svg_subprocess_character_generator.h"

const int DIM_X = 1600;
const int DIM_Y = 200;

SvgSubprocessCharacterGenerator* scoreboard;

float bg_r, bg_g, bg_b, bg_m;

void quit(int code) {
	delete scoreboard;
	exit(code);
}

void display() {
	glClearColor(bg_r * bg_m, bg_g * bg_m, bg_b * bg_m, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	scoreboard->paint_gl();
	glutSwapBuffers();
	scoreboard->output_pipe( ).get( );
}

void keyboard( unsigned char key, int x, int y ) {
	int mod = glutGetModifiers();

	// Esc
	if (key == 27 && mod == GLUT_ACTIVE_SHIFT) {
		quit(0);
	}
}

void specialkey( int key, int x, int y ) {
//	int mod = glutGetModifiers();

	// F1-F12
	if (key >= GLUT_KEY_F1 && key <= GLUT_KEY_F12)
	{
		switch (key)
		{
		case GLUT_KEY_F1:
			bg_m = 0.25f;
			break;
		case GLUT_KEY_F2:
			bg_m = 0.5f;
			break;
		case GLUT_KEY_F3:
			bg_m = 0.75f;
			break;
		case GLUT_KEY_F4:
			bg_m = 1.0f;
			break;
		case GLUT_KEY_F5:
			bg_r = bg_g = bg_b = 1.0f;
			break;
		case GLUT_KEY_F6:
			bg_r = 1.0f;
			bg_g = bg_b = 0.0f;
			break;
		case GLUT_KEY_F7:
			bg_r = bg_g = 1.0f;
			bg_b = 0.0f;
			break;
		case GLUT_KEY_F8:
			bg_g = 1.0f;
			bg_r = bg_b = 0.0f;
			break;
		case GLUT_KEY_F9:
			bg_r = 0.0f;
			bg_g = bg_b = 1.0f;
			break;
		case GLUT_KEY_F10:
			bg_r = bg_g = 0.0f;
			bg_b = 1.0f;
			break;
		case GLUT_KEY_F11:
			bg_r = bg_b = 1.0f;
			bg_g = 0.0f;
			break;
		case GLUT_KEY_F12:
			bg_r = bg_g = bg_b = 0.0f;
			break;
		default:
			break;
		}
	}
}

void timer(int parm) {
	glutPostRedisplay();
	glutTimerFunc( 1000/60, timer, 1 );
}

void make2d(int x, int y) {
	int oldmode;
	glGetIntegerv(GL_MATRIX_MODE, &oldmode);
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, (float) x, 0.0f, (float) y, 0.0f, 1.0f);
	glPopMatrix();
	glMatrixMode(oldmode);
}

int main(int argc, char* argv[]) {

	// initialize GLUT
	int argcp = 1;
    glutInit( &argcp , &(argv[0]) );

    // set RGBA mode with double and depth buffers
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutGameModeString( "1024x768:32@60" );

    // start fullscreen game mode
//    glutEnterGameMode();
//	fprintf(stderr, "Game mode entered\n");

    // start windowed mode
	glutInitWindowSize(DIM_X, DIM_Y);
	glutInitWindowPosition(0, 0);
	int win = glutCreateWindow("Exaboard OpenGL renderer");
    make2d(DIM_X, DIM_Y);

    // set blend mode
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    std::string ruby_cmd = "ruby ";
    if (argc >= 2) { ruby_cmd.append(argv[1]); }
    else {
    	fprintf(stderr, "No .rb file specified\n");
    	return 1;
    }
    scoreboard =
    	new SvgSubprocessCharacterGenerator(ruby_cmd.c_str());
    scoreboard->set_position(20, DIM_Y - 20);

    bg_r = bg_g = bg_b = 1.0f;
    bg_m = 0.75f;

	// setup window callbacks
    glutDisplayFunc( display );
	glutKeyboardFunc( keyboard );
	glutSpecialFunc( specialkey );
    glutTimerFunc( 1000/60, timer, 1 );
	fprintf(stderr, "Callbacks loaded\n");

	// enter main loop
    glutMainLoop();

	quit(0);
	return 0;
}
