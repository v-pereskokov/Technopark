#!/bin/sh
# example:
# usage: ./start_task4 hello.conf hello
# $1 - conf
# $2 - app
CONF=$1
APP=$2
ROOT=~/Desktop/topquestion

cd $ROOT
exec gunicorn -c $ROOT/topquestion/$CONF --bind localhost:8081 topquestion.$APP:application
