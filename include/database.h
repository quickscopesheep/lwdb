#pragma once
#include "prerequisites.h"

struct Row{
    long key;
    Row* next;

    int size;
    void* data;
};

struct Database{
    Row* first;
};

Database* db_create();
Row* db_addRow(Database* db, long key, int rowSize);
Row* db_getRow(Database* db, long key);
void db_deleteRow(Database* db, long key);
void db_free(Database* db);