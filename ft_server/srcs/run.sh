
service nginx start
service nginx status

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=son/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

rm etc/nginx/sites-available/default
mv ./tmp/default etc/nginx/sites-available/default

## autoindex
if [ ${AUTOINDEX} -eq -1 ] ; then
        sed -i 's/autoindex on;/autoindex off;/' etc/nginx/sites-available/default
fi

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv ./tmp/config.inc.php /var/www/html/phpmyadmin/

service nginx restart
service nginx status
service php7.3-fpm start
service php7.3-fpm status
service mysql start
service php7.3-fpm restart
mysql < var/www/html/phpmyadmin/sql/create_tables.sql -u root --skip-password
mysqladmin -u root -p password

mysql < ./tmp/query.sql

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv ./wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
mv ./tmp/wp-config.php var/www/html/wordpress/

service nginx restart
service nginx status

bash
