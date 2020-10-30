import { Component } from 'react';

// Component composition with children prop
class Amount extends Component {
  render() {
    return (
      <div>
        <span>US Dollar: {this.props.amount} </span>

        <button type="button" onClick={this.props.onIncrement}>
          +
        </button>
        <button type="button" onClick={this.props.onDecrement}>
          -
        </button>

        {this.props.children}
      </div>
    );
  }
}

export default Amount;
