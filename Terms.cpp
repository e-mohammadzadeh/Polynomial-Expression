#include "stdafx.h"
#include "Terms.h"
#include "Components.h"
#include<iostream>

using namespace std;

Terms::Terms()
{
	length = 0;
	for (int i = 0; i < termSize; i++)
	{
		components[i].coefficient = NULL;
		components[i].exponent = NULL;
	}
}


void Terms::setTerms(double coef, int exp)
{
	components[length].coefficient = coef;
	components[length].exponent = exp;
	++length;
}


Components Terms::getTerms(int index)
{
	return components[index];
}


bool Terms::attachTerms(double coef, int exp)
{
	if (length < termSize)
	{
		components[length].coefficient = coef;
		components[length].exponent = exp;
		++length;
		return 1;
	}
	else
	{
		return 0;
	}

}


int Terms::setSize()
{
	for (int i = 0; i < length; i++)
	{
		if (components[i].coefficient == NULL && components[i].exponent == NULL)
		{
			length--;
		}
	}
	return length;
}


void Terms::removeTerms(double coef, int exp, int address)
{
	components[address].coefficient = NULL;
	components[address].exponent = NULL;
}


void Terms::deleteTerms(double coef, int exp, int index)
{
	if (coef == 0.0 && exp == 0)
	{
		components[index].coefficient = NULL;
		components[index].exponent == NULL;
	}
}


void Terms::sortTerms()
{
	for (int i = length - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (components[j].exponent < components[j + 1].exponent)
			{
				swapTerms(j);
			}
		}
	}
	length = setSize();
}


void Terms::swapTerms(int j)
{
	double coefTemp;
	int  expTemp;
	expTemp = components[j].exponent;
	components[j].exponent = components[j + 1].exponent;
	components[j + 1].exponent = expTemp;

	coefTemp = components[j].coefficient;
	components[j].coefficient = components[j + 1].coefficient;
	components[j + 1].coefficient = coefTemp;
}


void Terms::sameTerms()
{
	int temp;
	for (int i = 0; i < length; i++)
	{
		temp = components[i].exponent;
		for (int j = i + 1; j <= length; j++)
		{
			if (temp == components[j].exponent && components[j].coefficient != NULL)
			{
				components[i].coefficient += components[j].coefficient;
				if (components[i].coefficient == 0)
				{
					components[i].coefficient = NULL;
					components[i].exponent = NULL;
				}
				removeTerms(components[j].coefficient, components[j].exponent, j);
			}
		}
	}
	length = setSize();
}


void Terms::show()
{
	for (int i = 0; i < termSize; i++)
	{
		if (components[i].coefficient)
		{
			cout << components[i].coefficient << "  " << components[i].exponent << endl;
		}
	}
}