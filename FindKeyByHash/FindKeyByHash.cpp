#include <iostream>
#include <string>
#include "md5.h"
#include <vector>
using std::cout;
using std::string;

int main()
{
	std::vector<char> vec(7); 
	vec.back() = '\0';
	int count = 0;

	for (size_t i = 96; i <= 126; ++i)
	{
		vec[0] = static_cast<char>(i);
		vec[5] = static_cast<char>(222 - i);

		for (size_t j = 86; j <= 126; ++j)
		{
			vec[2] = static_cast<char>(j);
			vec[3] = static_cast<char>(212 - j); 

			for (size_t k = 83; k <= 126; ++k)
			{
				vec[1] = static_cast<char>(k);
				vec[4] = static_cast<char>(209 - k);

				++count;
				if (md5(string(vec.data())) == "96c4dda0c4a0b34262b1d91d47056f9e")
				{
					cout << vec.data() << "\n";
					goto wq;
				}
			}
		}

	}

	wq:
	cout << count;
}

