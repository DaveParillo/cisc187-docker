
# A Singleton Console Logger

A simple Singleton logger based on a safer singleton that does not use pointers.

Compile with:

    c++ -std=c++11 -Wall -Wextra -pedantic *.cpp -o log.exe

And run like this:

    ./log.exe -f foo -l debug -l trace -l info

Run with different combinations of arguments to see how the output changes.

See:
 - [Alexandrescu on Singletons](http://loki-lib.sourceforge.net/index.php?n=Pattern.Singleton)

