
#include "dialog.h"
#include "mainwindow.h"

#include <QApplication>

// Определение функции main
int main(int argc, char* argv[]) {

  // Создание экземпляра класса QApplication и передача аргументов командной строки
  QApplication a(argc, argv);

  // Создание диалогового окна
  Dialog d;

  // Если диалоговое окно было закрыто с результатом QDialog::Accepted
  if (d.exec() == QDialog::Accepted) {
    // Создание экземпляра класса MainWindow
    MainWindow w;

    // Получение имени первого игрока из диалогового окна
    QString fp = d.getFirstPlayer();

    // Получение имени второго игрока из диалогового окна
    QString sp = d.getSecondPlayer();

    // Получение размера поля из диалогового окна
    int fsize = d.getFieldSize();

    // Установка параметров MainWindow
    w.setup(fsize, fp, sp);

    // Отображение главного окна
    w.show();

    // Запуск главного цикла обработки событий QApplication
    return a.exec();
  } else {
    // Если диалоговое окно было закрыто с результатом QDialog::Rejected, выход из программы
    return 0;
  }
}