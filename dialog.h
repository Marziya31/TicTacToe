/**
 * @file dialog.h
 * @brief Заголовочный файл класса Dialog.
 */

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

/**
 * @brief Класс диалогового окна.
 * 
 * Этот класс представляет собой диалоговое окно, которое используется
 * для получения информации от пользователя о размере поля и именах
 * игроков.
 */
class Dialog : public QDialog {
  Q_OBJECT

 public:
  /**
   * @brief Конструктор класса Dialog.
   * 
   * @param parent Указатель на родительский объект.
   */
  explicit Dialog(QWidget* parent = nullptr);

  /**
   * @brief Деструктор класса Dialog.
   */
  ~Dialog();

  /**
   * @brief Метод для получения имени первого игрока.
   * 
   * @return Имя первого игрока.
   */
  QString getFirstPlayer();

  /**
   * @brief Метод для получения имени второго игрока.
   * 
   * @return Имя второго игрока.
   */
  QString getSecondPlayer();

  /**
   * @brief Метод для получения размера поля.
   * 
   * @return Размер поля.
   */
  int getFieldSize();

  /**
   * @brief Метод для изменения размера поля напрямую в UI. Используется в тестах.
   * 
   * @param field_size Размер поля.
   */
  void setFieldSize(int field_size);
  /**
   * @brief Метод для изменения имени первого игрока напрямую в UI. Используется в тестах.
   * 
   * @param first_player Имя первого игрока.
   */
  void setFirstPlayer(QString first_player);
  /**
   * @brief Метод для изменения имени второго игрока напрямую в UI. Используется в тестах.
   * 
   * @param second_player Имя второго игрока.
   */
  void setSecondPlayer(QString second_player);

 private:
  Ui::Dialog* ui; /**< Указатель на объект интерфейса пользователя. */
};

#endif  // DIALOG_H
