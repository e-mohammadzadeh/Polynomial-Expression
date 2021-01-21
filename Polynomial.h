#pragma once
#include "stdafx.h"
#include<iostream>
#include "Polynomial.h"	
#include "Terms.h"

using namespace std;

class Polynomial
{
public:
	Terms terms;
	void setPoly(double, int);
	Polynomial polySingleMultiplication(Polynomial, double, int);
	int polySize(Polynomial);
	Polynomial polyMultiplication(Polynomial, Polynomial);
	Polynomial polySummation(Polynomial, Polynomial);
	Polynomial polySubtraction(Polynomial, Polynomial);
	int compare2Exponent(int, int);
	bool isZero(Polynomial);
	void polyShow(Polynomial);
};