const db = require('../database');

const Tilitapahtumat = {
  getAll: function(callback) {
    return db.query('select * from Tilitapahtumat', callback);
  },
  getById: function(id, offset, callback) {
    return db.query('SELECT * FROM Tilitapahtumat WHERE idTili=? ORDER BY Aikaleima DESC LIMIT 5 OFFSET ?', [id, parseInt(offset)], callback);
},
  add: function(Tilitapahtumat, callback) {
    return db.query(
      'insert into Tilitapahtumat (Aikaleima, Saldomuutos, Muutoslaji, idTili, Paikkatieto) values(?,?,?,?,?)',
      [Tilitapahtuma.Aikaleima, Tilitapahtuma.Saldomuutos, Tilitapahtuma.Muutoslaji, Tilitapahtuma.idTili, Tilitapahtuma.Paikkatieto],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, Tilitapahtumat, callback) {
    return db.query(
      'update Tilitapahtumat set Aikaleima=?,Saldomuutos=?,Muutoslaji=?,idTili=?,Paikkatieto=?',
      [Tilitapahtuma.Aikaleima, Tilitapahtuma.Saldomuutos, Tilitapahtuma.Muutoslaji, Tilitapahtuma.idTili, Tilitapahtuma.Paikkatieto, id],
      callback
    );
  }
};
module.exports = Tilitapahtumat;