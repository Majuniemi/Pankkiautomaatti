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

router.get('/getone/:id',
    function (request, response) {
        Tili.getOne(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });

router.get('/getdebit/:id',
    function (request, response) {
        Tili.getDebit(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });

router.get('/getcredit/:id',
    function (request, response) {
        Tili.getCredit(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getSaldo/:id',
    function (request, response) {
        Tili.getSaldo(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
    router.get('/getTili/:id',
    function (request, response) {
        Tili.getTili(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getLuottoraja/:id',
    function (request, response) {
        Tili.getLuottoraja(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getNostopalkkioeuro/:id',
    function (request, response) {
        Tili.getNostopalkkioeuro(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getNostopalkkioprosentti/:id',
    function (request, response) {
        Tili.getNostopalkkioprosentti(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getValuutta/:id',
    function (request, response) {
        Tili.getValuutta(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.get('/getMuuntokerroin/:id',
    function (request, response) {
        Tili.getMuuntokerroin(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult[0]);
            }
        })
    });
router.put('/updateSaldo/:id/:newSaldo',
    function (request, response) {
        const id = request.params.id;
        const newSaldo = request.params.newSaldo;

        Tili.updateSaldo(id, newSaldo, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json({ message: 'Saldo updated successfully' });
            }
        });
    }
);
router.post('/uusiTilitapahtuma/',
    function (request, response) {
        const { Aikaleima, Saldomuutos, Muutoslaji, idTili, Paikkatieto } = request.body;

        Tili.uusiTilitapahtuma(Aikaleima, Saldomuutos, Muutoslaji, idTili, Paikkatieto, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.status(201).json({ message: 'Uusi tietue luotu onnistuneesti' });
            }
        });
    }
);

module.exports = router;