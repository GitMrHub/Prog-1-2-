#include "pch.h"
#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;  


class Equipment {
private:

	char *equipmen_name;
	double equipmen_price, equipmen_date, equipmen_number;

public:

	Equipment() {
		equipmen_name = new char[15];

		strcpy(equipmen_name, "APPLE");
		equipmen_price = 11500;
		equipmen_date = 11092017;
		equipmen_number = 12345654312350;

		cout << "Default constructor Equipment\n" << endl;

	}

	Equipment(char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12) {
		equipmen_name = new char[strlen(equipmen_name_12) + 1];

		strcpy(equipmen_name, equipmen_name_12);
		equipmen_price = equipmen_price_12;
		equipmen_date = equipmen_date_12;
		equipmen_number = equipmen_number_12;

		cout << "\nConstructor Equipment with  parameters" << endl;
	}

	Equipment(Equipment &a) {
		equipmen_name = new char[strlen(a.equipmen_name) + 1];

		strcpy(equipmen_name, a.equipmen_name);
		equipmen_price = a.equipmen_price;
		equipmen_date = a.equipmen_date;
		equipmen_number = a.equipmen_number;

		cout << "\nCopy constructor Equipment" << endl;
	}

	Equipment& setname(char *equipmen_name_12) {
		delete[] equipmen_name;
		equipmen_name = new char[strlen(equipmen_name_12) + 1];
		strcpy(equipmen_name, equipmen_name_12);
		return *this;
	}

	Equipment& setprice(double equipmen_price_12) {
		equipmen_price = equipmen_price_12;
		return *this;
	}

	Equipment& setdate(double equipmen_date_12) {
		equipmen_date = equipmen_date_12;
		return *this;
	}

	Equipment& setnumber(double number_12) {
		equipmen_number = number_12;
		return *this;
	}

	~Equipment() {
		if (equipmen_name) {
			delete[] equipmen_name;

			cout << "\nDestructor Equipment\n" << endl;
		}
	}

	char* getname() {
		return equipmen_name;
	}

	double getprice() {
		return equipmen_price;
	}

	double getdate() {
		return equipmen_date;
	}

	double getnumber() {
		return equipmen_number;
	}

	void  print() {
		printf("EQUIPMENT: Name - %s. Price - %0.2lf. Date - %0.0lf. Number - %0.0lf.\n", equipmen_name, equipmen_price, equipmen_date, equipmen_number);

	}

	void view() {
		cout << "EQUIPMENT: Price - " << equipmen_price << "." << endl;
	}
};


class Modernization {
private:

	double moderzatiom_price, moderzatiom_date;

public:

	Modernization() {
		moderzatiom_price = 300;
		moderzatiom_date = 23022018;

		cout << "\nDefault constructor Modernization\n" << endl;
	}

	Modernization(double moderzatiom_price_22, double moderzatiom_date_22) {
		moderzatiom_price = moderzatiom_price_22;
		moderzatiom_date = moderzatiom_date_22;

		cout << "\nConstructor Modernization with  parameters" << endl;
	}

	Modernization(Modernization &a) {
		moderzatiom_price = a.moderzatiom_price;
		moderzatiom_date = a.moderzatiom_date;

		cout << "\nCopy constructor Modernization" << endl;
	}

	Modernization& setprice1(double moderzatiom_price_22) {
		moderzatiom_price = moderzatiom_price_22;
		return *this;
	}

	Modernization& setdate1(double moderzatiom_date_22) {
		moderzatiom_date = moderzatiom_date_22;
		return *this;
	}

	~Modernization() {
		cout << "\nDestructor Modernization\n" << endl;
	}

	double getprice1() {
		return moderzatiom_price;
	}

	double getdate1() {
		return moderzatiom_date;
	}

	void  print() {
		printf("MODERNIZATION: Price - %0.2lf. Date - %0.0lf.\n", moderzatiom_price, moderzatiom_date);
	}
	void view() {
		cout << "MODERNIZATION: Price - " << moderzatiom_price << "." << endl;
	}
};


class Working_equipment : public Equipment {
	private:

		double introduction_date, residual_value;

	public:

		Working_equipment() {
			introduction_date = 170319;
			residual_value = 1000;

			cout << "Default constructor Working_equipment" << endl;
		}

		Working_equipment(double introduction_date32, double residual_value32, char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12)
		:Equipment(equipmen_name_12, equipmen_price_12, equipmen_date_12, equipmen_number_12) {

			introduction_date = introduction_date32;
			residual_value = residual_value32;

			cout << "\nConstructor Working_equipment with  parameters" << endl;
		}

		Working_equipment(Working_equipment &a) : Equipment(a.getname(), a.getprice(), a.getdate(), a.getnumber()) {
			introduction_date = a.introduction_date;
			residual_value = a.residual_value;

			cout << "\nCopy constructor Working_equipment" << endl;
		}

		Working_equipment& setdate2(double introduction_date32) {
			introduction_date = introduction_date32;
			return *this;
		}

		Working_equipment& setprice2(double residual_value32) {
			residual_value = residual_value32;
			return *this;
		}

		Working_equipment& setequipment(char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12) {
			Equipment::setname(equipmen_name_12);
			Equipment::setprice(equipmen_price_12);
			Equipment::setdate(equipmen_date_12);
			Equipment::setnumber(equipmen_number_12);
			return *this;
		}

		~Working_equipment() {
			cout << "\nDestructor Working_equipment\n" << endl;
		}

		double getdate2() {
			return introduction_date;
		}

		double getprice2() {
			return residual_value;
		}

		void print() {
			Equipment::print();
			cout << "WORKING_EQUIPMENT: Introduction_date - " << introduction_date << ". Residual_value - " << residual_value << "." << endl;
		}

		void view() {
			cout << "WORKING_EQUIPMENT: Price - " << residual_value << "." << endl;
		}
};


class Upgraded_equipment: public Working_equipment, public Modernization {
	private:

		double added_value;

	public:

		Upgraded_equipment() {
			added_value = 200;

			cout << "Default constructor Upgraded_equipment" << endl;
		}

		Upgraded_equipment(double added_value42, double introduction_date32, double residual_value32, char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12, double moderzatiom_price_22, double moderzatiom_date_22)
		:Working_equipment (introduction_date32, residual_value32, equipmen_name_12, equipmen_price_12, equipmen_date_12,  equipmen_number_12), 
		 Modernization(moderzatiom_price_22, moderzatiom_date_22) {

			added_value = added_value42;

			cout << "\nConstructor Upgraded_equipment with  parameters" << endl;
		}

		Upgraded_equipment(Upgraded_equipment &a): Working_equipment(a.getdate2(), a.getprice2(), a.getname(), a.getnumber(), a.getdate(), a.getnumber()), Modernization(a.getprice1(), a.getdate1()){
			added_value = a.added_value;

			cout << "\nCopy constructor  Upgraded_equipment\n" << endl;
		}

		Upgraded_equipment& setvalue(double added_value42) {
			added_value = added_value42;
			return *this;
		}

		Upgraded_equipment& setwork_and_modern(double introduction_date32, double residual_value32, char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12, double moderzatiom_price_22, double moderzatiom_date_22) {

			Working_equipment::setdate2(introduction_date32);
			Working_equipment::setprice2(residual_value32);
			Working_equipment::setequipment(equipmen_name_12, equipmen_price_12, equipmen_date_12, equipmen_number_12);

			Modernization::setdate1(moderzatiom_date_22);
			Modernization::setprice1(moderzatiom_price_22);
			return *this;
		}

		~Upgraded_equipment() {
			cout << "\nDestructor Upgraded_equipment\n" << endl;
		}

		double getvalue() {
			return added_value;
		}

		void print() {
			Working_equipment::print();
			Modernization::print();
			cout << "UPGRADED_EQUIPMENT: Added value - " << added_value <<"." << endl;
		}

		void view() {
			cout << "UPGRADED_EQUIPMENT: Price - " << added_value << "." << endl;
		}
};


int main() {
	char name_12[15];
	double price_12, date_12, number_12;
	Equipment obj11;

	printf("__________________________________________________________________________________________\n\n");

	obj11.print();

	printf("___________________________________________________________________________________________\n\n");

	printf("Enter equipment. Name. Price. Date(xxxxxxxx). Number: \n");
	scanf("%s%lf%lf%lf", name_12, &price_12, &date_12, &number_12);
	
	Equipment obj12(name_12, price_12, date_12, number_12);
	Equipment obj13 = obj12;

	printf("___________________________________________________________________________________________\n\n");
	obj11.print();
	obj12.print();
	obj13.print();
	printf("___________________________________________________________________________________________\n\n");

	printf("Enter new name, price, date, number for obj13:\n");
	scanf("%s%lf%lf%lf", name_12, &price_12, &date_12, &number_12);

	obj13.setname(name_12);
	obj13.setprice(price_12);
	obj13.setnumber(number_12);
	obj13.setdate(date_12);
	printf("___________________________________________________________________________________________\n\n");

	obj11.print();
	obj12.print();
	obj13.print();

	printf("__________________________________________________________________________________________\n\n");

	double price_22, date_22;
	Modernization obj21;
	printf("__________________________________________________________________________________________\n\n");

	obj21.print();

	printf("__________________________________________________________________________________________\n\n");
	printf("Enter modernization. Price. Date(xxxxxxxx).\n");
	scanf("%lf%lf", &price_22, &date_22);

	Modernization obj22(price_22, date_22);
	Modernization obj23 = obj22;

	printf("__________________________________________________________________________________________\n\n");
	obj21.print();
	obj22.print();
	obj23.print();
	printf("__________________________________________________________________________________________\n\n");

	printf("Enter new price, date for obj23:\n");
	scanf("%lf%lf", &price_22, &date_22);

	obj23.setprice1(price_22);
	obj23.setdate1(date_22);

	printf("__________________________________________________________________________________________\n\n");
	obj21.print();
	obj22.print();
	obj23.print();
	printf("__________________________________________________________________________________________\n\n");

	double date_32, price_32;
	Working_equipment obj31;
	printf("__________________________________________________________________________________________\n\n");

	obj31.print();

	printf("__________________________________________________________________________________________\n\n");
	printf("Enter working_equipment. Date(xxxxxx). Price.\n");
	scanf("%lf%lf", &date_32, &price_32);

	Working_equipment obj32(date_32, price_32, obj12.getname(), obj12.getprice(), obj12.getdate(), obj12.getnumber());
	Working_equipment obj33 = obj32;

	printf("__________________________________________________________________________________________\n\n");
	obj31.print();
	printf("\n");
	obj32.print();
	printf("\n");
	obj33.print();
	printf("__________________________________________________________________________________________\n\n");

	printf("Enter new date , price for obj33:\n");
	scanf("%lf%lf", &date_32, &price_32);
	printf("\n\n");

	obj33.setdate2(date_32);
	obj33.setprice2(price_32);
	obj33.setequipment(obj13.getname(), obj13.getprice(), obj13.getdate(), obj13.getnumber());

	printf("__________________________________________________________________________________________\n\n");
	obj31.print();
	printf("\n");
	obj32.print();
	printf("\n");
	obj33.print();
	printf("__________________________________________________________________________________________\n\n");

	double added_value42;
	Upgraded_equipment obj41;
	printf("__________________________________________________________________________________________\n\n");

	obj41.print();

	printf("__________________________________________________________________________________________\n\n");
	cout << "Enter added_value: ";
	cin >> added_value42;

	Upgraded_equipment obj42(added_value42, obj32.getdate2(), obj32.getprice2(),obj12.getname(), obj12.getprice(), obj12.getdate(),obj12.getnumber(), obj22.getprice1(), obj22.getdate1());
	Upgraded_equipment obj43 = obj42;
	printf("__________________________________________________________________________________________\n\n");
	obj41.print();
	printf("\n");
	obj42.print();
	printf("\n");
	obj43.print();
	printf("__________________________________________________________________________________________\n\n");

	printf("Enter new value for obj43:\n");
	cin >> added_value42;

	obj43.setvalue(added_value42);
	obj43.setwork_and_modern(obj33.getdate2(), obj33.getprice2(),obj13.getname(), obj13.getprice(), obj13.getdate(), obj13.getnumber(), obj23.getprice1(), obj23.getdate1());

	printf("__________________________________________________________________________________________\n\n");
	obj41.print();
	printf("\n");
	obj42.print();
	printf("\n");
	obj43.print();
	printf("__________________________________________________________________________________________\n");
	system("pause");
	printf("\n");

	obj11.view();
	obj21.view();
	obj31.view();
	obj41.view();
	printf("\n");

	obj12.view();
	obj22.view();
	obj32.view();
	obj42.view();
	printf("\n");

	obj13.view();
	obj23.view();
	obj33.view();
	obj43.view();
	printf("__________________________________________________________________________________________\n");
	system("pause");
	return 0;
}
