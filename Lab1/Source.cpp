//13. ������� �����, � ������� ����������� ������� ��� ������ � ����������� ���������:
//�) ������� ������ �������� ������ � ������� � ����������� ���������.
//�) ������� ������ � ������ ������ ������� ������ ��������� �������� ������� �������� ������� � ������ ��������� ���� ������;
//������ ��� ������� �������� �����������.
//������������ ����������� � �����������.
//���������� ������ ����������� ������, ���������� ��� �������.

//1. ������� �����, ��������� ��������� ������.
//2. ����� ������������ �������� � ������ � �������.
//3. ��������� ������ � �������.
//4. ����� ��������� ��������.
//5. ������ ������� �������� ������ �� ������ ��������.

#include <iostream>
#include "Matrix.h"
#include "Tools.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	Matrix matrix;
	fillingMatrixMenu(matrix);
	matrix.showMatrix();
	operationsWithMatrix(matrix);
}