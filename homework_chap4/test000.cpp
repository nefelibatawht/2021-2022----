//string ������ʹ��
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str1;
    str1 = "hello STL";
    cout << str1 << endl;
    string str2("012345", 0, 2); //���±�Ϊ0��ʼ��ȡ�鴮���Ӵ�������Ϊ2
    cout << str2 << endl;
    string str3(6, '3'); //��ȡ6��3���ַ���
    cout << str3 << endl;

    return 0;
}
