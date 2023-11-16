const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

/*router.post('/', 
  function(request, response) {
    if(request.body.idKortti && request.body.Pinkoodi) {
      const idKortti = request.body.idKortti;
      const Pin = request.body.Pinkoodi;
      
        login.checkPassword(idKortti, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(Pin, dbResult[0].Pinkoodi, function(err, compareResult) {
                if(compareResult) {
                  console.log("Onnistui");
                  const token = generateAccessToken({ idKortti: idKortti });
                  response.send(token);
                }
                else {
                    console.log("Väärä PIN-koodi");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("Väärä korttinumero");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Kortin numero tai PIN-koodi puuttuu");
      response.send(false);
    }
  }
);*/

router.post('/', function (request, response) {
  if (request.body.username && request.body.password) {
    const username = request.body.username; // Use 'username' instead of 'user'
    const password = request.body.password; // Use 'password' instead of 'pass'

    login.checkPassword(username, function (dbError, dbResult) {
      if (dbError) {
        response.json(dbError);
      } else {
        if (dbResult.length > 0) {
          bcrypt.compare(password, dbResult[0].Pinkoodi, function (err, compareResult) {
            if (compareResult) {
              console.log("success");
              const token = generateAccessToken({ username: username });
              response.send(token);
            } else {
              console.log("wrong password");
              response.send(false);
            }
          });
        } else {
          console.log("user does not exist");
          response.send(false);
        }
      }
    });
  } else {
    console.log("username or password missing");
    response.send(false);
  }
});


/*function generateAccessToken(idKortti) {
  dotenv.config();
  return jwt.sign(idKortti, process.env.MY_TOKEN, { expiresIn: '1800s' });
}*/

module.exports=router;