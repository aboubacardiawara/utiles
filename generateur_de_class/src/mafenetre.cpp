#include "mafenetre.h"
#include "fenetrecodegenere.h"
#include <string>
#include <QApplication>
#include <QLineEdit>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QDateEdit>
#include <QDate>
#include <string>
#include <QCalendar>


// NORMAL MEMBERS
MaFenetre::MaFenetre() : QWidget()
{
    //setFixedSize(350, 450);
    m_generated_code_window = new FenetreCodegenere();
    // initialisation
    main_layout = new QVBoxLayout(this);
    data_layout = new QVBoxLayout;
    buton_layout = new QHBoxLayout;


    createClassDefinitionGroup();
    createOptionsGroup();
    createCommentGroup();
    addButtons();
    main_layout->addLayout(buton_layout);
}

void MaFenetre::createClassDefinitionGroup()
{

    QGroupBox *class_definition_group = new QGroupBox("Class definition");
    QFormLayout *class_definition_form = new QFormLayout;
    class_name = new QLineEdit;
    class_parent_name = new QLineEdit;
    class_definition_form->addRow("&name", class_name);
    class_definition_form->addRow("class &parent", class_parent_name);
    data_layout->addLayout(class_definition_form);
    class_definition_group->setLayout(data_layout);
    main_layout->addWidget(class_definition_group);
}

void MaFenetre::createOptionsGroup()
{
    QGroupBox *options_group = new QGroupBox("Options");
    QFormLayout *options_layout = new QFormLayout;

    // radio buttons
    include_header_buton = new QCheckBox("prevent multiple inclusion");
    generate_constructor_buton = new QCheckBox("generate constructor");
    generate_destructor_buton = new QCheckBox("generate destructor");
    options_layout->addRow(include_header_buton);
    options_layout->addRow(generate_constructor_buton);
    options_layout->addRow(generate_destructor_buton);


    options_group->setLayout(options_layout);
    main_layout->addWidget(options_group);

}

void MaFenetre::createCommentGroup()
{

    author = new QLineEdit;
    classDescription = new QTextEdit;
    QDateTimeEdit *date_widget = new QDateEdit(QDate::currentDate());

    comment_group = new QGroupBox("add comment");
    QFormLayout *comments_form = new QFormLayout;

    comments_form->addRow("author", author);
    comments_form->addRow("Creation date", date_widget);
    comments_form->addRow("Class role", classDescription);


    comment_group->setLayout(comments_form);
    comment_group->setCheckable(true);
    main_layout->addWidget(comment_group);
}

void MaFenetre::addButtons()
{
    QPushButton *buton_generate = new QPushButton("Generate");
    QPushButton *buton_exit = new QPushButton(tr("Exit"));
    buton_layout->addWidget(buton_generate);
    buton_layout->addWidget(buton_exit);

    QObject::connect(buton_generate, SIGNAL(clicked()), this, SLOT(showResult()));
    QObject::connect(buton_exit, SIGNAL(clicked()), qApp, SLOT(quit()));

}

void MaFenetre::showResult()
{
    QString prevent_multiple_inclusion_start, prevent_multiple_inclusion_end, constructor, destructor, comment;
    if (generate_constructor_buton->isChecked())
    {
        constructor = "\t" + class_name->text() + "();\n\n";
    }
    else {
        constructor = "\n\n";
    }
    if (generate_destructor_buton->isChecked())
    {
        destructor = "\t~" + class_name->text() + "();\n\n";
    }
    else
    {
        destructor = "\n\n";
    }
    if (include_header_buton->isChecked())
    {
        prevent_multiple_inclusion_start = "#ifndef " + class_name->text().toUpper() + "_H\n";
        prevent_multiple_inclusion_start.append("#define " + class_name->text().toUpper() + "_H \n\n");
        prevent_multiple_inclusion_end = "\n#endif";
    }
    else {
        prevent_multiple_inclusion_start = "";
        prevent_multiple_inclusion_end = "";
    }
    if (comment_group->isChecked())
    {
        comment = "/**\n * ";
        comment.append(classDescription->toPlainText().replace("\n", "\n * ") + "\n");
        if (not author->text().isEmpty())
        {
            comment.append(" * @author " + author->text() + "\n");
        }
        comment.append(" * @date ");
        QString y, m, d;
        y = "01";
        m = "09";
        d = "2021";
        comment.append(d + "/" + m + "/" + y + "\n");

        comment.append("*/\n");

    }
    else
    {
        comment = "";
    }
    QString definition("class " +
                       class_name->text() +
                       class_parent_name->text() +
                       "\n{\npublic:\n" +
                       QString("\t// insert operations code\n") +
                       constructor +
                       destructor +
                       QString("private:\n\t// insert property here\n") +
                       "}\n");

    m_generated_code_window->receive(prevent_multiple_inclusion_start +
                                     comment +
                                     definition +
                                     prevent_multiple_inclusion_end);
    m_generated_code_window->show();
}
