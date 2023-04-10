FROM debian:buster

RUN apt update -y; apt install -y nginx openssl
RUN mkdir -p /etc/nginx/ssl; mkdir -p /run/nginx
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes -out /etc/nginx/ssl/ssl_certificat.pem -keyout /etc/nginx/ssl/ssl_key.key -subj  "/C=FR/L=Lyon/O=42/OU=lbourniq/CN=lbourniq.42.fr"

COPY conf/nginx.conf /etc/nginx/conf.d/

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]
