get('/api/person/:id').to.json({
    name: "Peter"
});

get('/api/person2/:id').to.mock({
    name: '@name',
    email: '@email',
    'region|1-3': ['@region']
});
