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
#include <QFrame>
#include <QObject>

class Arena : public QFrame {
    Q_OBJECT
private:
    bool touched;
public:
    Arena();
public slots:
    void touch();
};

class Controller : public QObject {
    Q_OBJECT
public:
    Controller(QObject * parent = 0);
public slots:
    void a1();
    void a2();
    void a3();
    void a4();
signals:
    void b1();
    void b2();
    void b3();
    void b4();
};

class BoolMediator : public QObject {
    Q_OBJECT
private:
    bool val;
public:
    BoolMediator(QObject * parent = 0, bool v = true);
public slots:
    void slot();
signals:
    void signal(bool);
};
