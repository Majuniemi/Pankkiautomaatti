const express = require('express');
const router = express.Router();
const Tili = require('../models/Tili_model');

router.get('/',
    function (request, response) {
        Tili.getAll(function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });

router.get('/:id',
    function (request, response) {
        Tili.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });

module.exports = router;