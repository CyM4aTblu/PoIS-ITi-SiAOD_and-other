#include <iostream>
using namespace std;
int killbits(int i)
{
	i = i & 0xAAAAAAAA;
	return i;
}
int main()
{
	cout << "Pease, enter yout num: " << endl;
	int n;
	cin >> n;
	cout << "After set odd bits in 0: " << killbits(n);
}