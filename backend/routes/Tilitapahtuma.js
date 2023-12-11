const express = require('express');
const router = express.Router();
const Tilitapahtuma = require('../models/Tilitapahtuma_model');

router.get('/', function (request, response) {
    Tilitapahtuma.getAll(function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            console.log(dbResult);
            response.json(dbResult);
        }
    });
});

router.get('/getFive/:id', function (request, response) {
    const id = request.params.id;
    const offset = request.query.offset || 0; // Oletusarvo on 0, jos offset-parametria ei anneta
    Tilitapahtuma.getById(id, offset, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    });
});

router.post('/', function (request, response) {
    Tilitapahtuma.add(request.body, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(request.body);
        }
    });
});

router.delete('/delete/id', function (request, response) {
    Tilitapahtuma.delete(request.params.id, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    });
});

router.put('/update/id', function (request, response) {
    Tilitapahtuma.update(request.params.id, request.body, function (err, dbResult) {
        if (err) {
            response.json(err);
        } else {
            response.json(dbResult);
        }
    });
});

module.exports = router;