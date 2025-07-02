#include <openssl/bn.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

EC_KEY *MakeNewKey()
{
  printf("%d\n", 11111111);
  EC_KEY *pkey = EC_KEY_new_by_curve_name(NID_secp256k1);
  EC_KEY_generate_key(pkey);
  const BIGNUM *privKey = EC_KEY_get0_private_key(pkey);
  if (privKey)
  {
    char *privKeyHex = BN_bn2hex(privKey);
    if (privKeyHex)
    {
      printf("%s\n", privKeyHex);
      OPENSSL_free(privKeyHex);
    }
  }
  return pkey;
}
void My_RAND_bytes(int size)
{
  const int length = 16;
  unsigned char randomBytes[length];
  RAND_bytes(randomBytes, size);
}

int run(int argc, char *argv[])
{
  const int length = 16;
  unsigned char randomBytes[length];
  RAND_add(NULL, 8, 1.5);
  RAND_add(NULL, 8, 1.5);
  RAND_add(NULL, 8, 1.5);
  EC_KEY *pkey = MakeNewKey();
  return 0;
}
int main(int argc, char *argv[])
{
  return run(argc, argv);
}
