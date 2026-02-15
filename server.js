const express = require('express');
const mysql = require('mysql2');
const bodyParser = require('body-parser');
const cors = require('cors');

const app = express();
app.use(cors());
app.use(bodyParser.json());

// Database connection
const db = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'helloworld',
    database: 'sum'
});

db.connect(err => {
    if (err) {
        console.error('Database connection failed:', err);
    } else {
        console.log('Connected to MySQL');
    }
});

// API route
app.post('/calculate', (req, res) => {
    const { number1, number2 } = req.body;
    const result = number1 + number2;

    const sql = 'INSERT INTO calculations (number1, number2, result) VALUES (?, ?, ?)';
    db.query(sql, [number1, number2, result], (err, data) => {
        if (err) {
            return res.status(500).json(err);
        }
        res.json({ result });
    });
});

app.listen(3000, () => {
    console.log('Server running on port 3000');
});
