#pragma once
#include "stdafx.h"
#include "Terms.h"
#include "Components.h"	
#include<iostream>

using namespace std;

#define termSize 100

class Terms
{
private:
	Components components[termSize];
	void swapTerms(int);
public:
	int length;
	Terms();
	void setTerms(double, int);
	Components getTerms(int);
	bool attachTerms(double, int);
	int setSize();
	void removeTerms(double, int, int);
	void deleteTerms(double, int, int);
	void sortTerms();
	void sameTerms();
	void show();
};