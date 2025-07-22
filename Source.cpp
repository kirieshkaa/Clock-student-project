#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fcntl.h>
#include <io.h>

//#include<chrono>
//#include<thread>


std::vector<std::wstring> zero	{ L" 0000 ", L"00  00", L"00  00", L"00  00", L" 0000 "};
std::vector<std::wstring> one	{ L"1111  ", L"  11  ", L"  11  ", L"  11  ", L"111111"};
std::vector<std::wstring> two	{ L" 2222 ", L"22  22", L"   22 ", L"  22  ", L"222222"};
std::vector<std::wstring> three	{ L" 3333 ", L"33  33", L"   333", L"33  33", L" 3333 "};
std::vector<std::wstring> four	{ L"44  44", L"44  44", L"444444", L"    44", L"    44"};
std::vector<std::wstring> five	{ L"555555", L"55    ", L"55555 ", L"    55", L"55555 "};
std::vector<std::wstring> six	{ L" 6666 ", L"66    ", L"66666 ", L"66  66", L" 6666 "};
std::vector<std::wstring> seven	{ L"777777", L"   77 ", L"  77  ", L" 77   ", L"77    "};
std::vector<std::wstring> eight	{ L" 8888 ", L"88  88", L" 8888 ", L"88  88", L" 8888 "};
std::vector<std::wstring> nine	{ L" 9999 ", L"99  99", L" 99999", L"    99", L" 9999 "};

std::vector<std::vector<std::wstring>> number{ zero, one, two, three, four, five, six, seven, eight, nine };

std::vector<std::wstring> colon{ L"   ", L" . ", L"   ", L" . ", L"   " };

std::vector<std::wstring> picture{
L" ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠉⢳⣰⠋⠙⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢧⡀⠁⢀⡜⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⠋⠀⠀⠀⠀⠀⠀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⣠⣴⣶⢦⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡾⠟⠛⠛⠛⠿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⣼⠋⠀⠀⠀⠈⠻⣷⣄⠀⠀⠀⠀⠀⢀⢸⡏⠀⠀⢀⣀⣀⠀⠘⣷⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⢸⡏⠀⠀⣠⣴⣦⡀⠸⣿⡷⠶⠾⠻⠛⠛⠃⠀⠀⡿⣿⣿⣿⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⣼⡇⠀⢸⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠿⠿⠛⠀⠀⠙⢷⡀⠀⠀⠀⠀⠀ ",
L"⠀⠀⠀⢽⡇⠀⠀⠉⠛⠛⠉⠀⠀⠀⠀⠰⣤⣤⠞⠀⠀⠀⠀⢀⢤⢤⠤⣄⠀⠀⢸⡇⠀⠀⠀⠀⠀",
L"⠀⠀⠀⢸⡇⠀⠀⢀⡴⢶⠲⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⢵⣁⡧⠃⠀⠀⣿⠃⠀⠀⠀⠀",
L"⠀⠀⠀⢸⣿⠀⠀⢯⣊⡧⠽⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠀⠀",
L"⠀⠀⠀⠐⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⡏⠀⠀⠀⠀",
L"⠀⢀⣠⣤⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠀⠙⠶⣄⠀⠀⠀",
L"⠀⣾⡏⠀⠸⡄⠀⠀⠀⠀⠀⠀⣰⠋⠁⠀⠀⠀⠀⠀⠀⠉⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡄ ",
L"⠰⣿⠀⠀⠀⠁⠀⠀⠀⠀⠀⢰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⡄⠀⠀⠀⠀⠀⠀⠀⠀ ⣿⠀",
L"⠘⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡇⠀⠀⠀⠀⠀⠀⠀ ⠀⢸ ",
L"⠀⢻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠊⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠁⠀⢠⠀⠀⠀⠀ ⠀⠀⡟⠀",
L"⠀⠈⣿⡆⠀⠀⠀⠀⠘⢆⠀⠀⠀⢸⣆⠀⠀⠀⠀⠀⠀⠀⢀⣾⠀⠀⠀⣿⠀⠀⠀ ⠀⠀⡼⠀⠀",
L"⠀⠀⠈⠻⣦⣀⠀⢀⠀⠈⣇⡄⠀⠀⠿⡆⠀⠀⠀⠀⠀⠀⣸⡇⠀⠀⠀⣿⠀⠀ ⣶⡾⠟⠀⠀⠀",
L"⠀⠀⠀⠀⠈⢛⣻⡿⠀⠀⠈⣷⡀⠀⠀⢻⡦⠤⠤⠤⠤⠄⡇⠀⠀⠀⢸⡇  ⣾⣅⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⠸⣯⣦⣤⣤⣴⣼⣇⠀⠀⠀⣷⡀⠀⠀⠀⣸⡏⠀⢠⠀⢸⣷⣤⣤⣾⠏⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠀⢹⣆⣷⣴⣾⡇⠀⠀⠀⢸⡇⢀⣼⠼⠾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⠛⠃⠀⠀⠀⠀⠀⠀⠱⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" 
};

void picture_output(int size) {
	for (int i = 0; i < size; i++) {
		std::wcout << picture[i] << '\n';
	}
}

void number_output(int num) {
	for (int i = 0; i < 5; i++) {
		std::wcout << number[num][i] << '\n';
	}
}

void clock_output(int hours, int minutes, int seconds) {
	int h1 = hours / 10, h2 = hours % 10, m1 = minutes / 10, m2 = minutes % 10,
		s1 = seconds / 10, s2 = seconds % 10;
	for (int i = 0; i < 5; i++) {
		std::wcout << number[h1][i] << "   " << number[h2][i] << "   " << colon[i] << "   "
			<< number[m1][i] << "   " << number[m2][i] << "   " << colon[i] << "   "
			<< number[s1][i] << "   " << number[s2][i] << "\n";
	}
}

int main() {
	//std::locale::global(std::locale(""));
	//setlocale(LC_ALL, "Russian");
	//system("chcp 65001"); 
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	time_t deltaClock;
	while (true) {
		std::time_t clock = std::time(NULL);
		std::tm* localTime = std::localtime(&clock);
		int hours = localTime->tm_hour;
		int mins = localTime->tm_min;
		int seconds = localTime->tm_sec;
		clock_output(hours, mins, seconds);
		picture_output(picture.size());
		deltaClock = std::time(NULL);
		while (deltaClock - clock < 1) {
			deltaClock = std::time(NULL);
		}
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
	}
}