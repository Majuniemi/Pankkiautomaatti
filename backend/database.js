const mysql=require('mysql2');
const connection=mysql.createPool({
    host: 'localhost',
    user: 'r9user',
    password: 'r9pass',
    database: 'BankSimul_R9'
});

module.exports=connection;