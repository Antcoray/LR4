#include <iostream>

void intro() {
  std::cout << "Задание 1. Выполнил Колесников Антон Сергеевич" << '\n';
  std::cout
      << "Определить количество инверсий в массиве (таких пар элементов, в"
         "которых большее значение находится слева от меньшего)."
      << '\n';
  std::cout << "*Введите  n = 0 чтобы выйти*" << '\n';
}

int correctInputk() {
  std::cout << "Введите число k --- число элементов массива" << '\n';
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число k" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

double correctInputx(int index) {
  std::cout << "Введите " << index + 1 << "-й элемент массива" << '\n';
  double x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число k" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int main() {
  while (true) {
    int k = correctInputk();
    std::cout << "k = " << k << '\n';
    int array[k];
    for (int i = 0; i < k; i++) {
      double x = correctInputx(i);
      array[i] = x;
    }
  }
  return 0;
}