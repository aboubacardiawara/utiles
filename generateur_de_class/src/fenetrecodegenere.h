#ifndef FENETRECODEGENERE_H
#define FENETRECODEGENERE_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
class FenetreCodegenere : public QWidget
{
    Q_OBJECT


public:
    explicit FenetreCodegenere();
    QTextEdit *getTextEdit();
    void receive(QString);
private:
    QVBoxLayout *main_layout;
    void addButton();
    void addZoneText();
    QTextEdit *m_textEditor;
};

#endif // FENETRECODEGENERE_H
