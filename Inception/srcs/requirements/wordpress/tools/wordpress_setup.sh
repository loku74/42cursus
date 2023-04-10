#!/bin/sh

set -e

if [ ! -f ./wp-config.php ]; then
    curl -O https://wordpress.org/latest.tar.gz
    tar -xzvf latest.tar.gz
    mv wordpress/* .
    rm -rf latest.tar.gz
    rmdir wordpress

    sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
    sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
    sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
    sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
    
    mv wp-config-sample.php wp-config.php
fi

sed -i "s/listen = \/run\/php\/php7.3-fpm.sock/listen = 9000/g" /etc/php/7.3/fpm/pool.d/www.conf

exec "$@"
