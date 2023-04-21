import React from 'react';
import 'bootstrap/dist/css/bootstrap.min.css';
import { Navbar, Nav } from 'react-bootstrap';

const AppNav = () => {

    return (  
    <Navbar collapseOnSelect expand="lg" bg="" variant="dark">
        <Navbar.Brand href="/">Jayberry Studios</Navbar.Brand>
        <Navbar.Toggle aria-controls="responsive-navbar-nav" />
        <Navbar.Collapse id="responsive-navbar-nav">
            <Nav className="mr-auto">
                <Nav.Link href="#">Home</Nav.Link>
                <Nav.Link href='#Professional'>Professional</Nav.Link>
                <Nav.Link href="#Experience">Experience</Nav.Link>
                <Nav.Link href="#Portfolio">Portfolio</Nav.Link>
                <Nav.Link href="#Contact">Contact</Nav.Link>
            </Nav>
        </Navbar.Collapse>
    </Navbar>
)};

export default AppNav;