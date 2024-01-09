knowledge_base = {
    'italian': ['pasta', 'tomatoes', 'olive oil'],
    'mexican': ['tortillas', 'beans', 'spices'],
    'indian': ['curry', 'rice', 'naan bread'],
    'chinese': ['soy sauce', 'rice noodles', 'ginger'],
    'mediterranean': ['grilled vegetables', 'feta cheese', 'olives']
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

    cuisines = []
    for d in knowledge_base.keys(d):
        if prob[d] == maxprob:
            cuisines.append(d)

    print()
    print("Recommended cuisines based on your preferences: ", end="")
    for cuisine in cuisines:
        print(cuisine, end=", ")


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