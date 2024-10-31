#include <iostream>

void intro() {
  std::cout << "=== Задание 8. Выполнил Колесников Антон Сергеевич ==="
            << std::endl;
  std::cout << "Эта программа считает выражение a0 - 2 * a1 + 4 * a2 - 8 * a3 "
               "+ ... + 2^(n-1) * (-1)^(n-1) * an-1 без использования "
               "вещественной арифметики"
            << std::endl;
  std::cout << "*Введите  n = 0 чтобы выйти*\n" << std::endl;
}

int main () {
    while(true) {
    double x = 0;
    bool incorrectInput = false;
    do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число n" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    } while(incorrectInput);
    std::cout << "CORRECT!!!" << '\n';
    }
    return 0;
}