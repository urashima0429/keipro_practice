#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int m = N%10;
	if (m==2||m==4||m==5||m==7||m==9){
		cout << "hon" << endl;
	}else if(m==0||m==1||m==6||m==8){
		cout << "pon" << endl;
	}else if(m==3){
		cout << "bon" <<endl;
	}

	return 0;
}