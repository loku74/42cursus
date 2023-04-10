FROM debian:buster

COPY ./tools/wordpress_setup.sh /bin

RUN apt update -y && apt install -y php php-fpm php-mysql curl
RUN mkdir /run/php && mkdir -p /var/www/html && chmod +x /bin/wordpress_setup.sh

WORKDIR /var/www/html/

EXPOSE 9000

ENTRYPOINT ["wordpress_setup.sh"]

CMD ["php-fpm7.3", "-F"]
