use BankSimul_R9;

create user r9user@'localhost' identified by 'r9pass';
grant all on BankSimul_R9.* to r9user@'localhost';

insert into Asiakas values ('280899', 'Jimi', 'Jakola');

select * from Asiakas;

insert into Kortti values ('1234123423452345', '1234', '2024-04-20');

select * from Kortti;

delete from Kortti where idKortti='1234123423452345';