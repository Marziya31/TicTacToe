#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#include <QApplication>
#include "dialog.h"

TEST_CASE("Test Dialog class methods") {
  // Создаем объект класса Dialog
  int argc = 1;
  char* argv[] = {};
  QApplication app(argc, argv);

  Dialog dialog(nullptr);

  SUBCASE("Тест функции getFirstPlayer") {
    // Устанавливаем имя первого игрока в поле ввода
    dialog.setFirstPlayer("Игрок номер 1");
    // Проверяем, что метод getFirstPlayer возвращает правильное имя
    REQUIRE(dialog.getFirstPlayer() == "Игрок номер 1");
  }

  SUBCASE("Тест функции getSecondPlayer") {
    // Устанавливаем имя второго игрока в поле ввода
    dialog.setSecondPlayer("Игрок номер 2");
    // Проверяем, что метод getSecondPlayer возвращает правильное имя
    REQUIRE(dialog.getSecondPlayer() == "Игрок номер 2");
  }

  SUBCASE("Test getFieldSize method") {
    // Устанавливаем размер поля в 10
    dialog.setFieldSize(10);

    // Проверяем, что метод getFieldSize возвращает правильный размер
    REQUIRE(dialog.getFieldSize() == 10);
  }
}
