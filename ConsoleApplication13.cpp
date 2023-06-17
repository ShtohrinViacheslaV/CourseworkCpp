#include <iostream>
#include<cmath>
#include <iomanip> 
#include<Windows.h>
#include<fstream>

#define pi 3,14

using namespace std;


//абстрактний клас
class Object {
protected:

	//oбчислювальний параметр
	double l;

public:

	//чисті віртуальні функції
	virtual void enter_file(const char* S) = 0;
	virtual void calc_l() = 0;
	virtual void output_file(const char* S) = 0;
	virtual const double output_l() = 0;

	virtual ~Object() {}

};

//похідний клас
class Mileage_molecule : public Object {

	double N = 0;
	double d = 0;
	double p = 0;
	double Tg = 0;

public:

	//конструктори
	Mileage_molecule() {};
	Mileage_molecule(double d, double p, double Tg);
	Mileage_molecule(const Mileage_molecule& Mm);


	void enter_file(const char* S);
	void calc_l();
	const double output_l();
	double calc_N();
	void output_file(const char* S);

	//перевантажені операції
	void operator=(Mileage_molecule const& Mm);
	friend bool operator==(Mileage_molecule const& A, Mileage_molecule const& B);
	friend bool operator!=(Mileage_molecule const& A, Mileage_molecule const& B);
	friend bool operator<(Mileage_molecule const& A, Mileage_molecule const& B);
	friend bool operator<=(Mileage_molecule const& A, Mileage_molecule const& B);
	friend bool operator>(Mileage_molecule const& A, Mileage_molecule const& B);
	friend bool operator>=(Mileage_molecule const& A, Mileage_molecule const& B);


	~Mileage_molecule() {}

};


int main()
{
	//для використання української мови
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	cout << "No I" << endl;
	cout << "Покажчик на батьківський клас. Пустий конструктор. Введення з файлу" << endl;
	Object* Obj_1 = new Mileage_molecule();
	Obj_1->enter_file("Obj_1.txt");
	Obj_1->calc_l();
	Obj_1->output_file("Obj_1_res.txt");
	cout << endl;

	cout << "No II" << endl;
	cout << "Покажчик на батьківський клас. Конструктор з ініціалізацією:" << endl << "N = 5    d = 3, 656 * 10 ^ -10    p = 1, 5    Tg = 500" << endl;
	Object* Obj_2 = new Mileage_molecule(3.656 * pow(10, -10), 1.5, 500);
	Obj_2->calc_l();
	cout << "l = " << Obj_2->output_l() << endl;
	cout << endl;

	ofstream ofs("comparison_res.txt");


		cout << "No III" << endl;
	cout << "Пустий конструктор. Введення з файлу " << endl;
	Mileage_molecule Obj_3;
	Obj_3.enter_file("Obj_3.txt");
	Obj_3.calc_l();
	Obj_3.output_file("Obj_3_res.txt");
	ofs << "l = " << Obj_3.output_l() << endl;
	cout << endl;

	cout << "No IV" << endl;
	cout << "Конструктор з ініціалізацією" << endl << "N = 1    d = 3,64 * 10^-10    p = 1,2    Tg = 300   " << endl;
	Mileage_molecule Obj_4(3.64 * pow(10, -10), 1.2, 300);
	Obj_4.calc_l();
	cout << "l = " << Obj_4.output_l() << endl;
	ofs << "l = " << Obj_4.output_l() << endl;
	cout << endl;

	cout << "No V" << endl;
	cout << "Конструктор копії" << endl << "No V  =  No IV" << endl;
	Mileage_molecule Obj_5(Obj_4);
	Obj_5.calc_l();
	cout << "l = " << Obj_5.output_l() << endl;
	ofs << "l = " << Obj_5.output_l() << endl;

	cout << endl << endl;



	//Порівняння
	ofs << "Порівняння" << endl;
	ofs << "_________________" << endl;

	cout << "Порівняння" << endl;
	cout << "Obj_3 == Obj_4 ?" << endl;
	if (Obj_3 == Obj_4) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 == Obj_4" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 != Obj_4" << endl;
	}

	cout << "Obj_4 == Obj_5 ?" << endl;
	if (Obj_4 == Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_4 == Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_4 != Obj_5" << endl;
	}

	cout << "Obj_3 == Obj_5 ?" << endl;
	if (Obj_3 == Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 == Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 != Obj_5" << endl;
	}

	ofs << "_________________" << endl;


	cout << "Obj_3 != Obj_4 ?" << endl;
	if (Obj_3 != Obj_4) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 != Obj_4" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 == Obj_4" << endl;
	}

	cout << "Obj_4 != Obj_5 ?" << endl;
	if (Obj_4 != Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_4 != Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_4 == Obj_5" << endl;
	}

	cout << "Obj_3 != Obj_5 ?" << endl;
	if (Obj_3 != Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 != Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 == Obj_5" << endl;
	}

	ofs << "_________________" << endl;


	cout << "Obj_3 > Obj_4 ?" << endl;
	if (Obj_3 > Obj_4) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 > Obj_4" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 <= Obj_4" << endl;
	}

	cout << "Obj_4 >= Obj_5 ?" << endl;
	if (Obj_4 >= Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_4 >= Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_4 < Obj_5" << endl;
	}

	cout << "Obj_3 < Obj_5 ?" << endl;
	if (Obj_3 < Obj_5) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 < Obj_5" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 >= Obj_5" << endl;
	}

	cout << "Obj_3 <= Obj_4 ?" << endl;
	if (Obj_3 <= Obj_4) {
		cout << "ТАК" << endl;
		ofs << "Obj_3 <= Obj_4" << endl;
	}
	else {
		cout << "НІ" << endl;
		ofs << "Obj_3 > Obj_4" << endl;
	}


	cout << endl << endl;




	//табуляція
	ofstream ofs1("tabulate_res.txt");
	ofs1 << "Табуляція за параметром Tg" << endl;
	ofs1 << "Tg \t l" << endl;
	cout << "Табуляція за параметром Tg" << endl;
	cout << "Tg \t l" << endl;

	for (int delta = 300; delta <= 1300; delta += 100) {
		Mileage_molecule l_tabulate(3.6 * pow(10, -10), 1.25, delta);
		l_tabulate.calc_l();
		ofs1 << delta << "\t" << setprecision(5) << l_tabulate.output_l() << endl;
		cout << delta << "\t" << setprecision(5) << l_tabulate.output_l() << endl;
	}

	cout << endl;
	cout << "Результати файлi 'tabulate_res.txt' " << endl;


	ofs.close();
	ofs1.close();


	delete Obj_1;
	delete Obj_2;

	system("pause");
	return 0;
}


Mileage_molecule::Mileage_molecule(double d, double p, double Tg) {
	this->d = d;
	this->p = p;
	this->Tg = Tg;
}

Mileage_molecule::Mileage_molecule(const Mileage_molecule& Mm) {
	N = Mm.N;
	d = Mm.d;
	p = Mm.p;
	Tg = Mm.Tg;
}

void Mileage_molecule::enter_file(const char* S) {
	ifstream ifs(S);
	if (!ifs)
	{
		cout << "Файл не відкритий " << endl;
		exit(1);
	}
	cout << "Файл відкритий " << endl;

	ifs >> N >> d >> p >> Tg;

	//cout << N << endl << d << endl << p << endl << Tg << endl;
}


void Mileage_molecule::calc_l() {
	N = calc_N();
	if (d == 0 || N == 0) {
		cout << "Помилка" << endl;
		exit(2);
	}

	else {

		l = 1.0 / (pi * d * d * N * sqrt(2));
	}

}
double Mileage_molecule::calc_N() {
	if (Tg == 0) {
		cout << "Помилка" << endl;
		exit(3);
	}
	else {
		N = (6.02497 * pow(10, 23) * p) / (Tg * 8.2056 * pow(10, -5));

	}
}

void Mileage_molecule::output_file(const char* S) {
	ofstream ofs(S);

	ofs << "_________________" << endl;
	ofs << "N = " << N << endl;
	ofs << "d = " << d << endl;
	ofs << "p = " << p << endl;
	ofs << "Tg = " << Tg << endl;
	ofs << "l = " << l << endl;
	ofs << "_________________" << endl;

	cout << "_________________" << endl;
	cout << "N = " << N << endl;
	cout << "d = " << d << endl;
	cout << "p = " << p << endl;
	cout << "Tg = " << Tg << endl;
	cout << "l = " << l << endl;
	cout << "_________________" << endl;

	cout << "Результати y файлі " << S << endl;
}

const double Mileage_molecule::output_l() {
	return l;
}

void Mileage_molecule::operator=(Mileage_molecule const& Mm) {
	N = Mm.N;
	d = Mm.d;
	p = Mm.p;
	Tg = Mm.Tg;
}


bool operator==(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l == B.l ? true : false;
}

bool operator!=(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l != B.l ? true : false;
}

bool operator<(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l < B.l ? true : false;
}

bool operator<=(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l <= B.l ? true : false;
}

bool operator>(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l > B.l ? true : false;
}

bool operator>=(Mileage_molecule const& A, Mileage_molecule const& B) {
	return A.l >= B.l ? true : false;
}
