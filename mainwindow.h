/**
 * @file mainwindow.h
 * @brief Заголовочный файл класса MainWindow.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qpushbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса MainWindow.
   * 
   * @param parent Указатель на родительский объект.
   */
  MainWindow(QWidget* parent = nullptr);

  /**
   * @brief Деструктор класса MainWindow.
   */
  ~MainWindow();

  /**
   * @brief Метод для установки начальных параметров игры.
   * 
   * @param size Размер игрового поля.
   * @param _firstPlayerName Имя первого игрока.
   * @param _secondPlayerName Имя второго игрока.
   */
  void setup(int size, QString _firstPlayerName, QString _secondPlayerName);

  /**
   * @brief Метод вызывается при клике на ячейку игрового поля.
   * 
   * @param button Указатель на кнопку, на которую был произведен клик.
   */
  void clicked(QPushButton* button);

  /**
   * @brief Метод для проверки наличия победителя.
   * 
   * @param player Флаг текущего игрока.
   * @return true, если есть победитель, иначе - false.
   */
  bool check(bool player);

  /**
   * @brief Метод для отображения окна с результатом игры.
   * 
   * @param player Флаг текущего игрока.
   * @param draw Флаг ничьей.
   */
  void displayWin(bool player, bool draw = false);

 private:
  bool currentPlayer = false;  // Флаг текущего игрока.
  int fieldSize;               // Размер игрового поля.
  QString firstPlayerName;     // Имя первого игрока.
  QString secondPlayerName;    // Имя второго игрока.
  Ui::MainWindow* ui;          // Указатель на интерфейс.

 private slots:
  /**
   * @brief Слот для перезапуска игры.
   */
  void restart();
};

#endif  // MAINWINDOW_H
