import React from 'react';
import './styles/App.css';
import {
  BrowserRouter as Router,
  Route,
  Switch
} from 'react-router-dom';
import notFound from './views/notFound'
import homePage from './views/homePage'
import AppNav from './components/appNav';


function App() {
  return (
    <Router>
      <div className="App">
      <AppNav />
        <div id="page-body">
          <Switch>
            <Route path="/" component={ homePage } exact/>
            <Route component={ notFound }/>
          </Switch>
        </div>
      </div>
      <div className="footer">
        <footer>
          <div className="a"><a href="/">Contact Us</a><br></br></div>
          <div className="a"><a href="/">Careers</a><br></br></div>
          <div className="a"><a href="/">Privacy Policy</a><br></br></div>
          &copy; 2021 Jayberry Studios
        </footer>
      </div>
    </Router>
  );
}

export default App;
