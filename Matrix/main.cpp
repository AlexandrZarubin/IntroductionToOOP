#include<iostream>
using namespace std;
class Matrix;
Matrix operator+(const Matrix& left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator/(const Matrix& left, const Matrix& right);
class Matrix
{
	int rows, cols;
	double** data;
public:
	int get_rows()const
	{
		return rows;
	}
	int get_cols()const
	{
		return cols;
	}
	double** get_data()const
	{
		return data;
	}
			//Constructors:
	//default
	Matrix(int rows=3, int cols=3) :rows(rows), cols(cols)
	{
		data = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[cols] {};
		}
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Matrix(int Size)
	{
		rows = cols = Size;
		data = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[cols] {};
		}
		cout << "SizeConstructor:\t" << this << endl;
	}
	//copy
	Matrix(const Matrix& other) :rows(other.rows), cols(other.cols)
	{
		data = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[cols];
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		cout << "CopyConstructors" << this << endl;
	}
	Matrix(Matrix&& other):rows(other.rows),cols(other.cols),data(other.data)
	{
		other.data = nullptr;
		other.cols = 0;
		other.rows = 0;
		cout << "MovieConstructor:\t" << this << endl;

	}
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]data[i];
		}
		delete[]data;
		cout << "Destructor" <<this<< endl;
	}
	//				Operators:
	Matrix& operator=(const Matrix& other)//operator prisvaivania
	{
		if (this == &other)return *this;
		for (int i = 0; i < rows; i++)
		{
			delete[]data[i];
		}
		delete[]data;
		rows = other.rows;
		cols = other.cols;
		data = new double* [rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new double[cols];
			for (int j = 0; j < cols; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	}
	Matrix& operator=(Matrix&& other)
	{
		if (this == &other)return *this;
		if (rows==other.rows&&cols==other.cols)
		{
			if (data) 
			{
				for (int i = 0; i < rows; i++)
				{
					delete[]data[i];
				}
				delete[]data;
				rows = 0;
				cols = 0;
			}
			data = other.data;
			rows = other.rows;
			cols = other.cols;

			other.data = nullptr;
			other.rows = 0;
			other.cols = 0;
		}
	}
	double& operator()(int cols, int rows)
	{
		return data[rows][cols];
	}
	double& operator()(int cols, int rows)const
	{
		return data[rows][cols];
	}
	//
	Matrix& operator+=(const Matrix& other) {
		/*if (rows != other.rows || cols != other.cols) {
			std::cerr << "Error: Matrix dimensions must match for addition.\n";
			return *this;
		}

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				data[i][j] += other.data[i][j];
			}
		}
		return *this;*/
		return *this = *this + other;
	}
	Matrix& operator-=(const Matrix& other)
	{
		return *this = *this - other;
	}
	Matrix& operator*=(const Matrix& other)
	{
		return *this = *this * other;
	}
	Matrix& operator/=(const Matrix& other)
	{
		return *this = *this / other;
	}
	//				Methods:
	void Print()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
	void FillRand(int minRand = 0, int maxRand = 100)
	{
		minRand *= 10;
		maxRand *= 10;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++) 
			{
				data[i][j] = minRand + rand() % (maxRand - minRand);
				data[i][j] /= 10;
			}
		}
	}
	
};
Matrix operator+(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() == right.get_cols() && left.get_rows() == right.get_rows())
	{
		int rows = left.get_rows();
		int cols = left.get_cols();
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result(i, j) = left(i, j) + right(i, j);
			}
		}
		return result;
	}
	else
	{
		cerr << "Размеры матрицы не совпадают" << endl;
		//return 0;
	}
	
}
Matrix operator-(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() == right.get_cols() && left.get_rows() == right.get_rows())
	{
		int rows = left.get_rows();
		int cols = left.get_cols();
		Matrix result(rows, cols);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result(i, j) = left(i, j) - right(i, j);
			}
		}
		return result;
	}
	else
	{
		cerr << "Размеры матрицы не совпадают" << endl;
		//return 1;
	}
}
Matrix operator*(const Matrix& left, const Matrix& right)
{
	if (left.get_cols() == right.get_rows())
	{
		Matrix result(left.get_rows(), right.get_cols());
		for (int i = 0; i < left.get_rows(); i++)
		{
			for (int j = 0; j < right.get_cols(); j++)
			{
				for (int k = 0; k < left.get_cols(); k++)
				{
					result(i, j) += left(i, k) * right(k, j);
				}
			}
		}
		return result;
	}
	else
	{
		cerr << "столбики левой матрицы дожны сопадать со строками правой матрицы" << endl;
		//return 0;
	}
}
Matrix operator/(const Matrix& left, const Matrix& right)
{
	if (left.get_rows() == right.get_rows() && left.get_cols() == right.get_cols())
	{
		Matrix result(left.get_rows(), right.get_cols());
		for (int i = 0; i < left.get_rows(); i++)
		{
			for (int j = 0; j < left.get_cols(); j++)
			{
				result(i, j) = left(i, j) / right(i, j);
			}
		}
		return result;
	}
	else
	{
		cerr << "Размеры матрицы не совпадают" << endl;
		//return 0;
	}
}

bool operator==(const Matrix& left, const Matrix& right)
{
	if (left.get_rows() != right.get_rows() || left.get_cols() != right.get_cols())
	{
		return false;
	}
	for (int i = 0; i < left.get_rows(); ++i) {
		for (int j = 0; j < left.get_cols(); ++j) {
			if (left.get_data()[i][j] != right.get_data()[i][j]) {
				return false;
			}
		}
	}
	return true;
}
bool operator!=(const Matrix& left, const Matrix& right)
{
	return !(left == right);
}
void main()
{
	setlocale(LC_ALL, "rus");
	Matrix A;
	A.Print();
	A.FillRand();
	A.Print();
	cout << "===\n";
	Matrix B = A;
	B.Print();
	Matrix D;
	D.FillRand();
	//Matrix C = D + B;
	//C.Print();
	Matrix C;
	C = D - B;
	cout << "---\n";
	C.Print();
	C = D * B;
	cout << "***\n";
	C.Print();
	C = D / B;
	cout << "////\n";
	C.Print();
	cout << "==\n";
	cout << (C == D) << endl;
	cout << "!=\n";
	cout << (C != D) << endl;
	C += D;
	cout << "+=\n";
	C.Print();
	C -= D;
	cout << "-=\n";
	C.Print();

}