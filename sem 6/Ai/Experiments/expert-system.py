knowledge_base = {
    'action': ['explosions', 'fight scenes', 'car chases'],
    'comedy': ['humor', 'laughs', 'funny dialogue'],
    'drama': ['emotional', 'intense', 'character development'],
    'romance': ['love story', 'heartwarming', 'chemistry'],
    'horror': ['scary', 'suspenseful', 'jump scares']
}

def inference(prefs):
    prob = {}
    for d in knowledge_base.keys():
        cnt = 0
        for s in knowledge_base[d]:
            if s in prefs:
                cnt += 1
        prob[d] = cnt / len(knowledge_base[d])
    
    maxprob = max(prob.values())

    genres = []
    for d in knowledge_base.keys():
        if prob[d] == maxprob:
            genres.append(d)

    print()
    print("Recommended genres based on your preferences: ", end="")
    for genre in genres:
        print(genre, end=", ")


def ask_preferences():
    preferences = set()
    for d in knowledge_base.keys():
        for pref in knowledge_base[d]:
            preferences.add(pref)
    preferences = list(preferences)
    prefs = []
    for pref in preferences:
        ans = input(f"Do you like {pref}? [y/n]: ")
        if ans == "y":
            prefs.append(pref)
    return prefs

user_prefs = ask_preferences()
inference(user_prefs)
