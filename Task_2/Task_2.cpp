#include <iostream>

void intro() {
  std::cout << "Задание 2. Выполнил Колесников Антон Сергеевич. Вариант 12"
            << '\n';
  std::cout
      << "Эта программа находит в каждом столбце матрицы минимальный элемент"
      << '\n';
  std::cout << "*Введите  M = 0 или N = 0 чтобы выйти*" << '\n';
}

int correctInputMN() {
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

double correctInputx(int indexM, int indexN) {
  std::cout << "Введите " << indexN + 1 << "-й элемент " << indexM + 1
            << "-й строки" << '\n';
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

void FindMinimumInColumns(double* a, int LastIndexM, int LastIndexN) {
  for (int j = 0; j <= LastIndexN; ++j) {
    double min = 0;
    int i = 0;
    min = *(a + (i * (LastIndexN + 1) + j));
    for (; i <= LastIndexM; ++i) {
 
      double num = *(a + (i * (LastIndexN + 1) + j));
      if (num <= min) {
        min = num;
      }
    }
    std::cout << "Минимальное значение в " << j + 1 << "-м"
              << " столбце матрицы"
              << " равно " << min << '\n';
  }
}

void OutputInput(double* a, int LastIndexM, int LastIndexN) {
  std::cout << "Ваша матрица выглядит так: " << '\n';
  for (int i = 0; i <= LastIndexM; ++i) {
    for (int j = 0; j <= LastIndexN; ++j) {
      std::cout << '[' << *(a + (i * (LastIndexN + 1) + j)) << "] ";
    }
    std::cout << '\n';
  }
}

int main() {
  intro();
  while (true) {
    std::cout << "Введите число M --- число строк матрицы" << '\n';
    int M = correctInputMN();
    if (M == 0) {
      break;
    }
    std::cout << "Введите число N --- число столбцов матрицы" << '\n';
    int N = correctInputMN();
    if (N == 0) {
      break;
    }
    double array[M][N];
    for (int i = 0; i <= M - 1; ++i) {
      for (int k = 0; k <= N - 1; ++k) {
        array[i][k] = correctInputx(i, k);
        //
      }
    }
    OutputInput(&array[0][0], M - 1, N - 1);
    FindMinimumInColumns(&array[0][0], M - 1, N - 1);
  }
  return 0;
}