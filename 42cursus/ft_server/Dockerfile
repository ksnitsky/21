FROM debian:buster

# packages
RUN apt update
RUN apt -y install wget ; \
	apt -y install nginx ; \
	apt -y install mariadb-server ; \
	apt -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring ;

# changing to site dir
WORKDIR /var/www/html/

# nginx confing
RUN rm -f /etc/nginx/sites-enabled/default ; \
	rm -rf *
COPY ./srcs/nginx-conf /etc/nginx/sites-enabled/default

# ssl
RUN openssl req -newkey rsa:2048 -x509 -sha256 -days 365 -nodes -keyout /etc/ssl/tkathrin.key -out /etc/ssl/tkathrin.crt -subj "/C=RU/ST=Russia/L=Kazan/OU=21kazan/CN=tkathrin"

# phpmyadmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.7/phpMyAdmin-4.9.7-english.tar.gz ; \
	tar -xvf phpMyAdmin-4.9.7-english.tar.gz && rm -rf phpMyAdmin-4.9.7-english.tar.gz ; \
	mv phpMyAdmin-4.9.7-english phpmyadmin ;
COPY ./srcs/config.inc.php ./phpmyadmin

# wordpress
RUN wget https://wordpress.org/latest.tar.gz ; \
	tar -xvf latest.tar.gz && rm -rf latest.tar.gz ; \
	mv wordpress/* . ; \
	rm -rf wordpress ;
COPY ./srcs/wp-config.php /var/www/html

# root dir is for 2 scripts
WORKDIR /root

# autoindex on/off script
COPY ./srcs/autoindex.sh ./

# starting server
COPY ./srcs/initserver.sh ./
RUN chown -R www-data:www-data /var/www/* ; \
	chmod -R 755 /var/www/*
CMD bash initserver.sh
