//﻿#include "pch.h"
#include <iostream>
#include <string.h>
#pragma warning(disable : 4996)
using namespace std;


class Provider {
	private:
		char *provider_name, *provider_country, *provider_number;

	public:

		Provider() {
			provider_name = new char[15];
			provider_country = new char[15];
			provider_number = new char[15];

			strcpy(provider_name, "APPLE");
			strcpy(provider_country, "USA");
			strcpy(provider_number, "+1450131710");
		}

		Provider(char *provider_name_12, char *provider_country_12, char *provider_number_12) {
			provider_name = new char[strlen(provider_name_12) + 1];
			provider_country = new char[strlen(provider_country_12) + 1];
			provider_number = new char[strlen(provider_number_12) + 1];

			strcpy(provider_name, provider_name_12);
			strcpy(provider_country, provider_country_12);
			strcpy(provider_number, provider_number_12);
		}

		Provider(Provider &a) {
			provider_name = new char[strlen(a.provider_name) + 1];
			provider_country = new char[strlen(a.provider_country) + 1];
			provider_number = new char[strlen(a.provider_number) + 1];

			strcpy(provider_name, a.provider_name);
			strcpy(provider_country, a.provider_country);
			strcpy(provider_number, a.provider_number);
		}

		Provider& setname(char *provider_name_12) {
			delete[] provider_name;
			provider_name = new char[strlen(provider_name_12) + 1];
			strcpy(provider_name, provider_name_12);
			return *this;
		}

		Provider& setcountry(char *provider_country_12) {
			delete[] provider_country;
			provider_country = new char[strlen(provider_country_12) + 1];
			strcpy(provider_country, provider_country_12);
			return *this;
		}

		Provider& setnumber(char *provider_number_12) {
			delete[] provider_number;
			provider_number = new char [strlen(provider_number_12) + 1];
			strcpy(provider_number, provider_number_12);
			return *this;
		}

		~Provider() {
			if (provider_name) {
				delete[] provider_name;
			} 
			if (provider_country) {
				delete[] provider_country;
			}
			if (provider_number) {
				delete[] provider_number;
			}
		}

		char* getname() {
			return provider_name;
		}

		char* getcountry() {
			return provider_country;
		}

		char* getnumber() {
			return provider_number;
		}

		void  print() {
			cout << "PROVIDER: Name - " << provider_name << ". Country - " << provider_country << ". Number - " << provider_number << ".\n" << endl;
		}

		void print_short() {
			cout << "Country : " << provider_country << "." << endl;

		}
};


class Equipment {
	private:
		char *equipmen_name;
		double equipmen_price, equipmen_date, equipmen_number;
		Provider info;

	public:

		Equipment() {
			equipmen_name = new char[15];

			strcpy(equipmen_name, "APPLE");
			equipmen_price = 11500;
			equipmen_date = 11092017;
			equipmen_number = 12345654312350;

		}

		Equipment(char* equipmen_name_22, double equipmen_price_22, double equipmen_date_22, double equipmen_number_22, char* provider_name_12, char* provider_country12, char* provider_number_12)
			:info(provider_name_12, provider_country12, provider_number_12){
			equipmen_name = new char[strlen(equipmen_name_22) + 1];

			strcpy(equipmen_name, equipmen_name_22);
			equipmen_price = equipmen_price_22;
			equipmen_date = equipmen_date_22;
			equipmen_number = equipmen_number_22;
		}

		Equipment(Equipment &a) :info(a.info.getname(), a.info.getcountry(), a.info.getnumber()) {
			equipmen_name = new char[strlen(a.equipmen_name) + 1];

			strcpy(equipmen_name, a.equipmen_name);
			equipmen_price = a.equipmen_price;
			equipmen_date = a.equipmen_date;
			equipmen_number = a.equipmen_number;
		}

		Equipment& setname(char *equipmen_name_22) {
			delete[] equipmen_name;
			equipmen_name = new char[strlen(equipmen_name_22) + 1];
			strcpy(equipmen_name, equipmen_name_22);
			return *this;
		}

		Equipment& setprice(double equipmen_price_22) {
			equipmen_price = equipmen_price_22;
			return *this;
		}

		Equipment& setdate(double equipmen_date_22) {
			equipmen_date = equipmen_date_22;
			return *this;
		}

		Equipment& setnumber(double number_2) {
			equipmen_number = number_2;
			return *this;
		}
	
		Equipment& setprovider(char *provider_name13, char *provider_country13, char *provider_number13) {
			info.setname(provider_name13);
			info.setcountry(provider_country13);
			info.setnumber(provider_number13);
			info.print();
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

		void  print() {
			printf("EQUIPMENT: Name - %s. Price - %0.2lf. Date - %0.0lf. Number - %0.0lf.\n", equipmen_name, equipmen_price, equipmen_date, equipmen_number);
			info.print();

		}

		void print_short() {
			cout << "Name : " << equipmen_name << "." << endl;
			info.print_short();
		}
};


class Modernization {
	private:
		double moderzatiom_price, moderzatiom_date;

	public:

		Modernization() {
			moderzatiom_price = 300;
			moderzatiom_date= 23022018;
		}

		Modernization(double moderzatiom_price_32, double moderzatiom_date_32) {
			moderzatiom_price = moderzatiom_price_32;
			moderzatiom_date = moderzatiom_date_32;
		}

		Modernization(Modernization &a) {
			moderzatiom_price = a.moderzatiom_price;
			moderzatiom_date = a.moderzatiom_date;
		}

		Modernization& setprice(double moderzatiom_price_32) {
			moderzatiom_price = moderzatiom_price_32;
			return *this;
		}

		Modernization& setdate(double moderzatiom_date_32) {
			moderzatiom_date = moderzatiom_date_32;
			return *this;
		}

		double getprice() {
			return moderzatiom_price;
		}

		double getdate() {
			return moderzatiom_date;
		}

		void  print() {
			printf("MODERNIZATION: Price - %0.2lf. Date - %0.0lf.\n\n", moderzatiom_price, moderzatiom_date);
		}

		void print_short() {
			cout << "Price : " << moderzatiom_price << "." << endl;
		}
};


int main() {
	char name_12[15], country_12[15], number_12[15];
	Provider obj11;
	obj11.print();

	printf("\n\nEnter provider. Name  Country  Number: \n");
	scanf("%s%s%s", name_12, country_12, number_12);
	printf("\n\n");
	printf("\n\_____________________________________________________________________________________\n\n");
	Provider obj12(name_12, country_12, number_12);
	Provider obj13 = obj12;

	obj11.print();
	obj12.print();
	obj13.print();

	printf("______________________________________________________________________________________\n\n");
	printf("\n\nEnter new name, country and number for obj13:\n");
	scanf("%s%s%s", name_12, country_12, number_12);
	printf("\n\n");
	obj13.setname(name_12);
	obj13.setcountry(country_12);
	obj13.setnumber(number_12);
	printf("______________________________________________________________________________________\n\n");

	obj11.print();
	obj12.print();
	obj13.print();

	printf("___________________________________________________________________________________________\n\n");
	char name_22[15];
	double price_22, date_22, number_22;
	Equipment obj21;
	obj21.print();
	printf("___________________________________________________________________________________________\n\n");

	printf("\nEnter equipment. Name. Price. Date(xxxxxxxx). Number: \n");
	scanf("%s%lf%lf%lf", name_22, &price_22, &date_22, &number_22);
	printf("\n\n");
	printf("___________________________________________________________________________________________\n\n");

	Equipment obj22(name_22, price_22, date_22, number_22, obj12.getname(), obj12.getcountry(), obj12.getnumber());
	Equipment obj23 = obj22;

	obj21.print();
	obj22.print();
	obj23.print();
	printf("___________________________________________________________________________________________\n\n");

	printf("\n\nEnter new name, price, date, number for obj23:\n");
	scanf("%s%lf%lf%lf", name_22, &price_22, &date_22, &number_22);
	printf("\n\n");

	obj23.setname(name_22);
	obj23.setprice(price_22);
	obj23.setnumber(number_22);
	obj23.setdate(date_22);
	obj23.setprovider(obj13.getname(), obj13.getcountry(), obj13.getnumber());
	printf("___________________________________________________________________________________________\n\n");

	obj21.print();
	obj22.print();
	obj23.print();

	printf("__________________________________________________________________________________________\n\n");
	double price_32, date_32;
	Modernization obj31;
	obj31.print();

	printf("__________________________________________________________________________________________\n\n");
	printf("\nEnter modernization. Price. Date(xxxxxxxx).\n");
	scanf("%lf%lf",&price_32, &date_32);
	printf("\n\n");

	Modernization obj32(price_32, date_32);
	Modernization obj33 = obj32;

	printf("__________________________________________________________________________________________\n\n");
	obj31.print();
	obj32.print();
	obj33.print();
	printf("__________________________________________________________________________________________\n\n");

	printf("\n\nEnter new price, date for obj33:\n");
	scanf("%lf%lf", &price_32, &date_32);
	printf("\n\n");

	obj33.setprice(price_32);
	obj33.setdate(date_32);

	printf("__________________________________________________________________________________________\n\n");
	obj31.print();
	obj32.print();
	obj33.print();
	printf("__________________________________________________________________________________________\n\n");
	system("pause");

	printf("\n\n\n\t\t\t FULL INFORMATION\n\n");

	cout << "\t\tPROVIDER\n\n" << endl;
	obj11.print();
	obj12.print();
	obj13.print();

	cout << "\t\tEQUIPMENT\n\n" << endl;
	obj21.print();
	obj22.print();
	obj23.print();

	cout << "\t\tMODERNIZATION\n\n" << endl;
	obj31.print();
	obj32.print();
	obj33.print();
	system("pause");

	printf("\n\n\n\t\t\t SHORT INFORMATION\n\n");

	cout << "\t\tPROVIDER\n\n" << endl;
	obj11.print_short();
	obj12.print_short();
	obj13.print_short();

	cout << "\t\tEQUIPMENT\n\n" << endl;
	obj21.print_short();
	obj22.print_short();
	obj23.print_short();

	cout << "\t\tMODERNIZATION\n\n" << endl;
	obj31.print_short();
	obj32.print_short();
	obj33.print_short();


	return 0;
}
