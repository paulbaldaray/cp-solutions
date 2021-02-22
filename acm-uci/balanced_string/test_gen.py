import string, random
n = 10**5
letters = [c for c in string.ascii_lowercase+string.ascii_uppercase]
random.shuffle(letters)
letters = letters[:-1]
# edgecase=n*'a'+'abAcBdCeDfEgFhGiHjIkJlKmLnMoNpOqPrQsRtSuTvUwVyWxYzX'
# print(edgecase)
print(''.join([letters[random.randrange(len(letters))] for i in range(n)]))
