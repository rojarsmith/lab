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

  return (
    <div className="App">
      <section class="navigation">
        <header className="App-header">
          <div>
            <nav>
              <ul className="nav-menu-list header-nav">
                <li>
                  <Link to="/">Page 1</Link>
                </li>
                <li>
                  <Link to="/page2">Page 2</Link>
                </li>
              </ul>
            </nav>
          </div>
          <div class="nav-menu-button">
            <HamburgerMenu
              isOpen={open}
              menuClicked={handleClick}
              width={36}
              height={30}
              strokeWidth={3}
              rotate={0}
              color='black'
              borderRadius={3}
              animationDuration={0.5} />
          </div>
        </header>
        <div>
          <Switch>
            <Route path="/" component={Comp1} exact />
            <Route path="/page2" component={Comp2} exact />
          </Switch>
        </div>
      </section>
    </div>
  );
}

export default App;
