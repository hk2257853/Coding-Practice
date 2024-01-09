# new learnings: 
# the evaluation formula is count / len(knowledge_base[d]) and not count
# need to print all max (like formula gave same val for 2, print both).
# 2 ways: while traversing keep a list of current maxes. if a greater comes, clear the list n push this n others with this val
# the way their code is

# note in exam don't worry about space n time complexity

kb = {
    'music': ['guitar', 'voilen', 'paino'],
    'drama': ['act', 'style', 'timepass'],
    'random': ['a', 'b', 'c', 'd']
}

def inferenceEngine(kb):
    maxp = 0
    preference = ''
    for c in kb.keys():
        count = 0
        for pref in kb[c]:
            print("do you like", pref, " say y or n")
            ans = input()
            if ans == "y":
                count += 1
        if(count/len(kb[c]) > maxp):
            maxp = count
            preference = c

    return preference

print(inferenceEngine(kb))
    