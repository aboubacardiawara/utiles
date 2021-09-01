#ifndef MAFENETRE_H
#define MAFENETRE_H

#include <QWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <fenetrecodegenere.h>


class MaFenetre : public QWidget
{
    Q_OBJECT

    public slots:
    void showResult();
    public:
    MaFenetre();

    private:
    /*************************
            OPERATIONS
    **************************/
    void createClassDefinitionGroup();
    void createOptionsGroup();
    void createCommentGroup();
    void addButtons();

    /*************************
            PROPRIETES
    **************************/
    /*the main layout (vertical directions, it contains all the following components)*/
    QVBoxLayout *main_layout;
    /*it contains the forms which allow to USER to enter class informations*/
    QVBoxLayout *data_layout;
    /*it contains the buttons to generate class or to exit program*/
    QHBoxLayout *buton_layout;

    /*class name entry*/
    QLineEdit *class_name;
    /*class parent name entry*/
    QLineEdit *class_parent_name;
    /*prevent multiple button*/
    QCheckBox *include_header_buton;
    /*add constructor button*/
    QCheckBox *generate_constructor_buton;
    /*add destructor button*/
    QCheckBox *generate_destructor_buton;
    /*author name button*/
    QLineEdit *author;
    /*creation date entry*/
    QDateTimeEdit *date_widget;
    /*class role entry*/
    QTextEdit *classDescription;

    QGroupBox *comment_group;

    /* */
    FenetreCodegenere *m_generated_code_window;


};

#endif // MAFENETRE_H
