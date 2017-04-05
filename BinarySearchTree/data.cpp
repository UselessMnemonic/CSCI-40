#include "Data.h"
int itemClass::Key() const//"int" matches the typedef of keytype in BST.h
    {
    return SearchKey;
    }

void itemClass::SetData(string data)
    {
    MoreData=data;
    }
    
void itemClass::SetSearch(int key)
    {
    SearchKey=key;
    }
    
string itemClass::GetData()
    {
    return MoreData;
    }
    