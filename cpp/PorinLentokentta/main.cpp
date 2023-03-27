#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct WeatherData {
    int year;
    int month;
    int day;
    double airTemperature;
    double highestTemperature;
    double lowestTemperature;
};

int main() {
    ifstream file("D:\\Porilentokentta.csv");
    if (!file.is_open()) {
        cerr << "Failed to open file\n";
        return 1;
    }
    vector<WeatherData> data;
    string line;
    while (getline(file, line)) {
        WeatherData wd;
        if (sscanf(line.c_str(), "%d %d %d %lf %lf %lf", &wd.year, &wd.month, &wd.day, &wd.airTemperature, &wd.highestTemperature, &wd.lowestTemperature) == 6) {
            data.push_back(wd);
        }
    }
    file.close();
    double highestTemperature = numeric_limits<double>::lowest();
    double lowestTemperature = numeric_limits<double>::max();
    WeatherData highestTemperatureData;
    WeatherData lowestTemperatureData;
    for (const WeatherData& wd : data) {
        if (wd.highestTemperature > highestTemperature) {
            highestTemperature = wd.highestTemperature;
            highestTemperatureData = wd;
        }
        if (wd.lowestTemperature < lowestTemperature) {
            lowestTemperature = wd.lowestTemperature;
            lowestTemperatureData = wd;
        }
    }
    cout << "Korkein lampotila: " << highestTemperature << " paivana " << highestTemperatureData.year << '-' << highestTemperatureData.month << '-' << highestTemperatureData.day << '\n';
    cout << "Alin lampotila: " << lowestTemperature << " paivana " << lowestTemperatureData.year << '-' << lowestTemperatureData.month << '-' << lowestTemperatureData.day << '\n';
}
