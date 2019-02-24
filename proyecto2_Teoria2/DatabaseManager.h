#pragma once

#include <string>
#include <vector>

#define MegaBytesInBytesSize 1048576
#define DataBlockSize 512
#define DataBlockMetadataSize 109 


struct DatabaseMetadata {

	int databaseSize, cantidadBloques, dataBlockSize;

	DatabaseMetadata(int _databaseSize, int _dataBlockSize) {

		databaseSize = _databaseSize * MegaBytesInBytesSize; //Convert it to Bytes
		cantidadBloques = databaseSize / DataBlockSize; // Calculate the amount of block
		dataBlockSize = _dataBlockSize;

	}

	DatabaseMetadata(){ }

};

struct Bloque {

	/* Primeros 105 bytes para la metadata del bloque (cada bloque actuara como tabla)
	 * cuando un bloque se llene escribir la misma metadata al bloque siguiente ***/

	Bloque(int datablocksize, int _registerSize) {
		Data = new char[datablocksize - DataBlockMetadataSize];
		nextBlock = 0;
		registerSize = _registerSize;
		hasSpace = true;
	}

	Bloque(int datablocksize) {
		Data = new char[datablocksize - DataBlockMetadataSize];
		nextBlock = 0;
		registerSize = 0;
		hasSpace = true;
	}

	char columnsType[20]; // Example: 'I;c20;c10;D' Let I be integer,c for char and the number for size and D for double
	char columnsName[60]; // Example: 'Nombre;Edad;Salario'
	char tableName[20];

	int nextBlock;
	int registerSize;
	bool hasSpace;

	char *Data;
};

class DatabaseManager
{

public:
	DatabaseManager();
	~DatabaseManager();

	bool createTable();
	bool createDatabase();
	bool dropDatabase();
	bool dropTable();
	bool insert(); //Think
	bool deleteTableData(); //Think
	bool select();
	bool update();

};

