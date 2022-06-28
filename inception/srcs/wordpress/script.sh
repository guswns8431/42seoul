#!bin/bash

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp
wp core download --allow-root --path=/var/www/html
mv ./tmp/wp-config.php /var/www/html/
wp core install --allow-root --url=${MARIADB_USER}.42.fr --title=${WORDPRESS_TITLE} --admin_user=${MARIADB_USER} --admin_password=${MARIADB_PASS} --admin_email=${WORDPRESS_EMAIL} --path=/var/www/html
wp user create --allow-root ${WORDPRESS_USER_LOGIN} ${WORDPRESS_USER_EMAIL} --user_pass=${WORDPRESS_USER_PASS} --path=/var/www/html
mv ./tmp/www.conf /etc/php/7.3/fpm/pool.d

echo "env[MARIADB_NAME] = $MARIADB_NAME" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_USER] = $MARIADB_USER" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_PASS] = $MARIADB_PASS" >> /etc/php/7.3/fpm/pool.d/www.conf
echo "env[MARIADB_HOST] = $MARIADB_HOST" >> /etc/php/7.3/fpm/pool.d/www.conf

mkdir -p /run/php/
touch /run/php/php7.3-fpm.pid
/usr/sbin/php-fpm7.3 -F
