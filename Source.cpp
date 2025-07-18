#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
//#include<chrono>
//#include<thread>


std::vector<std::string> zero	{" 0000 ", "00  00", "00  00", "00  00", " 0000 "};
std::vector<std::string> one	{"1111  ", "  11  ", "  11  ", "  11  ", "111111"};
std::vector<std::string> two	{" 2222 ", "22  22", "   22 ", "  22  ", "222222"};
std::vector<std::string> three	{" 3333 ", "33  33", "   333", "33  33", " 3333 "};
std::vector<std::string> four	{"44  44", "44  44", "444444", "    44", "    44"};
std::vector<std::string> five	{"555555", "55    ", "55555 ", "    55", "55555 "};
std::vector<std::string> six	{" 6666 ", "66    ", "66666 ", "66  66", " 6666 "};
std::vector<std::string> seven	{"777777", "   77 ", "  77  ", " 77   ", "77    "};
std::vector<std::string> eight	{" 8888 ", "88  88", " 8888 ", "88  88", " 8888 "};
std::vector<std::string> nine	{" 9999 ", "99  99", " 99999", "    99", " 9999 "};

std::vector<std::vector<std::string>> number{ zero, one, two, three, four, five, six, seven, eight, nine };

std::vector<std::string> colon{ "   ", " . ", "   ", " . ", "   " };


void number_output(int num) {
	for (int i = 0; i < 5; i++) {
		std::cout << number[num][i] << '\n';
	}
}

void clock_output(int hours, int minutes, int seconds) {
	int h1 = hours / 10, h2 = hours % 10, m1 = minutes / 10, m2 = minutes % 10,
		s1 = seconds / 10, s2 = seconds % 10;
	for (int i = 0; i < 5; i++) {
		std::cout << number[h1][i] << "   " << number[h2][i] << "   " << colon[i] << "   "
			<< number[m1][i] << "   " << number[m2][i] << "   " << colon[i] << "   "
			<< number[s1][i] << "   " << number[s2][i] << "\n";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	time_t deltaClock;
	while (true) {
	std::time_t clock = std::time(NULL);
	std::tm* localTime = std::localtime(&clock);
	int hours = localTime->tm_hour;
	int mins = localTime->tm_min;
	int seconds = localTime->tm_sec;
	clock_output(hours, mins, seconds);
	
	deltaClock = std::time(NULL);
	while (deltaClock - clock < 1) {
		deltaClock = std::time(NULL);
	}
	//std::this_thread::sleep_for(std::chrono::seconds(1));
	system("cls");
	}
}