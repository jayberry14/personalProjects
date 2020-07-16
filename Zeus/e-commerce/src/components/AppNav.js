import React from 'react';
import { Link } from 'react-router-dom';
import 'bootstrap/dist/css/bootstrap.min.css';
import { Navbar, Nav, NavDropdown } from 'react-bootstrap';

const AppNav = () => ( //className="btn btn-primary btn-rounded btn-sm my-0"
    // <Navbar className="navbar navbar-inverse">
    //     <div className="container-fluid">
    //         <div className="navbar-header">
    //             <button type="button" className="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
    //                 <span className="icon-bar"/>
    //                 <span className="icon-bar"/>
    //                 <span className="icon-bar"/>
    //             </button>
    //             <Link className="navbar-brand" to="/">Elevate Your Web Store!</Link>
    //         </div>
    //         <div className="collapse navbar-collapse" id="myNavbar">
    //             <ul className="nav navbar-nav">
    //                 <li>
    //                     <Link to="/manageProducts">Manage Your Products</Link>
    //                 </li>
    //                 <li>
    //                     <Link to="/profile">Profile</Link>
    //                 </li>
    //             </ul>
    //             <ul className="nav navbar-nav navbar-right">
    //                 <li><Link to="/"><span className="glyphicon glyphicon-user"></span> Sign Up</Link></li>
    //                 <li><Link to="/"><span className="glyphicon glyphicon-log-in"></span> Login</Link></li>
    //             </ul>
    //         </div>
    //     </div>
    // </Navbar>   
    <Navbar collapseOnSelect expand="lg" bg="dark" variant="dark">
        <Navbar.Brand href="#home">React-Bootstrap</Navbar.Brand>
        <Navbar.Toggle aria-controls="responsive-navbar-nav" />
        <Navbar.Collapse id="responsive-navbar-nav">
            <Nav className="mr-auto">
            <Nav.Link href="#features">Features</Nav.Link>
            <Nav.Link href="#pricing">Pricing</Nav.Link>
            <NavDropdown title="Dropdown" id="collasible-nav-dropdown">
                <NavDropdown.Item href="#action/3.1">Action</NavDropdown.Item>
                <NavDropdown.Item href="#action/3.2">Another action</NavDropdown.Item>
                <NavDropdown.Item href="#action/3.3">Something</NavDropdown.Item>
                <NavDropdown.Divider />
                <NavDropdown.Item href="#action/3.4">Separated link</NavDropdown.Item>
            </NavDropdown>
        </Nav>
        <Nav>
            <Nav.Link href="#deets">More deets</Nav.Link>
            <Nav.Link eventKey={2} href="#memes">
                Dank memes
            </Nav.Link>
        </Nav>
    </Navbar.Collapse>
</Navbar>
);

export default AppNav;