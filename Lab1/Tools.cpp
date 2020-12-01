#include "Tools.h"
#include "Matrix.h"

int inputNaturalNumber()
{
	int number;
	while (1)
	{
		cin >> number;
		if (number > 0 && cin.get() == '\n')
			return number;
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Incorrect input" << endl;
			cout << "Natural number: ";
		}
	}
}

void fillingMatrixMenu(Matrix&matrix)
{
	
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1 - ��������� ������� �������" << endl;
	cout << "����� - ���������� ���������� �������" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	if (_getch() == '1')
		matrix.fillMatrixManually();
	else
		matrix.fillMatrixRandom();
}

void showMenuOperationsWithMatrix()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "1. �������� ������ � ������� � ����������� ���������." << endl;
	cout << "2. � ������ ������ ������ ��������� �������� ������� �������� ������� � ������ ��������� ���� ������" << endl;
	cout << "0 - �����" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

void operationsWithMatrix(Matrix matrix)
{
	showMenuOperationsWithMatrix();
	bool should_continue = true;
	while (should_continue)
	{
		switch (_getch())
		{
		case '1': matrix.zeroing(); matrix.showMatrix(); showMenuOperationsWithMatrix(); break;
		case '2': matrix.swapFirstAndUneven(); matrix.showMatrix(); showMenuOperationsWithMatrix(); break;
		case '0': should_continue = false;
		}
	}
}