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

void OutputInput(double (*)[], int LastIndexM, int LastIndexN) {
std::cout << "Ваша матрица выглядит так: " << '\n';
  for(int i = 0; i <= LastIndexM; ++i) {
  for (int k = 0; k <= LastIndexN; ++k) {
    std::cout << '[' << array[i][k] << ']' << ' ';
    if(k == LastIndexN) {
        std::cout;
    }
  }
  }
  std::cout << '\n';
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
    OutputInput(array,M - 1, N - 1);
  }
  return 0;
}