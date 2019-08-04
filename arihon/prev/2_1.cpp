#include <iostream>
#include <stack>
#include <queue>

using namespace std;


int fact(int n){
    if (n == 0) return 1;
    return n * fact(n-1);
}

int memo[100];
int fib(int n){
    if (n <= 1) return n; // 0 or 1
    if (memo[n] != 0) return memo[n];
    return memo[n] = fib(n-1)+fib(n-2);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    int n;
    cin >> n;
    cout << fact(n) << endl;
    cout << fib(n) << endl;

}