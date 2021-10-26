//string 容器的使用
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str1;
    str1 = "hello STL";
    cout << str1 << endl;
    string str2("012345", 0, 2); //从下表为0开始获取珠串的子串，长度为2
    cout << str2 << endl;
    string str3(6, '3'); //获取6个3的字符串
    cout << str3 << endl;

    return 0;
}
