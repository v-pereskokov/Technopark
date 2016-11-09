#!/bin/sh
# example:
# usage: ./start_task4 hello.conf hello
# $1 - conf
# $2 - app
CONF=$1
APP=$2
ROOT=/var/www/topquestion

cd $ROOT
exec gunicorn -c $ROOT/topquestion/$CONF topquestion.$APP:application
