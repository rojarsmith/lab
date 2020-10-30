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
  const [isLoadingTodos, setIsLoadingTodos] = useState(false);

  // const TodoListOne = withTodosEmpty(TodoList);
  // const TodoListTwo = withTodosNull(TodoListOne);
  // const TodoListThree = withLoadingIndicator(TodoListTwo);

  const TodoListWithConditionalRendering = withLoadingIndicator(withTodosNull(withTodosEmpty(TodoList)));

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
        <TodoListWithConditionalRendering todos={todos} isLoadingTodos={isLoadingTodos} />
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

export default App;

function TodoList({ todos, isLoadingTodos }) {
  // if (isLoadingTodos) {
  //   return (
  //     <div>
  //       <p>Loading todos ...</p>
  //     </div>
  //   );
  // }

  // Removed conditional rendering with null check

  // if (!todos.length) {
  //   return (
  //     <div>
  //       <p>You have no Todos.</p>
  //     </div>
  //   );
  // }

  return (
    <div>
      {todos.map(todo => <li key={todo.id} todo={todo} />)}
    </div>
  );
}

// function withTodosNull(Component) {
//   return function (props) {
//     return !props.todos
//       ? null
//       : <Component {...props} />
//   }
// }

// JavaScript ES6 arrow functions
const withTodosNull = (Component) => (props) =>
  !props.todos
    ? null
    : <Component {...props} />


const withTodosEmpty = (Component) => (props) =>
  !props.todos.length
    ? <div><p>You have no Todos.</p></div>
    : <Component {...props} />

// JavaScript ES6 rest destructuring 
const withLoadingIndicator = (Component) => ({ isLoadingTodos, ...others }) =>
  isLoadingTodos
    ? <div><p>Loading todos ...</p></div>
    : <Component {...others} />
