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
#include <QObject>
#include <QTimer>
#include <iostream>
#include "arenawidget.h"
#include "geometry.h"

class SignalAcceptor : public QObject {

    Q_OBJECT

private:
    BSRect a_cln;
    BSRect a_deact;
//    ArenaWidget * arena_widget; <--- мы перешли на сигналы и теперь нам
//                                     не надо это хранить! очень удобно
public:
    SignalAcceptor(ArenaWidget * aw) :
        a_cln(BSPoint(0, 0), BSPoint(1, 1)),
        a_deact(BSPoint(1, 0), BSPoint(1, 1))
    {
        QObject::connect(this, SIGNAL(changeColor(const BSPoint &, const ColorStrategy &)),
                         aw,   SLOT(change_color(const BSPoint &, const ColorStrategy &)));
        QObject::connect(this, SIGNAL(clear_one()),
                         aw,   SLOT(clear()));
        QObject::connect(this, SIGNAL(activate_one()),
                         aw,   SLOT(activate()));
        QObject::connect(this, SIGNAL(deactivate_one()),
                         aw,   SLOT(deactivate()));

    }
public slots:
    void act1() {
        std::cout << "act1" << std::endl;
        emit activate_one();
    }
    void act2() {
        std::cout << "act2" << std::endl;
    }
    void acc_click(BSPoint p) {
        std::cout << "Click at " << p << " -- "
                  << a_cln.is_inside(p)
                  << std::endl;
        if (a_cln.is_inside(p)) {
            emit clear_one();
        } else
        if (a_deact.is_inside(p)) {
            emit deactivate_one();
            QTimer::singleShot(2200, this, SLOT(act1()));
        } else {
            int x(p.x());
            BSFlags f;
            if (x%3 == 0) f.fire();
            ++x;
            if (x%3 == 0) f.occupy();
            ++x;
            if (x%3 == 0) f.mark();
            emit changeColor(
                p,
                ColorStrategy(
                    f,
                    p.y()%2 == 0 ? update_mode_blink : update_mode_smooth
                )
            );
        }
    }
signals:
    void changeColor(BSPoint const & p, ColorStrategy const & c);
    void clear_one();
    void activate_one();
    void deactivate_one();
};

