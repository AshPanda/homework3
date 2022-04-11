/* 1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). 
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь). 
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

2. Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). 
От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. 
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти».
Примечание: если использовать виртуальный базовый класс, то объект самого "верхнего" базового класса создает самый "дочерний" класс.

3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

Продемонстрировать использование перегруженных операторов.

4. Создать класс Card, описывающий карту в игре БлэкДжек. 
У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. 
Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/

#include <iostream>
#include <cmath>

//Task #1
class Figure
{
public:
	Figure(double height, double width) {}
	virtual double area() = 0;
	void setValues(double height, double width) {
		this->height = height;
		this->width = width;
	}

protected:
	double height;
	double width;
};

class Parallelogram : public Figure
{
public:
	Parallelogram(double height, double width) : Figure (height, width) {}
};
#define PI 3.14159265358979323846
class Circle: public Figure
{
public:
	Circle(double radius) : Figure(radius, radius) {}
	double area() override { return PI * pow(height, 2); }
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double height, double width) : Parallelogram(height, width) {}
	double area() override { return height * width; }
};
class Square : public Parallelogram
{
public:
	Square(double height, double width) : Parallelogram(height, width) {}
	double area() override { return pow(height,2); }
};
class Rhombus : public Parallelogram
{
public:
	Rhombus(double height, double width) : Parallelogram(height, width) {}
};

//Task#2
class Car
{
public:
	Car(std::string company, std::string model) {
		this->company = company;
		this->model = model;
	}
	~Car() {}

private:
	std::string company;
	std::string model;
};

class Bus : virtual public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model) {}
	~Bus() {}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model) {}
	~PassengerCar() {}
};

class MiniVan : public Bus, public PassengerCar
{
public:
	MiniVan(std::string company, std::string model) : Bus(company, model), PassengerCar(company, model), Car(company, model) {}
	~MiniVan() {}
};

//Task#3
class Fraction
{
public:
	int getValue(const Fraction& other) const {
		int left = this->denominator;
		int right = other.denominator;
		while (left !=right)
		{
			if (left < right) {
				left += this->denominator;
			}
			else
			{
				right += other.denominator;
			}
		}
		return 1;
	}

	Fraction(int numerator, int denominator) {
		setDenominator(denominator);
	}
// =\
	

private:
	int numerator;
	int denominator;
	void setDenominator(int _denominator) {
		if (_denominator !=0)
		{
			this->denominator = _denominator;
		}
		else {
			this->denominator = 1;
			std::cout << "Warning: denominator is 0! For further calculations denominator is set to 1!" << std::endl;
		}
		if (_denominator < 0) {
			this->denominator = -this->denominator;
			this->numerator = -this->numerator;
		}
	}
};


//Task#4
enum rank {
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHT = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10
};
enum suit
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};
class Card
{
public:

	Card(rank Rank, suit Suit) : Rank(Rank), Suit (Suit) {
		isFaceUp = true;
	}
	~Card(){}
	int GetValue() const {
		return Rank;
	}
	void Flip(){
		isFaceUp = !(isFaceUp);
	}

private:
	rank Rank;
	suit Suit;
	bool isFaceUp;
};

int main()
{

	Card c0(SEVEN, HEARTS);
	std::cout << c0.GetValue() << std::endl;
}


