import Fragment, { useState, useEffect } from 'react';
import logo from './logo.svg';
import './App.css';

import axios from 'axios';
// import Amount from './CurrencyConverter/AmountComponent';
// import Amount from './CurrencyConverter/AmountChildrenComponent';
import Amount from './CurrencyConverter/AmountRenderPropComponent';
import withAmount from './CurrencyConverter/AmountRenderPropHocComponent';
import { withTodosNull, withCondition, withEither, withTodosEmpty, withLoadingIndicator } from './HigherOrderComponent/WithTodos';
import useHackerNewsApi from './CustomHook/DataFetch';

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
  // const [data, setData] = useState({ hits: [] });
  const [query, setQuery] = useState('redux');
  const [search, setSearch] = useState('redux');
  const [url, setUrl] = useState(
    '/api/news/search?query=redux',
  );
  // const [isLoading, setIsLoading] = useState(false);
  // const [isError, setIsError] = useState(false);
  const [{ data, isLoading, isError }, doFetch] = useHackerNewsApi();

  // const TodoListOne = withTodosEmpty(TodoList);
  // const TodoListTwo = withTodosNull(TodoListOne);
  // const TodoListThree = withLoadingIndicator(TodoListTwo);

  const conditionFn = (props) => !props.todos;

  const EmptyMessage = () =>
    <div>
      <p>You have no Todos.</p>
    </div>

  const LoadingIndicator = () =>
    <div>
      <p>Loading todos ...</p>
    </div>

  // const TodoListWithConditionalRendering = withLoadingIndicator(withTodosNull(withTodosEmpty(TodoList)));
  // const TodoListWithConditionalRendering = withLoadingIndicator(withCondition(withTodosEmpty(TodoList), conditionFn));
  const TodoListWithConditionalRendering = withEither(
    withLoadingIndicator(withTodosEmpty(TodoList)), conditionFn, LoadingIndicator);

  // useEffect(() => {
  //   const fetchData = async () => {
  //     setIsError(false);
  //     setIsLoading(true);

  //     try {
  //       const result = await axios(url);

  //       setData(result.data);
  //     } catch (error) {
  //       setIsError(true);
  //     }

  //     setIsLoading(false);
  //   }

  //   fetchData();
  // }, [url]);

  // useEffect(() => {
  //   const fetchData = async () => {
  //     const result = await fetch(
  //       '/api/news/search?query=redux',
  //     ).then((res) => res.json());
  //     console.log(result);
  //     setData(result);
  //   }

  //   fetchData();
  // }, []);

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
      <form
        onSubmit={(event) => {
          doFetch(`/api/news/search?query=${query}`);

          event.preventDefault();
        }}>
        <input
          type="text"
          value={query}
          onChange={event => setQuery(event.target.value)}
        />
        <button type="submit">Search</button>
      </form>

      {isError && <div>Something went wrong ...</div>}

      {isLoading ? (
        <div>Loading ...</div>
      ) : (
          <ul>
            {
              data.hits.map(item => (
                <li key={item.objectID}>
                  <a href={item.url}>{item.title}</a>
                </li>
              ))
            }
          </ul>
        )}

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
            <Euro key='euro' amount={amount} />
            <Pound key='pound' amount={amount} />
          </div>
        )}
      >
      </Amount>
        Hoc
      <CurrenciesWithAmount amount={amount} />
    </div>
  );

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

}

export default App;


