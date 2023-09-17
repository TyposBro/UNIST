import argparse
import math


# ^Utility functions
def read_text(txt):
    with open(txt, 'r') as file:
        data = file.read()
    return data


def read_and_parse_key(public_key):
    obj = {}
    with open(public_key, 'r') as file:
        for line in file:
            # Remove any newline characters
            line = line.strip()
            # Split the line on the equals sign
            key, value = line.split('=')
            obj[key] = value
    return obj


# *1 RSA Key Generation
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


# *2.1 RSA Encryption
def encrypt_text(plaintext_ascii, e, n):
    ciphertext = []
    for i in plaintext_ascii:
        ciphertext.append(
            pow(i, int(e), int(n)))
    return [hex(c) for c in ciphertext]


def print_ciphertext(ciphertext, prefix="Ciphertext:"):
    txt = prefix
    for i in ciphertext:
        txt += f' {i}'
    print(txt)


def write_ciphertext_to_file(ciphertext, output):
    with open(output, 'w') as f:
        for i in ciphertext:
            if i == ciphertext[-1]:
                f.write(f'{i}')
                break
            f.write(f'{i} ')
        f.close()


# *2.2 RSA Descryption
def decrypt_text(ciphertext, d, n):
    plaintext = []
    for i in ciphertext:
        plaintext.append(
            pow(i, int(d), int(n)))
    return ''.join([chr(c) for c in plaintext])


#! Driver code
parser = argparse.ArgumentParser(description='RSA Key Generator')


# ~Args for part #1
parser.add_argument('--generate-key', action='store_true',
                    help='Generate RSA key')
parser.add_argument('--p', type=int, help='Prime number p')
parser.add_argument('--q', type=int, help='Prime number q')


# ~Args for 2.1 part
parser.add_argument("--encrypt", type=str, help="Path to the plaintext file.")
parser.add_argument("--public-key", type=str,
                    help="Path to the public key file.")
parser.add_argument("--output", type=str,
                    help="Path to the output file.")


# ~Args for part #2.2
parser.add_argument("--decrypt", type=str, help="Path to the encrypted file.")
parser.add_argument("--private-key", type=str,
                    help="Path to the private key file.")


# ~Args for part #3.1
parser.add_argument("--sign", type=str, help="Verification message.")
parser.add_argument("--signature", type=str,
                    help="Path to the signature file.")


# ~Args for part #3.2
parser.add_argument("--verify", type=str, help="Verification message.")


# ~Parse the arguments
args = parser.parse_args()

if args.generate_key:
    # Args for 1st part
    p = args.p
    q = args.q
    # generate keys using p and q
    (e, d, mod, phi) = generate(p, q)
    # print keys
    print_generated_keys(e, d, mod, phi)
    # print keys to file
    print_generated_keys_to_file(e, d, mod)

elif args.encrypt:
    # Args for 2nd part
    encrypt = args.encrypt
    public_key = args.public_key
    output_encrypt = args.output

    # read plaintext
    plaintext = read_text(encrypt)
    # read public key
    public_key_obj = read_and_parse_key(public_key)
    plaintext_ascii = [ord(c) for c in plaintext]
    # encrypt plaintext
    hex_ciphertext = encrypt_text(
        plaintext_ascii, public_key_obj["e"], public_key_obj["n"])
    # print ciphertext
    print_ciphertext(hex_ciphertext)
    # write ciphertext to file
    write_ciphertext_to_file(hex_ciphertext, output_encrypt)


elif args.decrypt:
    # Args for 3rd part
    decrypt = args.decrypt
    private_key = args.private_key
    output_decrypt = args.output

    # read ciphertext
    ciphertext = read_text(decrypt)
    ciphertext = ciphertext.split(' ')
    ciphertext = [int(c, 16) for c in ciphertext]

    # read private key
    private_key_obj = read_and_parse_key(private_key)

    # decrypt ciphertext
    plaintext = decrypt_text(
        ciphertext, private_key_obj["d"], private_key_obj["n"])
    print(f'Decrypted plaintext: {plaintext}')
    # write plaintext to file
    with open(output_decrypt, 'w') as f:
        f.write(f'{plaintext}')
        f.close()

elif args.sign:
    sign = args.sign
    private_key = args.private_key
    signature = args.signature
    sign_ascii = [ord(c) for c in sign]
    private_key_obj = read_and_parse_key(private_key)
    singed_msg = encrypt_text(
        sign_ascii, private_key_obj["d"], private_key_obj["n"])
    write_ciphertext_to_file(singed_msg, signature)
    print_ciphertext(singed_msg, "Signature:")


elif args.verify:
    verify = args.verify
    public_key = args.public_key
    signature = args.signature
    verify_ascii = [ord(c) for c in verify]
    public_key_obj = read_and_parse_key(public_key)

    # read signature
    signature = read_text(signature)
    signature = signature.split(' ')
    signature = [int(c, 16) for c in signature]
    decrypted_signature = decrypt_text(
        signature, public_key_obj["e"], public_key_obj["n"])
    if verify == decrypted_signature:
        print("Signature is valid")
    else:
        print("Signature is invalid")


else:
    print("No arguments provided. Please use --help to see the list of available arguments.")
