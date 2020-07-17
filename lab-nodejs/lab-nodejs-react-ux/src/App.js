import React, { useState } from 'react';
import { Route, Switch, withRouter, Link } from 'react-router-dom';
import HamburgerMenu from 'react-hamburger-menu';
import Comp1 from './components/Comp1';
import Comp2 from './components/Comp2';
import logo from './logo.svg';
import './App.css';


function App() {
  const [open, setOpen] = useState(false);

  const handleClick = event => setOpen(!open);
  // const handleClick = (props) => {
  //   setOpen(!open);
  // }

  return (
    <div className="App">
      <header className="App-header">
        <div>
          <ul className="uk-navbar-nav">
            <li>
              <Link to="/">Page 1</Link>
            </li>
            <li>
              <Link to="/page2">Page 2</Link>
            </li>
          </ul>
        </div>
        <div>
          <HamburgerMenu
            isOpen={open}
            menuClicked={handleClick}
            width={18}
            height={15}
            strokeWidth={1}
            rotate={0}
            color='black'
            borderRadius={0}
            animationDuration={0.5} />
        </div>
        <div class="navicon">
          {/* <a class="nav-toggle" href="#"><span></span></a> */}

        </div>
      </header>
      <div>
        <Switch>
          <Route path="/" component={Comp1} exact />
          <Route path="/page2" component={Comp2} exact />
        </Switch>
      </div>
    </div>
  );
}

export default App;
