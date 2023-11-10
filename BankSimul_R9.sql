create database studentdb;
use studentdb;
create table student(
    id_student int primary key,
    firstname varchar(45),
    lastname varchar(45)
);
insert into student values(1,'Teppo','Testi');
insert into student values(2,'Liisa','Joki');

create user studentAdmin@'localhost' identified by 'studentPass';
grant all on studentdb.* to studentAdmin@'localhost';
