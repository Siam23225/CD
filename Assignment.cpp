!pip install nltk
import nltk
from nltk import ngrams
from collections import defaultdict, Counter
from google.colab import files

nltk.download('punkt')

uploaded = files.upload()

file_name = list(uploaded.keys())[0]
try:
    with open(file_name, 'r', encoding='utf-8') as file:
        text = file.read()
except FileNotFoundError:
    print(f"File not found: {file_name}")
    raise

tokens = nltk.word_tokenize(text.lower())
)
bigrams = list(ngrams(tokens, 2))

bigram_model = defaultdict(Counter)
for w1, w2 in bigrams:
    bigram_model[w1][w2] += 1

def predict_next_word(word):
    next_word_counter = bigram_model[word]
    if next_word_counter:
        return next_word_counter.most_common(5)
    else:
        return "No prediction available"

while True:

    user_input = input("Enter a word to predict the next word (or type 'exit' to quit): ").lower()

    if user_input == 'exit':
        break

    predictions = predict_next_word(user_input)

    print(f"Next word predictions for '{user_input}': {predictions}")
