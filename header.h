#include<iostream>
#include<locale>
#include <fstream>
#include <sstream>
using namespace std;

//узел
struct Node {
    //колонки
    string tableColon;
    Node *next;
};


// связь колонок и таблиц
struct TablColonNode{
    //табл
    string table;
    // указываем на 1 колонку
    Node* fColon;
    TablColonNode* next;
};

//Файл json
struct configuration{
    string name;
    int tuples_limit;
    TablColonNode* Storage;
};

//Индексы строк
struct IndexPrintColon{
    string indexFromStrok;
    IndexPrintColon* next;
};

//Для селекта
struct PrintColon{
    string fromTabl;
    int fromColon;
    IndexPrintColon* strochki;
    PrintColon* next;
};

void whithFile(configuration& cond);
void NewFile(configuration cond);
void Insert(string comand, configuration cond);
PrintColon* Select(string comand, string condName);
string CutToFrom(string command);
string CutAfterWhere(string command);
void StrPrint(string CondName, PrintColon* chosen);
void Where(string CondName, PrintColon* chosen, string comand, string adComand);
void StrDel(string CondName, PrintColon* chosen);
void LockTable(string CondName);
void UnlockTable(string CondName);
bool isLocked(string CondName);
