#!/bin/sh

build_dir=build
src_dir=../../src

mkdir -p "$build_dir"

for i in arena flags geometry legend_io map_io arena_io flags_io legend map
do
   echo "Build $i..."
   if test "a$1" != 'afast' -o ! -e "$build_dir/$i.o"
   then
       g++ -g -c -Wall -Wextra -Weffc++ -o "$build_dir/$i.o" "$src_dir/logic/$i.cpp"
   fi
done

echo "Build main..."
g++ -g -c -Wall -I "$src_dir/logic" -o "$build_dir/logic-demo.o" logic-demo.cpp

echo "Link..."
c++ -o logic-demo "$build_dir"/*.o

echo "Done"
