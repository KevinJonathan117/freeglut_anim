#pragma once
#include"Vector.h"
#include"Matrix.h"

class Ccamera {
private:
	vector3D posisiKamera, titikPandang, orientasi, U, V, N; 
	Matrix camera;
public:
	Ccamera (vector3D _u, vector3D _v, vector3D _n) {
		posisiKamera = _u;
		titikPandang = _v;
		orientasi = _n;

        N = titikPandang - posisiKamera;
        N = N.unit();

        /*vector3D a = N ^ orientasi;
        vector3D b = a * N;
        V = orientasi - b; // V = orientasi - N * (N ^ orientasi)
        V = V.unit();*/
        V = orientasi - N * (N ^ orientasi);
        V = V.unit();

        U = V * N;
        U = U.unit();

        double Udot, Vdot, Ndot;
        vector3D nU = posisiKamera * -1;
        Udot = nU ^ U;
        Vdot = nU ^ V;
        Ndot = nU ^ N;

        camera.setElement(0, 0, U.x()); //Ux Uy Uz Udot
        camera.setElement(0, 1, U.y()); //Vx Vy Vz Vdot
        camera.setElement(0, 2, U.z()); //Nx Ny Nz Ndot
        camera.setElement(0, 3, Udot);  //0  0  0  1

        camera.setElement(1, 0, V.x());
        camera.setElement(1, 1, V.y());
        camera.setElement(1, 2, V.z());
        camera.setElement(1, 3, Vdot);

        camera.setElement(2, 0, N.x());
        camera.setElement(2, 1, N.y());
        camera.setElement(2, 2, N.z());
        camera.setElement(2, 3, Ndot);

        camera.setElement(3, 0, 0);
        camera.setElement(3, 1, 0);
        camera.setElement(3, 2, 0);
        camera.setElement(3, 3, 1);
	}
	Ccamera(double _ux, double _uy, double _uz, double _vx, double _vy, double _vz, double _nx, double _ny, double _nz) {
		posisiKamera.set(_ux, _uy, _uz);
		titikPandang.set(_vx, _vy, _vz);
		orientasi.set(_nx, _ny, _nz);

        N = titikPandang - posisiKamera;
        N = N.unit();

        vector3D a = N ^ orientasi;
        vector3D b = a * N;
        V = orientasi - b;
        V = V.unit();

        U = V * N;
        U = U.unit();

        double Udot, Vdot, Ndot;
        vector3D nU = posisiKamera * -1;
        Udot = nU ^ U;
        Vdot = nU ^ V;
        Ndot = nU ^ N;

        camera.setElement(0, 0, U.x());
        camera.setElement(0, 1, U.y());
        camera.setElement(0, 2, U.z());
        camera.setElement(0, 3, Udot);

        camera.setElement(1, 0, V.x());
        camera.setElement(1, 1, V.y());
        camera.setElement(1, 2, V.z());
        camera.setElement(1, 3, Vdot);

        camera.setElement(2, 0, N.x());
        camera.setElement(2, 1, N.y());
        camera.setElement(2, 2, N.z());
        camera.setElement(2, 3, Ndot);

        camera.setElement(3, 0, 0);
        camera.setElement(3, 1, 0);
        camera.setElement(3, 2, 0);
        camera.setElement(3, 3, 1);
	}
    Matrix getMatrix() {
        return camera;
    }
    void setCamera(vector3D _u, vector3D _v, vector3D _n) {
        posisiKamera = _u;
        titikPandang = _v;
        orientasi = _n;

        N = titikPandang - posisiKamera;
        N = N.unit();

        /*vector3D a = N ^ orientasi;
        vector3D b = a * N;
        V = orientasi - b; // V = orientasi - N * (N ^ orientasi)
        V = V.unit();*/
        V = orientasi - N * (N ^ orientasi);
        V = V.unit();

        U = V * N;
        U = U.unit();

        double Udot, Vdot, Ndot;
        vector3D nU = posisiKamera * -1;
        Udot = nU ^ U;
        Vdot = nU ^ V;
        Ndot = nU ^ N;

        camera.setElement(0, 0, U.x()); //Ux Uy Uz Udot
        camera.setElement(0, 1, U.y()); //Vx Vy Vz Vdot
        camera.setElement(0, 2, U.z()); //Nx Ny Nz Ndot
        camera.setElement(0, 3, Udot);  //0  0  0  1

        camera.setElement(1, 0, V.x());
        camera.setElement(1, 1, V.y());
        camera.setElement(1, 2, V.z());
        camera.setElement(1, 3, Vdot);

        camera.setElement(2, 0, N.x());
        camera.setElement(2, 1, N.y());
        camera.setElement(2, 2, N.z());
        camera.setElement(2, 3, Ndot);

        camera.setElement(3, 0, 0);
        camera.setElement(3, 1, 0);
        camera.setElement(3, 2, 0);
        camera.setElement(3, 3, 1);
    }
};