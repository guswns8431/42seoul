#!bin/bash

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv /wordpress/* /var/www/html/
chown -R www-data:www-data /var/www/html
rm -r /wordpress latest.tar.gz
mv ./tmp/wp-config.php /var/www/html/wp-config.php
mv ./tmp/www.conf /etc/php/7.3/fpm/pool.d


echo "env[MARIADB_NAME] = $MARIADB_NAME" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_USER] = $MARIADB_USER" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_PASS] = $MARIADB_PASS" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_HOST] = $MARIADB_HOST" >> /etc/php/7.3/fpm/pool.d/www.conf
service php7.3-fpm start

bash #지워야함
