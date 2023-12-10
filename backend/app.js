var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var KorttiRouter = require('./routes/Kortti');
var loginRouter = require('./routes/login');
var AsiakasRouter = require('./routes/Asiakas');
var TiliRouter = require('./routes/Tili');
var TilitapahtumaRouter = require('./routes/Tilitapahtuma');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/login', loginRouter);
app.use(authenticateToken);    //Tämän jälkeen olevat reitit ovat suojattuja ja vaativat Tokenin
app.use('/Kortti', KorttiRouter);
app.use('/Asiakas', AsiakasRouter);
app.use('/Tili', TiliRouter);
app.use('/Tilitapahtuma', TiliRouter);


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, Kortti) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.Kortti = Kortti
  
      next()
    })
  }

module.exports = app;
