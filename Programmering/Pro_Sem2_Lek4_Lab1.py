from collections import Counter

text = ('to be or not to be that is the question')
counter = Counter(text.split())
for word, count in sorted(counter):
    print(f'{word:<12}{count}')
