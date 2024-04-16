text = ('John, Ann, James, James, Ann, James, John, Ann, Ann, John, Ann, Ann, James, John, John, Ann, James, James') 

word_counts = {}

for word in text.split(', '):
    if word in word_counts: 
        word_counts[word] += 1  # update existing key-value pair
    else:
        word_counts[word] = 1  # insert new key-value pair

print(word_counts)

