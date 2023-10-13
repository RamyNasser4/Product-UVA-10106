#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	string firstNumber, secondNumber;
	while (cin >> firstNumber) {
		cin >> secondNumber;
		int arr[600] = {};
		int arrIndex = 0;
		int lastIndex;
		reverse(firstNumber.begin(), firstNumber.end());
		reverse(secondNumber.begin(), secondNumber.end());
		for (int i = 0; secondNumber.length() > i; ++i) {
			int carry = 0;
			int currentIndex = arrIndex;
			for (int j = 0; firstNumber.length() > j; ++j, ++currentIndex) {
				arr[currentIndex] += (((secondNumber[i] - '0')
						* (firstNumber[j] - '0')) + carry) % 10;
				carry = (((secondNumber[i] - '0') * (firstNumber[j] - '0'))
						+ carry) / 10;
			}
			arr[currentIndex] += carry;
			++arrIndex;
			lastIndex = currentIndex;
		}
		for (int i = 0; lastIndex >= i; ++i) {
			if (arr[i] > 9) {
				int currentCarry = arr[i] / 10;
				int carryIndex = i + 1;
				arr[carryIndex] += currentCarry;
				while (arr[carryIndex] > 9) {
					currentCarry = arr[carryIndex] / 10;
					arr[carryIndex] %= 10;
					++carryIndex;
					arr[carryIndex] += currentCarry;
				}
				arr[i] %= 10;
			}
		}
		while(arr[lastIndex]==0 && lastIndex!=0){
			--lastIndex;
		}
		for (int i = lastIndex; i >= 0; --i) {
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}
