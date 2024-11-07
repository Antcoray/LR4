#include <iostream>

void intro() {
  std::cout << "Задание 1. Выполнил Колесников Антон Сергеевич. Вариант 12"
            << '\n';
  std::cout << "Эта программа определяет количество инверсий в массиве (таких "
               "пар элементов, в "
               "которых большее значение находится слева от меньшего)."
            << '\n';
  std::cout << "*Введите  k = 0 чтобы выйти*" << '\n';
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
      std::cout << "Некорректный ввод. Введите элемент массива" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int findInversions(double array[], int LastIndex) {
  int inversions = 0;
  for (int i = 0; i <= LastIndex; ++i) {
    for (int m = i + 1; m <= LastIndex; ++m) {
      if (array[i] > array[m]) {
        ++inversions;
      }
    }
  }
  return inversions;
}

void OutputInput(double array[], int LastIndex) {
  std::cout << "Ваш массив выглядит так: " << '\n';
  for (int i = 0; i <= LastIndex; ++i) {
    std::cout << '[' << array[i] << ']' << ' ';
  }
  std::cout << '\n';
}
int main() {
  intro();
  while (true) {
    int k = correctInputk();
    if (k == 0) {
      break;
    }
    double array[k];
    for (int i = 0; i < k; ++i) {
      double x = correctInputx(i);
      array[i] = x;
    }
    OutputInput(array, k - 1);
    std::cout << "Количество инверсий = " << findInversions(array, k - 1)
              << std::endl;
  }
  return 0;
}