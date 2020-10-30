import { useState, useEffect } from 'react';
import logo from './logo.svg';
import './App.css';

// import Amount from './CurrencyConverter/AmountComponent';
// import Amount from './CurrencyConverter/AmountChildrenComponent';
import Amount from './CurrencyConverter/AmountRenderPropComponent';
import withAmount from './CurrencyConverter/AmountRenderPropHocComponent';

const Euro = ({ amount }) => <p>Euro: {amount * 0.86}</p>;

const Pound = ({ amount }) => <p>Pound: {amount * 0.76}</p>;

const TodoItem = ({ todo }) => <p>id: {todo.id} todo: {todo}</p>

const CurrenciesWithAmount = withAmount([Euro, Pound]);

// Config proxy parameter in the package.json avoid CROS.
// "proxy": "http://localhost:5020"
function App() {
  const [amount, setAmount] = useState(0);
  const [todos, setTodos] = useState();

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
        <TodoList todos={todos} />
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
        Hoc
        <CurrenciesWithAmount />
      </header>
    </div>
  );
}

function TodoList({ todos, isLoadingTodos }) {
  if (isLoadingTodos) {
    return (
      <div>
        <p>Loading todos ...</p>
      </div>
    );
  }

  if (!todos) {
    return null;
  }

  if (!todos.length) {
    return (
      <div>
        <p>You have no Todos.</p>
      </div>
    );
  }

  return (
    <div>
      {todos.map(todo => <li key={todo.id} todo={todo} />)}
    </div>
  );
}

export default App;
