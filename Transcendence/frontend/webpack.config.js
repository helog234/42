// webpack.config.js

const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './src/index.js', // Point d'entrée de votre application
  output: {
    path: path.resolve(__dirname, 'dist'), // Répertoire de sortie
    filename: 'bundle.js', // Nom du fichier JavaScript généré
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './src/index.html', // Modèle HTML à utiliser
    }),
  ],
};
