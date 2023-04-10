FROM debian:buster

COPY ./tools/script.sh .

RUN apt-get update && apt-get install -y mariadb-server && chmod +x script.sh

EXPOSE 3306

ENTRYPOINT ["./script.sh"]
CMD ["mysqld", "--bind-address=0.0.0.0"]

