#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fcntl.h>
#include <io.h>
#include <chrono>
#include <thread>

#include "images.h"

void picture_output(int size, std::wstring space, const std::vector<std::wstring> &picture) {
	for (int i = 0; i < size; i++) {
		std::wcout << space << picture[i] << '\n';
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
	std::wcout << "\n\n\n";
}

std::wstring spacer(const std::vector<std::wstring> &picture) {
	int space_size = (zero[0].size() * 6 + colon[0].size() + 21) / 2 - picture[0].size() / 2;
	std::wstring space{};
	for (int i = 0; i < space_size; i++) {
		space += ' ';
	}
	return space;
}

int main() {
	srand(time(0));
	_setmode(_fileno(stdout), _O_U16TEXT); //для вывода unicode символов

	std::vector<std::wstring> picture = pictureCollection[rand() % 4];
	std::wstring space = spacer(picture);
	
	time_t deltaClock;
	while (true) {
		std::time_t clock = std::time(NULL);
		std::tm* localTime = std::localtime(&clock);
		int hours = localTime->tm_hour;
		int mins = localTime->tm_min;
		int seconds = localTime->tm_sec;
		clock_output(hours, mins, seconds);
		picture_output(picture.size(), space, picture);
		deltaClock = std::time(NULL);

		std::this_thread::sleep_for(std::chrono::seconds(1));
		system("cls");
	}
}