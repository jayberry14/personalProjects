import React from 'react';
import { Title, Professional, Experience, Portfolio, Contact } from '../styles/HomeStyles';
import { Button } from 'react-bootstrap';

window.onscroll = function() { showTopButton() };
function showTopButton() {
    if (document.body.scrollTop > 500 || document.documentElement.scrollTop > 500) {
        document.getElementById("topBtn").style.display = 'block';
    }
    else {
        document.getElementById("topBtn").style.display = 'none';
    }
};

window.onclick = function() { goToTop() };
function goToTop() {
    document.body.scrollTop = 0;
    document.documentElement.scrollTop = 0;
};

const homePage = () => {
    return(
        <>
            <Button id="topBtn" title="Go to Top">Back to Top</Button>
            {/* <HeroPicture>
                <HeroText>

                </HeroText>
            </HeroPicture> */}
            <Title>
                I'm
                Josh
                Mayberry.
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
            </Title>
            <Professional id='Professional'>
                Here are my skills.
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
            </Professional>
            <Experience id='Experience'>
                This is my work history.
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
            </Experience>
            <Portfolio id='Portfolio'>
                Check out my projects.
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
            </Portfolio>
            <Contact id='Contact'>
                Please fill out this form.
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
                <br></br>
            </Contact>
        </>
    )
};

export default homePage;