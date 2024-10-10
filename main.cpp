#include "header.h"
int main()
{
    //json file
    configuration cond;
    whithFile(cond);
    //Создание файлов
    
    while (isLocked(cond.name));
    LockTable(cond.name);
    NewFile(cond);

    string comand;
    getline(cin, comand);
    while(true){
     //Раздел
    istringstream Stream(comand);
    string element;
    Stream>>element;
    if(element=="INSERT"){
        Insert(comand, cond);
    }else if(element=="SELECT"){
        string selCommand = CutToFrom(comand);
        string wheCommand = CutAfterWhere(comand);
        PrintColon* chosen = Select(selCommand, cond.name);
        Where(cond.name, chosen, wheCommand, selCommand);
        StrPrint(cond.name, chosen);
    }else if (element == "DELETE")
    {
        Stream>>element;
        Stream>>element;
        string tablName = element;
        string wheCommand = CutAfterWhere(comand);
        //На основе удаления создаем селект
        string selCommand = "SELECT " + tablName + "." + tablName + "_pk";
        PrintColon* chosen = Select(selCommand, cond.name);
        Where(cond.name, chosen, wheCommand, selCommand);

        StrDel(cond.name, chosen);
    }
    else if (element == "EXIT"){
        UnlockTable(cond.name);
        return 0;
    }
    
    getline(cin, comand);
}

    return 0;
}


