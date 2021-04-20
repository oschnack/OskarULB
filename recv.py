"""
Nom: Oskar Schnack
Matricule: 495661
Date: 16/04/2021
But: Le programme sert à decoder des messages qui ont ete crypter et ecrit sur un fichier .txt. Il peut gerer deux typer de cryptage
    I-> cryptage de type Cesar
    II-> cryptage de type Enigma
Résultat: imprime et décode tout nouveau message qui sont écrit dans le fichier donner par l'utilisateur

"""

import copy
import sys
import time
from ctypes import CDLL, c_char_p


def uncaesar(message, decalage, shift):
    """

    :param message: message a décode
    :param decalage: valeur booléen pour avoir le sens du decalage
    :param shift: valeur en int, qui dit de combien nous avons decaler le message
    :return: renvoie le message decoder
    """

    res = ''
    ALPHLEN = 26
    if decalage == 1:  # cas de decalage vers la droite
        for i in message:
            if i == ' ':
                res += i
            else:
                test = ord(i) - shift
                if test < 65:
                    res += chr(test + ALPHLEN)
                elif test > 90:
                    res += chr(test - ALPHLEN)
                else:
                    res += chr(test)
    else:  # cas de decalage vers la gauche
        for i in message:
            if i == ' ':
                res += i
            else:
                test = ord(i) + shift
                if test < 65:
                    res += chr(test + ALPHLEN)
                elif test > 90:
                    res += chr(test - ALPHLEN)
                else:
                    res += chr(test)
    return res[:-1]


def rec_caes(filename, rightshift, shift):
    """
    :param filename: nom du fichier où lire le/les messages
    :param rightshift: sens du décalge
    :param shift: valeur qui indique de combien a été decale le message
    :return: aucun return, print just le message décoder

    Cette fonction ouvre le fichier et lit ligne par ligne les mesage à decoder, elle fait appeller a uncaesar pr le
    décrytpage
    """
    filename = filename
    print("Appuyer sur Ctrl+C quand vous voulez couper la communication")
    with open(filename) as f:
        try:
            while True:
                line = f.readline(8)
                if line:
                    print(f"Nouveau message: {line}", '->', uncaesar(line, rightshift, shift))
                time.sleep(1)

        except KeyboardInterrupt:
            print("Press Ctrl-C to terminate while statement")


def enigma_decode(filename):
    """
    :param filename: Prend le nom du fichier demander
    :return: aucun return, mais la fonction print le message decoder ligne par ligne dans filename

    Decode les messages encode par enigma et fait appel a la librairie dynamique Enigma.so pour la partie décryptage
    """
    enigmalib = CDLL("./enigma.so")
    enigmalib.enigma.restype = c_char_p
    enigmalib.enigma.argstypes = [c_char_p]
    print("Appuyer sur Ctrl+C quand vous voulez couper la communication")
    with open(filename, 'rb') as f:#ouverture du fichier en lecture et de type byte pour permettre un bon
        # format avec Enigmalib
        try: #condition qui permet d'arreter le programme avec un ctrl-c quand on a finit d'envoyer des messages
            while True:
                line = f.readline()
                line_pure = copy.copy(line.decode("utf-8"))
                if line:
                    print(f"Nouveau message:", line_pure, '->',  enigmalib.enigma(line).decode("utf-8"))

                time.sleep(1)

        except KeyboardInterrupt:
            print("Press Ctrl-C to terminate while statement")


def main():
    if sys.argv[1] == "Enigma":
        filename: str = sys.argv[2]
        print(f"Communication chiffrée avec Enigma via {filename}")
        enigma_decode(filename)
    else:
        if len(sys.argv) < 4:
            print("Utilisation: python recv.py G|D décalage fichier.", file=sys.stderr)
            sys.exit(1)
        if sys.argv[1] not in ("G", "D"):
            print(f"Le premier argument doit être G ou D, {sys.argv[1]} est incorrect", file=sys.stderr)
            sys.exit(1)
        right_shift: bool = sys.argv[1] == "D"
        shift: int = int(sys.argv[2])
        filename: str = sys.argv[3]
        print(f"Communication chiffrée avec César {sys.argv[1]} {shift} via {filename}")
        rec_caes(filename, right_shift, shift)


if __name__ == "__main__":
    main()
