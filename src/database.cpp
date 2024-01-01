#include "database.h"

Database* db_create(){
    Database *db = (Database*)malloc(sizeof(Database));
    db->first = nullptr;

    return db;
}

Row* db_addRow(Database* db, long key, int rowSize){
    Row* newRow = (Row*)malloc(sizeof(Row));
    newRow->key = key;

    newRow->size = rowSize;
    newRow->data = malloc(rowSize);

    newRow->next = db->first;
    db->first = newRow;

    return newRow;
}

Row* db_getRow(Database* db, long key){
    Row* r = db->first;

    if(r == nullptr)
        return nullptr;

    while(r != nullptr){
        if(r->key == key)
            return r;
        
        r = r->next;
    }

    return nullptr;
}

void db_deleteRow(Database* db, long key){

}

void db_free(Database* db){

}