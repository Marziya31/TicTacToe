/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *welcome_label;
    QHBoxLayout *layout_field_size;
    QLabel *label_field_size;
    QSpinBox *field_size;
    QSlider *slider_field_size;
    QHBoxLayout *layout_first_player;
    QLabel *label_first_player;
    QLineEdit *first_player;
    QHBoxLayout *layout_second_player;
    QLabel *label_second_player;
    QLineEdit *second_player;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName("verticalLayout");
        welcome_label = new QLabel(Dialog);
        welcome_label->setObjectName("welcome_label");
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        welcome_label->setFont(font);
        welcome_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(welcome_label);

        layout_field_size = new QHBoxLayout();
        layout_field_size->setObjectName("layout_field_size");
        label_field_size = new QLabel(Dialog);
        label_field_size->setObjectName("label_field_size");

        layout_field_size->addWidget(label_field_size);

        field_size = new QSpinBox(Dialog);
        field_size->setObjectName("field_size");
        field_size->setMinimum(3);
        field_size->setMaximum(10);

        layout_field_size->addWidget(field_size);

        slider_field_size = new QSlider(Dialog);
        slider_field_size->setObjectName("slider_field_size");
        slider_field_size->setMinimum(3);
        slider_field_size->setMaximum(10);
        slider_field_size->setOrientation(Qt::Horizontal);

        layout_field_size->addWidget(slider_field_size);


        verticalLayout->addLayout(layout_field_size);

        layout_first_player = new QHBoxLayout();
        layout_first_player->setObjectName("layout_first_player");
        label_first_player = new QLabel(Dialog);
        label_first_player->setObjectName("label_first_player");

        layout_first_player->addWidget(label_first_player);

        first_player = new QLineEdit(Dialog);
        first_player->setObjectName("first_player");

        layout_first_player->addWidget(first_player);


        verticalLayout->addLayout(layout_first_player);

        layout_second_player = new QHBoxLayout();
        layout_second_player->setObjectName("layout_second_player");
        label_second_player = new QLabel(Dialog);
        label_second_player->setObjectName("label_second_player");

        layout_second_player->addWidget(label_second_player);

        second_player = new QLineEdit(Dialog);
        second_player->setObjectName("second_player");

        layout_second_player->addWidget(second_player);


        verticalLayout->addLayout(layout_second_player);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));
        QObject::connect(field_size, &QSpinBox::valueChanged, slider_field_size, &QSlider::setValue);
        QObject::connect(slider_field_size, &QSlider::valueChanged, field_size, &QSpinBox::setValue);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        welcome_label->setText(QCoreApplication::translate("Dialog", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214 \320\262 \320\270\320\263\321\200\321\203 \320\272\321\200\320\265\321\201\321\202\320\270\320\272\320\270 \320\275\320\276\320\273\320\270\320\272\320\270 \320\275\320\260 Qt!", nullptr));
        label_field_size->setText(QCoreApplication::translate("Dialog", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\277\320\276\320\273\321\217", nullptr));
        label_first_player->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217 \320\277\320\265\321\200\320\262\320\276\320\263\320\276 \320\270\320\263\321\200\320\276\320\272\320\260", nullptr));
        label_second_player->setText(QCoreApplication::translate("Dialog", "\320\230\320\274\321\217 \320\262\321\202\320\276\321\200\320\276\320\263\320\276 \320\270\320\263\321\200\320\276\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
