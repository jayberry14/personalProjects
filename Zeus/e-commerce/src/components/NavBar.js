import React from 'react';
import { Link } from 'react-router-dom';
import 'bootstrap/dist/css/bootstrap.min.css';

const NavBar = () => ( //className="btn btn-primary btn-rounded btn-sm my-0"
    <nav className="navbar navbar-inverse">
        <div className="container-fluid">
            <div className="navbar-header">
                <button type="button" className="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
                    <span className="icon-bar"></span>
                    <span className="icon-bar"></span>
                    <span className="icon-bar"></span>
                </button>
                <Link className="navbar-brand" to="/">Elevate Your Web Store!</Link>
            </div>
            <div className="collapse navbar-collapse" id="myNavbar">
                <ul className="nav navbar-nav">
                    <li>
                        <Link to="/manageProducts">Manage Your Products</Link>
                    </li>
                    <li>
                        <Link to="/profile">Profile</Link>
                    </li>
                </ul>
                <ul className="nav navbar-nav navbar-right">
                    <li><Link to="/"><span className="glyphicon glyphicon-user"></span> Sign Up</Link></li>
                    <li><Link to="/"><span className="glyphicon glyphicon-log-in"></span> Login</Link></li>
                </ul>
            </div>
        </div>
    </nav>   
);

export default NavBar;