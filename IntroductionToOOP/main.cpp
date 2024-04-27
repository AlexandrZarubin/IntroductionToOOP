#include<iostream>

using namespace std;

class Point //создаем структуру 'Point', котора€ будет описывать точки на плоскости.
{
	double x;
	double y;
public:
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	double distance()const
	{
		return sqrt(x * x + y * y);
	}
};
double distance(const Point& A, const Point& B)
{
	/*
	double Dx = A.get_x() - B.get_x();
	double Dy = A.get_y() - B.get_y();
	return sqrt(Dx * Dx + Dy * Dy);
	*/

	return (double)sqrt(pow(B.get_x() - A.get_x(),2) + pow(B.get_y() - A.get_y(),2));
}

//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "rus");
	#ifdef STRUCT_POINT
		cout << "Hello OOP" << endl;

	int a;		//ќбъ€вление перменной 'a' типа 'int'
	Point A;	//ќбъ€вление перменной 'a' типа 'Point'
	//—оздание объекта 'ј' структура 'Point'
	//—оздание экземпл€ра структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	cout << sizeof(Point);
	cout << sizeof(A);
	Point* pA = &A;
	cout << (*pA).x << "\t" << (*pA).y << endl;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B;
	B.set_x(-5);
	B.set_y(-3);
	cout<< A.get_x() << "\t" << A.get_y() << endl;
	cout << A.distance() << endl;
	cout << distance(A, B);
}
/*
-------------------------------------------------------------
.  - оператор пр€мого доступа, используетс€ дл€ обращени€ к пол€м объекта по имени объекта;
-> - оператор косвенного доступа, используетс€ дл€ обращени€ к пол€м объекта по адресу объекта;
-------------------------------------------------------------
*/

/*
-------------------------------------------------------------
1. Encapsulation - это сокрытие определенной части класса от внешнего мира;
	private:	закрытые пол€, доступные только внутри класса;
	public:		открытые пол€, доступные в любом месте программы;
	protected:	защищенные пол€, доступные внутри класса, и его дочерних классов;

	get/set-методы
	get (вз€ть, получить) - открывают доступ к закрытым переменным на чтение, т.е.,
							позвол€ют получить значени€ закрытых переменных в классе.
	set (задать, установить) - открывают доступ к закрытым переменным на запись, т.е.,
							   позвол€ют задать значени€ закрытых переменных.
							    роме того, set-методы обеспечивают фильтрацию данных,
							   т.е., предотвращают попадание некорректных данных
							   в переменные члены класса, именно поэтому, set-методы
							   так же рекомендуют использовать внутри класса, не смотр€ на то,
							   что внутри класса есть пр€мой доступ к переменным.
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------------
*/