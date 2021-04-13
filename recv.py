import sys
import time


def uncaesar(message, decalage, shift):
    """

    :param message: message a decode
    :param decalage: valeur booleen pour avoir le sens du decalage
    :param shift: valeur en int, qui dit de combien nous avons decaler le message
    :return:
    """

    res = ''
    ALPHLEN = 26
    if decalage == 1:  # cas de droite
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
    else:  # cas de gauche
        for i in message:
            if i == ' ':
                res += i
            else:
                test = ord(i) + shift
                if test < 65:
                    res += chr(test - ALPHLEN)
                elif test > 90:
                    res += chr(test + ALPHLEN)
                else:
                    res += chr(test)
    return res[:-1]


def rec_caes(filename, rightshift, shift):
    filename = filename
    print("Appuyer sur Ctrl+C quand vous voulez couper la communication")
    with open(filename) as f:
        try:
            while True:
                line = f.readline()
                if line:
                    print(f"Nouveau message: {line}", '->', uncaesar(line, rightshift, shift))
                time.sleep(1)

        except KeyboardInterrupt:
            print("Press Ctrl-C to terminate while statement")


def enigma(filename):
    print("Appuyer sur Ctrl+C quand vous voulez couper la communication")
    with open(filename) as f:
        try:
            while True:
                line = f.readline()
                if line:
                    print(f"Nouveau message: {line}", '->', line)  # ->> rajouter enigma apres avec la force de la
                    # bibliotheke
                time.sleep(1)

        except KeyboardInterrupt:
            print("Press Ctrl-C to terminate while statement")


def main():
    """
    if (sys.argv[0] == "enigma"):
        filename: str = sys.argv[2]
        fonction = enigma.cpp
        print(f"Communication chiffrée avec Enigma via {filename}")
        enigma(filename)

    """
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
    rec_caes(filename,right_shift, shift)


if __name__ == "__main__":
    main()
