import { Component } from 'react';

// const Euro = ({ amount }) => <p>Euro: {amount * 0.86}</p>;

// const Pound = ({ amount }) => <p>Pound: {amount * 0.76}</p>;

// Lifting State
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
            </div>
        );
    }
}

export default Amount;
