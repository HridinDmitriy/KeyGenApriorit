#include <iostream>
#include <vector>
#include <string>
#include <ctime>  
#include <conio.h>

using std::cout;
using std::vector;
using std::string;

void fill_partially_serial_key(vector<char>& serial_key, size_t last_symb_code, size_t sum, size_t first_ind, size_t sec_ind);
string generate_key();

int main()
{ 
	srand(static_cast<unsigned int>(time(nullptr)));
 
	do
	{
		cout << generate_key();
		cout << "\nPress any key to get next serial key...\n";

	} while (_getch());
}

string generate_key()
{
	vector<char> serial_key(7); 
	int last_valid_symb_code = 126; 

	// serial_key[0] + serial_key[5] should be 222 (0xDE)
	fill_partially_serial_key(serial_key, last_valid_symb_code, 222, 0, 5);

	// serial_key[2] + serial_key[3] should be 212 (0xD4) 
	fill_partially_serial_key(serial_key, last_valid_symb_code, 212, 2, 3);

	// serial_key[1] + serial_key[4] should be 754 - 222 - 212 - 6 * 16 - 15 = 209
	fill_partially_serial_key(serial_key, last_valid_symb_code, 209, 1, 4);

	serial_key.back() = '\0'; 
	return serial_key.data(); 
}

void fill_partially_serial_key(vector<char>& serial_key, size_t last_symb_code, size_t sum, size_t first_ind, size_t sec_ind)
{
	size_t offset = sum - last_symb_code; 
	size_t char_code = rand() % (last_symb_code - offset + 1) + offset;

	serial_key[first_ind] = static_cast<char>(char_code);
	serial_key[sec_ind] = static_cast<char>(sum - char_code);
}