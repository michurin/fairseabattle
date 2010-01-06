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
#include <time.h>
#include <fstream>

#include "geometry.h"
#include "map.h"
#include "map_io.h"
#include "arena.h"
#include "flags.h"
#include "legend.h"
#include "legend_io.h"
#include "flags_io.h"
#include "arena_io.h"

// Russian
//int legend[] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0};
int legend[] = {4, 4, 4, 3, 3, 3, 0};

// http://www.boardgamecapital.com/battleship-rules.htm
//int legend[] = {5, 4, 3, 3, 2, 0};

// extrim
//int legend[] = {4, 4, 3, 3, 2, 2, 1, 0};

// extrim - 2 (short)
//int legend[] = {2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0};

void utest1() {
    int legend[] = {4, 2, 2, 0};
    BSArenaPuzzle pz(10, legend);
    std::cout << pz << std::endl;
    pz.apply_result(BSPoint(3, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(4, 3), BSArena::r_continue_in_that_direction);
//    pz.apply_result(BSPoint(5, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(6, 3), BSArena::r_continue_in_that_direction);
    std::cout << pz << std::endl;
    std::cout << "===" << std::endl;
    BSPoint p = pz.find_fire();
    std::cout << "===" << std::endl;
    std::cout << p << std::endl;
    std::cout << "===" << std::endl;
}

void utest2() {
    int legend[] = {4, 2, 2, 0};
    BSArenaPuzzle pz(10, legend);
    std::cout << pz << std::endl;
    pz.apply_result(BSPoint(3, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(4, 3), BSArena::r_continue_in_that_direction);
//    pz.apply_result(BSPoint(5, 3), BSArena::r_continue_in_that_direction);
//    pz.apply_result(BSPoint(6, 3), BSArena::r_continue_in_that_direction);
    std::cout << pz << std::endl;
    std::cout << "===" << std::endl;
    BSPoint p = pz.find_fire();
    std::cout << "===" << std::endl;
    std::cout << p << std::endl;
    std::cout << "===" << std::endl;
}

void utest3() {
    int legend[] = {4, 2, 2, 0};
    BSArenaPuzzle pz(10, legend);
    std::cout << pz << std::endl;
    pz.apply_result(BSPoint(3, 3), BSArena::r_continue_in_that_direction);
//    pz.apply_result(BSPoint(4, 3), BSArena::r_continue_in_that_direction);
//    pz.apply_result(BSPoint(5, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(6, 3), BSArena::r_continue_in_that_direction);
    std::cout << pz << std::endl;
    std::cout << "===" << std::endl;
    BSPoint p = pz.find_fire();
    std::cout << "===" << std::endl;
    std::cout << p << std::endl;
    std::cout << "===" << std::endl;
}

void utest4() {
    int legend[] = {4, 2, 2, 0};
    BSArenaPuzzle pz(10, legend);
    std::cout << pz << std::endl;
    pz.apply_result(BSPoint(3, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(6, 6), BSArena::r_continue_in_that_direction);
    std::cout << pz << std::endl;
    std::cout << "===" << std::endl;
    BSPoint p = pz.find_fire();
    std::cout << "===" << std::endl;
    std::cout << p << std::endl;
    std::cout << "===" << std::endl;
}

/**********************************************/

void vtest1() {
    int legend[] = {3, 1, 1, 0};
    BSArenaPuzzle pz(10, legend);
    std::cout << pz << std::endl;
    pz.apply_result(BSPoint(2, 3), BSArena::r_milk);
    pz.apply_result(BSPoint(3, 2), BSArena::r_milk);
    pz.apply_result(BSPoint(3, 3), BSArena::r_continue_in_that_direction);
    pz.apply_result(BSPoint(3, 5), BSArena::r_drowned);
    std::cout << "____________" << std::endl;
    std::cout << pz << std::endl;
    std::cout << "___SEARCH___" << std::endl;
    BSPoint p = pz.find_fire();
}

/**********************************************/

void test_set() {
    unsigned long cnt(0);
    BSArenaKey a(10, legend);
    while(true) {
        std::cout << "\033[0;0H\033[0J";
        for(int xxx(0); xxx<5; ++xxx) {
            a.load_legend(legend);
            a.auto_setup();
            std::cout << cnt << std::endl << a;
            ++cnt;
        }
    }
}


void test_fire() {
    BSArenaKey ky(10, legend);
    BSArenaPuzzle pz(10, legend);
    BSArena::result r;

    int c(0);
    time_t st;
    st = time(&st);
    int error(-1);

//    std::ifstream file("logic-demo.log");
    std::ofstream file("logic-demo.log");
//    std::streambuf* cout_sbuf = std::cout.rdbuf(); // save original sbuf
    std::cout.rdbuf(file.rdbuf());

    while(error == -1) {

        file.seekp(0);
        file << "OK";

        ky.load_legend(legend);
        ky.auto_setup();
        pz.load_legend(legend);
        pz.clean();

        ++c;
        long dt = time(NULL) - st;

        std::cerr << "=======" <<
                     " (count=" << c << "; dt=" << dt << ") " <<
                     "==========" << std::endl;

        for (int i(0); i<1000; ++i) {
            file << "\n\n=======" << i <<
                         " (count=" << c << "; dt=" << dt << ") " <<
                         "==========\n\n" << std::endl;

            BSPoint p = pz.find_fire();
            file << "======FIRE TO " << p <<
                         " (count=" << c << "; dt=" << dt << ") " <<
                         std::endl;
            r = ky.apply_fire(p);
            file << "======RESULT " << r <<
                         " (count=" << c << "; dt=" << dt << ") " <<
                         std::endl;

            switch(r) {
                case BSArena::r_milk:            // мимо
                    break;
                case BSArena::r_already_fired:   // сюда уже стреляли
                    error = r;
                    break;
                case BSArena::r_wasted_effort:   // мимо, но вам и так должно быть известно, что здесь ничего нет
                    error = r;
                    break;
                case BSArena::r_continue_in_that_direction: // ранен, продолжайте добивать
                    break;
                case BSArena::r_drowned:         // утонул
                    break;
                case BSArena::r_game_over:       // добит последний, игра окончена
                    break;
                default:
                    error = r;
                    break;
            }

            if (error != -1) break;

            pz.apply_result(p, r);

            if (r == BSArena::r_game_over) break;
        }
        if (r != BSArena::r_game_over) {
            file << "\n====== 1000 (!!!) ======\n";
            break;
        }
        if (error != -1) {
            file << "\n====== error(r) = " << error << " (!!!) ======\n";
            break;
        }
        file << "DONE.\n\n\n";
    }

    file << "DONE AND EXIT (NORMAL / ERROR FOUND).\n\n\n";

}


int main() {
    test_set();
//    test_fire();

/*
    vtest1();

    utest1();
    utest2();
    utest3();
    utest4();
*/

//    BSLegend l(legend);
//    std::cout << l << std::endl;
//    l.remove(3);
//    l.remove(3);
//    std::cout << l << std::endl;
//    for(BSLegend::uniqiter i(l); i(); ++i) {
//      std::cout << ">" << *i << std::endl;
//    }
//    BSArenaKey ky(10, legend);
//    ky.auto_setup();
    return 0;
}
