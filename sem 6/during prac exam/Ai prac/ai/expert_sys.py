knowledge_base = {
    'commonflu': ['muscle pain', 'cough', 'fever', 'runny nose', 'sneezing', 'sore throat'],
    'coronavirus': ['loss of taste', 'loss of smell', 'sore throat', 'cough', 'fever', 'shortness of breath']
}# dictionary => disease: [symptoms]

def inference(symptoms):

    probability = {}

    # assign probabilities to diseases
    for disease in knowledge_base.keys():
        count = 0
        for symptom in knowledge_base[disease]:
            if symptom in symptoms:
                count += 1
        probability[disease] = count / len(knowledge_base[disease])

    # find max prob disease
    max_probability = 0
    for disease in probability.keys():
        if probability[disease] > max_probability:
            max_probability = probability[disease]

    #create string of diseases with max probability
    diseases = ''
    for d in probability.keys():
        if probability[d] == max_probability:
            diseases += d + ', '

    diseases = list(diseases)
    diseases[-2] = '.'
    diseases = ''.join(diseases)

    if max_probability == 1:
        print('You are having ' + diseases)
    elif max_probability > 0:
        print('You may have ' + diseases)
    else:
        print('You are not having any disease')

def ask_questions():
    symptoms = []
    questions = []

    for disease in knowledge_base.keys():
        questions += knowledge_base[disease] # adding all diseases in questions

    questions = list(set(questions))

    print('Please answer the following questions: ')
    for question in questions:
        answer = input(f'Do you have {question}? [yes/no]: ')
        if answer.lower() == 'yes':
            symptoms.append(question)
        print('')

    return symptoms

symptoms = ask_questions()
inference(symptoms)