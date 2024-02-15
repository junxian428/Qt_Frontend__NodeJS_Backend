const express = require('express');
const app = express();
const port = 3000;

// Define a simple GET endpoint
app.get('/api/greet', (req, res) => {
  res.send('Hello, this is your GET API endpoint!');
});

// Start the server
app.listen(port, () => {
  console.log(`Server is listening at http://localhost:${port}`);
});
