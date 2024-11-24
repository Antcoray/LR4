#include <gtest/gtest.h>

#include <iostream>

#include "Task_2.h"

TEST(mainTest, ProgramFinishedSuccessfully) { ASSERT_EQ(main2(), 0); }
TEST(FindMinimumInColumnsTests, Test_1) {
  const int M = 5, N = 4;
  int Aarray[M][N] = {{1, 2, 3, 4},
                      {6, 7, 8, 9},
                      {10, 11, -9, 13},
                      {15, 16, 17, 18},
                      {-20, 21, 22, 23}};
  ASSERT_EQ(FindMinimumInColumns(&Aarray[0][0], M - 1, N - 1), 4);
}

TEST(FindMinimumInColumnsTests, Test_2) {
  const int M = 5, N = 4;
  int Aarray[M][N] = {{1, 2, 3, -4},
                      {6, 7, 8, 9},
                      {10, 11, -9, 13},
                      {15, 16, 17, 18},
                      {-20, 21, 22, 23}};
  ASSERT_EQ(FindMinimumInColumns(&Aarray[0][0], M - 1, N - 1), -4);
}
TEST(FindMinimumInColumnsTests, Test_3) {
  const int M = 5, N = 4;
  int Aarray[M][N] = {{1, 2, 3, 100},
                      {6, 7, 8, -9},
                      {10, 11, -9, 13},
                      {15, 16, 17, 18},
                      {-20, 21, 22, 23}};
  ASSERT_EQ(FindMinimumInColumns(&Aarray[0][0], M - 1, N - 1), -9);
}
TEST(FindMinimumInColumnsTests, Test_4) {
  const int M = 5, N = 4;
  int Aarray[M][N] = {{1, 1, 3, 100},
                      {6, 1, -100, -9},
                      {10, 1, -9, 13},
                      {15, 16, 17, -18},
                      {-20, 21, 22, 23}};
  ASSERT_EQ(FindMinimumInColumns(&Aarray[0][0], M - 1, N - 1), -18);
}

TEST(FindMinimumInColumnsTests, Test_5) {
  const int M = 5, N = 4;
  int Aarray[M][N] = {{1, 1, 3, 100},
                      {6, 1, -100, -9},
                      {10, 1, -9, -13},
                      {15, 16, 17, -18},
                      {-20, 21, 22, 23}};
  ASSERT_EQ(FindMinimumInColumns(&Aarray[0][0], M - 1, N - 1), -18);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}

void intro() {
  std::cout << "Задание 2. Выполнил Колесников Антон Сергеевич. Вариант 12"
            << '\n';
  std::cout
      << "Эта программа находит в каждом столбце матрицы минимальный элемент"
      << '\n';
  //  std::cout << "*Введите  M = 0 или N = 0 чтобы выйти*" << '\n';
}

int correctInputMN() {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    /*if (x < 0 ) {
      std::cout << "Некорректный ввод. Введите число" << std::endl;
      incorrectInput = true;
    }*/
    if (x != 0 && x != 1) {
      std::cout << "Некорректный ввод. Введите число" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}
/*
int correctInputx(int indexM, int indexN) {
  std::cout << "Введите " << indexN + 1 << "-й элемент " << indexM + 1
            << "-й строки" << '\n';
  double x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}
*/
double FindMinimumInColumns(int* a, int LastIndexM, int LastIndexN) {
  double min = 0;
  for (int j = 0; j <= LastIndexN; ++j) {
    min = 0;
    int i = 0;
    min = *(a + (i * (LastIndexN + 1) + j));
    for (; i <= LastIndexM; ++i) {
      double num = *(a + (i * (LastIndexN + 1) + j));
      if (num <= min) {
        min = num;
      }
    }
    /*std::cout << "Минимальное значение в " << j + 1 << "-м"
              << " столбце матрицы"
              << " равно " << min << '\n';*/
  }
  return min;
}

void OutputInput(int* a, int LastIndexM, int LastIndexN) {
  std::cout << "Ваша матрица выглядит так: " << '\n';
  for (int i = 0; i <= LastIndexM; ++i) {
    for (int j = 0; j <= LastIndexN; ++j) {
      std::cout << '[' << *(a + (i * (LastIndexN + 1) + j)) << "] ";
    }
    std::cout << '\n';
  }
}

int main2() {
  // intro();
  // while (true) {
  /*std::cout <<  "Введите число M --- число строк матрицы" <<
      "Введите число 1, чтобы найти минимальный элемент в каждом столбце "
      "матрицы, или 0, чтобы выйти"
            << '\n';*/
  // int /*M*/ x = correctInputMN();
  // if (/*M*/ x == 0) {
  //  break;
  //}
  /*
  std::cout << "Введите число N --- число столбцов матрицы" << '\n';
  int N = correctInputMN();
  if (N == 0) {
    break;
  }*/
  const int M = 5, N = 4;
  int array[M][N] = {{1, 2, 3, 4},
                     {6, 7, 8, 9},
                     {10, 11, -9, 13},
                     {15, 16, 17, 18},
                     {-20, 21, 22, 23}};
  /*for (int i = 0; i <= M - 1; ++i) {
    for (int k = 0; k <= N - 1; ++k) {
      array[i][k] = correctInputx(i, k);
    }
  } */
  // OutputInput(&array[0][0], M - 1, N - 1);
  FindMinimumInColumns(&array[0][0], M - 1, N - 1);
  // }
  return 0;
}