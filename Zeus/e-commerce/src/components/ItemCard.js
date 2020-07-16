import React from 'react';
import { Link } from 'react-router-dom';
import { Card, Face1, Face2, Face1Content, Face2ContentA, Face2ContentP , ContentImg, FaceH3 } from '../styles/Styles';

const ItemCard = ({ name, price, description, imageUrl, id, key }) => (
    <Card key={key}>
        <Face1>
            <Face1Content>
                <ContentImg src={imageUrl} alt="Product"/>
                <FaceH3>{ name }</FaceH3>
            </Face1Content>
        </Face1>
        <Face2>
            <div>
                <Face2ContentP>${price}</Face2ContentP><br></br>
                <Face2ContentP>{description}</Face2ContentP><br></br>
                <Face2ContentA to={`/item/${id}`}>Item Info</Face2ContentA>
            </div>
        </Face2>
    </Card>
);

export default ItemCard;