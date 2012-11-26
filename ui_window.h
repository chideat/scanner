/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Wed Sep 19 16:34:57 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *host;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *start;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QSpinBox *end;
    QSpacerItem *horizontalSpacer;
    QPushButton *scan;
    QTextEdit *result;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(399, 464);
        Window->setMinimumSize(QSize(0, 464));
        verticalLayoutWidget = new QWidget(Window);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        host = new QLineEdit(verticalLayoutWidget);
        host->setObjectName(QString::fromUtf8("host"));

        horizontalLayout->addWidget(host);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        start = new QSpinBox(verticalLayoutWidget);
        start->setObjectName(QString::fromUtf8("start"));
        start->setMinimum(1);
        start->setMaximum(65535);

        horizontalLayout_2->addWidget(start);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        end = new QSpinBox(verticalLayoutWidget);
        end->setObjectName(QString::fromUtf8("end"));
        end->setMinimum(1);
        end->setMaximum(65535);
        end->setSingleStep(1);

        horizontalLayout_2->addWidget(end);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        scan = new QPushButton(verticalLayoutWidget);
        scan->setObjectName(QString::fromUtf8("scan"));
        scan->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scan->sizePolicy().hasHeightForWidth());
        scan->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(scan);


        verticalLayout->addLayout(horizontalLayout_2);

        result = new QTextEdit(verticalLayoutWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setUndoRedoEnabled(false);
        result->setLineWrapMode(QTextEdit::WidgetWidth);
        result->setReadOnly(true);
        result->setAcceptRichText(false);
        result->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(result);

        Window->setCentralWidget(verticalLayoutWidget);
        statusBar = new QStatusBar(Window);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Window->setStatusBar(statusBar);

        retranslateUi(Window);

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Window", "Target:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Window", "Port Start", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Window", "Port End", 0, QApplication::UnicodeUTF8));
        scan->setText(QApplication::translate("Window", "Scan", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
