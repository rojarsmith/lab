import { useState, useEffect } from 'react';
import logo from './logo.svg';
import './App.css';

// import Amount from './CurrencyConverter/AmountComponent';
// import Amount from './CurrencyConverter/AmountChildrenComponent';
import Amount from './CurrencyConverter/AmountRenderPropComponent';

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

  return (
    <div className="App">
      <header className="App-header">
        <Amount
          renderAmountOne={amount => (
            <div>
              <h2>My one Amount</h2>
              <Euro amount={amount} />
              <Pound amount={amount} />
            </div>
          )}
          renderAmountTwo={amount => (
            <div>
              <h2>My two Amount</h2>
              <Euro amount={amount} />
              <Pound amount={amount} />
            </div>
          )}
        >
        </Amount>
      </header>
    </div>
  );
}

export default App;
