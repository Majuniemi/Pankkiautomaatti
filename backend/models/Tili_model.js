const db = require('../database');

const Tili = {
  getAll: function(callback) {
    return db.query('select * from Tili', callback);
  },
  getById: function(id, callback) {
    return db.query('select COUNT(Tili.idTili) AS count from Kortti LEFT JOIN Tili ON Kortti.idKortti = Tili.idKortti WHERE Kortti.idKortti=? GROUP BY Kortti.idKortti', [id], callback);
  }
};

module.exports = Tili;