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
		equipmen_date = 110917;
		equipmen_number = 12345;
	}

	Equipment(char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12) {
		equipmen_name = new char[strlen(equipmen_name_12) + 1];

		strcpy(equipmen_name, equipmen_name_12);
		equipmen_price = equipmen_price_12;
		equipmen_date = equipmen_date_12;
		equipmen_number = equipmen_number_12;
	}

	Equipment(Equipment &a) {
		equipmen_name = new char[strlen(a.equipmen_name) + 1];

		strcpy(equipmen_name, a.equipmen_name);
		equipmen_price = a.equipmen_price;
		equipmen_date = a.equipmen_date;
		equipmen_number = a.equipmen_number;
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

	friend bool operator == (Equipment &a, Equipment &b) {
		 if ((strcmp(a.equipmen_name,b.equipmen_name)) || (a.equipmen_price != b.equipmen_price) || (a.equipmen_date != b.equipmen_date) || (a.equipmen_number != b.equipmen_number)) {
			 cout << "obj12 != obj13" << endl;
			 return 0;
		 }

		 cout << "obj12 == obj13" << endl;
		 return 1;
	}

	 friend ostream& operator << (ostream &out, Equipment &c) {
		 return out << "EQUIPMENT: NAME - " << c.equipmen_name << ". PRICE - " << c.equipmen_price << ". DATE(" << c.equipmen_date << "). NUMBER : " << c.equipmen_number << "."<<endl;
	 }

	 friend istream& operator >> (istream &inp, Equipment &c) {
		 return inp >> c.equipmen_name >> c.equipmen_price >> c.equipmen_date >> c.equipmen_number;
	 }

	 Equipment& operator = (const Equipment &a) {
		 equipmen_name = new char[strlen(a.equipmen_name) + 1];
		 strcpy(equipmen_name, a.equipmen_name);

		 equipmen_price = a.equipmen_price;
		 equipmen_date = a.equipmen_date;
		 equipmen_number = a.equipmen_number;
		 return *this;
	 }
};


class Working_equipment : public Equipment {
private:

	double introduction_date, residual_value;

public:

	Working_equipment() {
		introduction_date = 170319;
		residual_value = 1000;
	}

	Working_equipment(double introduction_date32, double residual_value32, char* equipmen_name_12, double equipmen_price_12, double equipmen_date_12, double equipmen_number_12)
		:Equipment(equipmen_name_12, equipmen_price_12, equipmen_date_12, equipmen_number_12) {

		introduction_date = introduction_date32;
		residual_value = residual_value32;
	}

	Working_equipment(Working_equipment &a) : Equipment(a.getname(), a.getprice(), a.getdate(), a.getnumber()) {
		introduction_date = a.introduction_date;
		residual_value = a.residual_value;
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

	~Working_equipment() {}

	double getdate2() {
		return introduction_date;
	}

	double getprice2() {
		return residual_value;
	}

	friend bool operator < (Working_equipment &a, Working_equipment &b) {
		if (a.residual_value < b.residual_value) {
			cout << "residual_value obj 32 < residual_value obj 33\n" << endl;
			return 0;
		}
		cout << "residual_value obj 33 < residual_value obj 32\n" << endl;
		return 1;
	}

	friend Working_equipment operator + (const Working_equipment& a, const Working_equipment& b) {
		Working_equipment temp;
		temp.residual_value = a.residual_value + b.residual_value;
		return temp;
	}

	friend Working_equipment& operator+=(Working_equipment &a, Working_equipment &b) {
		a.residual_value += b.residual_value;
		return a;
	}

	friend Working_equipment& operator ++ (Working_equipment& a) {
		a.residual_value += 1;
		return a;
	}

	friend Working_equipment& operator ++ (Working_equipment& a, int i) {
		a.residual_value = a.residual_value + 1;
		return a;
	}

	friend ostream& operator << (ostream &out, Working_equipment &c){
		return out << "EQUIPMENT: NAME - " << c.getname() << ". PRICE - " << c.getprice() << ". DATE(" << c.getdate() << "). NUMBER : " << c.getnumber() << ".\n" << "WORKING_EQUIPMENT: Introduction_date - " << c.introduction_date << ". PRICE - " << c.residual_value << endl;
	}

	friend istream& operator >> (istream &inp, Working_equipment &c) {
		return inp >> c.introduction_date >> c.residual_value;
	}

	Working_equipment& operator = (const Working_equipment  &a){
		introduction_date = a.introduction_date;
		residual_value = a.residual_value;
		Equipment :: operator = (a);
		return *this;
	}
};


int main() {
	Equipment obj11, obj12;

	printf("__________________________________________________________________________________________\n\n");
	cout << obj11;
	printf("___________________________________________________________________________________________\n\n");

	printf("Enter equipment. Name. Price. Date(xxxxxxxx). Number: \n");
	cin >> obj12;
	Equipment obj13 = obj12;

	printf("___________________________________________________________________________________________\n\n");
	cout << obj11;
	cout << obj12;
	cout << obj13;
	printf("___________________________________________________________________________________________\n\n");

	printf("Enter new name, price, date, number for obj13:\n");
	cin >> obj13;
	printf("___________________________________________________________________________________________\n\n");

	cout << obj11;
	cout << obj12;
	cout << obj13;

	obj12 == obj13;
	printf("__________________________________________________________________________________________\n\n");

	Working_equipment obj31, obj32, obj34;

	cout << obj31;

	printf("__________________________________________________________________________________________\n\n");
	printf("Enter working_equipment. Date(xxxxxx). Price.\n");
	cin >> obj32;
	obj32.setequipment(obj12.getname(), obj12.getprice(), obj12.getdate(), obj12.getnumber());
	Working_equipment obj33 = obj32;

	printf("__________________________________________________________________________________________\n\n");
	cout << obj31;
	printf("\n");
	cout << obj32;
	printf("\n");
	cout << obj33;
	printf("__________________________________________________________________________________________\n\n");

	obj33.setequipment(obj13.getname(), obj13.getprice(), obj13.getdate(), obj13.getnumber());
	printf("Enter new date , price for obj33:\n");
	cin >> obj33;

	printf("__________________________________________________________________________________________\n\n");
	cout << obj31;
	printf("\n");
	cout << obj32;
	printf("\n");
	cout << obj33;
	printf("__________________________________________________________________________________________\n\n");

	obj32 < obj33;

	cout <<"OBJ 31++: \n"  << obj31++ << endl;
	cout << "OBJ ++33: \n" << ++ obj33 << endl;

	obj34 = obj31 + obj32;
	cout <<"obj34 = obj31 + obj32: \n"<< obj34;

	return 0;
}