const db = require('../database');

const Asiakas = {
  getAll: function(callback) {
    return db.query('select * from Asiakas', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from Asiakas where idAsiakas=?', [id], callback);
  },
  add: function(Asiakas, callback) {
    return db.query(
      'insert into Asiakas (idAsiakas,Etunimet,Sukunimi) values(?,?,?)',
      [Asiakas.idAsiakas, Asiakas.Etunimet, Asiakas.Sukunimi],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from Asiakas where idAsiakas=?', [id], callback);
  },
  update: function(id, Asiakas, callback) {
    return db.query(
      'update Asiakas set idAsiakas=?,Etunimet=?, Sukunimi=? where idAsiakas=?',
      [Asiakas.idAsiakas, Asiakas.Etunimet, Asiakas.Sukunimi, id],
      callback
    );
  }
};
module.exports = Asiakas;