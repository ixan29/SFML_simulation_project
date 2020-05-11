
APP="../SFML-2.5.1/bin/rope.exe"
CXX="g++"
INCLUDE="-IC:../SFML-2.5.1/include"
LIB=" -LC:./../SFML-2.5.1/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system"

for f in $(find ./ -name "*.cpp" )
do
    n=${f##*/}
    o=${n/.cpp/.o}

    if [ "$f" -nt "./$o" ]; then
        echo $o
        $CXX -c $f $INCLUDE
    fi
done

$CXX *.o -o $APP $LIB