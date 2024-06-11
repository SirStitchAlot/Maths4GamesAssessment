#pragma once

#include <raymath.h>
#include <iostream>
#include <string>
using namespace std;



struct Matrix3 {
// ---- matrix 3 ---- // 
/*
	m00 m01 m02
	m10 m11 m12
	m20 m21 m22
 */

	float m00, m01, m02; // local x-axis
	float m10, m11, m12; // local y-axis
	float m20, m21, m22; // local z-axis
	
	// code
	
	string debug() {
		string s = "";
		s =	 to_string(m00) + " | " + to_string(m01) + " | " + to_string(m02) + " | \n";
		s += to_string(m10) + " | " + to_string(m11) + " | " + to_string(m12) + " | \n";
		s += to_string(m20) + " | " + to_string(m21) + " | " + to_string(m22) + " | \n";
		return s;
	}
};

struct CustomVector3 {
	float x, y, z;
	// code
};

class Helper{
public:
	Helper();
	~Helper();

};

