#!/bin/sh
# example:
# usage: ./start_task3 hello.conf hello
# $1 - conf
# $2 - app
CONF=$1
APP=$2
ROOT=/var/www/environment/topquestion/task3

cd $ROOT
exec gunicorn -c $ROOT/$CONF --bind localhost:8081 $APP:application

