# group_9

## Minun vastuualueeni

Vastasin tässä projektissa sisäänkirjautumisen toteutuksesta. Tietokantaan perustetun asiakkaan oli mahdollista kirjautua sisään pankkikorttinumerolla ja PIN-koodilla. Pankkikortin numero luettiin sovelluksen käyttöön RFID-kortilta ja PIN-koodi salattiin tietokantaan bcrypt menetelmällä. Onnistuneen sisäänkirjautumisen jälkeen luotiin kirjautumisavain, jolla oli tietty voimassaoloaika.

Käyttöliittymä teki tietokantapyynnöt käyttäen REST API:a ja HTTP pyyntöjä. Tietojen tallentamiseen käytimme MySQL tietokantaa ja toimintalogiikan kehitimme Node.js tekniikalla.

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