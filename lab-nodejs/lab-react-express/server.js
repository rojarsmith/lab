var express = require('express');
var app = express();

app.get('/api', function (req, res) {
    res.send('ok');
})

app.get('/api/news/search', function (req, res) {
    console.log(req.query.query)
    // Dont use setInterval, crash.
    setTimeout(function () {
        res.send({
            hits:
                [{
                    objectID: 'obj1',
                    url: 'http://111',
                    title: 'tit1' + req.query.query
                },
                {
                    objectID: 'obj2',
                    url: 'http://222',
                    title: 'tit2' + req.query.query
                }]
        });
    }, 1000);
})

app.listen(5020);