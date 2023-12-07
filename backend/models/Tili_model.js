const db = require('../database');

const Tili = {
    getAll: function(callback) {
      return db.query('select * from Tili', callback);
    },
    getById: function(id, callback) {
      return db.query('select COUNT(Tili.idTili) AS count from Kortti LEFT JOIN Tili ON Kortti.idKortti = Tili.idKortti WHERE Kortti.idKortti=? GROUP BY Kortti.idKortti', [id], callback);
    },
    getOne: function(id, callback) {
      return db.query('select Tili.idTili AS tili from Tili INNER JOIN Kortti ON Kortti.idKortti = Tili.idKortti WHERE Kortti.idKortti=? GROUP BY Tili.idTili', [id], callback);
    },
    getDebit: function(id, callback) {
      return db.query('select Tili.idTili AS tili from Tili INNER JOIN Kortti ON Kortti.idKortti = Tili.idKortti WHERE Kortti.idKortti=? AND Tili.Luottoraja IS NULL GROUP BY Tili.idTili', [id], callback);
    },
    getCredit: function(id, callback) {
      return db.query('select Tili.idTili AS tili from Tili INNER JOIN Kortti ON Kortti.idKortti = Tili.idKortti WHERE Kortti.idKortti=? AND Tili.Luottoraja IS NOT NULL GROUP BY Tili.idTili', [id], callback);
    },
    getSaldo: function(id, callback) {
        return db.query('select Tili.Saldo AS saldo from Tili  WHERE Tili.idTili=? ', [id], callback);
    },
    getTili: function(id, callback) {
      return db.query('select COUNT(Tili.idTili) AS count from Tili  WHERE Tili.idTili=? ', [id], callback);
  },
    getLuottoraja: function(id, callback) {
        return db.query('select Tili.Luottoraja AS luottoraja from Tili  WHERE Tili.idTili=? ', [id], callback);
    },
    getNostopalkkioeuro: function(id, callback) {
        return db.query('select Tili.NPEuro AS NPEuro from Tili  WHERE Tili.idTili=? ', [id], callback);
    },
    getNostopalkkioprosentti: function(id, callback) {
        return db.query('select Tili.NPProsentti AS NPProsentti from Tili  WHERE Tili.idTili=? ', [id], callback);
    },
    getValuutta: function(id, callback) {
      return db.query('select Tili.idValuutta AS valuutta from Tili  WHERE Tili.idTili=? ', [id], callback);
    },
    getMuuntokerroin: function(id, callback) {
        return db.query('select Valuutta.Kurssi AS kurssi from Tili INNER JOIN Valuutta ON Valuutta.idValuutta = Tili.idValuutta WHERE Tili.idTili=?', [id], callback);
    },
    updateSaldo: function(id, newSaldo, callback) {
        return db.query('UPDATE Tili SET Saldo = ? WHERE idTili = ?', [newSaldo, id], callback);
    },
    uusiTilitapahtuma: function (aikaleima, saldoMuutos, MuutosLaji, idTili, paikkatieto, callback) {
        const sql = 'INSERT INTO Tilitapahtumat (Aikaleima, SaldoMuutos, MuutosLaji, idTili, Paikkatieto) VALUES (?, ?, ?, ?, ?)';
        const values = [aikaleima, saldoMuutos, MuutosLaji, idTili, paikkatieto];

        return db.query(sql, values, callback);
    }
  };
  
  module.exports = Tili;