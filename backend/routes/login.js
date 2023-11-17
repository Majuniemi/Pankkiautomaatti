const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const Kortti = require('../models/Kortti_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.idKortti && request.body.Pinkoodi){
      const username = request.body.idKortti;
      const password = request.body.Pinkoodi;
        Kortti.checkPassword(username, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(password,dbResult[0].Pinkoodi, function(err,compareResult) {
                if(compareResult) {
                  console.log("Onnistui");
                  const token = generateAccessToken({ username: Kortti });
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
              console.log("Korttia ei ole olemassa");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Kortti tai PIN-koodi puuttuu");
      response.send(false);
    }
  }
);

function generateAccessToken(username) {
  dotenv.config();
  return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '1800s' });
}


module.exports=router;