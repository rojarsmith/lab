import React from 'react';
import './App.css';
import ComponentA from './components/ComponentA';
import { MyComponent, FancyButton } from './components/CreateForwardRef';

const multiButton = () => {
  var output = [];
  for (let i = 0; i < 4; ++i) {
    output.push(<button key={i}>{i}</button>)
  }
  return output;
}

const getValue = (event) => {
  console.log(event.target.value)
}

function App() {
  const ref = React.createRef();

  return (
    <div>
      <FancyButton ref={ref}>Click me!</FancyButton>
      <MyComponent />
      <ComponentA theme='dark' />
      {multiButton()}
      <button value={true} onClick={getValue}>Get value</button>
    </div>
  );
}

export default App;
