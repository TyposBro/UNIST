import argparse
import math


# Euclid's algorithm for determining the greatest common divisor
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


# Driver code
parser = argparse.ArgumentParser(description='RSA Key Generator')
parser.add_argument('--generate-key', action='store_true',
                    help='Generate RSA key')
parser.add_argument('--p', type=int, help='Prime number p')
parser.add_argument('--q', type=int, help='Prime number q')

args = parser.parse_args()

if args.generate_key:
    p = args.p
    q = args.q
    # generate keys using p and q
    (encrypt, decrypt, mod, phi) = generate(p, q)


print(f'RSA key pair generated:')
print(f'n={mod}')
print(f'e={encrypt}')
print(f'd={decrypt}')
print(f'phi={phi}')


# Write the public key to a file
with open('public_key.txt', 'w') as f:
    f.write(f'n={mod}\n')
    f.write(f'e={encrypt}')
    f.close()
# Write the private key to a file
with open('private_key.txt', 'w') as f:
    f.write(f'n={mod}\n')
    f.write(f'd={decrypt}')
    f.close()
