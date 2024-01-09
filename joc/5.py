import math

d = {
    'Adam': 95,
    'Lisa': 85,
    'Bart': 59
}

print(d.keys())
print(d.items())

print(math.gcd(10, 20))

a = 0
[print(i, end=" ") for i in range(10)]

name =("kiran","bhushan","madan")
print (name[-1]) # ans: madan

print('afdaf')
print('''asdfasdf''')

# Graph = nx.gnp random graph(25,1.0) # complete graph

'''
text = "This is the first sentence. This is the second sentence. And this is the third sentence."
sentences = sent_tokenize(text) # nlp lib that will split the input text in list of sentences

output: ['This is the first sentence.', 'This is the second sentence.', 'And this is the third sentence.']
'''