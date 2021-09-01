#include <QPushButton>
#include "fenetrecodegenere.h"

FenetreCodegenere::FenetreCodegenere() : QWidget()
{
    resize(500, 500);
    main_layout = new QVBoxLayout(this);
    addZoneText();
    addButton();
}

void FenetreCodegenere::addZoneText()
{
    const int  tabStop = 4;
    QFont font;
    QFontMetrics metrics(font);
    m_textEditor = new QTextEdit;
    m_textEditor->setTabStopDistance(tabStop * metrics.horizontalAdvance(' '));

    main_layout->addWidget(m_textEditor);
}

void FenetreCodegenere::addButton()
{
    QPushButton *button_close = new QPushButton("close");
    main_layout->addWidget(button_close);

    QObject::connect(button_close, SIGNAL(clicked()), this, SLOT(close()));
}

QTextEdit* FenetreCodegenere::getTextEdit()
{
    return m_textEditor;
}

void FenetreCodegenere::receive(QString contain)
{
    m_textEditor->setText(contain);
    m_textEditor->setReadOnly(true);
}
