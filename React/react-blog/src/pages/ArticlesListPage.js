import React from 'react';
import articleContent from './Article-Content';
import AritclesList from '../components/ArticlesList';
 
const ArticlesListPage = () => (
    <>
    <h1>Articles List</h1>
    <AritclesList articles={articleContent}></AritclesList>
    </>
);

export default ArticlesListPage;