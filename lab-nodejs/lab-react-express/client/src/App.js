import { useState, useEffect } from 'react';
import logo from './logo.svg';
import './App.css';

import AmountComponent from './CurrencyConverter/AmountComponent';

const Euro = ({ amount }) => <p>Euro: {amount * 0.86}</p>;

const Pound = ({ amount }) => <p>Pound: {amount * 0.76}</p>;

// Config proxy parameter in the package.json avoid CROS.
// "proxy": "http://localhost:5020"
function App() {
  const [amount, setAmount] = useState(0);

  useEffect(() => {
    fetch('/api')
      .then(res => res.text())
      .then(text => console.log(text))
      .catch(function (error) {
        console.log('Problem with your fetch operation: ', error.message);
      });;
  }, []);

  const onIncrement = () => {
    setAmount(amount + 1);
  };

  const onDecrement = () => {
    setAmount(amount - 1);
  };

  return (
    <div className="App">
      <header className="App-header">
        <AmountComponent
          amount={amount}
          onIncrement={onIncrement}
          onDecrement={onDecrement}
        />

        <Euro amount={amount} />
        <Pound amount={amount} />
      </header>
    </div>
  );
}

export default App;
