// Polynomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Polynomial.h"
#include "Terms.h"
#include<iostream>
#include<windows.h>

using namespace std;

void switchCase(Polynomial &, Polynomial &);
int menu();
void inputSwitchCase(Polynomial &, Polynomial &);
int inputMenu();
void polynomialInput(Polynomial &);
void attachSwitchCase(Polynomial &, Polynomial &);
int attachMenu();
void termsAttachInput(Polynomial &);
void multSwitchCase(Polynomial &, Polynomial &);
int multMenu();
void printSwitchCase(Polynomial &, Polynomial &);
int printMenu();

int main()
{
	Polynomial poly1, poly2;
	switchCase(poly1, poly2);
	return 0;
}


void switchCase(Polynomial &poly1, Polynomial &poly2)
{
	Polynomial polySum, polySub;
	bool flag = true;
	while (flag)
	{
		system("cls");
		switch (menu())
		{
		case 1:
		{
			system("cls");
			inputSwitchCase(poly1, poly2);
			cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			attachSwitchCase(poly1, poly2);
			cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			multSwitchCase(poly1, poly2);
			cin.get();
			break;
		}
		case 4:
		{
			Polynomial p;
			system("cls");
			p = poly1.polySummation(poly1, poly2);
			cout << "Summation of two polynomial is : ";
			p.polyShow(p);
			cin.get();
			break;
		}
		case 5:
		{
			system("cls");
			polySub = poly1.polySubtraction(poly1, poly2);
			cout << "Subtraction of two polynomial is : ";
			polySub.polyShow(polySub);
			cin.get();
			break;
		}
		case 6:
		{
			system("cls");
			printSwitchCase(poly1, poly2);
			break;
		}
		case 7:
		{
			system("cls");
			flag = false;
			cout << "\n\n\t\tPROGRAME FINISHED\n\n"
				<< "\t\tERFAN MOHAMMADZADEH\n\n";
			Beep(200, 100); Beep(300, 100); Beep(400, 100); Beep(500, 100); Beep(600, 100); Beep(700, 100); Beep(800, 100); Beep(900, 100); Beep(1000, 100);
			cin.get();
			cin.get();
			break;
		}
		}
	}
}


int menu()
{
	int choice;
	cout << "\n*************** MAIN MENU ***************\n\n"
		<< "1) Add a Polynomial\n"
		<< "2) Attach new terms to the Polynomials\n"
		<< "3) Multiplication of two Polynomial\n"
		<< "4) Summation of two Polynomial\n"
		<< "5) Subtraction of two Polynomial\n"
		<< "6) Show Polynomial\n"
		<< "7) Exit\n\n"
		<< "======================================================\n"
		<< "# Plz, Select One Option : ";
	cin >> choice;
	if (choice > 7 || choice < 1)
	{
		cout << "Error: You Entered Wrong number\nSelect again : \a";
		cin >> choice;
	}
	return choice;
}


void inputSwitchCase(Polynomial &poly1, Polynomial &poly2)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		switch (inputMenu())
		{
		case 1:
		{
			system("cls");
			polynomialInput(poly1);
			cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			polynomialInput(poly2);
			cin.get();
			break;
		}
		case 3:
		{
			flag = false;
			break;
		}
		}
	}
}


int inputMenu()
{
	int choice;
	cout << "\n*************** INPUT MENU ***************\n\n"
		<< "1) Input first Polynomial\n"
		<< "2) Input second Polynomial\n"
		<< "3) Back to main menu\n\n"
		<< "===================================\n"
		<< "# Plz, Select One Option : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error : You Entered Wrong number\nSelect again : \a";
		cin >> choice;
	}
	return choice;
}


void polynomialInput(Polynomial &poly)
{
	double coef;
	int expon, length;
	cout << "Please Enter Polynomial's terms length : ";
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		cout << "Enter One polynomial expression(To this way : first Coefficients second Exponents) : ";
		cin >> coef >> expon;
		poly.setPoly(coef, expon);
	}
	poly.terms.sameTerms();
	poly.terms.sortTerms();
	poly.terms.length = poly.terms.setSize();
}


void attachSwitchCase(Polynomial &poly1, Polynomial &poly2)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		switch (attachMenu())
		{
		case 1:
		{
			system("cls");
			termsAttachInput(poly1);
			break;
		}
		case 2:
		{
			system("cls");
			termsAttachInput(poly2);
			break;
		}
		case 3:
		{
			flag = false;
			break;
		}
		}
	}
}


int attachMenu()
{
	int choice;
	cout << "\n*************** ATTACH MENU ***************\n\n"
		<< "1) Attach new term to first Polynomial\n"
		<< "2) Attach new term to second Polynomial\n"
		<< "3) Back to main menu\n\n"
		<< "===================================\n"
		<< "# Plz, Select One Option : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error : You Entered Wrong number\nSelect again : \a";
		cin >> choice;
	}
	return choice;
}


void termsAttachInput(Polynomial &poly)
{
	double coef;
	int exp;
	cout << "Enter Coefficient : ";
	cin >> coef;
	cout << "Enter Exponent : ";
	cin >> exp;
	if (poly.terms.attachTerms(coef, exp))
	{
		poly.terms.sameTerms();
		poly.terms.sortTerms();
		cout << "\nNew Polynomial after Attaching : ";
		poly.polyShow(poly);
	}
	else
	{
		cout << "Error : There is NOT enough space to add new term to the Polynomial\n";
	}
	cin.get();
}


void multSwitchCase(Polynomial &poly1, Polynomial &poly2)
{
	bool flag = true;
	double coef;
	int exp;
	Polynomial multPoly, singleMultPoly;
	while (flag)
	{
		system("cls");
		switch (multMenu())
		{
		case 1:
		{
			system("cls");
			multPoly = poly1.polyMultiplication(poly1, poly2);
			cout << "The product of multiplication of two Polynomial is : ";
			poly1.polyShow(multPoly);
			cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Enter Coefficient : ";
			cin >> coef;
			cout << "Enter Exponent : ";
			cin >> exp;
			singleMultPoly = poly1.polySingleMultiplication(poly1, coef, exp);
			cout << "The product of multiplication of a term and first polynomial is : ";
			poly1.polyShow(singleMultPoly);
			cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			cout << "Enter Coefficient : ";
			cin >> coef;
			cout << "Enter Exponent : ";
			cin >> exp;
			singleMultPoly = poly2.polySingleMultiplication(poly2, coef, exp);
			cout << "The product of multiplication of a term and second polynomial is : ";
			poly2.polyShow(singleMultPoly);
			cin.get();
			break;
		}
		case 4:
		{
			flag = false;
			break;
		}
		}
	}
}


int multMenu()
{
	int choice;
	cout << "\n*************** MULTIPLICATION MENU ***************\n\n"
		<< "1) First Polynomial Multiplication in Second Polynomial\n"
		<< "2) First Polynomail Multiplication in a Term\n"
		<< "3) Second Polynomail Multiplication in a Term\n"
		<< "4) Back to main menu\n\n"
		<< "===================================\n"
		<< "# Plz, Select One Option : ";
	cin >> choice;
	if (choice > 4 || choice < 1)
	{
		cout << "Error : You Entered Wrong number\nSelect again : \a";
		cin >> choice;
	}
	return choice;
}


void printSwitchCase(Polynomial &poly1, Polynomial &poly2)
{
	bool flag = true;
	while (flag)
	{
		system("cls");
		switch (printMenu())
		{
		case 1:
		{
			system("cls");
			cout << "First Polynomial is : ";
			poly1.polyShow(poly1);
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Second Polynomial is : ";
			poly2.polyShow(poly2);
			break;
		}
		case 3:
		{
			flag = false;
			break;
		}
		}
		cin.get();
	}
}


int printMenu()
{
	int choice;
	cout << "\n*************** PRINT MENU ***************\n\n"
		<< "1) Print First Polynomial\n"
		<< "2) Print Second Polynomail\n"
		<< "3) Back to main menu\n\n"
		<< "===================================\n"
		<< "# Plz, Select One Option : ";
	cin >> choice;
	if (choice > 3 || choice < 1)
	{
		cout << "Error : You Entered Wrong number\nSelect again : \a";
		cin >> choice;
	}
	return choice;
}