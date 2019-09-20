//Converting Roman numerals to Arabic and back
#include <iostream>
#include <string>

using namespace std;

void roman_To_Arabic(string input) { //converts roman numerals to arabic numerals
	int total = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'I') {
			if (input[i + 1] == 'V') {
				total += 4;
				i += 1;
			}
			else if (input[i + 1] == 'X') {
				total += 9;
				i += 1;
			}
			else total += 1;
		}

		else if (input[i] == 'X') {
			if (input[i + 1] == 'L') {
				total += 40;
				i += 1;
			}
			else if (input[i + 1] == 'C') {
				total += 90;
				i += 1;
			}
			else total += 10;
		}
		else if (input[i] == 'C') {
			if (input[i + 1] == 'D') {
				total += 400;
				i += 1;
			}
			else if (input[i + 1] == 'M') {
				total += 900;
				i += 1;
			}
			else total += 100;
		}
		else if (input[i] == 'V') {
			total += 5;
		}
		else if (input[i] == 'L') {
			total += 50;
		}
		else if (input[i] == 'D') {
			total += 500;
		}
		else if (input[i] == 'M') {
			total += 1000;
		}
		else {
			cout << "Error: Invalid Roman numeral\n" << endl;
			return;
		}
	}
	cout << input << " is equal to " << total << endl;
}

void arabic_To_Roman(int num) { //converts Arabic numerals to Roman numerals
	string final_num;
	if (num < 0) {
		cout << "Error: Negative numbers not accepted" << endl;
	}
	else if (num == 0) {
		cout << num << " in Roman numerals is nulla" << endl;
	}
	else {
		//thousands digit
		int thousands = num / 1000;
		for (int m = 1; m <= thousands; m++) {
			final_num += 'M';
		}
		int remainder = num % 1000;

		//hundreds digit
		int hundreds = remainder / 100;
		if (hundreds == 4) {
			final_num += "CD";
		}
		else if (hundreds == 9) {
			final_num += "CM";
		}
		else if (hundreds >= 5) {
			final_num += 'D';
			for (int d = 1; d <= (hundreds - 5); d++) {
				final_num += 'C';
			}
		}
		else {
			for (int c = 1; c <= hundreds; c++) {
				final_num += 'C';
			}
		}
		remainder %= 100;

		//tens digit
		int tens = remainder / 10;
		if (tens == 4) {
			final_num += "XL";
		}
		else if (tens == 9) {
			final_num += "XC";
		}
		else if (tens >= 5) {
			final_num += 'L';
			for (int l = 1; l <= (tens - 5); l++) {
				final_num += 'X';
			}
		}
		else {
			for (int x = 1; x <= tens; x++) {
				final_num += 'X';
			}
		}
		//ones digit
		int ones = remainder % 10;
		if (ones == 4) {
			final_num += "IV";
		}
		else if (ones == 9) {
			final_num += "IX";
		}
		else if (ones >= 5) {
			final_num += 'V';
			for (int v = 1; v <= (ones - 5); v++) {
				final_num += 'I';
			}
		}
		else {
			for (int o = 1; o <= ones; o++) {
				final_num += 'I';
			}
		}
		cout << num << " in Roman numerals is " << final_num << endl;
	}
}

int main() {
	char convert_type;
	string roman_input;
	int num_input;

	while (true) {
		cout << "To convert Roman to Arabic numerals enter r\nTo convert Arabic to Roman numerals, enter a\nTo exit, enter anything else" << endl;
		cin >> convert_type;

		if (convert_type == 'r') {
			cout << "Please enter a Roman numeral" << endl;
			cin >> roman_input;
			roman_To_Arabic(roman_input);
		}
		else if (convert_type == 'a') {
			cout << "Please enter a number" << endl;
			cin >> num_input;
			arabic_To_Roman(num_input);
		}
		else break;
	}

	return 0;
}

