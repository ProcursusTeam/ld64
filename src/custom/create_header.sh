#!/bin/sh
printf "static const char *%s = " "$3" > $2
cat $1 | sed s/\"/\\\\\"/g | sed s/^/\"/ | sed s/\$/\\\\n\"/ >> $2
printf ";\n" >> $2
