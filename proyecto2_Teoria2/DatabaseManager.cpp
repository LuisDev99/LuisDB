#include "DatabaseManager.h"
#include <fstream>
#include <direct.h>
#include <string>
#include <iostream>

using namespace std;

DatabaseManager::DatabaseManager()
{
}


DatabaseManager::~DatabaseManager()
{
}

bool DatabaseManager::createTable()
{
	return false;
}

bool DatabaseManager::createDatabase()
{
	string databaseName;
	int datablockSize;
	int databaseSize;

	cout << "  ### CREANDO BASE DE DATO ### \n\n";

	cout << "Ingrese el nombre de la base de dato: ";
	cin >> databaseName;

	cout << "Ingrese el tamaño (MB): ";
	cin >> databaseSize;

	cout << "Tamaño de bloques\n1. 512\n2. 1024\n3. 2048\n4. 4096\n5. 8192\nEliga un tamaño: ";
	cin >> datablockSize;

	switch (datablockSize) {

	case 1:
		datablockSize = 512;
		break;

	case 2:
		datablockSize = 1024;
		break;

	case 3:
		datablockSize = 2048;
		break;

	case 4:
		datablockSize = 4096;
		break;

	case 5:
		datablockSize = 8192;
		break;

	default:
		cout << "Ingreso una opcion invalida! El tamaño sera 4096 por defecto\n";
		datablockSize = 4096;
		break;

	}
	

	_mkdir(databaseName.c_str());
	
	string pathToDatabaseDirectory = databaseName + "//" + databaseName + ".db";

	fstream writer(pathToDatabaseDirectory.c_str(), ios::binary);

	DatabaseMetadata dbMetadata(databaseSize);
	



	return false;
}

bool DatabaseManager::dropDatabase()
{
	return false;
}

bool DatabaseManager::dropTable()
{
	return false;
}

bool DatabaseManager::insert()
{
	return false;
}

bool DatabaseManager::deleteTableData()
{
	return false;
}

bool DatabaseManager::select()
{
	return false;
}

bool DatabaseManager::update()
{
	return false;
}
