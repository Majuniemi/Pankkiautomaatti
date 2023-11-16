const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;
const Kortti={
  getAll: function(callback) {
    return db.query('select * from Kortti', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from Kortti where idKortti=?', [id], callback);
  },
  add: function(Kortti, callback) {
    bcrypt.hash(Kortti.Pinkoodi, saltRounds, function(err, hash) {
      return db.query('insert into Kortti (idKortti, Pinkoodi, Voimassa) values(?,?,?)',
      [Kortti.idKortti, hash, Kortti.Voimassa], callback);
    });
  },
  delete: function(id, callback) {
    return db.query('delete from Kortti where idKortti=?', [id], callback);
  },
  update: function(id, Kortti, callback) {
    bcrypt.hash(Kortti.Pinkoodi, saltRounds, function(err, hash) {
      return db.query('update Kortti set idKortti=?, Pinkoodi=?, Voimassa=? where idKortti=?',
      [Kortti.idKortti, hash, Kortti.Voimassa, id], callback);
    });
  }
};
          
module.exports = Kortti;