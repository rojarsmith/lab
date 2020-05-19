import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
//import App from './App';
import * as serviceWorker from './serviceWorker';

const multiButton = () => {
  var output=[];
  for(let i=0;i<4;++i){
    output.push(<button>{i}</button>)
  }
  return output;
}

const getValue = (event) => {
  console.log(event.target.value)
}

ReactDOM.render(
  <React.StrictMode>
    { multiButton() }
    <button value={true} onClick={getValue}>Get value</button>
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();
