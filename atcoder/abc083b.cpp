#include <iostream>
using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
	// init
    int n, a, b;
    int sum_sum = 0;

    // input
    cin >> n >> a >> b;

    // check
    for (int i = 0; i < n; ++i){
        int sum = findSumOfDigits(i+1);
        if (a <= sum && sum <= b){
            sum_sum += i+1;
        }
    }

    // output
    cout << sum_sum << endl;
}

