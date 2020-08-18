import React from 'react';
import './App.css';
import ComponentA from './components/ComponentA';

const multiButton = () => {
  var output = [];
  for (let i = 0; i < 4; ++i) {
    output.push(<button>{i}</button>)
  }
  return output;
}

const getValue = (event) => {
  console.log(event.target.value)
}

function App() {
  return (
    <div>
      <ComponentA theme='dark' />
      {multiButton()}
      <button value={true} onClick={getValue}>Get value</button>
    </div>
  );
}

export default App;
