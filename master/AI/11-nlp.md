## language model

it's a probability distribution of sequence of words

problems:
* natural languages are not finite
* they evolve over time
* ambiguity

models
* ngram --> text prediction, text generation, spell checking
* bag of words --> text classification, sentiment analysis
* word2vec --> text classification, text generation, document clustering

## n-gram (characters)

language model describing the probability distribution of n-grams in a text
* P("d","o","g")
* with markov chain -->  P("g"|"o","d")

smoothing
* ngram works better if there are a lot of evidences of an ngram
* giving small probabilities to unseen n-grams, done with:
    * laplace smoothing --> P(ngram) = 1/(n+2)
    * backoff smoothing --> P(ngram) = P(ngram-1)

## bag of words

* language model assigning frequencies to each word
* used for text classification and representation
* semantics between words is given by a dictionary --> hard to mantain

## word2vec

each word is described by a vector containing the probability of being near a certain word

can be used in 2 ways
* cbow --> uses the context to learn a word
* skip gram --> uses a word to predict the context

## subword model

describes subwords instead of normal words, since a word has many different forms

algo
* init the dictionary entries (only characters)
* find the most frequent pair of adjacent entries
* create a new subword and add it in the dictionary
* replace the pairs with the new subword
* repeat

## transformer (seq2seq)

deep language model, from a given text input it produces an output (transduction)

training phase
* input embedding --> encode text as word2vec
* positional encoding --> encode the position of each word in the vector

attention algorithm (transduction)
* compute the soft table of a query
* softmax the result to get the probability distribution

stacking encoding blocks
* pipeline of transformers

## model pre training

pretrain a model to starting point, so that it can be specialized in something else later, 3 approaches
* decoder
    * it learns how to predict the next word (unsupervised)
    * unidirectional, only takes into account the previous words
    * GPT
* masked via encoder
    * it learns how to guess the right word in a given context (supervised)
    * bidirectional, takes into account the words around the mask
    * google BERT
* transformer