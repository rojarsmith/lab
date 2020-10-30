import { useState, useEffect } from 'react';
import logo from './logo.svg';
import './App.css';

import AmountComponent from './CurrencyConverter/AmountComponent';

// Config proxy parameter in the package.json avoid CROS.
// "proxy": "http://localhost:5020"
function App() {
  useEffect(() => {
    fetch('/api')
      .then(res => res.text())
      .then(text => console.log(text))
      .catch(function (error) {
        console.log('Problem with your fetch operation: ', error.message);
      });;
  }, []);

  return (
    <div className="App">
      <header className="App-header">
        <AmountComponent></AmountComponent>
      </header>
    </div>
  );
}

export default App;
