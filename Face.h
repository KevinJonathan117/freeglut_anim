#pragma once
class Face {
private:
	int a, b, c;
public:
	Face(int _a = 0, int _b = 0, int _c = 0) {
		a = _a;
		b = _b;
		c = _c;
	}
	void set(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	int getC() {
		return c;
	}
};