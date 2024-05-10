#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class vectorTest
{
    vector<string> strVec;
    public:
    vectorTest() {}
    vectorTest(vector<string>&  ent):strVec(ent) {}
    int getsize() {return strVec.size();}
    void addStringEnd(string str) {strVec.push_back(str);}
    void addStringIndex(string str, int pos) {
        auto it = strVec.begin() + pos;
        strVec.insert(it, str);
    }
    void printStrings()
    {
        for(const auto &item: strVec)
        {
            cout << item << " "; 
        }
        cout << endl;
    }
};

int main()
{
    string str1 = "Hello";
    string str2 = "C++";
    string str3 = "My";
    string str4 = "Programmer";
    vector<string> elem = {str1, str2};
    vectorTest vec = vectorTest(elem);
    cout <<"size of vector = " <<vec.getsize()<<endl;
    vec.printStrings();
    vec.addStringIndex(str3, 1);
    vec.addStringEnd(str4);
    vec.printStrings();

}