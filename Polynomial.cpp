#include "stdafx.h"
#include "Polynomial.h"
#include "Terms.h"
#include "Components.h"
#include<iostream>

using namespace std;

void Polynomial::setPoly(double coef, int exp)
{
	terms.setTerms(coef, exp);
}


int Polynomial::polySize(Polynomial poly)
{
	return poly.terms.length;
}


Polynomial Polynomial::polySingleMultiplication(Polynomial poly, double coef, int exp)
{
	Polynomial answerPoly;
	for (int i = 0; i < polySize(poly); i++)
	{
		answerPoly.setPoly(poly.terms.getTerms(i).coefficient * coef, poly.terms.getTerms(i).exponent + exp);
	}
	answerPoly.terms.sameTerms();
	answerPoly.terms.sortTerms();
	answerPoly.terms.length = answerPoly.terms.setSize();
	return answerPoly;
}


Polynomial Polynomial::polyMultiplication(Polynomial firstPoly, Polynomial secondPoly)
{
	Polynomial answerPoly;
	for (int i = 0; i < polySize(firstPoly); i++)
	{
		for (int j = 0; j < polySize(secondPoly); j++)
		{
			answerPoly.setPoly(firstPoly.terms.getTerms(i).coefficient * secondPoly.terms.getTerms(j).coefficient,
				firstPoly.terms.getTerms(i).exponent + secondPoly.terms.getTerms(j).exponent);
		}
	}
	answerPoly.terms.sameTerms();
	answerPoly.terms.sortTerms();
	answerPoly.terms.length = answerPoly.terms.setSize();
	return answerPoly;
}


Polynomial Polynomial::polySummation(Polynomial firstPoly, Polynomial secondPoly)
{
	Polynomial answerPoly;
	double coefficient;
	int startA = 0, startB = 0, finishA = firstPoly.terms.length, finishB = secondPoly.terms.length;
	while (startA <= finishA && startB <= finishB)
	{
		switch (compare2Exponent(firstPoly.terms.getTerms(startA).exponent, secondPoly.terms.getTerms(startB).exponent))
		{
		case -1:
		{
			answerPoly.terms.setTerms(secondPoly.terms.getTerms(startB).coefficient, secondPoly.terms.getTerms(startB).exponent);
			startB++;
			break;
		}
		case 0:
		{
			coefficient = firstPoly.terms.getTerms(startA).coefficient + secondPoly.terms.getTerms(startB).coefficient;
			if (coefficient)
			{
				answerPoly.terms.setTerms(coefficient, firstPoly.terms.getTerms(startA).exponent);
			}
			startA++;
			startB++;
			break;
		}
		case 1:
		{
			answerPoly.terms.setTerms(firstPoly.terms.getTerms(startA).coefficient, firstPoly.terms.getTerms(startA).exponent);
			startA++;
			//break;
		}
		}
	}
	for (; startA <= finishA; startA++)
	{
		answerPoly.terms.setTerms(firstPoly.terms.getTerms(startA).coefficient, firstPoly.terms.getTerms(startA).exponent);
	}
	for (; startB <= finishB; startB++)
	{
		answerPoly.terms.setTerms(secondPoly.terms.getTerms(startB).coefficient, secondPoly.terms.getTerms(startB).exponent);
	}
	answerPoly.terms.sameTerms();
	answerPoly.terms.sortTerms();
	answerPoly.terms.length = answerPoly.terms.setSize();
	return answerPoly;
}


Polynomial Polynomial::polySubtraction(Polynomial firstPoly, Polynomial secondPoly)
{
	Polynomial answerPoly, negetivePoly;
	for (int i = 0; i < polySize(secondPoly); i++)
	{
		negetivePoly.setPoly((secondPoly.terms.getTerms(i).coefficient * -1), secondPoly.terms.getTerms(i).exponent);
		answerPoly = polySummation(firstPoly, negetivePoly);
	}
	answerPoly.terms.sameTerms();
	answerPoly.terms.sortTerms();
	return answerPoly;
}


int Polynomial::compare2Exponent(int firstExp, int secondExp)
{
	if (firstExp > secondExp)
	{
		return 1;
	}
	if (firstExp == secondExp)
	{
		return 0;
	}
	if (firstExp < secondExp)
	{
		return -1;
	}
}


bool Polynomial::isZero(Polynomial poly)
{
	if (poly.terms.getTerms(0).coefficient == NULL && poly.terms.getTerms(0).exponent == NULL && poly.terms.length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Polynomial::polyShow(Polynomial poly)
{
	if (isZero(poly))
	{
		cout << "This Polynomial is Empty\n";
	}
	else
	{
		if (poly.terms.length == 1)
		{
			if (poly.terms.getTerms(0).exponent == 0)
			{
				cout << poly.terms.getTerms(0).coefficient;
			}
			else if (poly.terms.getTerms(0).exponent == 1)
			{
				cout << poly.terms.getTerms(0).coefficient << "x";
			}
			else
			{
				cout << poly.terms.getTerms(0).coefficient << "x^" << poly.terms.getTerms(0).exponent;
			}
		}
		else
		{
			cout << poly.terms.getTerms(0).coefficient << "x ^" << noshowpos << poly.terms.getTerms(0).exponent << " ";
			for (int i = 1; i < poly.terms.length; i++)
			{
				if (poly.terms.getTerms(i).exponent == 0 && poly.terms.getTerms(i).coefficient == 0)
				{
					poly.terms.deleteTerms(poly.terms.getTerms(i).coefficient, poly.terms.getTerms(i).exponent, i);
				}
				else if (poly.terms.getTerms(i).exponent == 0 && poly.terms.getTerms(i).coefficient != 0)
				{
					cout << " " << showpos << poly.terms.getTerms(i).coefficient;
				}
				else if (poly.terms.getTerms(i).exponent == '1' || poly.terms.getTerms(i).exponent == 1)
				{
					cout << " " << showpos << poly.terms.getTerms(i).coefficient << "x";
				}
				else
				{
					cout << " " << showpos << poly.terms.getTerms(i).coefficient << "x ^" << noshowpos << poly.terms.getTerms(i).exponent;
				}
			}

		}
	}
	cin.get();
}