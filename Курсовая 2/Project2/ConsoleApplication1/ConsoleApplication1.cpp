#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "AirVehicle.h"
#include "Broomstick.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "FastCamel.h"
#include "GroundVehicle.h"
#include "MagicCarpet.h"
#include "OffroadBoots.h"
#include "Vehicle.h"

using namespace std;

bool sortByTime(const pair<string, double>& a, const pair<string, double>& b) {
    return a.second < b.second;
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    while (true) {
        vector<Vehicle*> vehicles;

        cout << "Добро пожаловать в гоночный симулятор!" << endl;
        cout << "1. Наземная гонка" << endl;
        cout << "2. Воздушная гонка" << endl;
        cout << "3. Наземно-воздушная гонка" << endl;
        cout << "4. Выйти из игры" << endl;
        cout << "Выберите тип гонки или введите 4 для выхода: ";

        int raceType;
        cin >> raceType;

        if (raceType == 4) {
            cout << "Спасибо за игру. До новых встреч!" << endl;
            break;
        }
        else if (raceType < 1 || raceType > 4) {
            cout << "Неверный выбор. Пожалуйста, выберите тип гонки от 1 до 4." << endl;
            continue;
        }

        string raceTypeName;
        if (raceType == 1) {
            raceTypeName = "Наземная гонка";
        }
        else if (raceType == 2) {
            raceTypeName = "Воздушная гонка";
        }
        else if (raceType == 3) {
            raceTypeName = "Наземно-воздушная гонка";
        }

        int distance;

        while (true) {
            cout << "Укажите длину дистанции (должна быть положительна): ";
            cin >> distance;
            if (distance <= 0) {
                cout << "Неверный выбор. Дистанция должна быть положительна!" << endl;
                continue;
            }
            break;
        }

        cout << "Должно быть зарегистрировано хотя бы 2 транспортных средства" << endl;

        while (true) {

            while (true) {
                cout << "Тип гонки: " << raceTypeName << endl;
                cout << "Текущая дистанция: " << distance << " км" << endl;
                cout << "Зарегистрированные транспортные средства:" << endl;

                for (const auto& vehicle : vehicles) {
                    cout << vehicle->getName() << endl;
                }
                int action;
                cout << "Выберите действие: " << endl;
                cout << "1. Зарегистрировать транспорт" << endl;
                cout << "2. Начать гонку" << endl;
                cin >> action;
                
                    if (action == 1) {
                        while (true) {
                            string vehiclesMenu[] = { "Верблюд", "Верблюд-быстроход", "Кентавр", "Ботинки-вездеходы", "Ковёр-самолёт", "Орёл", "Метла" };
                            
                            cout << "Зарегистрированные транспортные средства:" << endl;

                            for (const auto& vehicle : vehicles) {
                                cout << vehicle->getName() << endl;
                            }

                            cout << "Список доступных транспортных средств:" << endl;
                            for (int i = 0; i < 7; ++i) {
                                cout << i + 1 << ". " << vehiclesMenu[i] << endl;
                            }
                            cout << "0. Закончить регистрацию" << endl;
                            cout << "Выберите транспорт для регистрации: ";

                            int vehicleChoice;
                            cin >> vehicleChoice;

                            if (vehicleChoice < 0 || vehicleChoice > 7) {
                                cout << "Неверный выбор. Пожалуйста, введите число от 0 до 7." << endl;
                                continue;
                            }

                            if (vehicleChoice == 0) {
                                cout << "Регистрация завершена." << endl;
                                break;
                            }

                            if ((raceType == 1 && (vehicleChoice > 4)) ||
                                (raceType == 2 && (vehicleChoice <= 4))) {
                                cout << "Ошибка: выбранное ТС не соответствует типу гонки." << endl;
                                continue;
                            }

                            bool alreadyRegistered = false;
                            for (const auto& vehicle : vehicles) {
                                if (vehicle->getName() == vehiclesMenu[vehicleChoice - 1]) {
                                    alreadyRegistered = true;
                                    break;
                                }
                            }

                            if (alreadyRegistered) {
                                cout << "Ошибка: Транспорт уже зарегистрирован." << endl;
                                continue;
                            }

                            switch (vehicleChoice) {
                            case 1:
                                vehicles.push_back(new Camel());
                                break;
                            case 2:
                                vehicles.push_back(new FastCamel());
                                break;
                            case 3:
                                vehicles.push_back(new Centaur());
                                break;
                            case 4:
                                vehicles.push_back(new OffroadBoots());
                                break;
                            case 5:
                                vehicles.push_back(new MagicCarpet());
                                break;
                            case 6:
                                vehicles.push_back(new Eagle());
                                break;
                            case 7:
                                vehicles.push_back(new Broomstick());
                                break;
                            default:
                                break;
                            }
                            cout << vehiclesMenu[vehicleChoice - 1] << " успешно зарегистрирован!" << endl;
                        }
                        
                    }

                
            
                else if (action == 2) {
                    if (vehicles.size() < 2) {
                        cout << "Ошибка: Для начала гонки необходимо зарегистрировать как минимум два транспортных средства." << endl;
                        continue;
                    }

                    vector<pair<string, double>> results;

                    for (const auto& vehicle : vehicles) {
                        results.emplace_back(vehicle->getName(), vehicle->calculateTime(distance));
                    }

                    sort(results.begin(), results.end(), sortByTime);

                    cout << "Результаты гонки:" << endl;
                    int position = 1;
                    for (const auto& result : results) {
                        cout << position << ". " << result.first << ", Время: " << result.second << " ч" << endl;
                        position++;
                    }

                    break;
                }

                else {
                    cout << "Ошибка: неверный выбор действия!" << endl;
                }

            }
            break;
        }

        for (const auto& vehicle : vehicles) {
            delete vehicle;
        }
    }

    return 0;
}

