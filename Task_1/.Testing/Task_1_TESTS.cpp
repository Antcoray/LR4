#include <gtest/gtest.h>
#include <iostream>
#include "Task_1.h"

TEST(InversionTest, AllInversions) {
  double array[] = {5, 4, 3, 2, 1};
  ASSERT_EQ(findInversions(array, 4), 10);
}

TEST(InversionTest, ReverseInversions) {
  double array[] = {1, 2, 3, 4, 5};
  ASSERT_EQ(findInversions(array, 4), 0);
}

TEST(InversionTest, SymmetricalNumInversions) {
  double array[] = {1, 2, 3, 2, 1};
  ASSERT_EQ(findInversions(array, 4), 4);
}

TEST(InversionTest, NotIntInversions) {
  double array[] = {5.5, 4.4, 3.3, 2.2, 1.1};
  ASSERT_EQ(findInversions(array, 4), 10);
}

TEST(InversionTest, ArrayOfOneNumber) {
  double array[] = {5.99};
  ASSERT_EQ(findInversions(array, 0), 0);
}

TEST(InversionTest, ArrayOfSimilarNumbers) {
  double array[] = {5.99, 5.99, 5.99, 5.99, 5.99};
  ASSERT_EQ(findInversions(array, 4), 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

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