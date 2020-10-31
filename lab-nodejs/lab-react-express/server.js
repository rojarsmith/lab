var express = require('express');
var app = express();

app.get('/api', function (req, res) {
    res.send('ok');
})

app.get('/api/news/search', function (req, res) {
    console.log(req.query.query)
    res.send({
        hits:
            [{
                objectID: 'obj1',
                url: 'http://111',
                title: 'tit1'
            },
            {
                objectID: 'obj2',
                url: 'http://222',
                title: 'tit2'
            }]
    });
})

app.listen(5020);