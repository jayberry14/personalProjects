import React from 'react';
import '../Modal.css';

const ItemInfoModal = ({ name, price, description, imageUrl, id }) => (
    <>
    <button type="button" class="btn trigger" data-toggle="modal" data-target="#exampleModal"> OFFER </button>
        <div class="modal fade" id="exampleModal" tabindex="-1" role="dialog" aria-labelledby="exampleModalLabel" aria-hidden="true">
            <div class="modal-dialog" role="document">
                <div class="modal-content">
                    <div class="modal-header "> <button type="button" class="close" data-dismiss="modal" aria-label="Close"> <span aria-hidden="true">&times;</span> </button> </div>
                    <div class="modal-body p-0 row">
                        <div class="col-12 col-lg-4 ad p-0"><img src={imageUrl} width="100px" height="100px" alt="productPhoto"></img></div>
                        <div class="details col-12 col-lg-8">
                            {/* <div class="heading d-flex">
                                <div class="logo"></div>
                                <div class="off"></div>
                            </div> */}
                            <h2>{name}</h2>
                            <p><small class="text-muted">{description}<br /><strong>${price}</strong></small></p>
                            {/* <div class="text-muted hurry"><small>Hurry. book now. Limited time offer</small></div> */}
                            {/* <div class="d-flex mt-2 mb-5"> <button type="button" class="btn booking"><label><strong>Books<br /></strong><small class="text-muted">Online</small></label></button> <button type="button" class="btn booking ml-4"><label><strong>Store<br /></strong><small class="text-muted">Locator</small></label></button> </div> */}
                        </div>
                    </div>
                </div>
            </div>
        </div>
        </>
);

export default ItemInfoModal;
