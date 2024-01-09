knowledge_base={
    'flu':['muscle pain','cough','fever','runny nose','sneezing','sore throat'],
    'tuberculosis':['chest pain','cough','fever','fatigue'],
    'coronavirus':['loss of taste','loss of smell','sore throat','cough','fever','shortness of breath']
}

def inference(sym):
    prob={}
    for d in knowledge_base.keys():
        cnt=0
        for s in knowledge_base[d]:
            if s in sym:
                cnt+=1
        prob[d]=cnt/len(knowledge_base[d])
    maxprob=0
    for d in knowledge_base.keys():
        if prob[d]>maxprob:
            maxprob=prob[d]

    diseases=[]
    for d in knowledge_base.keys():
        if prob[d]==maxprob:
            diseases.append(d)

    print()
    print("You may have the following diseases: ",end="")
    for d in diseases:
        print(d,end=", ")        


def askquestions():
    quest=set()
    for d in knowledge_base.keys():
        for sym in knowledge_base[d]:
            quest.add(sym)
    quest=list(quest)
    symptoms=[]
    for sym in quest:
        ans=input(f"Do you have {sym}? [y/n]: ")
        if ans=="y":
            symptoms.append(sym)
    return symptoms        

sym=askquestions()
inference(sym)