/********************************************************************************
** Form generated from reading UI file 'Dlg_Scanner.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_SCANNER_H
#define UI_DLG_SCANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dlg_Scanner
{
public:
    QPushButton *btn_Connect;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_LineDisplay;

    void setupUi(QWidget *Dlg_Scanner)
    {
        if (Dlg_Scanner->objectName().isEmpty())
            Dlg_Scanner->setObjectName(QString::fromUtf8("Dlg_Scanner"));
        Dlg_Scanner->resize(897, 614);
        btn_Connect = new QPushButton(Dlg_Scanner);
        btn_Connect->setObjectName(QString::fromUtf8("btn_Connect"));
        btn_Connect->setGeometry(QRect(740, 20, 93, 28));
     
		verticalLayoutWidget = new QWidget(Dlg_Scanner);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 701, 491));
       
		verticalLayout_LineDisplay = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_LineDisplay->setSpacing(6);
        verticalLayout_LineDisplay->setContentsMargins(11, 11, 11, 11);
        verticalLayout_LineDisplay->setObjectName(QString::fromUtf8("verticalLayout_LineDisplay"));
        verticalLayout_LineDisplay->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Dlg_Scanner);

        QMetaObject::connectSlotsByName(Dlg_Scanner);
    } // setupUi

    void retranslateUi(QWidget *Dlg_Scanner)
    {
        Dlg_Scanner->setWindowTitle(QApplication::translate("Dlg_Scanner", "Dlg_Scanner", nullptr));
        btn_Connect->setText(QApplication::translate("Dlg_Scanner", "\350\277\236\346\216\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dlg_Scanner: public Ui_Dlg_Scanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_SCANNER_H
