#!/bin/bash

service mysql start
mysql < ./tmp/init_mariadb.sql
rm -f ./tmp/init_mariadb.sql

service mysql stop
echo "test"

mysqld_safe
