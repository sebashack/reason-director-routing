const path = require('path');

module.exports = {
  entry: './lib/js/src/Main.bs.js',
  output: {
    path: path.join(__dirname, 'public'),
    filename: 'bundle.js'
  }
};
