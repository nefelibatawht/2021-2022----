//#include <iostream>
//using namespace std;
//class BiNode {
//public:
//	int data;
//	BiNode* next;
//};
//BiNode* Get(BiNode* T) {
//	T = new BiNode[10];
//	return T;
//}
//int main(void) {
//	BiNode *H = new BiNode[10];
//	cout << H << endl;
//	H = NULL;
//	cout << H << endl;
//	delete(H);
//	cout << H << endl;
//	H=Get(H);
//	
//	cout << H << endl;
//	cout << H+1 << endl;
//	return 0;
//
//}

//A[0][1][2]按行优先方式在内存的存储地址为：100+（0*2*4+1*4+2）*1=106
//A[0][1][2]按列优先方式在内存的存储地址为：100 + （2 * 2 * 3 + 1 * 3 + 0） * 1 = 115