// Anagramm-Generator

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <string>

// Heap's algorithm
// Source: https://en.wikipedia.org/wiki/Heap%27s_algorithm
void generateAnagram(int k, std::vector<char> A, std::vector<std::string> &output) {
	if (k == 1) {
		std::string s(A.begin(), A.end());
		output.push_back(s);
	}
	else {
		for (int i = 0; i < k; i++) {
			generateAnagram(k - 1, A, output);
			if (i < k - 1) {
				if (k % 2 == 0) {
					char c = A[i];
					char d = A[k - 1];
					A[i] = d;
					A[k - 1] = c;
				}
				else {
					char c = A[0];
					char d = A[k - 1];
					A[0] = d;
					A[k - 1] = c;
				}
			}
		}
	}
}

int main()
{
	std::cout << "*** Anagram generator ***" << std::endl;
	std::cout << "Enter a word: ";

	std::string s;
	std::cin >> s;

	std::chrono::system_clock::time_point startTime = std::chrono::system_clock::now();		

	std::vector<char> data(s.begin(), s.end());
	std::vector<std::string> output;

	generateAnagram(data.size(), data, output);

	for (size_t i = 0; i < output.size(); i++) {
		std::cout << (i+1) << ": " << output.at(i).c_str() << std::endl;
	}
	
	std::chrono::system_clock::time_point endTime = std::chrono::system_clock::now();
	const auto timeDiff = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

	std::cout << "Calculation time: " << timeDiff.count() << "ms\n";
}
