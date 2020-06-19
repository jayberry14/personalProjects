import React from 'react';
import aritcleContent from './Article-Content';
import AritclesList from '../components/ArticlesList';
import Page404 from './404';

const ArticlePage = ({ match }) => {
    const name = match.params.name;
    const article = aritcleContent.find(article => article.name === name);

    if(!article) return <Page404/>

    const otherArticles = aritcleContent.filter(article => article.name !== name);

    return (
        <>
        <h1>{article.title}</h1>
        {article.content.map((paragraph, key) => (
            <p key={key}>{paragraph}</p>
        ))}
        <h2>Other Articles</h2>
            <AritclesList articles={otherArticles}></AritclesList>
        </>
    );
}

export default ArticlePage;