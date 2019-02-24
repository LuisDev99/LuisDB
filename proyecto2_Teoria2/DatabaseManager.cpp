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
	string databaseName, path;
	int datablockSize;
	int databaseSize;

	cout << "  ### CREANDO BASE DE DATO ### \n\n";

	cout << "Ingrese el nombre de la base de dato: ";
	cin >> databaseName;
	path = databaseName;

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
	
	path = "Databases//" + databaseName;
	_mkdir(path.c_str());
	
	string pathToDatabaseDirectory = path + "//" + databaseName + ".dbb";

	fstream writer(pathToDatabaseDirectory.c_str(), ios::out | ios::binary);

	DatabaseMetadata dbMetadata(databaseSize, datablockSize);
	
	/*First 12 bytes for the metadata of the db*/
	writer.write(reinterpret_cast<char *>(&dbMetadata), sizeof DatabaseMetadata);

	/*Next, the map of bytes which will help to find an empty block, create them with all and set it to true*/

	bool dummyBool = true;
	for (int i = 0; i < dbMetadata.cantidadBloques; i++) {
		writer.write(reinterpret_cast<char *>(&dummyBool), sizeof(bool));
	}

	/*The rest, write the empty blocks*/
	Bloque block(dbMetadata.dataBlockSize);

	for (int i = 0; i < dbMetadata.cantidadBloques; i++) {
		writer.write(reinterpret_cast<char *>(&block), sizeof block);
	}

	cout << "Database Created\n ";
	system("pause");

	return true;
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


//TEEST
/*fstream reader(pathToDatabaseDirectory.c_str(), ios::in | ios::binary);
DatabaseMetadata mFresh;

reader.seekg(0, ios::beg);

reader.read(reinterpret_cast<char *>(&mFresh), sizeof(DatabaseMetadata));

cout << mFresh.databaseSize << "-> " << mFresh.dataBlockSize << "--> " << mFresh.cantidadBloques;

//For the boolean vector

bool  erick;
fstream reader(pathToDatabaseDirectory.c_str(), ios::in | ios::binary);

reader.seekg(12, ios::beg);

for (int i = 0; i < dbMetadata.cantidadBloques; i++) {
reader.read(reinterpret_cast<char *>(&erick), sizeof(bool));
cout << erick;
}

system("pause");*/