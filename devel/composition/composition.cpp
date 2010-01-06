/*
 * Copyright 2010 Alexey Michurin
 *
 * This file is part of FairSeaBattle.
 *
 * FairSeaBattle is free software: you can redistribute
 * it and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * FairSeaBattle is distributed in the hope that
 * it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the
 * GNU General Public License along with FairSeaBattle.
 * If not, see <http://www.gnu.org/licenses/>.
 */
#include <QApplication>
#include <QMainWindow>
#include <QBoxLayout>
#include <QMenuBar>
#include <QToolBar>
/*
#include <QtCore>
#include <QMessageBox>
#include <QApplication>
#include <QMenu>
#include <QFrame>
#include <QGridLayout>
#include <iostream>
#include <stdlib.h>
*/
#include "composition.h"

/*
план инициализации и функционирования:
   - создаются основные объекты:
     - объект отображения
     - контроллер
       - внутри контроллера находится объекты логики
   - настраиваесть обмен сигналами между
     контроллером и представлением

открытые вопросы:
   - представление состоит из трёх объектов
     (два поля и меню); надо ли проводить
     все сигналы через объект представления
     или их поставлять сразу в контроллер?
     видимо, достаточно только одной единой
     точки -- контроллера.
*/

//------------------------------------------------------

void setup_frame(QFrame * f) {
    f->setFrameStyle(QFrame::Panel | QFrame::Raised);
    f->setLineWidth(2);
    f->setFixedSize(QSize(100, 100)); // [S] not resize
}

//------------------------------------------------------

Arena::Arena() :
    QFrame(),
    touched(true)
{
}

void
Arena::touch() {
    touched = ! touched;
    setFrameStyle(QFrame::Panel | (touched ? QFrame::Raised : QFrame::Sunken));
}

//------------------------------------------------------

Controller::Controller(QObject * parent) :
    QObject(parent) {
}
void Controller::a1() { emit b1(); }
void Controller::a2() { emit b2(); }
void Controller::a3() { emit b3(); }
void Controller::a4() { emit b4(); }

//------------------------------------------------------

BoolMediator::BoolMediator(QObject * parent, bool v) :
    QObject(parent),
    val(v)
{
}

void
BoolMediator::slot() {
    emit signal(val);
}

//------------------------------------------------------

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    Controller contr;

    // MAIN WINDOW

    QMainWindow main_window;

    // CENTRAL WIDGET (AND BIND TO CONTROLLER)

    QFrame * left_arena = new Arena;
    setup_frame(left_arena);
    QFrame * right_arena = new Arena;
    setup_frame(right_arena);

    // получаем сигналы только из контроллера

    QObject::connect(&contr, SIGNAL(b2()), left_arena,  SLOT(touch()));
    QObject::connect(&contr, SIGNAL(b3()), right_arena, SLOT(touch()));
    QObject::connect(&contr, SIGNAL(b4()), left_arena,  SLOT(touch()));
    QObject::connect(&contr, SIGNAL(b4()), right_arena, SLOT(touch()));

    QFrame * central_widget = new QFrame();
    setup_frame(central_widget);

    QBoxLayout * layout = new QBoxLayout(QBoxLayout::LeftToRight);
    layout->setSizeConstraint(QLayout::SetFixedSize); // [S] not resize
    layout->addWidget(left_arena);
    layout->addWidget(right_arena);
    central_widget->setLayout(layout);

    main_window.setCentralWidget(central_widget);

    // MENU (AND BIND TO CONTROLLER)

    // получаем сигналы только из контроллера
    // отправляем сигналы только в контроллер

    QObject * mediator;

    QAction *a;
    QAction *aaa;
    QMenu *m;
    QMenuBar *mb(main_window.menuBar());
    QToolBar *t;

    m = mb->addMenu(QObject::tr("Menu"));
    t = main_window.addToolBar(QObject::tr("FaFa"));

    a = new QAction(QObject::tr("A1 (quit)"), &main_window);
    a->setShortcut(Qt::CTRL+Qt::Key_1);
    QObject::connect(a, SIGNAL(triggered()), &contr, SLOT(a1()));
    m->addAction(a);
    t->addAction(a);
    aaa = a; // save

    a = new QAction(QObject::tr("A2"), &main_window);
    a->setShortcut(Qt::CTRL+Qt::Key_2);
    QObject::connect(a, SIGNAL(triggered()), &contr, SLOT(a2()));
    mediator = new BoolMediator(a, false);
    QObject::connect(a, SIGNAL(triggered()), mediator, SLOT(slot()));
    QObject::connect(mediator, SIGNAL(signal(bool)), aaa, SLOT(setEnabled(bool)));
    m->addAction(a);
    t->addAction(a);

    a = new QAction(QObject::tr("A3"), &main_window);
    a->setShortcut(Qt::CTRL+Qt::Key_3);
    QObject::connect(a, SIGNAL(triggered()), &contr, SLOT(a3()));
    mediator = new BoolMediator(a, true);
    QObject::connect(a, SIGNAL(triggered()), mediator, SLOT(slot()));
    QObject::connect(mediator, SIGNAL(signal(bool)), aaa, SLOT(setEnabled(bool)));
    m->addAction(a);
    t->addAction(a);

    a = new QAction(QObject::tr("A4"), &main_window);
    a->setShortcut(Qt::CTRL+Qt::Key_4);
    QObject::connect(a, SIGNAL(triggered()), &contr, SLOT(a4()));
    m->addAction(a);
    t->addAction(a);

    // BIND CONTROLLER

    QObject::connect(&contr, SIGNAL(b1()), &app, SLOT(quit()));

    main_window.show();

    main_window.layout()->setSizeConstraint(QLayout::SetFixedSize); // [S] not resize

    return app.exec();
}
