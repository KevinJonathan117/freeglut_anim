#include<GL/freeglut.h>
#include<iostream>
#include"Vector.h"
#include "Matrix.h"
#include"Color.h"
#include"Light.h"
#include"Mesh.h"
#include"Camera.h"
#include<sstream>
#include<fstream>
using namespace std;

int windowWidth = 800;
int windowHeight = 800;
int orthoX = 100;
int orthoY = 100;
int orthoZ = 100;
vector3D trans, scalingV;
vector3D lightPosition(0, 10, 10);
Ccolor lightColor(240, 240, 240);
Clight light(lightPosition, lightColor, 0.6);
double posisiKameraX = 0, posisiKameraY = 6, posisiKameraZ = 13, sudutPandangX = 0, sudutPandangY = 6, sudutPandangZ = 0, orientasiX = 0, orientasiY = 7, orientasiZ = 13;
vector3D posisiKamera(posisiKameraX, posisiKameraY, posisiKameraZ), sudutPandang(sudutPandangX, sudutPandangY, sudutPandangZ), orientasi(orientasiX, orientasiY, orientasiZ);
Ccamera camera(posisiKamera, sudutPandang, orientasi);
double posisiKameraX1 = 0, posisiKameraY1 = 6, posisiKameraZ1 = 26, sudutPandangX1 = 0, sudutPandangY1 = 6, sudutPandangZ1 = 0, orientasiX1 = 0, orientasiY1 = 7, orientasiZ1 = 26;
vector3D posisiKamera1(posisiKameraX1, posisiKameraY1, posisiKameraZ1), sudutPandang1(sudutPandangX1, sudutPandangY1, sudutPandangZ1), orientasi1(orientasiX1, orientasiY1, orientasiZ1);
Ccamera camera1(posisiKamera1, sudutPandang1, orientasi1);
vector3D drawPoint[10000];

double transX = 0, transY = 0, transZ = 0, rotationX = 0, rotationY = 0, rotationZ = 0;
struct scaleSize {
	double x = 1;
	double y = 1;
	double z = 1;
};
scaleSize scalesize;
Matrix translation, rotateX, rotateY, rotateZ, scale, position;
Mesh mesh, table;

void initiate()
{
	mesh.ReadMesh("mesh.obj");
	table.ReadMesh("StylishDesk.obj");
	for (int i = 0; i < mesh.getVertexCount(); i++) {
		drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
	}
	mesh.setVertex(drawPoint);
	for (int i = 0; i < table.getVertexCount(); i++) {
		drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
	}
	table.setVertex(drawPoint);
	glEnable(GL_DEPTH_TEST);
}

void display() {
	//clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//draw the object
	///mesh.draw(light, drawPoint);
	mesh.draw(light);
	table.draw1(light);
	//swap buffer
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	double move = 5;

	/*if (key == 'w')
	{
		rotationX = rotationX + move;
		rotateX.rotateX(rotationX);
	}
	if (key == 'a')
	{
		rotationY = rotationY - move;
		rotateY.rotateY(rotationY);
	}
	if (key == 's')
	{
		rotationX = rotationX - move;
		rotateX.rotateX(rotationX);
	}
	if (key == 'd')
	{
		rotationY = rotationY + move;
		rotateY.rotateY(rotationY);
	}
	if (key == 'e')
	{
		rotationZ = rotationZ + move;
		rotateZ.rotateZ(rotationZ);
	}
	if (key == 'f')
	{
		rotationZ = rotationZ - move;
		rotateZ.rotateZ(rotationZ);
	}
	if (key == 'i')
	{
		transY = transY + move - 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == 'j')
	{
		transX = transX - move + 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == 'k')
	{
		transY = transY - move + 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == 'l')
	{
		transX = transX + move - 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == 'o')
	{
		transZ = transZ - move + 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == 'p')
	{
		transZ = transZ + move - 4;
		trans.set(transX, transY, transZ - 10);
		translation.translate(trans);
	}
	if (key == ',')
	{
		scalesize.x *= 0.5;
		scalesize.y *= 0.5;
		scalesize.z *= 0.5;
		scalingV.set(scalesize.x, scalesize.y, scalesize.z);
		scale.scaling(scalingV);
	}
	if (key == '.')
	{
		scalesize.x *= 2.0;
		scalesize.y *= 2.0;
		scalesize.z *= 2.0;
		scalingV.set(scalesize.x, scalesize.y, scalesize.z);
		scale.scaling(scalingV);
	}*/
	if (key == 'a') {
		posisiKameraX -= 1;
		sudutPandangX -= 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraX1 -= 1;
		sudutPandangX1 -= 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}

	if (key == 'd') {
		posisiKameraX += 1;
		sudutPandangX += 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraX1 += 1;
		sudutPandangX1 += 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	if (key == 'w') {
		posisiKameraY -= 1;
		sudutPandangY -= 1;
		orientasiY -= 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraY1 -= 1;
		sudutPandangY1 -= 1;
		orientasiY1 -= 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}

	if (key == 's') {
		posisiKameraY += 1;
		sudutPandangY += 1;
		orientasiY += 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraY1 += 1;
		sudutPandangY1 += 1;
		orientasiY1 += 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	if (key == ',')
	{
		posisiKameraZ += 1;
		sudutPandangZ += 1;
		orientasiZ += 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraZ1 += 1;
		sudutPandangZ1 += 1;
		orientasiZ1 += 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	if (key == '.')
	{
		posisiKameraZ -= 1;
		sudutPandangZ -= 1;
		orientasiZ -= 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraZ1 -= 1;
		sudutPandangZ1 -= 1;
		orientasiZ1 -= 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	/*position = translation * rotateX * rotateY * rotateZ * scale;
	mesh.transform(position);*/
	glutPostRedisplay();
}

void reshape(int width, int height) {
	glViewport(0, 0, width, height);
	double aspect = 1.0 * width / height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 5000);
}

int counterTimer = 0;
void timer(int)
{
	if (counterTimer <= 5 && counterTimer >= 3) {
		posisiKameraY -= 1;
		sudutPandangY -= 1;
		orientasiY -= 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraY1 -= 1;
		sudutPandangY1 -= 1;
		orientasiY1 -= 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	if (counterTimer <= 7 && counterTimer >= 6) {
		posisiKameraZ -= 1;
		sudutPandangZ -= 1;
		orientasiZ -= 1;
		posisiKamera.set(posisiKameraX, posisiKameraY, posisiKameraZ);
		sudutPandang.set(sudutPandangX, sudutPandangY, sudutPandangZ);
		camera.setCamera(posisiKamera, sudutPandang, orientasi);
		for (int i = 0; i < mesh.getVertexCount(); i++) {
			drawPoint[i] = camera.getMatrix() * mesh.getVertexOriginalIndex(i);
		}
		mesh.setVertex(drawPoint);

		posisiKameraZ1 -= 1;
		sudutPandangZ1 -= 1;
		orientasiZ1 -= 1;
		posisiKamera1.set(posisiKameraX1, posisiKameraY1, posisiKameraZ1);
		sudutPandang1.set(sudutPandangX1, sudutPandangY1, sudutPandangZ1);
		camera1.setCamera(posisiKamera1, sudutPandang1, orientasi1);
		for (int i = 0; i < table.getVertexCount(); i++) {
			drawPoint[i] = camera1.getMatrix() * table.getVertexOriginalIndex(i);
		}
		table.setVertex(drawPoint);
	}
	counterTimer++;
	glutTimerFunc(1000 / 3.0, timer, 0);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Teapot Window");
	//display
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	//glutKeyboardFunc(keyboard);

	///glOrtho(-orthoX, orthoX, -orthoY, orthoY, -orthoZ, orthoZ);
	//Background Color: black
	glClearColor(0, 0, 0, 0);
	initiate();
	timer(0);
	glutMainLoop();
	return 0;
}