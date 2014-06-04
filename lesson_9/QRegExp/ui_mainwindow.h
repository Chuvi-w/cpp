/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadAction;
    QAction *saveAction;
    QAction *clearAction;
    QWidget *centralWidget;
    QLineEdit *regExpEdit;
    QLabel *label;
    QPlainTextEdit *sourceText;
    QPlainTextEdit *resultText;
    QCheckBox *maxLenSearchBox;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 406);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        loadAction = new QAction(MainWindow);
        loadAction->setObjectName(QStringLiteral("loadAction"));
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QStringLiteral("saveAction"));
        clearAction = new QAction(MainWindow);
        clearAction->setObjectName(QStringLiteral("clearAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        regExpEdit = new QLineEdit(centralWidget);
        regExpEdit->setObjectName(QStringLiteral("regExpEdit"));
        regExpEdit->setGeometry(QRect(170, 20, 321, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Verdana"));
        font1.setPointSize(12);
        regExpEdit->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 141, 16));
        sourceText = new QPlainTextEdit(centralWidget);
        sourceText->setObjectName(QStringLiteral("sourceText"));
        sourceText->setGeometry(QRect(10, 60, 481, 81));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sourceText->sizePolicy().hasHeightForWidth());
        sourceText->setSizePolicy(sizePolicy);
        sourceText->setSizeIncrement(QSize(1, 1));
        sourceText->setFont(font1);
        sourceText->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        resultText = new QPlainTextEdit(centralWidget);
        resultText->setObjectName(QStringLiteral("resultText"));
        resultText->setGeometry(QRect(10, 150, 481, 161));
        resultText->setFont(font1);
        maxLenSearchBox = new QCheckBox(centralWidget);
        maxLenSearchBox->setObjectName(QStringLiteral("maxLenSearchBox"));
        maxLenSearchBox->setGeometry(QRect(30, 330, 221, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 505, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(loadAction);
        menu->addAction(saveAction);
        menu->addAction(clearAction);

        retranslateUi(MainWindow);
        QObject::connect(sourceText, SIGNAL(textChanged()), MainWindow, SLOT(applyRegExp()));
        QObject::connect(regExpEdit, SIGNAL(textChanged(QString)), MainWindow, SLOT(applyRegExp()));
        QObject::connect(maxLenSearchBox, SIGNAL(stateChanged(int)), MainWindow, SLOT(applyRegExp()));
        QObject::connect(clearAction, SIGNAL(triggered()), sourceText, SLOT(clear()));
        QObject::connect(saveAction, SIGNAL(triggered()), MainWindow, SLOT(saveText()));
        QObject::connect(loadAction, SIGNAL(triggered()), MainWindow, SLOT(loadText()));
        QObject::connect(sourceText, SIGNAL(textChanged()), MainWindow, SLOT(myNewSlot()));
        QObject::connect(sourceText, SIGNAL(textChanged()), MainWindow, SLOT(myNewSlot()));
        QObject::connect(resultText, SIGNAL(textChanged()), MainWindow, SLOT(myNewSlot()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\200\320\275\321\213\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217: \320\277\320\276\320\270\321\201\320\272 \320\275\320\276\320\274\320\265\321\200\320\276\320\262 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\276\320\262", 0));
        loadAction->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0));
        saveAction->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\262 \321\204\320\260\320\271\320\273", 0));
        clearAction->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \321\202\320\265\320\272\321\201\321\202", 0));
        regExpEdit->setText(QApplication::translate("MainWindow", "(\\d+-\\d+-\\d+)", 0));
        label->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\263\321\203\320\273\321\217\321\200\320\275\320\276\320\265 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265:", 0));
        sourceText->setPlainText(QApplication::translate("MainWindow", "Offsets:   12  sdgsd 14 99 231 7\n"
"213-12-14", 0));
        maxLenSearchBox->setText(QApplication::translate("MainWindow", "\320\226\320\260\320\264\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272 \321\201\321\202\321\200\320\276\320\272", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
