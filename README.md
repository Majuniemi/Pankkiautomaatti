# Pankkiautomaatti

Opin tässä projektissa luomaan käyttöliittymiä Qt Frameworkillä ja ohjelmoimaan käyttöliittymän toiminnot C++ ohjelmointikielellä. Käytimme tässä tuotteessa olio-ohjelmointia ja ymmärrän olioiden toimintalogiikkaa tämän projektin jälkeen hyvin. Opin integroimaan käyttöliittymän ja tietokannan toimivaksi kokonaisuudeksi, jolla on tosielämän käyttötarkoitus. 

Opin myös käyttämään Git-versionhallintaa ja GitHub-palvelua usean henkilön projektissa erittäin hyvin. 

## Minun vastuualueeni

Vastasin tässä projektissa sisäänkirjautumisen toteutuksesta. Tietokantaan perustetun asiakkaan oli mahdollista kirjautua sisään pankkikorttinumerolla ja PIN-koodilla. Pankkikortin numero luettiin sovelluksen käyttöön RFID-kortilta ja PIN-koodi salattiin tietokantaan bcrypt menetelmällä. Onnistuneen sisäänkirjautumisen jälkeen luotiin kirjautumisavain, jolla oli tietty voimassaoloaika.

Käyttöliittymä teki tietokantapyynnöt käyttäen REST API:a ja HTTP pyyntöjä. Tietojen tallentamiseen käytimme MySQL tietokantaa ja toimintalogiikan kehitimme Node.js tekniikalla.

Loin projektissa käytettäville tekniikoille alustukset ja suunnittelin relaatiotietokannan. Autoin ryhmämme jäseniä monipuolisesti heidän vastuualueillaan ja osallistuin kaikkiin työvaiheisiin aktiivisesti.

## Pankkiautomaatin käyttöliittymä

<img src="Pankkiautomaatti_ui.png">

## ER-kaavio

Projektissa käytettävän tietokannan ER-kaavio.

<img src="ER-kaavio.png">

## Järjestelmäympäristö

Projektin järjestelmäympäristö käy ilmi alla olevasta käyttöönottokaaviosta.

<img src="Käyttöönottokaavio.png">

## Tietokantayhteys
Luodaan tunnus, jolla sovelluksesta kytkeydytään tietokantaan.

<pre>
create user r9user@'localhost' identified by 'r9pass';
grant all on BankSimul_R9.* to r9user@'localhost'; 
</pre>