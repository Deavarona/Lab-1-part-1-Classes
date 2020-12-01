#include <iostream>
#include "Matrix.h"
#include "Tools.h"
using namespace std;

Matrix::Matrix()
{
	setSize();
	m_matrix = new int* [m_number_of_rows];
	for (int i = 0; i < m_number_of_rows; i++)
		m_matrix[i] = new int[m_number_of_columns];
	//cout << "Matrix[" << m_number_of_rows << ";" << m_number_of_columns << "] was created!" << endl;
	//cout << endl;
}

Matrix::Matrix(const Matrix& other)
{
	//cout << "Copy constructor is working" << endl;
	m_number_of_rows = other.m_number_of_rows;
	m_number_of_columns = other.m_number_of_columns;
	m_minimal_row = other.m_minimal_row;
	m_minimal_column = other.m_number_of_columns;

	m_matrix = new int* [other.m_number_of_rows];
	for (int i = 0; i < other.m_number_of_rows; i++)
	{
		m_matrix[i] = new int[other.m_number_of_columns];
	}

	for (int i = 0; i < other.m_number_of_rows; i++)
		for (int j = 0; j < other.m_number_of_columns; j++)
			m_matrix[i][j] = other.m_matrix[i][j];
}

void Matrix::setSize()
{
	cout << "Nuber of rows: ";
	int number_of_rows = inputNaturalNumber();
	setRows(number_of_rows);
	system("cls");

	cout << "Number of columns: ";
	int number_of_columns = inputNaturalNumber();
	setColumns(number_of_columns);
	system("cls");
}

void Matrix::setRows(int number_of_rows = SIZE_OF_MATRIX)
{
	m_number_of_rows = number_of_rows;
}

void Matrix::setColumns(int number_of_columns = SIZE_OF_MATRIX)
{
	m_number_of_columns = number_of_columns;
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_number_of_rows; i++)
		delete[]m_matrix[i];
	delete[]m_matrix;
	//cout << "Matrix[" << m_number_of_rows << ";" << m_number_of_columns << "] was deleted" << endl;
}

void Matrix::fillMatrixRandom()
{
	srand(time(NULL));
	for (int i = 0; i < m_number_of_rows; i++)
		for (int j = 0; j < m_number_of_columns; j++)
		{
			m_matrix[i][j] = rand() % RAND_INTERVAL + 1;
		}
}

void Matrix::fillMatrixManually()
{
	for (int i=0; i<m_number_of_rows; i++)
		for (int j = 0; j < m_number_of_columns; j++)
		{
			cout << "element[" << i + 1 << ";" << j + 1 << "] = ";
			m_matrix[i][j] = inputNaturalNumber();
		}
}

void Matrix::showMatrix()
{
	for (int i = 0; i < m_number_of_rows; i++)
	{
		for (int j = 0; j < m_number_of_columns; j++)
			cout << m_matrix[i][j] << " \t";
		cout << endl;
	}
	cout << endl;
}

void Matrix::findMinimal()
{
	m_minimal_row = 0;
	m_minimal_column = 0;
	for (int i = 0; i < m_number_of_rows; i++)
		for (int j = 0; j < m_number_of_columns; j++)
			if (m_matrix[i][j] < m_matrix[m_minimal_row][m_minimal_column])
			{
				m_minimal_row = i;
				m_minimal_column = j;
			}
}

void Matrix::zeroing()
{
	findMinimal();
	cout << "Minimal element: " << m_matrix[m_minimal_row][m_minimal_column] << " at " << m_minimal_row + 1 << " row " <<
		m_minimal_column + 1 << " column" << endl;
	zeroRow();
	zeroColumn();
}

void Matrix::zeroRow()
{
	for (int i = 0; i < m_number_of_rows; i++)
	{
		m_matrix[i][m_minimal_column] = 0;
	}
}

void Matrix::zeroColumn()
{
	for (int i = 0; i < m_number_of_columns; i++)
	{
		m_matrix[m_minimal_row][i] = 0;
	}
}

void Matrix::swapFirstAndUneven()
{
	cout << "First uneven in the row swap with the first element in that row" << endl;
	for (int i = 0; i < m_number_of_rows; i++)
		for (int j = 0; j < m_number_of_columns; j++)
		{
			if (m_matrix[i][j] % 2 != 0)
			{
				swap(m_matrix[i][0], m_matrix[i][j]);
				break;
			}
		}
}