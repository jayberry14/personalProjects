std::vector<int> isZigzag(std::vector<int> numbers) {
    int tripleSize = numbers.size() - 2;
    std::vector<int> triples;
    for (int i = 0; i < tripleSize; i++) 
    {
        if ((numbers[i] < numbers[i + 1]) && (numbers[i + 1] > numbers[i + 2]))
        {
            triples.push_back(1);
            cout << "Triples at [" << i << "] is: " << triples[i] << endl;
        }
        else if ((numbers[i] > numbers[i + 1]) && (numbers[i + 1] < numbers[i + 2]))
        {
            triples.push_back(1);
            cout << "Triples at [" << i << "] is: " << triples[i] << endl;
        }
        else
        {
            triples.push_back(0);
            cout << "Triples at [" << i << "] is: " << triples[i] << endl;
        }
    }
    return triples;
}
