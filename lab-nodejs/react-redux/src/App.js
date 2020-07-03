import React, { Component } from 'react';
import './App.css';
import { INCREMENT, DECREMENT } from './redux/actions';

class App extends Component {

  increment = () => {
    const number = this.select.value * 1;
    this.props.store.dispatch({ type: INCREMENT, data: number });
  }

  decrement = () => {
    const number = this.select.value * 1;
    this.props.store.dispatch({ type: DECREMENT, data: number });
  }

  render() {
    const { number, name } = this.props.store.getState();
    console.log(this.props.store.getState());
    return (
      <div className="App">
        <p>
          click {number} times ...... by {name}
        </p>
        <div>
          <select ref={select => this.select = select}>
            <option value="1">1</option>
            <option value="2">2</option>
            <option value="10">10</option>
          </select>
          <button onClick={this.increment}>+</button>
          <button onClick={this.decrement}>-</button>
        </div>
      </div>
    );
  }
}


export default App;
