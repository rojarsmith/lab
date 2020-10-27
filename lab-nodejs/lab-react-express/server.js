var express = require('express');
var app = express();

app.get('/api', function (req, res) {
    // do something
    res.send('ok');
})

app.listen(5020);