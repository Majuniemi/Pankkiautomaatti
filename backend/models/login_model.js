const db = require('../database');

const login = {
  checkPassword: function (username, callback) {
    return db.query('SELECT Pinkoodi FROM Kortti WHERE idKortti=?', [username], callback);
  },
};

module.exports = login;
