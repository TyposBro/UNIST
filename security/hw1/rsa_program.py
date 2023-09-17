import argparse
import math

# *1. RSA Key Generation


def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def generate(p, q):
    # Step 1: Compute n and phi
    mod = p * q  # Modulus for both the Private and Public keys
    phi = (p-1)*(q-1)  # Euler's totient function

    # Step 2: Choose e
    e = 3
    while (e < phi):
        if (gcd(e, phi) == 1):
            break
        else:
            e += 1

    # Step 3: Compute d
    for i in range(2, phi):
        # print(f'i: {i}')
        if (math.fmod((e*i), phi) == 1):
            d = i
    return (e, d, mod, phi)


def print_generated_keys(e, d, mod, phi):
    print(f'RSA key pair generated:')
    print(f'n={mod}')
    print(f'e={e}')
    print(f'd={d}')
    print(f'phi={phi}')


def print_generated_keys_to_file(e, d, mod):
    # Write the public key to a file
    with open('public_key.txt', 'w') as f:
        f.write(f'n={mod}\n')
        f.write(f'e={e}')
        f.close()
    # Write the private key to a file
    with open('private_key.txt', 'w') as f:
        f.write(f'n={mod}\n')
        f.write(f'd={d}')
        f.close()


# *2. RSA Encryption & Descryption


def char_to_hex(char):
    return hex(ord(char))


def read_plaintext(plaintext):
    with open(plaintext, 'r') as file:
        data = file.read()
    return data


def read_and_parse_public_key(public_key):
    obj = {}
    with open(public_key, 'r') as file:
        for line in file:
            # Remove any newline characters
            line = line.strip()
            # Split the line on the equals sign
            key, value = line.split('=')
            obj[key] = value
    return obj


def print_ciphertext(ciphertext):
    print(f'Ciphertext: {ciphertext}')

# print hex ciphertext list to terminal


def print_ciphertext(ciphertext):
    txt = ""
    for i in ciphertext:
        if i == ciphertext[-1]:
            txt += f'{i}'
            break
        txt += f'{i} '
    print(txt)


def write_ciphertext_to_file(ciphertext, output):
    with open(output, 'w') as f:
        for i in ciphertext:
            if i == ciphertext[-1]:
                f.write(f'{i}')
                break
            f.write(f'{i} ')
        f.close()


# Driver code
parser = argparse.ArgumentParser(description='RSA Key Generator')
# Add arguments
# Args for 1st part of the assignment
parser.add_argument('--generate-key', action='store_true',
                    help='Generate RSA key')
parser.add_argument('--p', type=int, help='Prime number p')
parser.add_argument('--q', type=int, help='Prime number q')

# Args for 2nd part of the assignment
parser.add_argument("--encrypt", type=str, help="Path to the plaintext file.")
parser.add_argument("--public-key", type=str,
                    help="Path to the public key file.")
parser.add_argument("--output", type=str,
                    help="Path to the output ciphertext file.")

# Args for 3rd part of the assignment

# Parse the arguments
args = parser.parse_args()

if args.generate_key:
    # Args for 1st part of the assignment
    p = args.p
    q = args.q
    # generate keys using p and q
    (e, d, mod, phi) = generate(p, q)
    # print keys
    print_generated_keys(e, d, mod, phi)
    # print keys to file
    print_generated_keys_to_file(e, d, mod)

if args.encrypt:
    # Args for 2nd part of the assignment
    encrypt = args.encrypt
    public_key = args.public_key
    output = args.output

    # read plaintext
    plaintext = read_plaintext(encrypt)
    # read public key
    public_key_obj = read_and_parse_public_key(public_key)
    plaintext_ascii = [ord(c) for c in plaintext]
    # encrypt plaintext
    ciphertext = []
    for i in plaintext_ascii:
        ciphertext.append(
            pow(i, int(public_key_obj['e']), int(public_key_obj['n'])))
    hex_ciphertext = [hex(c) for c in ciphertext]
    print_ciphertext(hex_ciphertext)
    # write ciphertext to file
    write_ciphertext_to_file(hex_ciphertext, output)


# if args.decrypt:
#     # Args for 3rd part of the assignment
#     decrypt = args.decrypt
#     private_key = args.private_key
#     output = args.output

    # read ciphertext
    # ciphertext = read_ciphertext(decrypt)
    # read private key
    # private_key_obj = read_and_parse_private_key(private_key)
