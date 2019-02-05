#include <string>
#include <ctime>
using namespace std;

// 
// stringの入出力はすごいめんどい
// 
void echo(){
	// charで受け取る必要がある
	string line;
	char tmp[256];
	scanf("%s", tmp);
	line = tmp;
	// c_str()しないと出力できない
	printf("%s", line.c_str());
}

// 
// CatクラスとDogクラスは同じ!!
// 
class Cat {
private: 
	string name;
public:
	Cat(string s){
		name = s;
	}
	void naku(){
		// string needs .c_str()
		printf("%s\n", name.c_str());
	}
};

class Dog {
	string name;
public:
	Dog();
	Dog(string);
	void naku() const;
};

// 生成時に与える値の型（種類）や個数によって決められる
Dog::Dog() : name("nanashi"){}
Dog::Dog(string s) : name(s){}
void Dog::naku() const{ 
	printf("%s\n", name.c_str());
}


// 
// 
// 
int randomizilerInt(min, max){
	// 乱数の初期化
	srand( (unsigned)time( NULL ) );
	return rand();
}


int main(int argc, char const *argv[])
{
	srand( (unsigned)time( NULL ) );
	
	printf("%d", rand());
	Cat cat1("cat1");
	cat1.naku();
	Dog dog1("dog1");
	dog1.naku();
	// 引数なしのとき()書いちゃいけないの気持ち悪い
	// Dog dog2(); <= ダメ
	Dog dog2;
	dog2.naku();

	
	return 0;
}

