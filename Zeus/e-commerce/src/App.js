import React from 'react';
import {
  BrowserRouter as Router,
  Route,
  Switch
} from 'react-router-dom';
import Modal from 'react-modal';
import PageNotFound from './views/PageNotFound';
import HomePage from './views/Home';
import NavBar from './components/NavBar';
import './styles/App.css';



Modal.setAppElement('body');

function App() {
  return (
    <Router>
      <div id="App" className="App">
        <NavBar />
        <div id="page-body">
          <Switch>
            <Route path="/" component={ HomePage } exact/>
            {/* <Route path="/item/:username/:name" component={ username, name }/> */}
            <Route component={ PageNotFound }/>
          </Switch>
        </div>
      </div>
      <div className="footer">
        <footer>&copy; 2020 Hackathon_Gang</footer>
      </div>
    </Router>
  );
}

export default App;
