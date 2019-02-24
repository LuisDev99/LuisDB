#include <iostream>
#include <string>
#include "DatabaseManager.h"

using namespace std;


void main() {

	DatabaseManager database;
	int menu = 0;

	do {

		system("cls");
		cout << " \t ### LuisDB Interactive DBCLI ###\n\n";
		cout << "1. Create Database\n2. Create Table\n3. Drop Database\n4. Drop Table\n";
		cout << "5. Select\n6. Update\n7. Delete\n8. Insert\n";
		cout << "\n\t Ingrese la opcion: ";

		cin >> menu;

		switch (menu) {

		case 1:
			database.createDatabase();
			break;

		case 2:
			database.createTable();
			break;

		case 3:
			database.dropDatabase();
			break;

		case 4:
			database.dropTable();
			break;

		case 5:
			database.select();
			break;

		case 6:
			database.update();
			break;

		case 7:
			database.deleteTableData();
			break;

		case 8:
			database.insert();
			break;
		}

	} while (menu != 5);

	system("pause");
}

