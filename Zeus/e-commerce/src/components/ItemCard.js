import React from 'react';
import { Link } from 'react-router-dom';

const ItemCard = ({ name, price, description, imageUrl, id, key }) => (
    <div key={key} className="card">
        <div className="face face1">
            <div className="content">
                <img src={imageUrl} alt="Product"></img>
                <h3>{ name }</h3>
            </div>
        </div>
        <div className="face face2">
            <div className="content">
                <p>${price}</p><br></br>
                <p>{description}</p><br></br>
                <Link to={`/item/${id}`}>Item Info</Link>
            </div>
        </div>
    </div>
);

export default ItemCard;