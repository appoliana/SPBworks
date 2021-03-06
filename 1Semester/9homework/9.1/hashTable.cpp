#include "hashTable.h"
#include "list.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct HashTable
{
    int size;
    List **table;
};

HashTable *createHashTable(int size)
{
    HashTable *result = new HashTable;
    result->table = new List* [size];
    for (int i = 0; i != size; i++)
    {
        result->table[i] = createList();
    }
    result->size = size;
    return result;
}

int hashFunction(string value)
{
    int result = 0;
    for (int i = 0; i < value.length(); ++i) {
        result = abs(result + (value[i]) % 10);
    }
    return result;
}

void deleteHashTable(HashTable *table)
{
    for (int i = 0; i != table->size; i++)
    {
        clear(table->table[i]);
    }
    delete[] table->table;
    delete table;
}

bool exist(const string &value, HashTable *table)
{
    bool flag = false;
    ListElement *temp = head(table->table[hashFunction(value) % table->size]);
    while (temp != 0)
    {
        if (elementKey(temp) == value) {
            flag = true;
        }
        temp = nextElement(temp);
    }
    return flag;
}

void printHashTable(HashTable *table)
{
    for (int i = 0; i != table->size; i++)
    {
        ListElement *temp = head(table->table[i]);
        while (temp != nullptr)
        {
            cout << elementKey(temp) << " " << elementCount(temp) << endl;
            temp = nextElement(temp);
        }
    }
}

void counterOfWords(const string &key, List *table)
{
    ListElement *temp = head(table);
    while (temp != nullptr)
    {
        if (elementKey(temp) == key)
        {
            increaseElementCounter(temp);
            break;
        }
        temp = nextElement(temp);
    }
}

void addToHashTable(HashTable *table, const string &value)
{
    if (exist(value, table)) {
        counterOfWords(value, table->table[hashFunction(value) % table->size]);
    }
    else {
        Value *temp = new Value;
        temp->count = 1;
        temp->key = value;
        insert(table->table[hashFunction(value) % table->size], temp);
    }
}

int maxLengthOfList(HashTable *table) 
{
    int maxLength = 0;
    int lengthOfList = 0;
    for (int i = 0; i != table->size; i++)
    {
        ListElement *temp = head(table->table[i]);
        while (temp != nullptr)
        {
            lengthOfList++;
            temp = nextElement(temp);
        }
        if (lengthOfList > maxLength) 
        {
            maxLength = lengthOfList;
        }
        lengthOfList = 0;
    }
    return maxLength;
}

double averageLengthOfList(HashTable *table) 
{
    double averageLength = 0;
    double lengthOfList = 0;
    for (int i = 0; i != table->size; i++)
    {
        ListElement *temp = head(table->table[i]);
        while (temp != nullptr)
        {
            lengthOfList++;
            temp = nextElement(temp);
        }
        averageLength += lengthOfList;
        lengthOfList = 0;
    }
    //cout << "(всего сегментов : " << averageLength << ") ";
    averageLength = averageLength / table->size;
    return averageLength;
}

