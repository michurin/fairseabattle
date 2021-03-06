# Fair Sea Battle

The FairSeaBattle -- sink the computer's fleet.

<p align="center"><img width="345" height="243" src="./fairseabattle.png" alt="Screenshot: Sea Battle game"></p>

You can get FairSeaBattle here: https://github.com/michurin/fairseabattle

Russian announce: https://habr.com/ru/post/80155/

Ported to Qt5 by [Alexander Drozdov](https://github.com/h4tr3d).

## Licensing

FairSeaBattle is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

FairSeaBattle is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FairSeaBattle.  If not, see <http://www.gnu.org/licenses/>.

## Building

Before building, you will need to have the Qt5 library installed
on your system ([https://www.qt.io/](https://www.qt.io/)).

Build:

```sh
qmake # or qmake-qt5
make  # or mingw32-make or nmake or other
```

Test it:

```sh
./fairseabattle
```

Install:

```sh
sudo cp ./fairseabattle /usr/local/bin/fairseabattle
```

or same

```sh
sudo make install
```

you can specify root dir of installation
if you want to prepare package or just
have reasons to do this

```sh
sudo make INSTALL_ROOT=/opt install
```

Enjoy!

Alexey Michurin
a.michurin@gmail.com
