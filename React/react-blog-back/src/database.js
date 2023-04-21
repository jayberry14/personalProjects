import mongodb from 'mongodb';
const MongoClient = mongodb.MongoClient;

const mongoConnect = (callBack) => {
    MongoClient.connect(
        'mongodb+srv://Joshua:ProTectOr@h0me#@joshcluster-k5d58.mongodb.net/test?retryWrites=true&w=majority'
    )
        .then(client => {
            console.log('Connected!');
            callback(client);
        })
        .catch(err => {
            console.log(err);
        });
};

module.exports = mongoConnect; 

