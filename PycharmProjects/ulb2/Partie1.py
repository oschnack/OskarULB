POSITION = {'A1': 0, 'B1': 0, 'C1': 0, 'D1': 0,
            'A2': 0, 'B2': 0, 'C2': 0, 'D2': 0,
            'A3': 0, 'B3': 0, 'C3': 0, 'D3': 0,
            'A4': 0, 'B4': 0, 'C4': 0, 'D4': 0}


def joueur_1(posj1):
    j = []
    j1 = posj1
    res = ''
    for e in posj1:
        j.append(e)
    if j[0] != 'A' and j[0] != 'B' and j[0] != 'C' and j[0] != 'D' or j[1] != '0' and j[1] != '1' \
            and j[1] != '2' and j[1] != '3' and j[1] != '4':
        print("Case non valide. Veuillez réessayer")
        res = None
    elif j1 in POSITION:
        res = j1
    return res


def joueur_2(posj2):
    j = []
    j2 = posj2
    res = ''
    for e in posj2:
        j.append(e)
    if j[0] != 'A' and j[0] != 'B' and j[0] != 'C' and j[0] != 'D' or j[1] != '0' and j[1] != '1' and j[1] != '2' \
            and j[1] != '3' and j[1] != '4':
        print("Case non valide. Veuillez réessayer.")
        res = None
    elif j2 in POSITION:
        res = j2
    return res


def print_plateau(plateau):
    MATR_PLAT = [[POSITION['A1'], POSITION['B1'], POSITION['C1'], POSITION['D1']],
                 [POSITION['A2'], POSITION['B2'], POSITION['C2'], POSITION['D2']],
                 [POSITION['A3'], POSITION['B3'], POSITION['C3'], POSITION['D3']],
                 [POSITION['A4'], POSITION['B4'], POSITION['C4'], POSITION['D4']]]
    for i in range(4, 0, -1):
        print(i, ' ', end='')
        for j in MATR_PLAT[i - 1][:4]:
            if j == 0:
                print('_', ' ', end='')
            elif j == 1:
                print('X', ' ', end='')
            elif j == 2:
                print('O', ' ', end='')
        print()
        print()
    print()
    print('  ', 'A ', 'B ', 'C ', 'D ')


def condition_victoire_joueur_1(game):
    if POSITION['A1'] == 1 and POSITION['A1'] == 1 and POSITION['A1'] == 1 and POSITION['A1'] == 1:
        victoire = 1
    elif POSITION['B1'] == 1 and POSITION['B1'] == 1 and POSITION['B1'] == 1 and POSITION['B1'] == 1:
        victoire = 1
    elif POSITION['C1'] == 1 and POSITION['A1'] == 1 and POSITION['A1'] == 1 and POSITION['A1'] == 1:
        victoire = 1
    elif POSITION['D1'] == 1 and POSITION['D1'] == 1 and POSITION['D1'] == 1 and POSITION['D1'] == 1:
        victoire = 1
    elif POSITION['A1'] == 1 and POSITION['A2'] == 1 and POSITION['A3'] == 1 and POSITION['A4'] == 1:
        victoire = 1
    elif POSITION['B1'] == 1 and POSITION['B2'] == 1 and POSITION['B3'] == 1 and POSITION['B4'] == 1:
        victoire = 1
    elif POSITION['C1'] == 1 and POSITION['C2'] == 1 and POSITION['C3'] == 1 and POSITION['C4'] == 1:
        victoire = 1
    elif POSITION['D1'] == 1 and POSITION['D2'] == 1 and POSITION['D3'] == 1 and POSITION['D4'] == 1:
        victoire = 1
    elif POSITION['A1'] == 1 and POSITION['B2'] == 1 and POSITION['C3'] == 1 and POSITION['D4'] == 1:
        victoire = 1
    elif POSITION['A4'] == 1 and POSITION['B3'] == 1 and POSITION['C2'] == 1 and POSITION['D1'] == 1:
        victoire = 1
    else:
        victoire = 0
    return victoire


def condition_victoire_joueur_2(game):
    if POSITION['A1'] == 2 and POSITION['A1'] == 2 and POSITION['A1'] == 2 and POSITION['A1'] == 2:
        victoire = 2
    elif POSITION['B1'] == 2 and POSITION['B1'] == 2 and POSITION['B1'] == 2 and POSITION['B1'] == 2:
        victoire = 2
    elif POSITION['C1'] == 2 and POSITION['A1'] == 2 and POSITION['A1'] == 2 and POSITION['A1'] == 2:
        victoire = 2
    elif POSITION['D1'] == 2 and POSITION['D1'] == 2 and POSITION['D1'] == 2 and POSITION['D1'] == 2:
        victoire = 2
    elif POSITION['A1'] == 2 and POSITION['A2'] == 2 and POSITION['A3'] == 2 and POSITION['A4'] == 2:
        victoire = 2
    elif POSITION['B1'] == 2 and POSITION['B2'] == 2 and POSITION['B3'] == 2 and POSITION['B4'] == 2:
        victoire = 2
    elif POSITION['C1'] == 2 and POSITION['C2'] == 2 and POSITION['C3'] == 2 and POSITION['C4'] == 2:
        victoire = 2
    elif POSITION['D1'] == 2 and POSITION['D2'] == 2 and POSITION['D3'] == 2 and POSITION['D4'] == 2:
        victoire = 2
    elif POSITION['A1'] == 2 and POSITION['B2'] == 2 and POSITION['C3'] == 2 and POSITION['D4'] == 2:
        victoire = 2
    elif POSITION['A4'] == 2 and POSITION['B3'] == 2 and POSITION['C2'] == 2 and POSITION['D1'] == 2:
        victoire = 2
    else:
        victoire = 0
    return victoire


def tour_j1(o):
    res = None
    while res is None:
        print_plateau('o')
        j1 = str(input("Joueur1>"))
        res = joueur_1(j1)
    POSITION[res] = 1
    if condition_victoire_joueur_1(POSITION) == 1:
        print("Victoire de joueur 1")
        print_plateau(POSITION)
        res = True
    elif condition_victoire_joueur_2(POSITION) == 2:
        print("Victoire de joueur 2")
        print_plateau(POSITION)
        res = True
    else:
        print_plateau(POSITION)
        res = False
    return res


def tour_j2(o):
    res = None
    while res is None:
        j2 = str(input("Joueur1>"))
        res = joueur_2(j2)
    POSITION[res] = 2
    if condition_victoire_joueur_2(POSITION) == 2:
        print("Victoire de joueur 2")
        print_plateau(POSITION)
        res = True
    elif condition_victoire_joueur_1(POSITION) == 1:
        print("Victoire de joueur 1")
        print_plateau(POSITION)
        res = True
    else:
        print_plateau(POSITION)
        res = False
    return res


tour_j1('o')

