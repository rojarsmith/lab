import { Component } from 'react';

// Render prop component hoc
const withAmount = currencyComponents =>
  class AmountRenderPropHocComponent extends Component {
    constructor(props) {
      super(props);

      this.state = {
        amount: 0,
      };
    }

    onIncrement = () => {
      this.setState(state => ({ amount: state.amount + 1 }));
    };

    onDecrement = () => {
      this.setState(state => ({ amount: state.amount - 1 }));
    };

    render() {
      return (
        <div>
          <span>US Dollar: {this.state.amount} </span>

          <button type="button" onClick={this.onIncrement}>
            +
        </button>
          <button type="button" onClick={this.onDecrement}>
            -
        </button>

          {currencyComponents.map(CurrencyComponent => (
            <CurrencyComponent amount={this.state.amount} />
          ))}
        </div>
      );
    }
  }

export default withAmount;
