/**
 * @file dialog.cpp
 * @brief Файл реализации класса Dialog.
 */

#include "dialog.h"
#include "ui_dialog.h"

/**
 * @brief Конструктор класса Dialog.
 * 
 * @param parent Указатель на родительский объект.
 */
Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

/**
 * @brief Метод для получения имени первого игрока.
 * 
 * @return Имя первого игрока.
 */
QString Dialog::getFirstPlayer() {
  QString text = ui->first_player->text();
  return text;
}

/**
 * @brief Метод для получения имени второго игрока.
 * 
 * @return Имя второго игрока.
 */
QString Dialog::getSecondPlayer() {
  QString text = ui->second_player->text();
  return text;
}

/**
 * @brief Метод для получения размера поля.
 * 
 * @return Размер поля.
 */
int Dialog::getFieldSize() {
  return ui->field_size->value();
}

/**
 * @brief Метод для изменения размера поля напрямую в UI. Используется в тестах.
 * 
 * @param field_size Размер поля.
 */
void Dialog::setFieldSize(int field_size) {
  ui->field_size->setValue(field_size);
}

/**
 * @brief Метод для изменения имени первого игрока напрямую в UI. Используется в тестах.
 * 
 * @param first_player Имя первого игрока.
 */
void Dialog::setFirstPlayer(QString first_player) {
  ui->first_player->setText(first_player);
}

/**
 * @brief Метод для изменения имени второго игрока напрямую в UI. Используется в тестах.
 * 
 * @param second_player Имя второго игрока.
 */
void Dialog::setSecondPlayer(QString second_player) {
  ui->second_player->setText(second_player);
}

/**
 * @brief Деструктор класса Dialog.
 */
Dialog::~Dialog() {
  delete ui;
}
