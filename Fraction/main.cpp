#include<iostream>
using namespace std;

class Fraction
{
	int integer;	//целое
	int numerator;	//числитель
	int denominator;//занменатель
	
	int NOD(const int a, const int b)
	{
		if (a == b)return b;
		if (a > b)return NOD(a - b, b);//рекурсия 
		return NOD(a, b - a);
	}
	int NOK(const int a, const int b)
	{

		return(a * b) / NOD(a, b);
	}
	public:
		//Encapsulation
		//SET
		int get_integer()const
		{
			return integer;
		}
		int get_numerator()const
		{
			return numerator;
		}
		int get_denominator()const
		{
			return denominator;
		}
		//GET
		void set_integer(int integer)
		{
			this->integer = integer;
		}
		void set_numerator(int numerator)
		{
			this->numerator = numerator;
		}
		void set_denominator(int denominator)
		{
			if (denominator == 0)denominator = 1;
			this->denominator = denominator;
		}
		//Constructor
		Fraction()
		{
			integer = 0;
			numerator = 0;
			denominator = 1;
			cout << "DefaultConstructor:\t" << this << endl;
		}
		Fraction(int integer)
		{
			this->integer = integer;
			this->numerator = 0;
			this->denominator = 1;
			cout << "1ArgConstructor:\t" << this << endl;
		}
		Fraction(int numerator, int denominator)
		{
			this->integer = 0;
			set_numerator(numerator);
			set_denominator(denominator);
			cout << "2ArgConstructor:\t" << this << endl;
		}
		Fraction(int integer , int numerator , int denominator)
		{
			set_integer(integer);
			set_numerator(numerator);
			set_denominator(denominator);
			cout << "3ArgConstructor:\t" << this << endl;
		}
		Fraction(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "copyConstructor:\t" << this << endl;
		}
		~Fraction()
		{
			cout << "Destructor:\t\t" << this << endl;
		}
		//Operators:
		Fraction& operator=(const Fraction& other)
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssignment:\t\t" << this << endl;
			return *this;
		}
		
		//2. Increment/Decrement:		 ++/--;
		// ++
		Fraction& operator++()		//prefix
		{
			integer++;
			return *this;
		}
		Fraction operator++(int)	//Suffix
		{
			Fraction old = *this;
			integer++;
			return old;
		}
		//--
		Fraction& operator--()		//prefix
		{
			integer--;
			return *this;
		}
		Fraction operator--(int)	//Suffix
		{
			Fraction old = *this;
			integer--;
			return old;
		}
		//
		//3. Compound assignments : +=, -=, *=, /=;


		//Methods
		void print()const
		{
			if (integer)cout << integer;
			if (numerator)
			{
				if (integer)cout << "(";
				cout << numerator << "/" << denominator;
				if (integer)cout << ")";
			}
			else if (integer == 0)cout << 0;
			cout << endl;
		}
		//перевод в неправильную дробь для бул
		Fraction& NoRight()
		{
			numerator += integer * denominator;
			integer = 0;
			return *this;
		}
		//В правильную
		Fraction& Right()
		{
			integer += numerator / denominator;
			numerator %= denominator;
			return *this;
		}
		
		Fraction& reduction()//Сокращение дроби
		{	
			int nod = NOD(numerator, denominator);
			
			numerator /= nod;
			denominator /= nod;
			return *this;
		}
		double transformation()const
		{
			return integer + (double)numerator / denominator;
		}


		//4. Операторы сравнения:		 ==, !=, >, <, >=, <=;
		/*
		bool operator==(const Fraction& other)const
		{
			return (transformation() == other.transformation());
		}
		*/

		/*bool operator==(Fraction other)
		{
			Fraction temp = *this;
			temp.NoRight();
			other.NoRight();
			int commonDenominator = NOK(temp.get_denominator(), other.get_denominator());
			return temp.get_numerator() * (commonDenominator / temp.get_denominator())
				==
				other.get_numerator() * (commonDenominator / other.get_denominator());
		}*/
		/*bool operator!=(Fraction other)
		{
			Fraction temp = *this;
			temp.NoRight();
			other.NoRight();
			int commonDenominator = NOK(temp.get_denominator(), other.get_denominator());
			return !(temp.get_numerator() * (commonDenominator / temp.get_denominator())
				==
				other.get_numerator() * (commonDenominator / other.get_denominator()));

		}*/

};
//Конец класса


//1. Арифметические опервторы: +, -, *, /;
	Fraction operator+(const Fraction& left, const Fraction& right)
	{
		Fraction Temp;
		Temp.set_integer(left.get_integer() + right.get_integer());
				
		Temp.set_numerator
		(
			(left.get_denominator() * right.get_numerator())
			+ 
			(left.get_numerator() * right.get_denominator())
		);
		Temp.set_denominator
		(
			left.get_denominator()*right.get_denominator()
		);
			//Temp.Right();
		Temp.Right();
		Temp.reduction();
		return Temp;
	}
	Fraction operator-(const Fraction& left, const Fraction& right)
	{
		Fraction Temp;
		Temp.set_integer(left.get_integer() - right.get_integer());		
		Temp.set_numerator
		(
			(left.get_numerator() * right.get_denominator())
			-
			(left.get_denominator() * right.get_numerator())
		);
		Temp.set_denominator
		(
			left.get_denominator() * right.get_denominator()
		);
		Temp.NoRight();
		Temp.Right();
		Temp.reduction();
		return Temp;
		
		
		


	}
	Fraction operator*(const Fraction& left, const Fraction& right)
	{
		Fraction Temp;
		int LeftNumeratorBuffer = 0;
		int RightNumeratorBuffer = 0;
		if (left.get_integer())
			LeftNumeratorBuffer = left.get_integer() * left.get_denominator()+left.get_numerator();
		else
			LeftNumeratorBuffer = left.get_numerator();

		if (right.get_integer())
			RightNumeratorBuffer = right.get_integer() * right.get_denominator()+right.get_numerator();
		else
			RightNumeratorBuffer = right.get_numerator();
		Temp.set_integer(0);
		Temp.set_numerator(LeftNumeratorBuffer * RightNumeratorBuffer);
		Temp.set_denominator(left.get_denominator() * right.get_denominator());
		//Temp.NoRight();
		Temp.Right();
		Temp.reduction();
		return Temp;
	}
	Fraction operator/(const Fraction& left, const Fraction& right)
	{
		Fraction Temp;
		int LeftNumeratorBuffer = 0;
		int RightNumeratorBuffer = 0;
		if (left.get_integer())
			LeftNumeratorBuffer = left.get_integer() * left.get_denominator() + left.get_numerator();
		else
			LeftNumeratorBuffer = left.get_numerator();

		if (right.get_integer())
			RightNumeratorBuffer = right.get_integer() * right.get_denominator() + right.get_numerator();
		else
			RightNumeratorBuffer = right.get_numerator();

		Temp.set_integer(0);
		Temp.set_numerator(LeftNumeratorBuffer * right.get_denominator());
		Temp.set_denominator(RightNumeratorBuffer * left.get_denominator());
		//Temp.NoRight();
		Temp.Right();
		Temp.reduction();
		return Temp;
	}


	////4. Операторы сравнения:		 ==, !=, >, <, >=, <=;
	bool operator==(const Fraction& left, const Fraction& right)
	{
		return (left.transformation() == right.transformation());
	}
	bool operator!=(const Fraction& left, const Fraction& right)
	{
		return !(left.transformation() == right.transformation());
	}
	bool operator>=(const Fraction& left, const Fraction& right)
	{
		return (left.transformation() >= right.transformation());
	}
	bool operator<=(const Fraction& left, const Fraction& right)
	{
		return (left.transformation() <= right.transformation());
	}
	bool operator<(const Fraction& left, const Fraction& right)
	{
		return (left.transformation() < right.transformation());
	}
	bool operator>(const Fraction& left, const Fraction& right)
	{
		return (left.transformation() > right.transformation());
	}

//5. Операторы перенаправления в поток и изъятия из потока, для работы cin / cout;
	std::ostream& operator<<(std::ostream& os, const Fraction& object)
	{
		if (object.get_integer())os << object.get_integer() << " ";
		os << object.get_numerator() << "/" << object.get_denominator();
		return os;
	}

	std::istream& operator>>(std::istream& is, Fraction& object)
	{
		int integer,numerator,denominator;
		is >> integer >> numerator>> denominator;
		object.set_integer(integer);
		object.set_numerator(numerator);
		object.set_denominator(denominator);
		return is;
	}

void main()
{
	setlocale(LC_ALL, "rus");
	Fraction A; //Default constructor
	A.print();
	Fraction B = 5;//Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();
	Fraction E = D;
	E.print();
	Fraction F;
	F = E;
	F.print();
	//Dz
	F++;
	F.print();
	//+
	Fraction R = F + F;
	R.print();
	cout << "1" << endl;
	R = R - F;
	R.print();
	cout << "2" << endl;
	R = F * F;
	F.print();
	R.print();
	cout << "3" << endl;
	R.print();
	R = R / F;
	R.print();
	cout << "4" << endl;
	cout << R << endl;
	//cin >> R;
	//R.print();
	cout << "5" << endl;
	cout << "F: ";
	F.print();
	cout << endl;
	R = F * F;
	cout << "R: ";
	R.print();
	cout << endl;
	cout <<"==" << (F == F) << endl;
	cout <<"!=" << (R != F) << endl;
	cout << ">" << (R > F) << endl;
	cout << "<" << (R < F) << endl;
}