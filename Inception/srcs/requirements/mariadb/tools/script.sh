#!/bin/bash

set -e

service mysql start

if [ ! -d "/var/lib/mysql/$MYSQL_DATABASE" ]

then

mysql_secure_installation << EOF

y
n
y
y
y
y
EOF

mysql -uroot -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;"

mysql -uroot -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;"

fi

mysqladmin -u root -p$MYSQL_ROOT_PASSWORD shutdown

exec "$@"
