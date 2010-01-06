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
//#include <QTimer>
#include "gui.h"
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "enter\n";
    QApplication app(argc, argv);
    std::cout << "app created\n";
    ArenaWidget ar;
    std::cout << "ar created\n";
    SignalAcceptor a(&ar);
    std::cout << "a created\n";

    QObject::connect(&ar, SIGNAL(click(BSPoint)),
                     &a,  SLOT(acc_click(BSPoint)));

    std::cout << "ar to a connected\n";

//    QTimer::singleShot(1200, &a, SLOT(act1()));
//    QTimer::singleShot(2000, &a, SLOT(act2()));
    ar.show();
    return app.exec();
}
