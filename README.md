# FairSeaBattle

The FairSeaBattle -- sink the computer's fleet.

You can get FairSeaBattle here:

* http://fairseabattle.googlecode.com/
* https://github.com/h4tr3d/fairseabattle

Last official sources:

* [sources](http://user.rol.ru/~alvm/fairseabattle-1.0pre2.tar.gz)
* [Windows Binaries](http://user.rol.ru/~alvm/fairseabattle-1.0pre2.zip)

Russian announce:

* <https://habr.com/ru/post/80155/>

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

Before building, you will need to have the Qt4 library installed
on your system (<http://www.trolltech.com/>).

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
