def minion_game(s):
    stuart = 0
    kevin = 0
    for i in range(len(s)):
        if s[i] in ['A', 'I', 'U', 'E', 'O']:
            kevin = kevin + len(s) - i
        else:
            stuart = stuart + len(s) - i
    if stuart > kevin:
        print('Stuart', stuart)
    elif stuart < kevin:
        print('Kevin', kevin)
    else:
        print('Draw')

if __name__ == '__main__':
    s = input()
    minion_game(s)