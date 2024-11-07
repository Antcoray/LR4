#include <gtest/gtest.h>

#include <sstream>

#include "Task_1.h"
#define TESTINGinPROGRESS

// Тестирование функции correctInputk
TEST(InputTest, CorrectInputK) {
  std::istringstream input("5\n");
  std::cin.rdbuf(input.rdbuf());  // Перенаправляем ввод
  EXPECT_EQ(correctInputk(), 5);
}

TEST(InputTest, IncorrectInputK) {
  std::istringstream input("abc\n5\n");
  std::cin.rdbuf(input.rdbuf());  // Перенаправляем ввод
  EXPECT_EQ(correctInputk(),
            5);  // Должен игнорировать некорректный ввод и принять 5
}

// Тестирование функции correctInputx
TEST(InputTest, CorrectInputX) {
  std::istringstream input("3.5\n");
  std::cin.rdbuf(input.rdbuf());  // Перенаправляем ввод
  EXPECT_EQ(correctInputx(0), 3.5);
}

TEST(InputTest, IncorrectInputX) {
  std::istringstream input("abc\n3.5\n");
  std::cin.rdbuf(input.rdbuf());  // Перенаправляем ввод
  EXPECT_EQ(correctInputx(0),
            3.5);  // Должен игнорировать некорректный ввод и принять 3.5
}

// Тестирование функции findInversions
TEST(InversionTest, NoInversions) {
  double array[] = {1, 2, 3, 4, 5};
  EXPECT_EQ(findInversions(array, 4), 0);  // Нет инверсий
}

TEST(InversionTest, SomeInversions) {
  double array[] = {5, 3, 2, 4, 1};
  EXPECT_EQ(findInversions(array, 4), 8);  // 8 инверсий
}

TEST(InversionTest, AllInversions) {
  double array[] = {5, 4, 3, 2, 1};
  EXPECT_EQ(findInversions(array, 4), 10);  // 10 инверсий
}

// Тестирование функции OutputInput
TEST(OutputTest, ArrayOutput) {
  std::ostringstream output;
  std::streambuf* coutbuf = std::cout.rdbuf();
  std::cout.rdbuf(output.rdbuf());  // Перенаправляем вывод

  double array[] = {1, 2, 3};
  OutputInput(array, 2);

  std::cout.rdbuf(coutbuf);  // Восстанавливаем стандартный вывод

  EXPECT_EQ(output.str(), "Ваш массив выглядит так: \n[1] [2] [3] \n");
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}