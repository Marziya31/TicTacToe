/**
 * @file mainwindow.cpp
 * @brief Файл реализации класса MainWindow.
 */

#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"

/**
 * @brief Конструктор класса MainWindow, 
 * который инициализирует главное окно приложения и 
 * устанавливает соединение сигнала нажатия кнопки перезапуска
 * со слотом restart()
 * 
 * @param parent указатель на родительский объект
 */
MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // Связываем нажатие кнопки restart с методом restart
  connect(ui->restart, &QPushButton::clicked, this, &MainWindow::restart);
}

/**
 * @brief Метод для установки начальных параметров игры.
 * 
 * @param size Размер игрового поля.
 * @param _firstPlayerName Имя первого игрока.
 * @param _secondPlayerName Имя второго игрока.
 */
void MainWindow::setup(int size, QString _firstPlayerName,
                       QString _secondPlayerName) {
  // Инициализируем размер поля в переменной класса
  fieldSize = size;

  // Проверяем, задано ли имя первого игрока, и если нет, то присваиваем ему значение "Игрок 1"
  if (_firstPlayerName.isEmpty()) {
    _firstPlayerName = QString("Игрок 1");
  }

  // Проверяем, задано ли имя второго игрока, и если нет, то присваиваем ему значение "Игрок 2"
  if (_secondPlayerName.isEmpty()) {
    _secondPlayerName = QString("Игрок 2");
  }

  // Присваиваем значения именам игроков в соответствующие переменные класса
  firstPlayerName = _firstPlayerName;
  secondPlayerName = _secondPlayerName;

  // Устанавливаем текст для метки первого игрока4
  ui->first_player->setText(firstPlayerName);

  // Устанавливаем текст для метки второго игрока
  ui->second_player->setText(_secondPlayerName);

  // Добавляем кнопки в сетку размещения
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      // Создаем кнопку
      QPushButton* button = new QPushButton(QString(""), ui->centralwidget);
      // Устанавливаем соединение между нажатием на кнопку и методом clicked класса MainWindow
      connect(button, &QPushButton::clicked, this,
              [this, button] { clicked(button); });
      // Устанавливаем свойство "cell" кнопки в true
      button->setProperty("cell", true);  

      // Устанавливаем пробел в качестве текста кнопки
      button->setText(" ");

      // Добавляем кнопку в сетку размещения
      ui->gridLayout->addWidget(button, i, j, 1, 1);
    }
  }

  // Обновляем сетку размещения
  ui->gridLayout->update();
}

/**
 * @brief Метод для проверки наличия победителя.
 * 
 * @param player Флаг текущего игрока.
 * @return true, если есть победитель, иначе - false.
 */
bool MainWindow::check(bool player) {

  // Выставляем значение заполненных клеток в 0 для проверки на ничью
  int numFilled = 0;

  // Проверяем все строки на наличие выигрышной комбинации
  for (int i = 0; i < fieldSize; i++) {
    // Получаем символ в первой ячейке строки, вот как это происходит:
    // 1. Эта строка кода получает указатель на виджет типа QPushButton, расположенный в ячейке,
    //    находящейся в строке i и столбце 0, внутри сетки QGridLayout, который хранится в объекте ui.
    //
    // 2. Для этого сначала вызывается метод itemAtPosition() объекта QGridLayout, который принимает два аргумента - номер строки и столбца.
    //    Метод возвращает указатель на объект типа QLayoutItem, который представляет виджет, находящийся в данной ячейке, или nullptr, если ячейка пуста.
    //
    // 3. Затем вызывается метод widget() объекта QLayoutItem, который возвращает указатель на виджет, связанный с данным элементом.
    //
    // 4. Далее, с помощью оператора ->, вызывается метод text() на полученном указателе на QPushButton,
    //    чтобы получить текст, отображаемый на этой кнопке.
    //
    // 5. Полученный текст сохраняется в переменную symbol.
    //
    // 6. Затем вызывается метод replace() на полученной строке текста, чтобы удалить все пробелы из текста кнопки.
    //    Результат сохраняется в той же переменной symbol.

    // В результате выполнения этой строки кода, переменная symbol будет содержать текст, отображаемый на кнопке,
    // находящейся в сетке QGridLayout в строке i и столбце 0, без пробелов.
    QString symbol = dynamic_cast<QPushButton*>(
                         ui->gridLayout->itemAtPosition(i, 0)->widget())
                         ->text()
                         .replace(" ", "");
    bool rowMatch = true;

    // Проверяем все ячейки в строке на равенство символу
    for (int j = 0; j < fieldSize; j++) {
      QString currentSymbol =
          dynamic_cast<QPushButton*>(
              ui->gridLayout->itemAtPosition(i, j)->widget())
              ->text()
              .replace(" ", "");
      if (symbol != currentSymbol) {
        rowMatch = false;
      }
      // Если ячейка не пустая, увеличиваем количество заполненных ячеек
      if (!currentSymbol.isEmpty()) {
        numFilled++;
      }
    }
    // Если вся строка заполнена одинаковыми символами и не является пустой, игрок победил
    if (rowMatch && !symbol.isEmpty()) {
      displayWin(player);
      return true;
    }
  }

  // Проверяем все столбцы на наличие выигрышной комбинации
  for (int i = 0; i < fieldSize; i++) {
    // Получаем символ в первой ячейке столбца
    QString symbol = dynamic_cast<QPushButton*>(
                         ui->gridLayout->itemAtPosition(0, i)->widget())
                         ->text()
                         .replace(" ", "");
    bool columnMatch = true;
    // Проверяем все ячейки в столбце на равенство символу
    for (int j = 0; j < fieldSize; j++) {
      if (symbol != dynamic_cast<QPushButton*>(
                        ui->gridLayout->itemAtPosition(j, i)->widget())
                        ->text()
                        .replace(" ", "")) {
        columnMatch = false;
        break;
      }
    }

    // Если весь столбец заполнен одинаковыми символами и не является пустым, игрок победил
    if (columnMatch && !symbol.isEmpty()) {
      displayWin(player);
      return true;
    }
  }

  // Получаем символ из верхнего левого угла
  QString symbol =
      dynamic_cast<QPushButton*>(ui->gridLayout->itemAtPosition(0, 0)->widget())
          ->text()
          .replace(" ", "");
  // Инициализируем переменную diagonalMatch как true
  bool diagonalMatch = true;

  // Проходим по всем ячейкам на диагонали, начиная со второй, т.к. первый символ уже был получен
  for (int i = 1; i < fieldSize; i++) {
    // Если текущий символ не совпадает с символом в верхнем левом углу
    if (symbol != dynamic_cast<QPushButton*>(
                      ui->gridLayout->itemAtPosition(i, i)->widget())
                      ->text()
                      .replace(" ", "")) {
      // То выигрышной комбинации нет, и выходим из цикла
      diagonalMatch = false;
      break;
    }
  }
  // Если на диагонали есть выигрышная комбинация и символ в ячейке не пустой
  if (diagonalMatch && !symbol.isEmpty()) {
    // Вызываем функцию отображения выигрыша и возвращаем true
    displayWin(player);
    return true;
  }

  // Получаем символ из правого нижнего угла
  symbol = dynamic_cast<QPushButton*>(
               ui->gridLayout->itemAtPosition(fieldSize - 1, 0)->widget())
               ->text()
               .replace(" ", "");

  // Инициализируем переменную diagonalMatch как true
  diagonalMatch = true;

  // Проходим по всем ячейкам на диагонали, начиная с первой, т.к. символ уже был получен
  for (int i = 0; i < fieldSize; i++) {
    // Если текущий символ не совпадает с символом в ячейке диагонали, расположенной выше и левее текущей
    if (symbol !=
        dynamic_cast<QPushButton*>(
            ui->gridLayout->itemAtPosition(fieldSize - 1 - i, i)->widget())
            ->text()
            .replace(" ", "")) {
      // То выигрышной комбинации нет, и выходим из цикла
      diagonalMatch = false;
      break;
    }
  }

  // Если на диагонали есть выигрышная комбинация и символ в ячейке не пустой
  if (diagonalMatch && !symbol.isEmpty()) {
    // Вызываем функцию отображения выигрыша и возвращаем true
    displayWin(player);
    return true;
  }

  // Если все ячейки заполнены
  if (numFilled == fieldSize * fieldSize) {
    // Вызываем функцию отображения ничьи и возвращаем true
    displayWin(player, true);
    return true;
  }

  // Если никакая из проверок не вернула true, значит выигрышной комбинации нет
  return false;
}

/**
 * @brief Метод для отображения окна с результатом игры.
 * 
 * @param player Флаг текущего игрока.
 * @param draw Флаг ничьей.
 */
void MainWindow::displayWin(bool player, bool draw) {
  // Если игра закончилась в ничью
  if (draw) {
    // Текст сообщения для ничьей
    QString text("Игра завершилась в ничью!");
    // Отображение информационного окна с сообщением о ничьей
    QMessageBox::information(this, "Игра окончена!", text);
  }
  // Если победил первый игрок
  else if (!player) {
    // Текст сообщения для победы первого игрока
    QString text("Победил " + firstPlayerName);
    // Отображение информационного окна с сообщением о победе первого игрока
    QMessageBox::information(this, "Игра окончена!", text);
  }
  // Если победил второй игрок
  else {
    // Текст сообщения для победы второго игрока
    QString text("Победил " + secondPlayerName);
    // Отображение информационного окна с сообщением о победе второго игрока
    QMessageBox::information(this, "Игра окончена!", text);
  }
  // Перезапуск игры
  restart();
}

/**
 * @brief Метод для перезапуска игры.
 */
void MainWindow::restart() {
  // Перебираем все элементы внутри сетки
  for (int i = 0; i < ui->gridLayout->count(); ++i) {
    // Получаем элемент с помощью указателя на QPushButton
    QPushButton* button =
        dynamic_cast<QPushButton*>(ui->gridLayout->itemAt(i)->widget());

    // Если элемент является кнопкой
    if (button) {

      // Делаем кнопку доступной для нажатия
      button->setEnabled(true);

      // Удаляем текст на кнопке
      button->setText(" ");

      // Удаляем все стили на кнопке
      button->setStyleSheet("");
    }
  }

  // Обнуляем текущего игрока (Игрок 1 всегда начинает первым)
  currentPlayer = false;

  // Устанавливаем стили для имен игроков (Игрок 1 всегда начинает первым, поэтому он жирным шрифтом)
  ui->first_player->setStyleSheet("font-weight: bold; color: red;");
  ui->second_player->setStyleSheet("color: cyan; font-weight: normal;");
}

/**
 * @brief Метод вызывается при клике на ячейку игрового поля.
 * 
 * @param button Указатель на кнопку, на которую был произведен клик.
 */
void MainWindow::clicked(QPushButton* button) {
  // Если текущий игрок - первый, установить цвет красным и текст "X" на кнопке.
  // В противном случае установить цвет голубым и текст "O" на кнопке.
  if (!currentPlayer) {
    button->setStyleSheet("color: red;");
    button->setText("X");

  } else {
    button->setStyleSheet("color: cyan;");
    button->setText("O");
  }

  // Отключить кнопку после клика.
  button->setDisabled(true);

  // Проверить, закончилась ли игра после хода игрока.
  bool gameEnds = check(currentPlayer);

  // Если игра не закончилась, переключить игрока.
  if (!gameEnds) {
    currentPlayer = !currentPlayer;

    // Если текущий игрок - первый, выделить первого игрока жирным шрифтом, а второго обыным
    // В противном случае, выделить второго игрока жирным шрифтом, а первого обычным
    if (!currentPlayer) {
      ui->first_player->setStyleSheet("font-weight: bold; color: red;");
      ui->second_player->setStyleSheet("color: cyan; font-weight: normal;");
    } else {
      ui->second_player->setStyleSheet("font-weight: bold; color: cyan;");
      ui->first_player->setStyleSheet("color: red; font-weight: normal;");
    }
  }
}

/**
 * @brief Деструктор класса MainWindow.
 */
MainWindow::~MainWindow() {
  // Удаляет интерфейс из памяти
  delete ui;
}
