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
  }
};

module.exports = Tili;