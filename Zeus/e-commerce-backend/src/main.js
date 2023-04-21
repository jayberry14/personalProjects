import express from 'express';
import bodyParser from 'body-parser';
import MongoClient from 'mongodb';
async function main(){
    /**
     * Connection URI. Update <username>, <password>, and <your-cluster-url> to reflect your cluster.
     * See https://docs.mongodb.com/ecosystem/drivers/node/ for more details
     */
    const uri = "mongodb+srv://Joshua:ProTectOr@h0me#@e-commerce-backend/test?retryWrites=true&w=majority";
    const uri = 'mongodb+srv://Joshua:ProTectOr@h0me#@cluster0-ntrwp.mongodb.net/shop';
  
    try {
        // Connect to the MongoDB cluster
        const client = await MongoClient.connect(uri, { useNewUrlParser: true }, { useUnifiedTopology: true });
        await client.connect();
 
        // Make the appropriate DB calls
        await  listDatabases(client);
 
    } catch (e) {
        console.error(e);
    } finally {
        await client.close();
    }
}

main().catch(console.error);
async function listDatabases(client){
    databasesList = await client.db().admin().listDatabases();
 
    console.log("Databases:");
    databasesList.databases.forEach(db => console.log(` - ${db.name}`));
};