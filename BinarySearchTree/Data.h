//Christopher Madrigal
#include <string>
using namespace std;
class itemClass
    {
    public:
        int Key() const;//"int" matches the typedef of keytype in BST.h
        string GetData();
        void SetData(string);//initialize MoreData
        void SetSearch(int);//initialize SearchKey
    private:
        int SearchKey;
        string MoreData;
    };
    
