#include <iostream>

void intro() {
  std::cout << "Задание 3. Выполнил Колесников Антон Сергеевич. Вариант 12"
            << '\n';
  std::cout
      << "Эта програамма получает из исходной квадратной матрицы порядка N "
         "целочисленную квадратную матрицу, в которой элемент равен 1,\nесли "
         "соответствующий ему элемент исходной матрицы больше элемента, "
         "расположенного на главной диагонали, и равен 0 в противном случае."
      << '\n';
  std::cout << "*Введите N = 0 чтобы выйти*" << '\n';
}

int correctInputN() {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите порядок квадратной матрицы"
                << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (x < 0) {
      std::cout << "Некорректный ввод. Введите порядок квадратной матрицы"
                << std::endl;
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
      std::cout << "Некорректный ввод. Введите целое число " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

void BuildNewMatrix(double** array, int LastIndexM, int LastIndexN) {
  std::cout << "Новая матрица выглядит так:\n";
  for (int i = 0; i <= LastIndexM; ++i) {
    for (int j = 0; j <= LastIndexN; ++j) {
      if (array[i][j] > array[i][i]) {
        std::cout << '[' << 1 << "] ";
      } else {
        std::cout << '[' << 0 << "] ";
      }
    }
    std::cout << '\n';
  }
}

void OutputInput(double** array, int LastIndexM, int LastIndexN) {
  std::cout << "Исходная матрица выглядит так: " << '\n';
  for (int i = 0; i <= LastIndexM; ++i) {
    for (int j = 0; j <= LastIndexN; ++j) {
      if (i != j) {
        std::cout << '[' << array[i][j] << "] ";
      } else {
        std::cout << '(' << array[i][j] << ") ";
      }
    }
    std::cout << '\n';
  }
  std::cout << "элементы главной диагонали обозначены как (x)" << '\n';
}

int main() {
  intro();
  while (true) {
    std::cout << "Введите число N --- порядок квадратной матрицы" << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    double** array = new double*[N];
    for (int i = 0; i < N; ++i) {
      array[i] = new double[N];
    }
    for (int i = 0; i <= N - 1; ++i) {
      for (int k = 0; k <= N - 1; ++k) {
        array[i][k] = correctInputx(i, k);
        //
      }
    }
    OutputInput(array, N - 1, N - 1);
    BuildNewMatrix(array, N - 1, N - 1);

    for (int i = 0; i < N; ++i) {
      delete[] array[i];
    }
    delete[] array;
  }
  return 0;
}